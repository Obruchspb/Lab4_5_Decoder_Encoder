cmake_minimum_required(VERSION 2.8) 

set(SOURSE 
HammingEncoder.cpp 
) 

set(HEDERS
HammingEncoder.hpp 
) 
add_library(encoder STATIC ${SOURSE} ${HEDERS})