aux_source_directory(. DIR_LIB_SRCS)
add_library(APUE_API ${DIR_LIB_SRCS})

# 指定库安装路径
install(TARGETS APUE_API DESTINATION bin)
install(FILES ../include/ DESTINATION include)