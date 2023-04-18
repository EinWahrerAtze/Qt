add_library(stopwatchlogic STATIC
				  stopwatch.cpp
)

target_link_libraries(stopwatchlogic PRIVATE Qt6::Core)
target_include_directories(stopwatchlogic INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})