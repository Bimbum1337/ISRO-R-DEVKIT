#pragma once

#define ENSURE_SIZE(class_name, sz) \
	int size_check ## class_name [ sizeof(class_name) == sz ? 1 : -1 ];

