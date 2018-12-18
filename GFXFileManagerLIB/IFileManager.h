#pragma once 

#include <Windows.h>
#include <stdio.h>

#include "shit_t.h"
#include "CJArchiveFm.h"
#include "searchresult.h"
#include "result_entry_t.h"
#include "DialogData.h"
#include "eCallbackState.h"

#define FM_VERSION 0x1007


typedef BOOL (__cdecl *error_handler_t)(HWND hwnd, const char *message, const char *caption);
typedef void (__cdecl *foreach_callback_t)(CALLBACK_STATE, result_entry_t *, void*);


#define SHOW_ERROR(msg, caption) \
	do { \
		if (error_handler) { \
			if (!error_handler((HWND)1, msg, "false")) \
				MessageBoxA(hwnd, msg, caption, MB_OK); \
		} else { \
			MessageBoxA(hwnd, msg, caption, MB_OK); \
		} \
	} \
	while (0)



class IFileManager
{
public:
	virtual int Mode(void) = 0; //returns the container-mode (1 for CP, 2 for CW)
	virtual int ConfigSet(int, int) = 0; //
	virtual int ConfigGet(int, int) = 0; //

	//
	// Container
	//

	// Create a new container
	// Parameter:
	// - filename: filename of the container
	// - password: password for accessing the new container
	virtual int CreateContainer(const char *filename,  const char *password) = 0;

	// Open an existing container
	// Parameter:
	// - filename: filename of the container
	// - password: password required for accessing the container
	// - mode: unknown, maybe for read and write access
	virtual int OpenContainer(const char *filename, const char* password, int mode) = 0;

	// Close the current container
	// No Parameter
	virtual int CloseContainer(void) = 0; //


	// Returns 1, if this instance has opened a container
	virtual int IsOpen(void) = 0; //



	virtual int CloseAllFiles(void) = 0; //Similar in both implementations

	// Returns the MainModule-handle
	virtual HMODULE MainModuleHandle(void) = 0;


	virtual int Function_9(int) = 0; //CPFileManager returns -1


	//
	// Files
	//

	
	// Open a file inside the container using a path
	// Parameter:
	// - filename: filename, relative to current dir or absolute path inside archive
	// - access: 0 for open-existing, 0x80000000 for open and share_read, 0x40000000 for create_always
	// - unknown: not used for original CPFileManager
	// Return:
	// Handle of opened file (can be any number or pointer) or -1 if opening is was unsuccessful
	virtual int Open(const char *filename, int access, int unknown) = 0; //


	// Open a file inside the container using the CJArchiveFm-class
	// Parameter:
	// - fm: A valid pointer to the CJArchiveFm-class
	// - filename: filename, relative to current dir or absolute path inside archive
	// - access: 0 for open-existing, 0x80000000 for open and share_read, 0x40000000 for create_always
	// - unknown: not used for original CPFileManager
	virtual int Open(CJArchiveFm* fm, const char *filename, int access, int unknown) = 0;

	virtual int Function_12(void) = 0; //return -1
	virtual int Function_13(void) = 0; //return 0

	virtual int Create(const char* filename, int unknown) = 0; //
	virtual int Create(CJArchiveFm * fm, const char * filename, int unknown) = 0; //
	

	// Delete a file by name
	// Parameter:
	// - filename: name of file to delete
	virtual int Delete(const char *filename) = 0; //

	// Close file by handle
	// Parameter:
	// hFile: Any handle or pointer identifiying this file
	virtual int Close(int hFile) = 0; //

	// Read a number of bytes from file
	// Parameter:
	// hFile: Any handle or pointer identifiying this file
	// lpBuffer: pointer to reserved memory for read operation
	// nNumberOfBytesToWrite: size of lpBuffer
	// lpNumberOfBytesWritten: pointer to memory, will contain the number of bytes read from the file
	virtual int Read(int hFile, char* lpBuffer, int nNumberOfBytesToRead, unsigned long *lpNumberOfBytesRead) = 0;

	// Write a number of bytes to file
	// Parameter:
	// hFile: Any handle or pointer identifiying this file
	// lpBuffer: pointer to reserved memory for read operation
	// nNumberOfBytesToWrite: size of lpBuffer
	// lpNumberOfBytesWritten: pointer to memory, will contain the number of bytes written to the file
	virtual int Write(int hFile, const char* lpBuffer, int nNumberOfBytesToWrite, unsigned long *lpNumberOfBytesWritten) = 0;




	// The next two functions are bugged, see issue #19
	// Get the full path of the executable
	virtual char* CmdLinePath(void) = 0;

	// Get the executable
	virtual char* CmdLineExe(void) = 0; //




	// Unknown function that gets two variables
	virtual shit_t* getShit(shit_t* shit) = 0; //get shit

	// Unknown function that sets two variables
	virtual int setShit(int a, int b) = 0; //set shit


	//
	// Directory Management
	//

	// Create a new directory in the container
	// Parameter:
	// - name: name of the directory
	virtual int DirectoryCreate(const char* name) = 0;

	// Delete a directory in the container
	// Parameter:
	// - name: name of the directory
	virtual int DirectoryRemove(const char* name) = 0;


	virtual bool ResetDirectory(void) = 0; //
	virtual bool ChangeDirectory(const char* dirname) = 0; //
	virtual int GetDirectoryName(size_t buffersize, char* Dst) = 0; //


	virtual int SetVirtualPath(const char *path) = 0; //set root
	virtual int GetVirtualPath(char *dest) = 0; //similar on both impl


	//
	// Searching
	//

	// Start a new search for files
	// Parameter:
	// - search: result structure representing a handle for the search
	// - pattern: matching pattern for a list of files
	// - entry: the output-structure for the first entry of the resulting list of files
	virtual searchresult_t* FindFirstFile(searchresult_t* search, const char* pattern, result_entry_t* entry) = 0;

	// Get the next file entry in the search result list
	// Parameter:
	// - search: result structure representing a handle for the search
	// - entry: the output-structure for the next entry of the resulting list of files
	virtual int FindNextFile(searchresult_t* search, result_entry_t* entry) = 0;

	// Free the search result
	// Parameter:
	// - search: result structure representing a handle for the search
	virtual int FindClose(searchresult_t* search) = 0;


	//
	// File Information
	//

	virtual int FileNameFromHandle(int hFile, char* dst, size_t count) = 0;
	virtual int GetFileSize(int hFile, LPDWORD lpFileSizeHigh) = 0;
	virtual BOOL GetFileTime(int hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastWriteTime) = 0;
	virtual BOOL SetFileTime(int hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastWriteTime) = 0;
	virtual int Seek(int hFile, LONG lDistanceToMove, DWORD dwMoveMethod) = 0;

	//
	// Others
	//

	virtual HWND GetHwnd(void) = 0;
	virtual void SetHwnd(HWND) = 0;
	virtual void RegisterErrorHandler(error_handler_t callback) = 0;

	virtual int ImportDirectory(const char *srcdir, const char *dstdir, const char *directory_name, bool create_target_dir) = 0;
	virtual int ImportFile(const char *srcdir, const char *dstdir, const char *filename, bool create_target_dir) = 0;
	virtual int ExportDirectory(const char *srcdir, const char *dstdir, const char *directory_name, bool create_target_dir) = 0;
	virtual int ExportFile(const char *srcdir, const char *dstdir, const char *filename, bool create_target_dir) = 0; // create_target_dir is unused

	// Returns: 0 on found, -1 on not found
	virtual int FileExists(char* name, int flags) = 0; //

	// Shows an open file dialog
	virtual int ShowDialog(DialogData *data);
	virtual int ForeachEntryInContainer(foreach_callback_t cb, const char *filter, void *userstate);
	virtual int UpdateCurrentDirectory(void) = 0; //
	virtual int Function_50(int) = 0; //returns zero in both impl.

	// get the version of this file manager
	virtual int GetVersion(void);

	//prompt error if version mismatch 
	virtual int CheckVersion(int version);

	virtual int Lock(int) = 0;
	virtual int Unlock() = 0;


private:
	void loop_container_content(foreach_callback_t cb, const char *filter, void* userstate);

	
};
