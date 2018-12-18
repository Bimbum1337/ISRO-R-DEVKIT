#include "StdAfx.h"
#include "ImGui_Windows.h"
#include "imgui-1.66/imgui.h"
#include "imgui-1.66/examples/imgui_impl_dx9.h"
#include "imgui-1.66/examples/imgui_impl_win32.h"
#include "GFX3DFunction/GFXVideo3d.h"
#include <GInterface.h>
#include "unsorted.h"
#include "GlobalHelpersThatHaveNoHomeYet.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Window bools

static bool ImGui_Window_InterfaceDebugger_Show = false;

// Window defs

void ImGui_Window_InterfaceDebugger(bool *p_open);


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
			ImGui::MenuItem("Keyframe Editor", 0, false, false);
			ImGui::MenuItem("Script Editor", 0, false, false);

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

	ImGui::End();

	if (ImGui_Window_InterfaceDebugger_Show) ImGui_Window_InterfaceDebugger(&ImGui_Window_InterfaceDebugger_Show);


	ImGui::EndFrame();

	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

LRESULT CALLBACK ImGui_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//printf("ImGui_WndProc\n");
	return ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam);
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
