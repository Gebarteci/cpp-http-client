cmake_minimum_required(VERSION 3.15)
project(HttpClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 1.10.5 # Use a recent, stable version
)
FetchContent_MakeAvailable(cpr)

add_executable(http_client src/main.cpp)

target_link_libraries(http_client PRIVATE cpr::cpr)
