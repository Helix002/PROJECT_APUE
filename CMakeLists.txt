# CMake 最低版本号要求
cmake_minimum_required(VERSION 2.8)

# 版本号
set(APUE_VERSION_MAJOR 3)
set(APUE_VERSION_MINOR 0)

# 支持gdb
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -std=c++11")

# 项目名
project(PROJECT_APUE)

# 可选宏
option(USE_APUE_API "Use APUE_API" ON)

#配置文件，用于宏编译
configure_file(
        ${PROJECT_SOURCE_DIR}/config.h.in
        ${PROJECT_BINARY_DIR}/config.h
)

# 指定头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include/)

# 用宏控制模块编译
if (USE_APUE_API)
    include_directories("${PROJECT_SOURCE_DIR}/src")
    add_subdirectory(src)
    set(EXTRA_LIBS ${EXTRA_LIBS} APUE_API)
endif (USE_APUE_API)

# 生成指定目标 可执行文件名APUE
add_executable(APUE example/main.c)
target_link_libraries(APUE ${EXTRA_LIBS})

# 指定安装路径 通过make install安装，还需要手动clean
install(TARGETS APUE DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)


# 测试
enable_testing()
macro(do_test arg1 result)
    add_test(test APUE )
    set_tests_properties(test
            PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

# 生成安装包
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
        "${CMAKE_CURRENT_SOURCE_DIR}/License.txt"
)
set(CPACK_PACKAGING_VERSION_MAJOR "${APUE_VERSION_MAJOR}")
set(CPACK_PACKAGING_VERSION_MINOR "${APUE_VERSION_MINOR}")
include(CPack)

