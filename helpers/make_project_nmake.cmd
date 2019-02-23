@echo off

call "%VS80COMNTOOLS%vsvars32.bat"

cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=RelWithDebInfo ..
