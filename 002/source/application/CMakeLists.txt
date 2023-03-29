add_executable(${PROJECT_NAME}
    main.cpp
    socket.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Network Qt6::Sql)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)