add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp
        AccountTest.cpp CarteTest.cpp
        TransazioneTest.cpp FinanzaTest.cpp
        DataTest.cpp)

add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)