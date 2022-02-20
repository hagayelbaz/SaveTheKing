add_subdirectory (GameObject)
add_subdirectory (statusLine)
add_subdirectory (menue)
add_subdirectory (Resources)
add_subdirectory (LevelManager)
add_subdirectory (GameManager)
add_subdirectory (TimeClock)

target_sources (${CMAKE_PROJECT_NAME} PRIVATE "main.cpp"
                                               "controler.cpp")
