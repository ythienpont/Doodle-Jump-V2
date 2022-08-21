FILE( GLOB SRCS src/*.cc )  # a variable called SRCS with all files whose path match "*.c *.cpp..."
FILE( GLOB HDRS include/*.h )  # a variable called SRCS with all files whose path match "*.c *.cpp..."

ADD_LIBRARY(
  lib
  ${SRCS}
  ${HDRS}
  )

TARGET_INCLUDE_DIRECTORIES(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
