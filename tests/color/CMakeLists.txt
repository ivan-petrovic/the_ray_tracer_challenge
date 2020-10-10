include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_ColorTuple create_color.cpp)
target_link_libraries(RTC_ColorTuple PRIVATE RTC_rtc)

add_executable(RTC_AddingColors adding_colors.cpp)
target_link_libraries(RTC_AddingColors PRIVATE RTC_rtc)

add_executable(RTC_SubtractingColors subtracting_colors.cpp)
target_link_libraries(RTC_SubtractingColors PRIVATE RTC_rtc)

add_executable(RTC_MultiplyingColorByScalar multiplying_by_scalar.cpp)
target_link_libraries(RTC_MultiplyingColorByScalar PRIVATE RTC_rtc)

add_executable(RTC_MultiplyingColors multiplying_colors.cpp)
target_link_libraries(RTC_MultiplyingColors PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Color.Create COMMAND RTC_ColorTuple)
add_test(NAME RTC.Color.Add COMMAND RTC_AddingColors)
add_test(NAME RTC.Color.Subtract COMMAND RTC_SubtractingColors)
add_test(NAME RTC.Color.MultiplyByScalar COMMAND RTC_MultiplyingColorByScalar)
add_test(NAME RTC.Color.Multiply COMMAND RTC_MultiplyingColors)
