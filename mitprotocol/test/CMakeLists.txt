
#设置可执行文件
add_executable(mymytest mytest.cpp)

#添加依赖
target_link_libraries(mymytest ${PROJECT_NAME}s)
