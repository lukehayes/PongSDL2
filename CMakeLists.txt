# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.7)
project ("app")

# ------------------------------------------------------
# Helper Variables
# ------------------------------------------------------
SET(SRC_DIR "src")
SET(SRC_FILE "${SRC_DIR}/main.cpp")
SET(LIBS_DIR "${PROJECT_SOURCE_DIR}/deps/libs")

SET(CORE_INCLUDES
	"${PROJECT_SOURCE_DIR}/include"
)

# ------------------------------------------------------
# WINDOWS
# ------------------------------------------------------
if (WIN32)
    message("Running on Windows")
    set(INC_DIRS
        ${PROJECT_SOURCE_DIR}/deps/libs/SDL/include
        ${CORE_INCLUDES}
    )
    include_directories(${INC_DIRS})
    link_directories(${PROJECT_SOURCE_DIR}/deps/libs/SDL/libs)


    # Add source to this project's executable.
    add_executable (app "${SRC_FILE}")

    add_subdirectory(src/app)
    add_subdirectory(src/entity)

    target_link_libraries(app game SDL2.lib)
    target_link_libraries(app SDL2main.lib)
    target_link_libraries(app entity)

endif(WIN32)


# ------------------------------------------------------
# OSX
# ------------------------------------------------------
if(APPLE)
    message("Running on APPLE")

    # Modules Path
    set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

    # Find SDL2 on OSX - must be at top
    find_package (SDL2 REQUIRED)

    include_directories(
		${PROJECT_SOURCE_DIR}/include
		${SDL2_INCLUDE_DIR}
    )


    # Add source to this project's executable.
    add_executable (app "${SRC_FILE}")

    add_subdirectory(${PROJECT_SOURCE_DIR}/src/app)

    target_link_libraries (app game ${SDL2_LIBRARIES})

endif(APPLE)

