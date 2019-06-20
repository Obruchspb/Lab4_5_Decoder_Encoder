cmake_minimum_required(VERSION 2.8) 

set(SOURSE 
HammingDecoder.cpp 
) 

set(HEDERS
HammingDecoder.hpp 
) 
add_library(decoder STATIC ${SOURSE} ${HEDERS})