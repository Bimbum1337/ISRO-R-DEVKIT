#include "ProcessViewer.h"

#include <Game.h>
#include <imgui/imgui.h>

void ProcessViewer::MenuItem() {
    ImGui::MenuItem("Process Viewer", 0, &bShow);
}
void ProcessViewer::Render() {

    if (!bShow) return;

    if (!ImGui::Begin("Process Viewer", &bShow)) {
        ImGui::End();
        return;
    }

    if (theApp.GetCurrentProcess() != NULL) {
        const CProcess *proc = theApp.GetCurrentProcess();

        ImGui::LabelText("Class Name", "%s", proc->GetRuntimeClass()->m_lpszClassName);
        ImGui::LabelText("Number of Updates", "%d", proc->m_iNumberOfUpdates);
        ImGui::LabelText("Elapsed seconds", "%f", proc->m_fElapsedSeconds);
        ImGui::LabelText("Process Run Terminate", "%d", proc->m_blProcessRunTerminate);
        ImGui::LabelText("Run", "%d", proc->m_blRun);
        ImGui::LabelText("Child Process", "%p", proc->GetChildProcess());

        RenderThreadlist(proc);

        RenderSomeMap(proc);
    }

    ImGui::End();
}

void ProcessViewer::RenderThreadlist(const CProcess *proc) const {

    ImGui::Text("Thread List (%d)", proc->m_sThreadList.size());

    ColumnHeader headers[] = {
            {"Key", 70},
            {"Value", 70},
    };

    ImGui::Columns(IM_ARRAYSIZE(headers), "TableTextureColumns", true);
    ImGui::Separator();

    float offset = 0.0f;
    for (int i = 0; i < IM_ARRAYSIZE(headers); i++) {
        ColumnHeader *header = &headers[i];
        ImGui::Text(header->label);
        ImGui::SetColumnOffset(-1, offset);
        offset += header->width;
        ImGui::NextColumn();
    }

    ImGui::Separator();

    for (std::n_map<undefined4, undefined4>::const_iterator it = proc->m_sThreadList.begin(); it != proc->m_sThreadList.end(); ++it) {
        ImGui::Text("%08x", (*it).first);
        ImGui::NextColumn();
        ImGui::Text("%08x", (*it).second);
        ImGui::NextColumn();
        ImGui::Separator();
    }

    ImGui::Columns(1);
    ImGui::Separator();
}

void ProcessViewer::RenderSomeMap(const CProcess *proc) const {

    ImGui::Text("Some List (%d)", proc->m_someMap.size());

    ColumnHeader headers[] = {
            {"Address", 70},
            {"Class Name", 120},
    };

    ImGui::Columns(IM_ARRAYSIZE(headers), "TableTextureColumns", true);
    ImGui::Separator();

    float offset = 0.0f;
    for (int i = 0; i < IM_ARRAYSIZE(headers); i++) {
        ColumnHeader *header = &headers[i];
        ImGui::Text(header->label);
        ImGui::SetColumnOffset(-1, offset);
        offset += header->width;
        ImGui::NextColumn();
    }

    ImGui::Separator();

    for (std::n_set<CObj *>::const_iterator it = proc->m_someMap.begin(); it != proc->m_someMap.end(); ++it) {
        ImGui::Text("%08x", (*it));
        ImGui::NextColumn();
        ImGui::Text("%s", (*it)->GetRuntimeClass()->m_lpszClassName);
        ImGui::NextColumn();
        ImGui::Separator();
    }

    ImGui::Columns(1);
    ImGui::Separator();
}
