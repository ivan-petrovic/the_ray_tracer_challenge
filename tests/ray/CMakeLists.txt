include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_CreateRay create_ray.cpp)
target_link_libraries(RTC_CreateRay PRIVATE RTC_rtc)

add_executable(RTC_PointOnRay point_on_ray.cpp)
target_link_libraries(RTC_PointOnRay PRIVATE RTC_rtc)

add_executable(RTC_TransformRay transform_ray.cpp)
target_link_libraries(RTC_TransformRay PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Ray.Create COMMAND RTC_CreateRay)
add_test(NAME RTC.Ray.Point COMMAND RTC_PointOnRay)
add_test(NAME RTC.Ray.Transform COMMAND RTC_TransformRay)
