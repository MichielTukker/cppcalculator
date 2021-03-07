# option(CPP_STARTER_USE_IMGUI "Enable compilation of ImGui sample" OFF)

# imgui example
# if(CPP_STARTER_USE_IMGUI)
#   message("Using Dear ImGui")
#   add_subdirectory(imgui)
# endif()

# Generic test that uses conan libs

add_executable(calcu main.cpp rpncompute.cpp)

find_package(fmt)
find_package(spdlog)
find_package(docopt)
target_link_libraries(
  calcu
  PRIVATE project_options
          project_warnings
          fmt::fmt 
          spdlog::spdlog 
          docopt::docopt)
          # CONAN_PKG::docopt.cpp
          # CONAN_PKG::fmt
          # CONAN_PKG::spdlog)

target_include_directories(calcu PRIVATE ../include)



