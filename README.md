# Silkroad Online Development Kit

SRO_DevKit is a C++ framework for creating and extending the game *Silkroad Online*. It aims to be binary compatible to
the original game client allowing the entire codebase to work without assembly code. The framework can easily be 
extended with interfaces for existing classes in the game.

## Getting started

The project comes with usage examples for an easy start. Check `source/DevKit_DLL/` for basic examples.

Due to binary compatibility, the recommended build environment is Visual C++ 8.0 aka Visual Studio 2005. Other 
environments can work, but are not recommended nor supported. Always make sure to compile on a `Release`-configuration.
Other configurations do not work.

### Requirements

* Visual Studio 2005
* CMake
* DirectX SDK 9b (included as submodule)

Optional:

* Daffodil (when using a Visual Studio version other than 2005)

The recommended IDE for beginners is Visual Studio 2010, but others can work, too. After installing all the 
dependencies, go to the helpers folder and run `make_project_vs2010.cmd` to create Visual Studio Project files.

### Debug

To debug in Visual Studio, copy a working game client to the `BinOut/` folder. Create a `sro_client.exe` that loads the
`DevClient_DLL.dll` using your method of choice. Set the `sro_client.exe` as executable in the project settings and 
don't forget the arguments (usually `/22 0 0`).

## Contribute

See our [Contribution Guidelines](CONTRIBUTING.md)

## License

This code has been licensed under the *DON'T BE A DICK PUBLIC LICENSE*. For the full license text, see the
[LICENSE.txt](LICENSE.txt) file.
