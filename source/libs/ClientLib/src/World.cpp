#include "World.h"

SWorld *GETMAP() {
    return reinterpret_cast<SWorld *(*) ()>(0x009edd60)();
}
