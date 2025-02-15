@echo off
mkdir build 2>nuL
cd build
: -------------------------------------------------------------------------------
: This is the current setup for using the LLVM Clang Compiler and its LLD Linker.
: For MSCV use // "cl ..\source\main.cpp"
clang++ ..\source\main.cpp -fuse-ld=lld -o clido.exe
: -------------------------------------------------------------------------------
echo Build Successful.!
cd ..
pausE