include_directories(
  "${Boost_INCLUDE_DIRS}"
  "${TOOLS_TOP}/ir"
  "${TOOLS_TOP}/parsers/src"
  "${MARS_TOP}/tools/include"
  "${ROSE_ROOT_DIR}/include/rose"
  "${RAPIDJSON_ROOT_DIR}")

add_subdirectory(autodse)
