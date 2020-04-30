#include "NIFCommunityWnd.h"

CNIFBlockWnd *CNIFCommunityWnd::GetBlockWnd() {
    return reinterpret_cast<CNIFBlockWnd*(__thiscall*)(CNIFCommunityWnd*)>(0x0058eeb0)(this);
}
