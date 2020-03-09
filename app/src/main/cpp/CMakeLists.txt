# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# 定义变量
set(var hello)
# 打印变量
message(${var})
message(${CMAKE_CURRENT_LIST_FILE})
message(${CMAKE_CURRENT_LIST_DIR})


# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# 将相对路径下的native-lib.cpp生成native-lib.so的共享库
add_library( # Sets the name of the library.
             person-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
        person/person-lib.cpp
        person/person.cpp)

add_library(
        teacher-lib
        SHARED
        teacher/teacher-lib.cpp
        teacher/teacher.cpp)

add_library(
        hello-lib
        SHARED
        hello/hello-lib.cpp)

add_library(
        skyqueue-lib
        SHARED
        queue/skyqueue.cpp)

# 将person路径纳入搜索
include_directories(person/)
include_directories(teacher/)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# 搜索一个特定的预置库log，并设置路径变量
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# 指定相关联的库，如native-lib和person-lib都需要关联log-lib
target_link_libraries( # Specifies the target library.
                       person-lib
                       teacher-lib
                       hello-lib
                       skyqueue-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )