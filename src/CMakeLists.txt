add_library(stack stack.c)

add_executable(task task.c)

target_link_libraries(task PRIVATE stack)