# Silkroad Online Development Kit

## Build

Due to binary compatibilty, the recommended build environment is Visual C++ 8.0 aka Visual Studio 2005. Other environments can work, but are not recommended nor supported. Always make sure to compile on a `Release`-configuration. Other configurations don't work.

### Requirements

* Visual Studio 2005
* CMake
* DirectX SDK 9b (included as submodule)

Optional:

* Daffodil (when using Visual Studio)

For an easy start, go to the helpers folder and run `make_project_vs2010.cmd` to create Visual Studio Project Files.

## Debug

To debug in Visual Studio, copy a working sro client to the `BinOut/` folder. Create a `sro_client.exe` that loads the `DevClient_DLL.dll` using your method of choice. Set the `sro_client.exe` as executable in the project settings and don't forget the arguments (usually `/22 0 0`).

## Contribute

See our [Contribution Guidelines](CONTRIBUTING.md)

## License

This code has been licensed under the *DON'T BE A DICK PUBLIC LICENSE*. For the full license text, see the [LICENSE.txt](LICENSE.txt) file.
