cmake_minimum_required(VERSION 3.15)
project(HttpClient)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
# --- cpr library ---
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 1.10.5
)
FetchContent_MakeAvailable(cpr)

# --- NEW: nlohmann/json library ---
FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)
# --- END NEW ---

add_executable(http_client src/main.cpp)

# --- UPDATED: Link both libraries ---
target_link_libraries(http_client PRIVATE cpr::cpr nlohmann_json::nlohmann_json)