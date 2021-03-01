include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_ObjectParser test_object_parser.cpp)
target_link_libraries(RTC_ObjectParser PRIVATE RTC_rtc)

##=========================
## Testing
##=========================
add_test(NAME RTC.ObjectParser COMMAND RTC_ObjectParser)
