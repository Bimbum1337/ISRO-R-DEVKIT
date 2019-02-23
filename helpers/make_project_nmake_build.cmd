@echo off

call "%VS80COMNTOOLS%vsvars32.bat"

cmake --build . --config RelWithDebInfo
