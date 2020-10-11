include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(EXAMPLE_Projectile example01.cpp)
target_link_libraries(EXAMPLE_Projectile PRIVATE RTC_rtc)

add_executable(EXAMPLE_Trajectory example02.cpp)
target_link_libraries(EXAMPLE_Trajectory PRIVATE RTC_rtc)
