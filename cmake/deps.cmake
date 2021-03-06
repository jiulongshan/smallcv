if(SMALLCV_USE_ASAN)
  if (MSVC)
    message(WARNING "AddressSanitizer for MSVC must be enabled manually in project's property page.")
  else()
    message(STATUS ">>> USE_ASAN: YES")
    message(STATUS ">>> CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
      # On debug mode
      set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
    elseif (CMAKE_BUILD_TYPE MATCHES "Release")
      # Note: `-g` is explicitly required here, even if NDK android.toolchain.cmake's `-g` exists.
      set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_LINKER_FLAGS_RELEASE "${CMAKE_LINKER_FLAGS_RELEASE} -g -fno-omit-frame-pointer -fsanitize=address")
    elseif (CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
      set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_LINKER_FLAGS_RELWITHDEBINFO} -g -fno-omit-frame-pointer -fsanitize=address")
    elseif (CMAKE_BUILD_TYPE MATCHES "MinSizeRel")
      set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_LINKER_FLAGS_MINSIZEREL "${CMAKE_LINKER_FLAGS_MINSIZEREL} -g -fno-omit-frame-pointer -fsanitize=address")
    elseif (CMAKE_BUILD_TYPE EQUAL "None" OR NOT CMAKE_BUILD_TYPE)
      set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fno-omit-frame-pointer -fsanitize=address")
      set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -g -fno-omit-frame-pointer -fsanitize=address")
    endif()
  endif()
else()
  message(STATUS ">>> USE_ASAN: NO")
endif()


# check memory leak with VLD in Visual Studio
if(SMALLCV_USE_VLD)
  add_definitions(-DSMALLCV_USE_VLD)
endif()

#----------------------------------------------------------------------#
# glfw
#----------------------------------------------------------------------#
if(SMALLCV_IMSHOW)
  find_package(glfw3 QUIET) # 3.3-stable branch recommended
  if(glfw3_FOUND)
    message(STATUS "[Found glfw3] glfw3_DIR is ${glfw3_DIR}")
  else()
    message(STATUS "[Not Found glfw3]")
    message(STATUS "Please remove cmake build cache, then:")
    message(STATUS "* If already installed glfw3, please set glfw3_DIR in one of:")
    message(STATUS "      file CMakeLists.txt, before `find_package(glfw3)`")
    message(STATUS "      file build/xxx.cache.cmake")
    message(STATUS "      file build/xxx.{sh,cmd}, with -Dglfw3_DIR=/path/to/glfw3Config.cmake")
    message(STATUS "      You may get inspired from build/xxx.cache.cmake :)")
    message(STATUS "* If not installed glfw3, may install binary via:")
    message(STATUS "      sudo apt install libglfw3-dev  # ubuntu")
    message(STATUS "      brew install glfw              # mac")
    message(STATUS "      vcpkg install glfw             # windows")
    message(STATUS "* You may also build and install glfw3 manually, e.g")
    message(STATUS "      git clone https://gitee.com/mirrors/glfw -b 3.3-stable glfw-3.3-stable")
    message(STATUS "      cd glfw-3.3-stable && mkdir build && cd build")
    message(STATUS "      cmake .. -DCMAKE_INSTALL_PREFIX=./install && cmake --build . && cmake --install .")
    message(STATUS "      then set glfw3_DIR before `find_package(glfw3)`")
    message(FATAL_ERROR "")
  endif()
endif()

#----------------------------------------------------------------------#
# ncnn
#----------------------------------------------------------------------#
if(SMALLCV_EXAMPLES_NCNN)
  find_package(ncnn REQUIRED) # >= 20201218 recommended
  if(ncnn_FOUND)
    message(STATUS "[Found ncnn] ncnn_DIR is ${ncnn_DIR}")
  else()
    message(STATUS "[Not Found ncnn]")
    message(STATUS "Please remove cmake build cache, then:")
    message(STATUS "* If already installed ncnn (version >= 20201218), please set ncnn_DIR in one of:")
    message(STATUS "      file CMakeLists.txt, before `find_package(ncnn)`")
    message(STATUS "      file build/xxx.cache.cmake")
    message(STATUS "      file build/xxx.{sh,cmd}, with -Dncnn_DIR=/path/to/ncnnConfig.cmake")
    message(STATUS "      You may get inspired from build/xxx.cache.cmake :)")
    message(STATUS "* You may also build and install ncnn manually, e.g")
    message(STATUS "      git clone https://gitee.com/mirrors/ncnn -b 20201218 ncnn20201218")
    message(STATUS "      cd ncnn20201218 && mkdir build && cd build")
    message(STATUS "      cmake .. -DCMAKE_INSTALL_PREFIX=./install && cmake --build . && cmake --install .")
    message(STATUS "      then set ncnn_DIR before `find_package(ncnn)`")
    message(FATAL_ERROR "")
  endif()
endif()