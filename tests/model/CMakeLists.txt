include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_SphereTransformation sphere_transformation.cpp)
target_link_libraries(RTC_SphereTransformation PRIVATE RTC_rtc)

#add_executable(RTC_AddingColors adding_colors.cpp)
#target_link_libraries(RTC_AddingColors PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Sphere.Transformation COMMAND RTC_SphereTransformation)
