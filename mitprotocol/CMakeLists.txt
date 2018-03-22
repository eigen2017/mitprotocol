cmake_minimum_required(VERSION 3.0)
project(mitprotocol)

set(CMAKE_CXX_STANDARD 11)

set(DIR_MYCROSS ${PROJECT_SOURCE_DIR}/src/mycross)
set(DIR_TRAFFIC ${PROJECT_SOURCE_DIR}/src/traffic)
set(DIR_WFDB ${PROJECT_SOURCE_DIR}/src/wfdb)
set(DIR_EASYTAR ${PROJECT_SOURCE_DIR}/src/easytar)

aux_source_directory(${DIR_TRAFFIC} SOURCE_TRAFFiC)
aux_source_directory(${DIR_WFDB} SOURCE_WFDB)
aux_source_directory(${DIR_EASYTAR} SOURCE_EASYTAR)


set(SOURCE_FILES ${SOURCE_TRAFFiC} ${SOURCE_WFDB} ${SOURCE_EASYTAR})

include_directories(${DIR_MYCROSS})
include_directories(${DIR_TRAFFIC})
include_directories(${DIR_WFDB})
include_directories(${DIR_EASYTAR})

if(CENTOS_X64)
    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
endif()

if(CENTOS_X64_PYTHON)
    include_directories(/usr/include/python2.7)

    set(DIR_PYTHONINTERFFACE ${PROJECT_SOURCE_DIR}/../doit/build/centos_x64_python/pythoninterface)
    aux_source_directory(${DIR_PYTHONINTERFFACE} SOURCE_PYTHONINTERFACE)
    set(SOURCE_FILES ${SOURCE_FILES} ${SOURCE_PYTHONINTERFACE})
    include_directories(${DIR_PYTHONINTERFFACE})

    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

    target_link_libraries(${PROJECT_NAME} boost_python)
endif()


if(CENTOS_X64_JAVA)

    include_directories(/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.141-1.b16.el7_3.x86_64/include)
    include_directories(/usr/lib/jvm/java-1.8.0-openjdk-1.8.0.141-1.b16.el7_3.x86_64/include/linux)

    set(DIR_CENTOSX64JAVAINTERFFACE ${PROJECT_SOURCE_DIR}/../doit/build/centos_x64_java/javainterface)
    aux_source_directory(${DIR_CENTOSX64JAVAINTERFFACE} SOURCE_CENTOSX64JAVAINTERFFACE)
    set(SOURCE_FILES ${SOURCE_FILES} ${SOURCE_CENTOSX64JAVAINTERFFACE})
    include_directories(${DIR_CENTOSX64JAVAINTERFFACE})

    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

endif()

if(ANDROID_PHONE)

    set(DIR_ANDROIDINTERFFACE ${PROJECT_SOURCE_DIR}/../doit/build/android/javainterface)
    aux_source_directory(${DIR_ANDROIDINTERFFACE} SOURCE_ANDROIDINTERFFACE)
    set(SOURCE_FILES ${SOURCE_FILES} ${SOURCE_ANDROIDINTERFFACE})
    include_directories(${DIR_ANDROIDINTERFFACE})

    add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

endif()


if (MYTEST)

    add_library(${PROJECT_NAME}s STATIC ${SOURCE_FILES})

    set_target_properties(${PROJECT_NAME}s PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

#    install(FILES src/traffic/mitprotocol.h DESTINATION include)
#
#    install(TARGETS ${PROJECT_NAME}s LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

    add_subdirectory(test)

endif ()

