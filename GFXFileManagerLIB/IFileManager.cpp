#define _CRT_SECURE_NO_WARNINGS
#include "IFileManager.h"
#include <iostream>
#include <iomanip>

int IFileManager::GetVersion(void) {
	std::cout << "FM::getVersion()";
	return FM_VERSION;
};

int IFileManager::CheckVersion(int version) {


	if (version != FM_VERSION) {
		std::cout << "FM::checkVersion(" << std::showbase << std::hex << version << ") = 0";

		char buffer[256];

		sprintf(buffer, "Dll Version(%x)\nNecessary Version(%x)", version, FM_VERSION);

		MessageBox(0, buffer, "Invalid Version(GFXFileManager.dll(Check Version))", MB_OK);

		return 0;
	}

	std::cout << "FM::checkVersion(" << std::showbase << std::hex << version << ") = 1";
	return 1;
};

int IFileManager::ShowDialog(DialogData *initstruct) {
	std::cout << "FM::ShowDialog(" << std::showbase << std::hex << initstruct << ") = 0";

	return 0;
};

int IFileManager::ForeachEntryInContainer(foreach_callback_t cb, const char *filter, void *userstate) {

	shit_t shit;

	this->getShit(&shit);

	cb(CALLBACK_STATE_INIT, NULL, userstate);

	loop_container_content(cb, filter, userstate);

	this->setShit(shit.a, shit.b);

	return 1;
}

void IFileManager::loop_container_content(foreach_callback_t cb, const char *filter, void *userstate) {

	searchresult_t res;
	result_entry_t entry;

	// Loop over all dirs

	this->FindFirstFile(&res, filter, &entry);

	if (res.success) {
		do {

			// Ignore everything thats not a directory or starts with a dot "."
			if (entry.type == ENTRY_FOLDER && entry.filename[0] != '.') {
				cb(CALLBACK_STATE_ENTER_DIR, &entry, userstate);

				if ( this->ChangeDirectory(entry.filename) ) {
					loop_container_content(cb, filter, userstate);

					this->ChangeDirectory("..");
				}

				cb(CALLBACK_STATE_LEAVE_DIR, NULL, userstate);
			}
		} while (this->FindNextFile(&res, &entry));

		this->FindClose(&res);
	}

	// Loop over all files
	this->FindFirstFile(&res, filter, &entry);

	if (res.success) {
		do {

			// Filter out the files
			if (entry.type == ENTRY_FILE) {
				cb(CALLBACK_STATE_FILE, &entry, userstate);
			}
		} while (this->FindNextFile(&res, &entry));

		this->FindClose(&res);
	}
}
