# 'rooster' is cpp31hours course prefix

# Get all subdirectories (not recursively) in directory <curdir> as list <result>
# Output example: "4.8Auto;4.9Assignments"
function(rooster_get_all_subdirs result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist} PARENT_SCOPE) # Set the variable in caller's scope
endfunction()

# Call add_subdirectory() for each directory in list <subdirs>, containing CMakeLists.txt
function(rooster_add_subdirs subdirs)
  foreach(subdir ${subdirs})
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt")
      add_subdirectory(${subdir})
    endif()
  endforeach()
endfunction()

# Call add_subdirectory() for each directory (not recursively) in CMAKE_CURRENT_SOURCE_DIR
function(rooster_add_all_subdirs_of_current_dir)
  rooster_get_all_subdirs(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
  rooster_add_subdirs("${SUBDIRS}")
endfunction()

# Call add_executable() on main.cpp (and optionally other sources) with executable name the same as directory name containing main.cpp
# example 1: function_name()
# example 2: function_name("one.cpp;two.cpp;three.cpp")
function(rooster_add_executable_with_curdir_name_maincpp)
  get_filename_component(EXECUTABLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  add_executable(${EXECUTABLE_NAME} main.cpp ${ARGN})
endfunction()

# Get <result>-list of top chapter subdirectories (not recursively) in directory <curdir>. Top chapter directory is dir with name of format '\d\d\.SomeName'
# Output example: "03.Iterators;22.Algorithms"
function(rooster_get_top_chapter_subdirs result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child} AND ${child} MATCHES ^[0-9][0-9]\\.[A-Za-z0-9_]+)
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist} PARENT_SCOPE) # Set the variable in caller's scope
endfunction()

# Call add_subdirectory() for each top chapter subdirectory
function(rooster_add_top_chapter_subdirs)
  rooster_get_top_chapter_subdirs(subdirs ${CMAKE_SOURCE_DIR}) # search in top-level-cmakelists' directory
  foreach(subdir ${subdirs})
    add_subdirectory(${subdir})
  endforeach()
endfunction()
