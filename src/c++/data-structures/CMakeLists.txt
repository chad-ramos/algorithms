cmake_minimum_required (VERSION 3.8)

set(This DataStructures)

# Add source to this project's executable.
set(Headers
)

set(Sources
	"dynamic-array.cpp"
)

add_library (${This} STATIC ${Headers} ${Sources})

# Include sub-projects.
add_subdirectory ("tests")

