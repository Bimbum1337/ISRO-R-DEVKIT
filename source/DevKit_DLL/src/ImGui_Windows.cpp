#include "StdAfx.h"
#include "ImGui_Windows.h"
#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_dx9.h"
#include "imgui/examples/imgui_impl_win32.h"
#include <GFX3DFunction/GFXVideo3d.h>
#include <GFX3DFunction/DrawingHelpers.h>
#include <Game.h>

#include <GInterface.h>
#include "unsorted.h"
#include "GlobalHelpersThatHaveNoHomeYet.h"

#include <NavMesh/RTNavMeshTerrain.h>
#include "hooks.h"
#include "GEffSoundBody.h"
#include "multibyte.h"
#include "CIFSystemMessage.h"
#include <StringUtils.h>
#include <EntityManagerClient.h>
#include <IFflorian0Guide.h>


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Window bools

static bool ImGui_Window_InterfaceDebugger_Show = false;
static bool ImGui_Window_NavMeshTool_Show = false;
static bool ImGui_Window_SoundTool_Show = false;
static bool ImGui_Window_EntityExplorer_Show = false;

// Window defs

void ImGui_Window_InterfaceDebugger(bool *p_open);
void ImGui_Window_SoundTool(bool *p_open);
void ImGui_Window_EntityExplorer(bool *p_open);


// Decls

void ImGui_Window_InterfaceDebugger(bool *p_open)
{
	static bool interface_draw_outline = false;
	static bool interface_draw_marker = false;

	if (!ImGui::Begin("Interface", p_open))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::PushItemWidth(-140);

	// ImGui::Text("Cursor: %5d|%-5d", g_Controler->mouse_x, g_Controler->mouse_y);

	RECT bounds;
	g_CurrentIfUnderCursor->GetBounds(bounds);

	ImGui::Text("@%p", g_CurrentIfUnderCursor);
	ImGui::Text("Class: %s", g_CurrentIfUnderCursor->GetRuntimeClass()->m_lpszClassName);
	ImGui::Text("Id: %d", g_CurrentIfUnderCursor->UniqueID());

	ImGui::Text("%4d|%4d|%4d|%4d", 
		bounds.left,
		bounds.top,
		bounds.bottom,
		bounds.right
		);

	ImGui::Checkbox("Draw Outline", &interface_draw_outline);
	//ImGui::Checkbox("Draw Marker", &interface_draw_marker);

	if (interface_draw_outline) {

		// Get BoundingBox of element
		

		// X1|Y1 ----- X2|Y1
		//   |           |
		//   |           |
		//   |           |
		// X1|Y2 ----- X2|Y2

		int x1 = bounds.left;
		int y1 = bounds.top;
		int x2 = bounds.left + bounds.right;
		int y2 = bounds.top + bounds.bottom;

		// Draw Top
		DXDrawLine(x1, y1, x2, y1, 0x00FF0000, 1.0);

		// Draw Bot
		DXDrawLine(x1, y2, x2, y2, 0x00FF0000, 1.0);

		// Draw Left
		DXDrawLine(x1, y1, x1, y2, 0x00FF0000, 1.0);

		// Draw Right
		DXDrawLine(x2, y1, x2, y2, 0x00FF0000, 1.0);
	}

	ImGui::End();
}



CRTNavMeshTerrain *pNavmesh = 0;

void ImGui_Window_NavMeshTool(bool *p_open)
{
	CGFXVideo3d *gfx = CGFXVideo3d::get();

	static bool bFreeze = false;
	if (!bFreeze || pNavmesh == 0)
	{
		pNavmesh = g_CurrentNavMesh;
	}

	ImGui::Begin("NavMesh Info", p_open);

	ImGui::Text("0x%p", pNavmesh);
	ImGui::Text("Region: 0x%04x", pNavmesh->region);

	ImGui::Text("Cells: %d", pNavmesh->m_navcells.size());

	ImGui::Checkbox("Freeze Current Mesh", &bFreeze);

	static bool bCells = false;
	ImGui::Checkbox("Render Cells", &bCells);

	static bool bEdgeInternal = false;
	ImGui::Checkbox("Render Edge (internal)", &bEdgeInternal);

	static bool bEdgeGlobal = false;
	ImGui::Checkbox("Render Edge (global)", &bEdgeGlobal);

	static bool bObjectOrigin = false;
	ImGui::Checkbox("Render Object Origin", &bObjectOrigin);

	static bool bObjectCells = false;
	ImGui::Checkbox("Render Object Cells", &bObjectCells);

	static int step = 20;
	ImGui::InputInt("Step", &step);

	// Render NavMeshTerrain Cells
	if (bCells)
	{
		for (std::vector<CRTNavCellQuad>::iterator it = pNavmesh->m_navcells.begin(); it != pNavmesh->m_navcells.end(); ++it)
		{
			D3DVECTOR v2 = {0.0, 30, 0.0};
			v2.x = it->vMin_X;
			v2.z = it->vMin_Z;

			D3DVECTOR v3 = {0.0, 30, 0.0};
			v3.x = it->vMax_X;
			v3.z = it->vMax_Z;

			D3DVECTOR pmiss1;
			pmiss1.x = v3.x;
			pmiss1.z = v2.z;

			D3DVECTOR pmiss2;
			pmiss2.x = v2.x;
			pmiss2.z = v3.z;

			PrettyLine3D(v2, pmiss1, step, pNavmesh);
			PrettyLine3D(pmiss1, v3, step, pNavmesh);
			PrettyLine3D(v3 ,pmiss2, step, pNavmesh);
			PrettyLine3D(pmiss2, v2, step, pNavmesh);
		}
	}

	// Render NavMeshTerrain Edges (internal)
	if (bEdgeInternal)
	{
		for (std::vector<CRTNavEdgeInternal>::iterator it = pNavmesh->m_edge_internal.begin(); it != pNavmesh->m_edge_internal.end(); ++it )
		{
			D3DVECTOR min, max;
			min.x = it->m_edge.EdgeMin.x;
			min.z = it->m_edge.EdgeMin.y;

			max.x = it->m_edge.EdgeMax.x;
			max.z = it->m_edge.EdgeMax.y;

			if (it->m_edge.N4_1 == 4)
			{
				PrettyLine3D(min, max, step, D3DCOLOR_ARGB(0, 0, 255, 0), pNavmesh);
			} 
			else if (it->m_edge.N4_1 == 2)
			{
				PrettyLine3D(min, max, step, D3DCOLOR_ARGB(0, 255, 0, 0), pNavmesh);
			}
			else
			{
				// Unsure what this means, but ill draw it anyways
				PrettyLine3D(min, max, step, D3DCOLOR_ARGB(0, 0, 255, 255), pNavmesh);
			}
		}
	}

	if (bObjectOrigin || bObjectCells)
	{
		for (std::vector<CollisionObject*>::iterator it = pNavmesh->m_objectlist.begin(); it != pNavmesh->m_objectlist.end(); ++it)
		{
			CollisionObject *collision_object = *it;

			float yaw = -collision_object->yaw;

			if (bObjectOrigin) 
			{
				D3DVECTOR &vec = collision_object->origin;
				D3DVECTOR vec2d;
				if (gfx->Project(vec, vec2d) > 0)
				{
					{
						// Red X
						D3DXVECTOR3 pTarget(20,0,0);
						rotatey(pTarget, yaw);

						pTarget += vec;

						D3DVECTOR pTarget2D;
						if (gfx->Project(pTarget, pTarget2D) > 0) DXDrawLine(vec2d.x, vec2d.y, pTarget2D.x, pTarget2D.y, D3DCOLOR_ARGB(0, 255, 0, 0), 1.0);
					}

					{
						// Blue Y
						D3DXVECTOR3 pTarget(0,20,0);
						rotatey(pTarget, yaw);

						pTarget += vec;
						
						D3DVECTOR pTarget2D;
						if (gfx->Project(pTarget, pTarget2D) > 0) DXDrawLine(vec2d.x, vec2d.y, pTarget2D.x, pTarget2D.y, D3DCOLOR_ARGB(0, 0, 0, 255), 1.0);
					}

					{
						// Green Z
						D3DXVECTOR3 pTarget(0,0,20);
						rotatey(pTarget, yaw);
						
						pTarget += vec;

						D3DVECTOR pTarget2D;
						if (gfx->Project(pTarget, pTarget2D) > 0) DXDrawLine(vec2d.x, vec2d.y, pTarget2D.x, pTarget2D.y, D3DCOLOR_ARGB(0, 0, 255, 0), 1.0);
					}

					if (it == pNavmesh->m_objectlist.begin())
					{
						DrawRect(vec2d.x-5, vec2d.y-5, 10, 10, D3DCOLOR_ARGB(0, 255, 0, 0));
					} 
					else
					{
						DrawRect(vec2d.x-5, vec2d.y-5, 10, 10, D3DCOLOR_ARGB(0, 255, 255, 0));
					}
				}
			}

			if (bObjectCells)
			{
				CRTNavMeshObj *nvm = collision_object->m_nvm_obj;

				for (std::vector<CRTNavCellTri>::iterator it = nvm->m_cells.begin(); it != nvm->m_cells.end(); ++it)
				{
					CRTNavCellTri &cell = *it;

					D3DXVECTOR3 p1, p2, p3, p12d, p22d, p32d;

					p1 = cell.vP1;
					rotatey(p1, yaw);
					p1 += collision_object->origin;

					p2 = cell.vP2;
					rotatey(p2, yaw);
					p2 += collision_object->origin;

					p3 = cell.vP3;
					rotatey(p3, yaw);
					p3 += collision_object->origin;

					
					bool vis1 = gfx->Project(p1, p12d) > 0;
					bool vis2 = gfx->Project(p2, p22d) > 0;
					bool vis3 = gfx->Project(p3, p32d) > 0;

					if (vis1 && vis2) DXDrawLine(p12d.x, p12d.y, p22d.x, p22d.y, D3DCOLOR_ARGB(0, 255, 128, 0), 1.0);
					if (vis2 && vis3) DXDrawLine(p22d.x, p22d.y, p32d.x, p32d.y, D3DCOLOR_ARGB(0, 255, 128, 0), 1.0);
					if (vis1 && vis3) DXDrawLine(p12d.x, p12d.y, p32d.x, p32d.y, D3DCOLOR_ARGB(0, 255, 128, 0), 1.0);
				}
			}
		}
	}

	ImGui::End();
}

bool sound_item_getter(void* data, int idx, const char **outdata)
{
	std::vector<std::n_string> *items = (std::vector<std::n_string>*)data;

	if (idx >= items->size())
		return false;

	std::n_string &str = items->at(idx);

	*outdata = str.c_str();

	return true;
}

bool ImGui_Window_SoundTool_FilterMatch(const std::n_wstring &input, const std::n_wstring &search)
{
	if (search.empty())
		return true;
#if 0
	std::vector<std::n_wstring> input_tokens = split(input, L':');
	std::vector<std::n_wstring> search_tokens = split(input, L':');

	std::vector<std::n_wstring>::iterator it_input;
	std::vector<std::n_wstring>::iterator it_search;

	for (
		it_input = input_tokens.begin(),
		it_search = search_tokens.begin();
		it_input != input_tokens.end() && it_search != search_tokens.end();
		++it_input, ++it_search)
	{
		if ((*it_input).empty() || (*it_search).empty()) 
			continue;

		if ((*it_input).find(*it_search) == std::n_wstring::npos)
		{
			return false;
		}

	}
#endif

	return !(input.find(search) == std::n_wstring::npos);
}

int ImGui_Window_SoundTool_Filter(std::vector<std::n_string> *items, const std::n_wstring &search)
{
	CGEffSoundBody* snd = CGEffSoundBody::get();

	items->clear();

	for (std::n_hash_map<std::n_wstring, int>::iterator it = snd->m_sounds.begin(); it != snd->m_sounds.end(); ++it)
	{
		if (ImGui_Window_SoundTool_FilterMatch((*it).first, search))
			items->push_back(TO_NSTRING((*it).first));
	}

	return 0;
}

void ImGui_Window_SoundTool(bool *p_open)
{
	static int current_item = 0;
	static std::vector<std::n_string> items;
	static bool inited = false;

	if (!inited)
	{
		ImGui_Window_SoundTool_Filter(&items, L"");
		inited = true;
	}

	if (!ImGui::Begin("Sound Tool", p_open))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	static char buffer[100];
	if (ImGui::InputText("Filter", buffer, ARRAY_SIZE(buffer)))
	{
		// Value has changed
		printf("Value has changed: %s\n", buffer);
		ImGui_Window_SoundTool_Filter(&items, acp_n_decode(buffer, strlen(buffer)));
	}


	if (ImGui::ListBox("Sounds", &current_item, &sound_item_getter, (void*)&items, items.size(), 20))
	{
		CGEffSoundBody* snd = CGEffSoundBody::get();

		std::n_string itm = items[current_item];
		std::n_wstring sndKey = TO_NWSTRING(itm);

		snd->PlaySoundInner(&sndKey, 0, 0.0);
	}


	ImGui::End();
}

struct EntityListColumnHeader
{
    const char* label;
    float size;
};

void ImGui_Window_EntityExplorer(bool *p_open) {

    if (!ImGui::Begin("EntityManager", p_open)) {
        ImGui::End();
        return;
    }

    EntityListColumnHeader headers[] =
        {
            { "ID", 40 },
            { "Address", 70 },
            { "Type", 120 },
            { "Position", 500 }
        };

    ImGui::Columns(IM_ARRAYSIZE(headers), "TableTextureColumns", true);
    ImGui::Separator();

    float offset = 0.0f;
    for(int i = 0; i < IM_ARRAYSIZE(headers); i++)
    {
        EntityListColumnHeader *header = &headers[i];
        ImGui::Text(header->label);
        ImGui::SetColumnOffset(-1, offset);
        offset += header->size;
        ImGui::NextColumn();
    }

    ImGui::Separator();

    static int selected = -1;

    for (std::map<int,CIObject*>::iterator it = g_pGfxEttManager->entities.begin(); it != g_pGfxEttManager->entities.end(); ++it)
    {
        char label[32];
        sprintf(label, "%d", it->first);

        if (ImGui::Selectable(label, selected == it->first, ImGuiSelectableFlags_SpanAllColumns))
            selected = it->first;

        ImGui::NextColumn();

        ImGui::Text("%p", it->second); ImGui::NextColumn();
        ImGui::Text("%s", it->second->GetRuntimeClass()->m_lpszClassName); ImGui::NextColumn();

        ImGui::Text("(%d,%d) (%.2f, %.2f, %.2f)",
                    it->second->region.single.x,
                    it->second->region.single.y,
                    it->second->location.x,
                    it->second->location.y,
                    it->second->location.z
        ); ImGui::NextColumn();

        ImGui::Separator();

    }

    ImGui::Columns(1);

    ImGui::Text("Number of Entites: %d", g_pGfxEttManager->entities.size());

    char label[32];
    sprintf(label, "Move to Entity #%d", selected);

    static bool b_checked = false;
    ImGui::Checkbox("Highlight selected", &b_checked);

    if (b_checked && selected != -1)
    {
        // ESP ON

        std::map<int,CIObject*>::iterator elem = g_pGfxEttManager->entities.find(selected);
        if (elem != g_pGfxEttManager->entities.end())
        {

            D3DVECTOR d2dpos, d2dpos_up, d2dpos_own;
            D3DVECTOR d3dpos = elem->second->location;
            D3DVECTOR d3dpos_up = elem->second->location;

            d3dpos_up.y += 18.0;

            if (CGFXVideo3d::get()->Project(d3dpos, d2dpos) > 0)
            {
                DrawRect(d2dpos.x-5, d2dpos.y-5, 10, 10);

                if (CGFXVideo3d::get()->Project(theApp.camera.character, d2dpos_own) > 0)
                {
                    DXDrawLine(d2dpos_own.x, d2dpos_own.y, d2dpos.x, d2dpos.y, D3DCOLOR_ARGB(0, 255, 255, 0), 1.0);
                }


            }

            if (CGFXVideo3d::get()->Project(d3dpos_up, d2dpos_up) > 0)
            {
                DXDrawLine(d2dpos.x, d2dpos.y, d2dpos_up.x, d2dpos_up.y, D3DCOLOR_ARGB(0, 0, 255, 0), 1.0);
            }
        }
    }

    if (ImGui::Button(label))
    {
        std::map<int,CIObject*>::iterator elem = g_pGfxEttManager->entities.find(selected);
        if (elem != g_pGfxEttManager->entities.end())
        {
            g_pCGInterface->m_Nav.MoveTo(elem->second->region, elem->second->location);
        }
    }

    ImGui::End();
}

void ImGui_OnCreate(HWND hWindow, void* msghandler, int a3)
{
	printf("ImGui_OnCreate\n");
	ImGui::CreateContext();

	ImGui_ImplWin32_Init(hWindow);
	ImGui_ImplDX9_Init(g_CD3DApplication->m_pd3dDevice);

}

void ImGui_OnEndScene()
{
	// printf("ImGui_OnEndScene %d\n", g_CD3DApplication->IsLost());

	if (g_CD3DApplication->IsLost())
	{
		return;
	}

	ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	    // Menu
    if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("Debug Mode", NULL, reinterpret_cast<bool*>(0x00EED6A7));
			
			ImGui::Separator();

			if (ImGui::MenuItem("Restart"))
				SendRestartRequest(2);
			
			if (ImGui::MenuItem("Exit"))
				SendRestartRequest(1);
			
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Edit"))
		{
			ImGui::MenuItem("Cut");
			ImGui::MenuItem("Copy");
			ImGui::MenuItem("Paste");
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Options"))
		{
			ImGui::MenuItem("Fullscreen");

			if (ImGui::BeginMenu("Resolution"))
			{
				ImGui::MenuItem("640x480 (4:3)");
				ImGui::MenuItem("800x600 (4:3)");
				ImGui::Separator();
				ImGui::MenuItem("Enter custom resolution");
				
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Camera"))
			{
				ImGui::MenuItem("Fixed behind character");
				ImGui::MenuItem("Fixed height");
				ImGui::MenuItem("Free visual point");
				ImGui::MenuItem("Free (Fly)");

				ImGui::EndMenu();
			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Tools"))
		{
			ImGui::MenuItem("Interface Tool", 0, &ImGui_Window_InterfaceDebugger_Show);
            ImGui::MenuItem("NavMesh Explorer", 0, &ImGui_Window_NavMeshTool_Show);
            ImGui::MenuItem("Enity Explorer", 0, &ImGui_Window_EntityExplorer_Show);
			ImGui::MenuItem("Keyframe Editor", 0, false, false);
			ImGui::MenuItem("Script Editor", 0, false, false);
			ImGui::MenuItem("Sound Tool", 0, &ImGui_Window_SoundTool_Show);

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Windows"))
		{
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}


	ImGui::Begin("Hello World");

	if (ImGui::Button("Hide"))
	{
		g_pCGInterface->m_IRM.GetResObj(1338, 1)->SetVisibility(false);
	}

	if (ImGui::Button("Show"))
	{
		g_pCGInterface->m_IRM.GetResObj(1338, 1)->SetVisibility(true);
	}

	if (ImGui::Button("Init Event")) {
	    g_pCGInterface->CreateFlorian0Event();
	}

    if (ImGui::Button("System Log"))
    {
        wchar_t message[] = L"System Log Message";

        // Color (Picker: https://developer.mozilla.org/en-US/docs/Web/CSS/CSS_Colors/Color_picker_tool)
        int color = D3DCOLOR_ARGB(255, 0, 255, 0);

        // Get the SystemLog Window - Media//resinfo//ginterface.txt - GDR_SYSTEM_MESSAGE_VIEW:CIFSystemMessage -> ID Should be 68
        CIFSystemMessage *systemmessage = reinterpret_cast<CIFSystemMessage *>(g_pCGInterface->m_IRM.GetResObj(68, 1));
        systemmessage->write(0xFF, color, message, 0, 1);
    }

	ImGui::End();

	if (ImGui_Window_InterfaceDebugger_Show) ImGui_Window_InterfaceDebugger(&ImGui_Window_InterfaceDebugger_Show);
	if (ImGui_Window_NavMeshTool_Show) ImGui_Window_NavMeshTool(&ImGui_Window_NavMeshTool_Show);
	
	if (ImGui_Window_SoundTool_Show) ImGui_Window_SoundTool(&ImGui_Window_InterfaceDebugger_Show);
    if (ImGui_Window_EntityExplorer_Show) ImGui_Window_EntityExplorer(&ImGui_Window_EntityExplorer_Show);

	ImGui::EndFrame();

	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

LRESULT CALLBACK ImGui_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//printf("ImGui_WndProc\n");

	// Check if context is already created
	if (!ImGui::GetCurrentContext())
		return RESULT_PASS;

	ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam);

	// Only pass events if imgui wants it
	if (ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard)
		return RESULT_DISCARD;

	return RESULT_PASS;
}

void ImGui_OnPreSetSize(int width, int height)
{
	printf("ImGui_OnPreSetSize\n");
	ImGui_ImplDX9_InvalidateDeviceObjects();
}

void ImGui_OnPostSetSize(int width, int height)
{
	printf("ImGui_OnPostSetSize\n");
	//ImGui_ImplDX9_CreateDeviceObjects();
	ImGui_ImplDX9_Init(g_CD3DApplication->m_pd3dDevice);
}
