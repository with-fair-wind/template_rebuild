cmake_minimum_required(VERSION 3.18)

if(WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake;${CMAKE_MODULE_PATH}")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install CACHE PATH "installation path" FORCE)

project(Template LANGUAGES CXX)

include(MyUsefulFuncs)

# add_subdirectory(function_template)
# add_subdirectory(class_template)
add_subdirectory(variable_template)

# add_subdirectory(tuple_package)
# add_subdirectory(template_full_specialization)
# add_subdirectory(template_partial_specialization)
# add_subdirectory(sfinae)
# add_subdirectory(fold_expression)
# add_subdirectory(concept_requires)
if(MSVC)
    add_generate_compile_commands_target(5)
endif()