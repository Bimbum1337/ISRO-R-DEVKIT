call "%VS100COMNTOOLS%\vsvars32.bat"
msbuild.exe /consoleloggerparameters:ErrorsOnly /maxcpucount /nologo /property:Configuration=Release /verbosity:quiet SRO_DevKit.sln
