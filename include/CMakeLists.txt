
add_subdirectory (statusLine)
add_subdirectory (GameObject)
add_subdirectory (menue)
add_subdirectory (Resources)
add_subdirectory (LevelManager)
add_subdirectory (GameManager)
add_subdirectory (TimeClock)

target_include_directories (${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})