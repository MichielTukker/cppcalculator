macro(run_conan)
  # Download automatically, you can also just copy the conan.cmake file
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
  list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
  
  add_definitions("-std=c++11")
  
  if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake"
                  TLS_VERIFY ON)
  endif()
  
  include(${CMAKE_BINARY_DIR}/conan.cmake)
#  include(conan.cmake)
  
  conan_add_remote(
    NAME
    bincrafters
    URL
    https://api.bintray.com/conan/bincrafters/public-conan)

  conan_cmake_configure(REQUIRES 
                        ${CONAN_EXTRA_REQUIRES}
                        catch2/2.13.3
                        docopt.cpp/0.6.2
                        fmt/6.2.0
                        spdlog/1.5.0
                        GENERATORS cmake_find_package)
  
  conan_cmake_autodetect(settings)
  
  conan_cmake_install(PATH_OR_REFERENCE .
                      BUILD missing
                      REMOTE conan-center
                      SETTINGS ${settings})
endmacro()
