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

See our [Contribution Guidelines](CONTRIBUTING.md)

## License

This code has been licensed under the *DON'T BE A DICK PUBLIC LICENSE*. For the full license text, see the [LICENSE.txt](LICENSE.txt) file.
