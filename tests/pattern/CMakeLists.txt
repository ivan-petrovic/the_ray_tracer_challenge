include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_StripedPattern create_striped_pattern.cpp)
target_link_libraries(RTC_StripedPattern PRIVATE RTC_rtc)

add_executable(RTC_StripedPatternProperties striped_pattern_properties.cpp)
target_link_libraries(RTC_StripedPatternProperties PRIVATE RTC_rtc)

add_executable(RTC_PatternTransformation pattern_transformation.cpp TestPattern.h)
target_link_libraries(RTC_PatternTransformation PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Pattern.Striped COMMAND RTC_StripedPattern)
add_test(NAME RTC.Pattern.StripedProperties COMMAND RTC_StripedPatternProperties)
add_test(NAME RTC.Pattern.Transformation COMMAND RTC_PatternTransformation)
