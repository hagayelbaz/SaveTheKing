add_subdirectory (Gift)

target_sources (${CMAKE_PROJECT_NAME} PRIVATE 
                                               "Wall.cpp"
                                               "Key.cpp"
                                               "Gate.cpp"
                                               "Fire.cpp"
                                               "Orc.cpp"
                                               "UnMoveAble.cpp"
                                               "TeleportManager.cpp"
                                               "Teleport.cpp"                       
                                               "Throne.cpp")