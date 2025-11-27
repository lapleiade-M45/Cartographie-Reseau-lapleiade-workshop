include_directories("include")

set(SRCS "../src/ft_inet.cpp" "../src/socket_client.cpp" main.cpp)

add_executable(test ${SRCS})

target_link_libraries(test PRIVATE ${CMAKE_SOURCE_DIR}/libft/libft.a)

add_test(NAME mytest COMMAND test)