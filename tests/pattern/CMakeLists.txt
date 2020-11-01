include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_StripedPattern create_striped_pattern.cpp)
target_link_libraries(RTC_StripedPattern PRIVATE RTC_rtc)

add_executable(RTC_StripedPatternProperties striped_pattern_properties.cpp)
target_link_libraries(RTC_StripedPatternProperties PRIVATE RTC_rtc)

add_executable(RTC_GradientPatternProperties gradient_pattern_properties.cpp)
target_link_libraries(RTC_GradientPatternProperties PRIVATE RTC_rtc)

add_executable(RTC_RingPatternProperties ring_pattern_properties.cpp)
target_link_libraries(RTC_RingPatternProperties PRIVATE RTC_rtc)

add_executable(RTC_Checker3DPatternProperties checker3d_pattern_properties.cpp)
target_link_libraries(RTC_Checker3DPatternProperties PRIVATE RTC_rtc)

add_executable(RTC_PatternTransformation pattern_transformation.cpp TestPattern.h)
target_link_libraries(RTC_PatternTransformation PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Pattern.Striped COMMAND RTC_StripedPattern)
add_test(NAME RTC.Pattern.StripedProperties COMMAND RTC_StripedPatternProperties)
add_test(NAME RTC.Pattern.GradientProperties COMMAND RTC_GradientPatternProperties)
add_test(NAME RTC.Pattern.RingProperties COMMAND RTC_RingPatternProperties)
add_test(NAME RTC.Pattern.Checker3DProperties COMMAND RTC_Checker3DPatternProperties)
add_test(NAME RTC.Pattern.Transformation COMMAND RTC_PatternTransformation)
