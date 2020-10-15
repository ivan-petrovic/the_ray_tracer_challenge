include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_Translation translation.cpp)
target_link_libraries(RTC_Translation PRIVATE RTC_rtc)

add_executable(RTC_Scaling scaling.cpp)
target_link_libraries(RTC_Scaling PRIVATE RTC_rtc)

add_executable(RTC_Rotation rotation.cpp)
target_link_libraries(RTC_Rotation PRIVATE RTC_rtc)

add_executable(RTC_Shearing shearing.cpp)
target_link_libraries(RTC_Shearing PRIVATE RTC_rtc)

add_executable(RTC_Chained_Transformations chained_transformations.cpp)
target_link_libraries(RTC_Chained_Transformations PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Transformation.Translation COMMAND RTC_Translation)
add_test(NAME RTC.Transformation.Scaling COMMAND RTC_Scaling)
add_test(NAME RTC.Transformation.Rotation COMMAND RTC_Rotation)
add_test(NAME RTC.Transformation.Shearing COMMAND RTC_Shearing)
add_test(NAME RTC.Transformation.Chaining COMMAND RTC_Chained_Transformations)
