include_directories("include")

set(SRCS ft_inet.cpp  main.cpp socket_client.cpp)

add_executable(network ${SRCS})

target_link_libraries(network PRIVATE ${CMAKE_SOURCE_DIR}/libft/libft.a)
