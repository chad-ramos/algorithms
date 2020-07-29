cmake_minimum_required (VERSION 3.8)

set(This DataStructures)

set(Sources
	"dynamic-array.cpp"
	"linked-list.cpp"
)

add_library (${This} STATIC ${Sources} )

# Include sub-projects.
add_subdirectory ("tests")

