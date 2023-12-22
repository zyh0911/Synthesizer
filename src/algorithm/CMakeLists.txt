add_library(libcomp)
target_include_directories(libcomp PRIVATE ${CMAKE_SOURCE_DIR})
target_compile_options(libdb PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>
)