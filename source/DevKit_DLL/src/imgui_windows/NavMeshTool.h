#pragma once

#include <NavMesh/RTNavMeshTerrain.h>

class NavMeshTool {
public:

    NavMeshTool();

    void Render();

    void MenuItem();

private:
    void RenderNavCells(const CRTNavMeshTerrain *pNavmesh) const;

    void RenderNavEdgeInternal(const CRTNavMeshTerrain *pNavmesh) const;

    void RenderNavEdgeGlobal(const CRTNavMeshTerrain *pNavmesh) const;

    void RenderObjectOrigin(const SNavMeshInst *pInst, bool bIsFirst) const;

    void RenderObjectCells(const SNavMeshInst *pInst) const;

    void RenderObjectInternalEdges(const SNavMeshInst *pInst) const;

    void RenderObjectGlobalEdges(const SNavMeshInst *pInst) const;

    void RenderObjectGrid(const SNavMeshInst *pInst) const;

private:
    bool bShow;

    bool bFreeze;

    bool bCells;
    bool bEdgeInternal;
    bool bEdgeGlobal;

    bool bObjectOrigin;
    bool bObjectCells;
    bool bObjectInternalEdges;
    bool bObjectGlobalEdges;
    bool bObjectGrid;

    int step;

    CRTNavMeshTerrain *m_pNavmesh;
};
