cmake_minimum_required(VERSION 3.5)
project(Twitterak)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES
	src/main.cpp 
	src/twitterak.cpp
	src/menu.cpp
	src/account.cpp
	src/signup.cpp
	src/password.cpp
	src/checkuser.cpp
	src/loggedin.cpp
	src/tweet.cpp
	src/help.cpp
	src/credits.cpp
	src/edit.cpp
	src/stringtolower.cpp

)

include_directories(include/ )
add_executable(Twitterak ${SOURCES})


