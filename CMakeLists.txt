cmake_minimum_required(VERSION 3.0)                                                                                                        
                                                                                                                                           
project(gameoflife)                                                                                                                        
                                                                                                                                           
set(CMAKE_CXX_STANDARD 11)                                                                                                                 
                                                                                                                                           
add_executable(gameoflife gameoflife.c generation.c)                                                                                       
