@echo off

call "%VS80COMNTOOLS%vsvars32.bat"

cmake -G "Visual Studio 10 2010" -T v80 -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
