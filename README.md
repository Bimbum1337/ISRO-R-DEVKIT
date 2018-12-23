# Silkroad Online Development Kit



## Build

Due to binary compatibilty, the recommended build environment is Visual C++ 8.0 aka Visual Studio 2005. Other environments can work, but are not recommended nor supported. The project itself comes with project files for Visual Studio 2010.

### Requirements

* Visual Studio 2005
* Visual Studio 2010
* DirectX SDK 9b (included as submodule)
* Daffodil for VC80-support in newer Visual Studio Editions

I am currently running tests with CMake to eliminate the Visual Studio 2010 dependency.

## Debug

To debug in Visual Studio, copy a working sro client to the `BinOut/` folder. Create a binary named `sro_client_dev.exe` that loads the `DevClient_DLL.dll` using your method of choice.

## Contribute

Please make a comment on every function you create that describes where you found it. This allows everyone to quickly navigate between code and binary.

Example:

```cpp
// CGFontTexture::sub_8B37A0(void) .text 008B37A0 0000007D 00000008 00000000 R . . . . . .
void CGFontTexture::sub_8B37A0()
{
	// ...
}
```

Every function should be completely implemented. Partial implementations are only allowed on individual occasions. The minimal implementation should either be an assertion (signaling *not yet implemented*) or a redirection to the original function in the code.

Example:

```cpp
// CIFTileWnd::SetGWndSize(void) .text 0081A920 00000005 00000004 00000000 R . . . . . .
void CIFTileWnd::SetGWndSize(int width, int height)
{
	assert(FALSE); // Not yet implemented
}
```

```cpp
// CIFTileWnd__sub_81AE00 .text 0081AE00 0000007D 00000010 00000000 R . . . . . .
void CIFTileWnd::sub_81AE00()
{
	// Redirection to original client code
	reinterpret_cast<void(__thiscall*)(CIFTileWnd*)>(0x0081AE00)(this);
}
```

If your new function appears to be empty, place a comment stating this.

```cpp
// CGWnd::OnUpdate() .text 00B9D7E0 00000001   R . . . . . .
void CGWnd::OnUpdate()
{
	// empty
}
```

## License

This code has been licensed under the *DON'T BE A DICK PUBLIC LICENSE*. For the full license text, see the [LICENSE.txt](LICENSE.txt) file.
