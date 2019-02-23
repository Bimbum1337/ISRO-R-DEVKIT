#include "vc80-stl.h"

#include <Test/Test.h>

#include <BSLib/BSLib.h>

bool vc80_vector();

bool vc80_stl()
{
    return vc80_vector();
}

bool vc80_vector()
{
    bool failed = false;
    failed |= check_size(std::vector<void*> , 0x10);
    failed |= check_size(std::n_vector<void*> , 0x10);
    failed |= check_size(std::list<void*> , 0xC);
    failed |= check_size(std::n_list<void*> , 0xC);
    failed |= check_size(std::string , 0xC);
    failed |= check_size(std::n_string , 0xC);
    failed |= check_size(std::wstring , 0xC);
    failed |= check_size(std::n_wstring , 0xC);

    return failed;
}
