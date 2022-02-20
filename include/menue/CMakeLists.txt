add_subdirectory (LevelMenue)
add_subdirectory (Instructions)

target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
