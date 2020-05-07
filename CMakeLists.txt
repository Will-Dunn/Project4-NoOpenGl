cmake_minimum_required(VERSION 3.15)
project(Project4_NoOpenGl)
##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "heart.svg")



#
##########################################


# Copy data files to build dir
foreach(file IN LISTS input01 )
    configure_file(${file} ${file} COPYONLY)
endforeach()
set(CMAKE_CXX_STANDARD 14)

add_executable(Project4_NoOpenGl
        main.cpp AlgoPath.h AlgoLine.h point.h )
