include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_PointLight create_point_light.cpp)
target_link_libraries(RTC_PointLight PRIVATE RTC_rtc)

add_executable(RTC_LightingFunction lighting_function.cpp)
target_link_libraries(RTC_LightingFunction PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.PointLight.Create COMMAND RTC_PointLight)
add_test(NAME RTC.Lighting.Function COMMAND RTC_LightingFunction)
