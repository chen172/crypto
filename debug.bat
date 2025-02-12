if not exist build (
    mkdir build
)
cd build
cmake ..
MSBuild.exe .\ALL_BUILD.vcxproj -p:Configuration=Debug
cd ..
set PATH=%PATH%;C:\LLVM\bin
set PYTHONHOME=C:\vcpkg\vcpkg\packages\python3_x64-windows\tools\python3
set PYTHONPATH=C:\vcpkg\vcpkg\packages\python3_x64-windows
mv .\build\Debug\hmac.exe .\hmac.exe
lldb .\hmac.exe
