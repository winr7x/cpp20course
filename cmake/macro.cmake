# 'rooster' is cpp31hours course prefix

# Call add_executable() on main.cpp with executable name the same as directory name containing main.cpp
macro(rooster_add_executable_with_curdir_name_maincpp)
  get_filename_component(EXECUTABLE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  add_executable(${EXECUTABLE_NAME} main.cpp)
endmacro()

# Get all subdirectories (not recursively) in directory <curdir> as list <result>
macro(rooster_get_all_subdirs result curdir)
  file(GLOB children RELATIVE ${curdir} ${curdir}/*)
  set(dirlist "")
  foreach(child ${children})
    if(IS_DIRECTORY ${curdir}/${child})
      list(APPEND dirlist ${child})
    endif()
  endforeach()
  set(${result} ${dirlist})
endmacro()

# Call add_subdirectory() for each directory in list <subdirs>
macro(rooster_add_subdirs subdirs)
  foreach(subdir ${subdirs})
    add_subdirectory(${subdir})
  endforeach()
endmacro()

# Call add_subdirectory() for each directory (not recursively) in CMAKE_CURRENT_SOURCE_DIR
macro(rooster_add_all_subdirs_of_current_dir)
  rooster_get_all_subdirs(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
  rooster_add_subdirs("${SUBDIRS}")
endmacro()
