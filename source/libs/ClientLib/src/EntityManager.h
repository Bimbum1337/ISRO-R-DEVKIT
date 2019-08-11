#pragma once

#include <BSLib/BSLib.h>
#include "IObject.h"

#include <map>

class CEntityManager : public CObjChild
{
public:
	char _gap[4];

	std::map<int, CIObject*> entities;
};
