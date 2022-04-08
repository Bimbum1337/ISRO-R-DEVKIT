#include "ICUser.h"
#include "Game.h"
#include "GFX3DFunction/RStateMgr.h"
#include "ICPlayer.h"
#include "CharacterDependentData.h"
#include <GlobalDataManager.h>
#include "unsorted.h"
#include <SimpleViewer/VBDynamic.h>

#define p_MiniIcon_TexturePtrs (*reinterpret_cast<IDirect3DBaseTexture9***>(0x0110ab38))

#define g_RuntimeTextureSomething (*reinterpret_cast<std::n_map<int, const IDirect3DBaseTexture9*> *>(0x0110af70))


GFX_IMPLEMENT_DYNAMIC_EXISTING(CICUser, 0x00ef1bc0)

// CICUser::GetGuildName() .text 009DB100 00000007   R . . . . . .
const std::wstring &CICUser::GetGuildName() const {
    return reinterpret_cast<const std::wstring &(__thiscall *)(const CICUser *)>(0x009DB100)(this);
}

UserGuildInfo *CICUser::GetGuildInfo() const {
    return m_pGuildInfo;
}

unsigned char CICUser::GetJobLevel() const {
    return reinterpret_cast<unsigned char (__thiscall *)(const CICUser *)>(0x009db0e0)(this);
}

undefined1 CICUser::FUN_009db0d0() const {
    return reinterpret_cast<undefined1 (__thiscall *)(const CICUser *)>(0x009db0d0)(this);
}

void CICUser::Func_15(int param_1, float *param_2) {
    //printf("Func_15 %d %p\n", param_1, param_2);
    //reinterpret_cast<void (__thiscall *)(const CICUser *, int param_1, float *param_2)>(0x009dea30)(this, param_1, param_2);

    TRIJOB_TYPE trijobType;
    std::n_wstring guildString;

    if (param_1 != 4) {
        CICharactor::Func_15(param_1, param_2);
        return;
    }

    CRStateMgr::SetStageOperator<0, D3DTSS_COLOROP>(D3DTOP_SELECTARG1);
    CRStateMgr::SetStageOperator<0, D3DTSS_COLORARG1>(D3DTA_TEXTURE);
    g_RStateMgr.FUN_00471360(0xf, 1);
    g_RStateMgr.FUN_00471360(0x19, 7);
    g_RStateMgr.FUN_00471360(0x18, 0x80);

    int outVar;
    g_RStateMgr.FUN_00478500(0x1c, &outVar);
    if (outVar != 0) {
        g_RStateMgr.FUN_00471360(0x1c, 0);
    }


    D3DVECTOR dataOut[8];
    this->fonttexture_playername.FUN_008b2d30(param_2, dataOut);
    float dataOut2x_local = dataOut[2].x;
    dataOut[0].z = m_renderDepth;
    dataOut[2].z = m_renderDepth;
    dataOut[4].z = m_renderDepth;
    dataOut[6].z = m_renderDepth;
    dataOut[1].y = 0.0f;
    dataOut[1].z = 0.0f;
    dataOut[3].y = 1.0f;
    dataOut[5].y = 1.0f;
    dataOut[5].z = 1.0f;
    dataOut[7].z = 1.0f;
    dataOut[3].z = 0.0f;
    dataOut[7].y = 0.0f;


    if (CGame::STA_FUN_004f9d00().field_c != '\0') {
        if (this->m_titleText.length() != 0) {
            dataOut[0].x = dataOut[0].x - (static_cast<float>(static_cast<short>(this->fonttexture_title.GetDimensions().width)) *0.5f + 2.0f);
        }
        dataOut[0].x = dataOut[0].x - 20.0f;
        dataOut[2].y = dataOut[0].y;
        dataOut[4].y = dataOut[0].y + 16.0f;
        dataOut[2].x = dataOut[0].x + 16.0f;
        dataOut[4].x = dataOut[0].x + 16.0f;
        dataOut[6].x = dataOut[0].x;
        dataOut[6].y = dataOut[4].y;

        trijobType = this->GetJobType();
        if (trijobType == TRIJOB_TRADER) {
            g_RStateMgr.SetTextureForStage(0, p_MiniIcon_TexturePtrs[0x0]); // interface\\ifcommon\\com_job_merchant.ddj
        } else if (trijobType == TRIJOB_THIEF) {
            g_RStateMgr.SetTextureForStage(0, p_MiniIcon_TexturePtrs[0x1]); // interface\\ifcommon\\com_job_thief.ddj
        } else if (trijobType == TRIJOB_HUNTER) {
            g_RStateMgr.SetTextureForStage(0, p_MiniIcon_TexturePtrs[0x2]); // interface\\ifcommon\\com_job_hunter.ddj
        }

        float fVar5 = dataOut[0].x;
        if (trijobType != TRIJOB_NOJOB) {
            // shift icon to the right
            dataOut[0].x = dataOut2x_local + 4.0f;
            dataOut[2].x = dataOut[0].x + 16.0f;
            dataOut[4].x = dataOut[0].x + 16.0f;
            dataOut[6].x = dataOut[0].x;
            int local_158 = 0;
            if (g_pDynamicVertexBuffer->IVBDynamic_Func_6(dataOut, 0x60, &local_158) != 0) {
                IDirect3DVertexBuffer9 *iVar5 = g_pDynamicVertexBuffer->IVBDynamic_Func_5();
                g_RStateMgr.m_pDevice->SetStreamSource(0, iVar5, 0, 0x18);
                g_RStateMgr.FUN_00470060(6, local_158, 2);
            }

            // probably resetting the position of the icon part1
            dataOut[6].x = fVar5;
            dataOut[2].x = fVar5 + 16.0f;
            dataOut[4].x = dataOut[2].x;
        }
        // probably resetting to default part2
        dataOut[0].x = fVar5;

        if (GetBeginnerState() != false) {
            g_RStateMgr.SetTextureForStage(0, p_MiniIcon_TexturePtrs[0x4]); // icon\\etc\\icon_rudiment.ddj

            int local_158 = 0;
            if (g_pDynamicVertexBuffer->IVBDynamic_Func_6(dataOut, 0x60, &local_158) != 0) {
                IDirect3DVertexBuffer9 *iVar5 = g_pDynamicVertexBuffer->IVBDynamic_Func_5();
                g_RStateMgr.m_pDevice->SetStreamSource(0, iVar5, 0, 0x18);
                g_RStateMgr.FUN_00470060(6, local_158, 2);
            }

            // maybe preparation for the next(?) icon
            dataOut[0].x = dataOut[0].x - 20.0f; // upper right
            dataOut[6].x = dataOut[6].x - 20.0f; // lower left
            dataOut[2].x = dataOut[0].x + 16.0f; // upper left
            dataOut[4].x = dataOut[6].x + 16.0f; // lower right
        }
    }

    RenderFortressIcons(dataOut, param_2);
    if (m_pGuildInfo != NULL && trijobType == TRIJOB_NOJOB && CGame::STA_FUN_004f9d00().field_10 != NULL) {
        m_renderX -= 20.0f;

        // GuildName
        guildString += L"[" + m_guildName;
        if (!m_grantName.empty()) {
            guildString += L" * " + m_grantName;
        }

        if (g_CGlobalDataManager->FUN_00939a60(g_pCICPlayer->FUN_009d68f0()) == 0 &&
            g_CGlobalDataManager->FUN_0093a610(m_guildName) != 0) {
            if (!m_fortressWarTitle.empty()) {
                guildString += L"(" + m_fortressWarTitle + L")";
            }
        }

        guildString += L"]";
        m_pGuildInfo->m_pFontTexture->FUN_008b3bd0(&guildString);
        m_pGuildInfo->m_pFontTexture->FUN_008b4d90(&m_renderY, 0xff);

        // Probably GuildIcon
        if (m_pGuildInfo->m_runtimeTexture != NULL) {
            D3DVECTOR dataOut_2[8];
            m_pGuildInfo->m_pFontTexture->FUN_008b2d30(param_2, dataOut_2);

            dataOut_2[0].x = dataOut_2[0].x - 20.0f;

            dataOut_2[1].y = 0.0f;
            dataOut_2[1].z = 0.0f;

            dataOut_2[2].y = dataOut_2[0].y;
            dataOut_2[2].x = dataOut_2[0].x + 16.0f;


            dataOut_2[3].y = 1.0f;
            dataOut_2[3].z = 0.0f;

            dataOut_2[4].y = dataOut_2[0].y + 16.0f;
            dataOut_2[4].x = dataOut_2[0].x + 16.0f;

            dataOut_2[5].y = 1.0f;
            dataOut_2[5].z = 1.0f;

            dataOut_2[6].x = dataOut_2[0].x;
            dataOut_2[6].y = dataOut_2[4].y;

            dataOut_2[7].y = 0.0;
            dataOut_2[7].z = 1.0;

            g_RStateMgr.SetTextureForStage(0, m_pGuildInfo->m_runtimeTexture->Func_2());
            int local_158 = 0;
            if (g_pDynamicVertexBuffer->IVBDynamic_Func_6(dataOut_2, 0x60, &local_158) != 0) {
                IDirect3DVertexBuffer9 *iVar5 = g_pDynamicVertexBuffer->IVBDynamic_Func_5();
                g_RStateMgr.m_pDevice->SetStreamSource(0, iVar5, 0, 0x18);
                g_RStateMgr.FUN_00470060(6, local_158, 2);
            }
        }

        // Probably AllianceIcon
        if (m_pGuildInfo->m_anotherRuntimeTexture != NULL) {
            D3DVECTOR dataOut_2[8];

            m_pGuildInfo->m_pFontTexture->FUN_008b2d30(param_2, dataOut_2);

            dataOut_2[0].x = dataOut_2[0].x - 36.0f;

            dataOut_2[1].y = 0.0f;
            dataOut_2[1].z = 0.0f;

            dataOut_2[2].x = dataOut_2[0].x + 16.0f;
            dataOut_2[2].y = dataOut_2[0].y;

            dataOut_2[3].y = 1.0f;
            dataOut_2[3].z = 0.0f;

            dataOut_2[4].x = dataOut_2[0].x + 16.0f;
            dataOut_2[4].y = dataOut_2[0].y + 16.0f;

            dataOut_2[5].y = 1.0f;
            dataOut_2[5].z = 1.0f;

            dataOut_2[6].x = dataOut_2[0].x;
            dataOut_2[6].y = dataOut_2[4].y;

            dataOut_2[7].y = 0.0f;
            dataOut_2[7].z = 1.0f;
            g_RStateMgr.SetTextureForStage(0, m_pGuildInfo->m_anotherRuntimeTexture->Func_2());
            int local_158 = 0;
            if (g_pDynamicVertexBuffer->IVBDynamic_Func_6(dataOut_2, 0x60, &local_158) != 0) {
                IDirect3DVertexBuffer9 *iVar5 = g_pDynamicVertexBuffer->IVBDynamic_Func_5();
                g_RStateMgr.m_pDevice->SetStreamSource(0, iVar5, 0, 0x18);
                g_RStateMgr.FUN_00470060(6, local_158, 2);
            }
        }

        // Fortress Icon?
        if (g_CGlobalDataManager->FUN_0093a610(m_guildName) != 0) {
            D3DVECTOR dataOut_2[8];
            m_pGuildInfo->m_pFontTexture->FUN_008b2d30(param_2, dataOut_2);
            dataOut_2[1].y = 0.0f;
            dataOut_2[1].z = 0.0f;
            dataOut_2[3].y = 1.0f;
            dataOut_2[5].y = 1.0f;
            dataOut_2[5].z = 1.0f;
            dataOut_2[7].z = 1.0f;
            dataOut_2[3].z = 0.0f;
            dataOut_2[7].y = 0.0f;
            dataOut_2[0].x =
                    static_cast<float>(m_pGuildInfo->m_pFontTexture->GetDimensions().width) + 5.0f + dataOut_2[0].x;
            dataOut_2[2].y = dataOut_2[0].y;
            dataOut_2[4].y = dataOut_2[0].y + 16.0f;
            dataOut_2[2].x = dataOut_2[0].x + 16.0f;
            dataOut_2[4].x = dataOut_2[0].x + 16.0f;
            dataOut_2[6].x = dataOut_2[0].x;
            dataOut_2[6].y = dataOut_2[4].y;


            const IDirect3DBaseTexture9 *puVar8 = g_RuntimeTextureSomething.find(
                    g_CGlobalDataManager->FUN_0093a610(m_guildName))->second;
            g_RStateMgr.SetTextureForStage(0, puVar8);

            int local_158 = 0;
            if (g_pDynamicVertexBuffer->IVBDynamic_Func_6(dataOut_2, 0x60, &local_158) != 0) {
                IDirect3DVertexBuffer9 *iVar5 = g_pDynamicVertexBuffer->IVBDynamic_Func_5();
                g_RStateMgr.m_pDevice->SetStreamSource(0, iVar5, 0, 0x18);
                g_RStateMgr.FUN_00470060(6, local_158, 2);
            }
        }
    }

    if (outVar != 0) {
        g_RStateMgr.FUN_00471360(0x1c, 1);
    }
    g_RStateMgr.SetStageOperator<0, D3DTSS_COLOROP>(D3DTOP_MODULATE);
    g_RStateMgr.FUN_00471360(0xf, 0);
    CICharactor::Func_15(param_1, param_2
    );
}


void CICUser::RenderFortressIcons(D3DVECTOR *dataOut, float *param_2) {
    undefined4 fortressSomething = g_pCICPlayer->FUN_009d68f0();
    int puVar4 = g_CCharacterDependentData.FUN_009870d0();

    if (m_pGuildInfo == NULL) {
        return;
    }

    if (!(g_CGlobalDataManager->FUN_00939a60(fortressSomething) != NULL &&
          CGame::STA_FUN_004f9d00().field_11 != NULL &&
          m_pGuildInfo->m_guildId != 0)) {
        return;
    }

    int iVar5 = g_CCharacterDependentData.FUN_00998280(m_pGuildInfo->m_guildId);

    IDirect3DBaseTexture9 *iconFilePath;

    if (g_CCharacterDependentData.FUN_00998230(&puVar4) == 0) {
        switch (iVar5 - 0xc9U) { // 201
            case 0: // 201
            case 2: // 203
                if (field_81c == 1) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0x6]; // icon\\etc\\mark_fortress2.ddj
                } else if (field_81c == 2) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0x7]; // icon\\etc\\mark_fortress3.ddj
                } else {
                    return;
                }
                break;
            case 1: // 202
                if (field_81c == 1) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0xa]; // icon\\etc\\mark_defensive2.ddj
                } else if (field_81c == 2) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0xb]; // icon\\etc\\mark_defensive3.ddj
                } else {
                    return;
                }
                break;
            case 3: // 204
                if (field_81c == 1) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0x8]; // icon\\etc\\mark_aggressive2.ddj
                } else if (field_81c == 2) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0x9]; // icon\\etc\\mark_aggressive3.ddj
                } else {
                    return;
                }
                break;
            default:
                return;
        }
    } else {
        switch (iVar5 - 0xc9U) {
            case 0:
            case 2:
                if (field_81c == 1) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0x6]; // icon\\etc\\mark_fortress2.ddj
                } else if (field_81c == 2) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0x7]; // icon\\etc\\mark_fortress3.ddj
                } else {
                    return;
                }
                break;
            case 1:
            case 3:
                if (field_81c == 1) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0xa]; // icon\\etc\\mark_defensive2.ddj
                } else if (field_81c == 2) {
                    iconFilePath = p_MiniIcon_TexturePtrs[0xb]; // icon\\etc\\mark_defensive3.ddj
                } else {
                    return;
                }
                break;
        }
    }

    g_RStateMgr.SetTextureForStage(0, iconFilePath); // FUN_004702d0(&g_pD3DDevice, 0, iconFilePath);
    dataOut[1].y = 0.0;
    dataOut[1].z = 0.0;

    dataOut[3].y = 1.0;
    dataOut[3].z = 0.0;

    dataOut[5].y = 1.0;
    dataOut[5].z = 1.0;

    dataOut[7].y = 0.0;
    dataOut[7].z = 1.0;

    dataOut[0].x = *param_2 - 16.0f;

    dataOut[2].x = dataOut[0].x + 32.0f;
    dataOut[4].x = dataOut[0].x + 32.0f;
    dataOut[6].x = dataOut[0].x;

    float fVar6 = (CGame::STA_FUN_004f9d00().field_10 != NULL) ? 64.0f : 44.0f;

    if (IsSame(GFX_RUNTIME_CLASS(CICPlayer)) &&
        CGame::STA_FUN_004f9d00().field_15 != NULL &&
        DAT_00eef5e8 == m_uniqueId) {
        fVar6 += 16.0f;
    }

    if (g_CCharacterDependentData.FUN_00992940(&m_name) != NULL &&
        CGame::STA_FUN_004f9d00().field_17 != NULL &&
        DAT_00eef5e8 != m_uniqueId) {
        fVar6 += 16.0f;
    }

    dataOut[0].y = param_2[1] - fVar6;
    dataOut[4].y = dataOut[0].y + 32.0f;
    dataOut[2].y = dataOut[0].y;
    dataOut[6].y = dataOut[4].y;
    g_RStateMgr.FUN_00470310(0x104);

    int local_158 = 0;
    if (g_pDynamicVertexBuffer->IVBDynamic_Func_6(dataOut, 0x60, &local_158) != 0) {
        IDirect3DVertexBuffer9 *buffer = g_pDynamicVertexBuffer->IVBDynamic_Func_5();
        g_RStateMgr.m_pDevice->SetStreamSource(0, buffer, 0, 0x18);
        g_RStateMgr.FUN_00470060(6, local_158, 2);
    }
}


void CICUser::Func_15_impl(int param_1, float *param_2) {
    CICUser::Func_15(param_1, param_2);
}

bool CICUser::GetBeginnerState() const {
    return reinterpret_cast<bool (__thiscall *)(const CICUser *)>(0x009dad40)(this);
}
