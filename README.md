# GLArki
GLAD+SDL3 练手库

# 依赖
1. vcpkg  
   - SDL3
   - GLAD
2. gcc
3. CMake
4. OpenGL(通常驱动自带)

# 配置
在环境变量中添加:  
   - `SDL3_INC` 指向 SDL3 的头文件目录
   - `SDL3_LIB` 指向 SDL3 的库文件目录
   - `GLAD_INC` 指向 GLAD 的头文件目录
   - `GLAD_LIB` 指向 GLAD 的库文件目录
   - `VCPKG_ROOT` 指向 vcpkg 的根目录
   - `GCC_ROOT` 指向 GCC 的根目录

# 编译并运行
`run.bat`