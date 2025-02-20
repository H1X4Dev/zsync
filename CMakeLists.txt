# This file is automatically generated from cmake.toml - DO NOT EDIT
# See https://github.com/build-cpp/cmkr for more information

cmake_minimum_required(VERSION 3.29)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "In-tree builds are not supported. Run CMake from a separate directory: cmake -B build")
endif()

# Enable support for MSVC_RUNTIME_LIBRARY
cmake_policy(SET CMP0091 NEW)

set(CMKR_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(CMKR_ROOT_PROJECT ON)

	# Bootstrap cmkr and automatically regenerate CMakeLists.txt
	include("cmake/cmkr.cmake" OPTIONAL RESULT_VARIABLE CMKR_INCLUDE_RESULT)
	if(CMKR_INCLUDE_RESULT)
		cmkr()
	endif()

	# Enable folder support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# Create a configure-time dependency on cmake.toml to improve IDE support
	set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS cmake.toml)
	if(NOT DEFINED CMAKE_MSVC_RUNTIME_LIBRARY)
		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
	endif()

endif()

include("cmake/pre-configure.cmake")

project(zsync
	LANGUAGES
		C
		CXX
	VERSION
		1.0.0
	DESCRIPTION
		"zsync - rsync over http"
)

# Target: compile-options
add_library(compile-options INTERFACE)

target_compile_definitions(compile-options INTERFACE
	_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
)

target_compile_features(compile-options INTERFACE
	cxx_std_23
)

if(MSVC) # msvc
	target_compile_options(compile-options INTERFACE
		"/W4"
		"/GR-"
	)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID MATCHES "Clang") # clang-any
	target_compile_options(compile-options INTERFACE
		-fno-rtti
	)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "GNU") # gcc
	target_compile_options(compile-options INTERFACE
		-fno-rtti
	)
endif()

# Target: zsync
set(zsync_SOURCES
	cmake.toml
	"src/base64.c"
	"src/client.c"
	"src/format_string.h"
	"src/getaddrinfo.c"
	"src/getaddrinfo.h"
	"src/http.c"
	"src/http.h"
	"src/librcksum/hash.c"
	"src/librcksum/internal.h"
	"src/librcksum/md4.c"
	"src/librcksum/md4.h"
	"src/librcksum/md4test.c"
	"src/librcksum/range.c"
	"src/librcksum/rcksum.h"
	"src/librcksum/rsum.c"
	"src/librcksum/state.c"
	"src/libzsync/sha1.c"
	"src/libzsync/sha1.h"
	"src/libzsync/sha1test.c"
	"src/libzsync/zmap.c"
	"src/libzsync/zmap.h"
	"src/libzsync/zsync.c"
	"src/libzsync/zsync.h"
	"src/make.c"
	"src/makegz.c"
	"src/makegz.h"
	"src/msc.h"
	"src/progress.c"
	"src/progress.h"
	"src/url.c"
	"src/url.h"
	"src/zlib/adler32.c"
	"src/zlib/compress.c"
	"src/zlib/crc32.c"
	"src/zlib/crc32.h"
	"src/zlib/deflate.c"
	"src/zlib/deflate.h"
	"src/zlib/inffixed.h"
	"src/zlib/inflate.c"
	"src/zlib/inflate.h"
	"src/zlib/inftrees.c"
	"src/zlib/inftrees.h"
	"src/zlib/trees.c"
	"src/zlib/trees.h"
	"src/zlib/zconf.h"
	"src/zlib/zconf.in.h"
	"src/zlib/zlib.h"
	"src/zlib/zutil.c"
	"src/zlib/zutil.h"
	"src/zsglobal.h"
)

add_executable(zsync)

target_sources(zsync PRIVATE ${zsync_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${zsync_SOURCES})

get_directory_property(CMKR_VS_STARTUP_PROJECT DIRECTORY ${PROJECT_SOURCE_DIR} DEFINITION VS_STARTUP_PROJECT)
if(NOT CMKR_VS_STARTUP_PROJECT)
	set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT zsync)
endif()

install(
	TARGETS
		zsync
	CONFIGURATIONS
		Release
	DESTINATION
		bin
	COMPONENT
		zsync
)
