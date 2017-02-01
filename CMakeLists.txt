cmake_minimum_required(VERSION 3.6)
project(SuMoS)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/c/unimotion.c src/c/unimotion.h src/c/main.c)

add_executable(SuMoS ${SOURCE_FILES})

# =======================================================================================
# External Libraries
# =======================================================================================

# ---------------------------------------------------------------------------------------
# ~ IOKit
# ---------------------------------------------------------------------------------------

include_directories(/opt/local/lib/IOKit)
target_link_libraries(SuMoS /opt/local/lib/IOKit/libIOKit.dylib)

# ---------------------------------------------------------------------------------------
# ~ CoreFoundation
# ---------------------------------------------------------------------------------------

include_directories(/opt/local/lib/CoreFoundation/)
target_link_libraries(SuMoS /opt/local/lib/CoreFoundation/libCoreFoundation.dylib)

# ---------------------------------------------------------------------------------------
# ~ JavaVM (jni)
# ---------------------------------------------------------------------------------------

include_directories(/opt/local/lib/JavaVM/)
target_link_libraries(SuMoS /opt/local/lib/JavaVM/libJavaVM.dylib)

# =======================================================================================