#include "NavMeshTool.h"
#include "../MathUtil.h"

#include <imgui/imgui.h>
#include <GFX3DFunction/GFXVideo3d.h>
#include <GFX3DFunction/DrawingHelpers.h>
#include <unsorted.h>

void NavMeshTool::Render() {

    if (!bShow) return;

    CGFXVideo3d *gfx = CGFXVideo3d::get();

    if (!bFreeze || m_pNavmesh == 0) {
        m_pNavmesh = g_CurrentNavMesh;
    }

    ImGui::Begin("NavMesh Info", &bShow);

    ImGui::Text("0x%p", m_pNavmesh);
    ImGui::Text("Region: 0x%04x", m_pNavmesh->m_Region);

    ImGui::Text("Total Cells: %d", m_pNavmesh->m_Cells.size());
    ImGui::Text("Open Cells: %d", m_pNavmesh->m_OpenCellCount);

    ImGui::Checkbox("Freeze Current Mesh", &bFreeze);
    ImGui::Checkbox("Render Cells", &bCells);
    ImGui::Checkbox("Render Edge (internal)", &bEdgeInternal);
    ImGui::Checkbox("Render Edge (global)", &bEdgeGlobal);
    ImGui::Checkbox("Render Object Origin", &bObjectOrigin);
    ImGui::Checkbox("Render Object Cells", &bObjectCells);
    ImGui::Checkbox("Render Object Internal Edges", &bObjectInternalEdges);
    ImGui::Checkbox("Render Object Global Edges", &bObjectGlobalEdges);
    ImGui::Checkbox("Render Object Grid", &bObjectGrid);

    ImGui::InputInt("Step", &step);

    // Render NavMeshTerrain Cells
    if (bCells) {
        RenderNavCells(m_pNavmesh);
    }

    // Render NavMeshTerrain Edges (internal)
    if (bEdgeInternal) {
        RenderNavEdgeInternal(m_pNavmesh);
    }

    if (bEdgeGlobal) {
        RenderNavEdgeGlobal(m_pNavmesh);
    }

    if (bObjectOrigin || bObjectCells || bObjectGlobalEdges || bObjectInternalEdges || bObjectGrid) {
        for (std::vector<SNavMeshInst *>::iterator it = m_pNavmesh->m_sObjList.begin();
             it != m_pNavmesh->m_sObjList.end(); ++it) {
            SNavMeshInst *pInst = *it;

            if (bObjectOrigin) {
                RenderObjectOrigin(pInst, it == m_pNavmesh->m_sObjList.begin());
            }

            if (bObjectCells) {
                RenderObjectCells(pInst);
            }

            if (bObjectInternalEdges) {
                RenderObjectInternalEdges(pInst);
            }

            if (bObjectGlobalEdges) {
                RenderObjectGlobalEdges(pInst);
            }

            if (bObjectGrid) {
                RenderObjectGrid(pInst);
            }
        }
    }

    ImGui::End();
}

NavMeshTool::NavMeshTool() : m_pNavmesh(0), bShow(false), bFreeze(false), bCells(false), bEdgeInternal(false),
                             bEdgeGlobal(false),
                             bObjectOrigin(false), bObjectCells(false), bObjectInternalEdges(false),
                             bObjectGlobalEdges(false), bObjectGrid(false), step(20) {

}

void NavMeshTool::RenderNavEdgeGlobal(const CRTNavMeshTerrain *pNavmesh) const {
    for (std::vector<CRTNavEdgeGlobal>::const_iterator it = pNavmesh->m_GlobalEdges.begin();
         it != pNavmesh->m_GlobalEdges.end(); ++it) {
        NavEdgeGlobal edge = it->m_sData;
        D3DXVECTOR3 min = ToVector3(edge.sLine.Min);
        D3DXVECTOR3 max = ToVector3(edge.sLine.Max);

        PrettyLine3D(min, max, step, GetColorFromEdgeFlag(edge.btFlag), pNavmesh);
    }
}

void NavMeshTool::RenderNavCells(const CRTNavMeshTerrain *pNavmesh) const {
    for (std::vector<CRTNavCellQuad>::const_iterator it = pNavmesh->m_Cells.begin();
         it != pNavmesh->m_Cells.end(); ++it) {
        D3DVECTOR v2 = {0.0, 30, 0.0};
        v2.x = it->m_vMin.x;
        v2.z = it->m_vMin.y;

        D3DVECTOR v3 = {0.0, 30, 0.0};
        v3.x = it->m_vMax.x;
        v3.z = it->m_vMax.y;

        D3DVECTOR pmiss1;
        pmiss1.x = v3.x;
        pmiss1.z = v2.z;

        D3DVECTOR pmiss2;
        pmiss2.x = v2.x;
        pmiss2.z = v3.z;

        PrettyLine3D(v2, pmiss1, step, pNavmesh);
        PrettyLine3D(pmiss1, v3, step, pNavmesh);
        PrettyLine3D(v3, pmiss2, step, pNavmesh);
        PrettyLine3D(pmiss2, v2, step, pNavmesh);
    }
}

void NavMeshTool::RenderNavEdgeInternal(const CRTNavMeshTerrain *pNavmesh) const {
    for (std::vector<CRTNavEdgeInternal>::const_iterator it = pNavmesh->m_InternalEdges.begin();
         it != pNavmesh->m_InternalEdges.end(); ++it) {
        NavEdge edge = it->m_sData;
        D3DXVECTOR3 min = ToVector3(edge.sLine.Min);
        D3DXVECTOR3 max = ToVector3(edge.sLine.Max);

        PrettyLine3D(min, max, step, GetColorFromEdgeFlag(edge.btFlag), pNavmesh);
    }
}

void NavMeshTool::RenderObjectOrigin(const SNavMeshInst *pInst, bool bIsFirst) const {
    CGFXVideo3d *gfx = CGFXVideo3d::get();
    const D3DVECTOR &vec = pInst->m_sObj.Offset;
    float yaw = -pInst->m_sObj.Yaw;
    D3DVECTOR vec2d;
    if (gfx->Project(vec, vec2d) > 0) {
        {
            // Red X
            D3DXVECTOR3 pTarget(20, 0, 0);
            rotatey(pTarget, yaw);

            pTarget += vec;

            D3DVECTOR pTarget2D;
            if (gfx->Project(pTarget, pTarget2D) > 0)
                DXDrawLine((int) vec2d.x, (int) vec2d.y, (int) pTarget2D.x, (int) pTarget2D.y,
                           D3DCOLOR_ARGB(0, 255, 0, 0), 1.0);
        }

        {
            // Blue Y
            D3DXVECTOR3 pTarget(0, 20, 0);
            rotatey(pTarget, yaw);

            pTarget += vec;

            D3DVECTOR pTarget2D;
            if (gfx->Project(pTarget, pTarget2D) > 0)
                DXDrawLine((int) vec2d.x, (int) vec2d.y, (int) pTarget2D.x, (int) pTarget2D.y,
                           D3DCOLOR_ARGB(0, 0, 0, 255), 1.0);
        }

        {
            // Green Z
            D3DXVECTOR3 pTarget(0, 0, 20);
            rotatey(pTarget, yaw);

            pTarget += vec;

            D3DVECTOR pTarget2D;
            if (gfx->Project(pTarget, pTarget2D) > 0)
                DXDrawLine((int) vec2d.x, (int) vec2d.y, (int) pTarget2D.x, (int) pTarget2D.y,
                           D3DCOLOR_ARGB(0, 0, 255, 0), 1.0);
        }

        if (bIsFirst) {
            DrawRect((int) vec2d.x - 5, (int) vec2d.y - 5, 10, 10, D3DCOLOR_ARGB(0, 255, 0, 0));
        } else {
            DrawRect((int) vec2d.x - 5, (int) vec2d.y - 5, 10, 10, D3DCOLOR_ARGB(0, 255, 255, 0));
        }
    }
}

void NavMeshTool::RenderObjectCells(const SNavMeshInst *pInst) const {
    CGFXVideo3d *gfx = CGFXVideo3d::get();
    CRTNavMeshObj *pObj = pInst->m_pObject;
    const D3DVECTOR &vec = pInst->m_sObj.Offset;
    const D3DXVECTOR3 &offset = pInst->m_sObj.Offset;
    float yaw = -pInst->m_sObj.Yaw;

    for (std::vector<CRTNavCellTri>::const_iterator it = pObj->m_Cells.begin(); it != pObj->m_Cells.end(); ++it) {
        const CRTNavCellTri &cell = *it;

        D3DXVECTOR3 p1, p2, p3, p12d, p22d, p32d;

        p1 = cell.AssocVertex[0]->Position;
        rotatey(p1, yaw);
        p1 += offset;

        p2 = cell.AssocVertex[1]->Position;
        rotatey(p2, yaw);
        p2 += offset;

        p3 = cell.AssocVertex[2]->Position;
        rotatey(p3, yaw);
        p3 += offset;

        bool vis1 = gfx->Project(p1, p12d) > 0;
        bool vis2 = gfx->Project(p2, p22d) > 0;
        bool vis3 = gfx->Project(p3, p32d) > 0;

        if (vis1 && vis2)
            DXDrawLine((int) p12d.x, (int) p12d.y, (int) p22d.x, (int) p22d.y,
                       D3DCOLOR_ARGB(0, 255, 128, 0), 1.0);

        if (vis2 && vis3)
            DXDrawLine((int) p22d.x, (int) p22d.y, (int) p32d.x, (int) p32d.y,
                       D3DCOLOR_ARGB(0, 255, 128, 0), 1.0);

        if (vis1 && vis3)
            DXDrawLine((int) p12d.x, (int) p12d.y, (int) p32d.x, (int) p32d.y,
                       D3DCOLOR_ARGB(0, 255, 128, 0), 1.0);

    }
}

void NavMeshTool::RenderObjectGrid(const SNavMeshInst *pInst) const {
    CGFXVideo3d *gfx = CGFXVideo3d::get();
    CRTNavMeshObj *pObj = pInst->m_pObject;
    const D3DXVECTOR3 &offset = pInst->m_sObj.Offset;
    float yaw = -pInst->m_sObj.Yaw;


    for (int y = 0; y < pObj->m_Grid.m_Height; y++) {
        for (int x = 0; x < pObj->m_Grid.m_Width; x++) {
            const float TILE_WIDTH = 100.0f;
            const float TILE_HEIGHT = 100.0f;

            D3DXVECTOR3 localOrigin =
                    ToVector3(pObj->m_Grid.m_Origin) + D3DXVECTOR3(x * TILE_WIDTH, 0, y * TILE_HEIGHT);
            D3DXVECTOR3 p1 = localOrigin + D3DXVECTOR3(0, 0, 0);
            D3DXVECTOR3 p2 = localOrigin + D3DXVECTOR3(TILE_WIDTH, 0, 0);
            D3DXVECTOR3 p3 = localOrigin + D3DXVECTOR3(0, 0, TILE_HEIGHT);
            D3DXVECTOR3 p4 = localOrigin + D3DXVECTOR3(TILE_WIDTH, 0, TILE_HEIGHT);

            rotatey(p1, yaw);
            rotatey(p2, yaw);
            rotatey(p3, yaw);
            rotatey(p4, yaw);

            p1 += offset;
            p2 += offset;
            p3 += offset;
            p4 += offset;

            D3DXVECTOR3 p1_2d, p2_2d, p3_2d, p4_2d;
            bool vis1 = gfx->Project(p1, p1_2d) > 0;
            bool vis2 = gfx->Project(p2, p2_2d) > 0;
            bool vis3 = gfx->Project(p3, p3_2d) > 0;
            bool vis4 = gfx->Project(p4, p4_2d) > 0;

            if (vis1 && vis2) DXDrawLine((int) p1_2d.x, (int) p1_2d.y, (int) p2_2d.x, (int) p2_2d.y, 0x00FF88FF, 1.0);
            if (vis1 && vis3) DXDrawLine((int) p1_2d.x, (int) p1_2d.y, (int) p3_2d.x, (int) p3_2d.y, 0x00FF88FF, 1.0);
            if (vis2 && vis4) DXDrawLine((int) p2_2d.x, (int) p2_2d.y, (int) p4_2d.x, (int) p4_2d.y, 0x00FF88FF, 1.0);
            if (vis3 && vis4) DXDrawLine((int) p3_2d.x, (int) p3_2d.y, (int) p4_2d.x, (int) p4_2d.y, 0x00FF88FF, 1.0);
        }
    }
}

void NavMeshTool::RenderObjectGlobalEdges(const SNavMeshInst *pInst) const {
    CGFXVideo3d *gfx = CGFXVideo3d::get();
    CRTNavMeshObj *pObj = pInst->m_pObject;
    const D3DXVECTOR3 &offset = pInst->m_sObj.Offset;
    float yaw = -pInst->m_sObj.Yaw;


    for (std::vector<PrimNavMeshEdge>::iterator it = pObj->m_GlobalEdges.begin();
         it != pObj->m_GlobalEdges.end(); ++it) {
        PrimNavMeshEdge &edge = *it;

        D3DXVECTOR3 p1, p2, p1_2d, p2_2d;
        p1 = edge.AssocVertex[0]->Position;
        rotatey(p1, yaw);
        p1 += offset;

        p2 = edge.AssocVertex[1]->Position;
        rotatey(p2, yaw);
        p2 += offset;

        bool vis1 = gfx->Project(p1, p1_2d) > 0;
        bool vis2 = gfx->Project(p2, p2_2d) > 0;

        if (vis1 && vis2) {
            DXDrawLine((int) p1_2d.x, (int) p1_2d.y, (int) p2_2d.x, (int) p2_2d.y,
                       GetColorFromEdgeFlag(edge.btFlag), 1.0);
        }
    }
}

void NavMeshTool::RenderObjectInternalEdges(const SNavMeshInst *pInst) const {
    CGFXVideo3d *gfx = CGFXVideo3d::get();
    CRTNavMeshObj *pObj = pInst->m_pObject;
    const D3DXVECTOR3 &offset = pInst->m_sObj.Offset;
    float yaw = -pInst->m_sObj.Yaw;

    for (std::vector<PrimNavMeshEdge>::const_iterator it = pObj->m_InternalEdges.begin();
         it != pObj->m_InternalEdges.end(); ++it) {
        const PrimNavMeshEdge &edge = *it;

        D3DXVECTOR3 p1, p2, p1_2d, p2_2d;
        p1 = edge.AssocVertex[0]->Position;
        rotatey(p1, yaw);
        p1 += offset;

        p2 = edge.AssocVertex[1]->Position;
        rotatey(p2, yaw);
        p2 += offset;

        bool vis1 = gfx->Project(p1, p1_2d) > 0;
        bool vis2 = gfx->Project(p2, p2_2d) > 0;

        if (vis1 && vis2) {
            DXDrawLine((int) p1_2d.x, (int) p1_2d.y, (int) p2_2d.x, (int) p2_2d.y,
                       GetColorFromEdgeFlag(edge.btFlag), 1.0);
        }
    }
}

void NavMeshTool::MenuItem() {
    ImGui::MenuItem("NavMesh Explorer", 0, &bShow);
}
