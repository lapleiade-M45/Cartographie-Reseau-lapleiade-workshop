include_directories("include")

include ( CTest )
enable_testing ()

set(SRCS "../src/ft_ip.cpp" "../src/socket_client.cpp" test_inet.cpp)

add_executable(inet_test ${SRCS})

target_link_libraries(inet_test PRIVATE ${CMAKE_SOURCE_DIR}/libft/libft.a)

add_test(NAME mytest COMMAND test)