if not exist build (
    mkdir build
)
cd build
cmake -DCMAKE_BUILD_TYPE="Release" ..
MSBuild.exe .\ALL_BUILD.vcxproj -p:Configuration=Release
cd ..
mv .\build\Release\hmacCPU.exe .\hmacCPU.exe
