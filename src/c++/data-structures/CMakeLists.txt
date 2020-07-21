cmake_minimum_required (VERSION 3.8)

set(This DataStructures)

# Add source to this project's executable.
set(Headers
	main.h
)

set(Sources
	main.cpp
)

add_library (${This} STATIC ${Headers} ${Sources})

# Include sub-projects.
add_subdirectory ("tests")

