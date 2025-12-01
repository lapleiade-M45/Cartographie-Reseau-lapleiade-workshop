include_directories("include")

set(SRCS ft_ip.cpp  main.cpp socket_client.cpp socket_serveur.cpp)

add_executable(network ${SRCS})

target_link_libraries(network PRIVATE ${CMAKE_SOURCE_DIR}/libft/libft.a)
