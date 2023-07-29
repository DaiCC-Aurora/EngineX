cmake_minimum_required(VERSION 3.25)
project(Engine)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        Engine
        src/EAction.cpp
        src/ECamera.cpp
        src/EColor.cpp
        src/EDebug.cpp
        src/EException.cpp
        src/EFile.cpp
        src/EFont.cpp
        src/EIcon.cpp
        src/EImage.cpp
        src/EMessagebox.cpp
        src/Engine.cpp
        src/EObject.cpp
        src/EString.cpp
        src/EText.cpp
        src/ETime.cpp
        src/EVideo.cpp
        src/EVoice.cpp

        include/EAction.h
        include/ECamera.h
        include/EColor.h
        include/EDebug.h
        include/EException.h
        include/EFile.h
        include/EFont.h
        include/EIcon.h
        include/EImage.h
        include/EMessagebox.h
        include/Engine.h
        include/EObject.h
        include/EString.h
        include/EText.h
        include/ETime.h
        include/EVideo.h
        include/EVoice.h
)

include_directories(
        include/
)