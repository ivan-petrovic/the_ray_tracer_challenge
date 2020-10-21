include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_CreateWorld create_world.cpp)
target_link_libraries(RTC_CreateWorld PRIVATE RTC_rtc)

add_executable(RTC_DefaultWorld create_default_world.cpp)
target_link_libraries(RTC_DefaultWorld PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.World.Create COMMAND RTC_CreateWorld)
add_test(NAME RTC.World.Default COMMAND RTC_DefaultWorld)
