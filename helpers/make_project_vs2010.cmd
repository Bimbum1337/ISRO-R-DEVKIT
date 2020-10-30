@echo off

where git.exe 2>NUL >NUL
if errorlevel 1 (
    echo WARNING
    echo WARNING git.exe was NOT found
    echo WARNING Did you check out the project with git?
    echo WARNING If not, please do!
) else (
    echo OK git.exe was found
)

where cmake.exe 2>NUL >NUL
if errorlevel 1 (
    echo ERROR cmake.exe was NOT found
    echo ERROR CMake was not installed correctly. Please follow the guide at
    echo ERROR https://florian0.gitlab.io/sro_devkit/build-environment/cmake/
    echo ERROR to install CMake correctly.
    pause
    exit -1
) else (
    echo OK cmake.exe was found
)

if "%VS80COMNTOOLS%"=="" (
    echo ERROR
    echo ERROR Visual Studio 2005 Environment could NOT be detected.
    echo ERROR Please make sure to install Visual Studio 2005.
    echo ERROR https://florian0.gitlab.io/sro_devkit/build-environment/visual-studio/2005/
    echo ERROR
    pause
    exit
) else (
    echo OK Visual Studio 2005 Environment was detected.
)

call "%VS80COMNTOOLS%vsvars32.bat"

where cl.exe 2>NUL
if errorlevel 1 (
    echo ERROR cl.exe WAS NOT FOUND
    echo ERROR Visual Studio 2005 compiler was not found
    echo ERROR Please make sure to install Visual Studio 2005 correctly
    echo ERROR https://florian0.gitlab.io/sro_devkit/build-environment/visual-studio/2005/
    echo ERROR Make sure you selected C++ support
    pause
    exit
) else (
    echo OK cl.exe was found
)

cl.exe user32.lib envcheck/winsdk.cpp >NUL

if not errorlevel 0 (
    echo ERROR
    echo ERROR Windows SDK is NOT functional
    echo ERROR Please make sure you did not install an express version of
    echo ERROR Visual Studio 2005
    echo ERROR

    del winsdk.obj >NUL
    del winsdk.exe >NUL

    pause
    exit
) else (
    echo OK Windows SDK is functional
    del winsdk.obj >NUL
    del winsdk.exe >NUL
)

cmake.exe -G "Visual Studio 10 2010" -T v80 -DCMAKE_BUILD_TYPE=RelWithDebInfo -DPUT_LOGLEVEL=PUT_WARNING ..
