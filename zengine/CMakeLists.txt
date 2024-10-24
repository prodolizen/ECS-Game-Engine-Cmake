cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(MYENGINE)

include_directories(
  src
)

add_library(myengine
	src/myengine/Core.h 
	src/myengine/Core.cpp
	src/myengine/myengine.h
	src/myengine/Entity.h
	src/myengine/Entity.cpp
	src/myengine/Component.h
	src/myengine/Component.cpp  
)

add_executable(game
 src/game/main.cpp
 src/game/Employee.h
 src/game/Employee.cpp
)

target_link_libraries(game myengine)