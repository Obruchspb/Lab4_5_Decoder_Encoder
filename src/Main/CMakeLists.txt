cmake_minimum_required(VERSION 2.8) 

project(Encoder_Decoder) 

set(SOURSE 
	t_main.cpp 
) 

add_executable(main ${SOURSE}) 

target_link_libraries(main PUBLIC encoder)
target_link_libraries(main PUBLIC decoder)
target_link_libraries(main PUBLIC gtest)