include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_RaySphereIntersection ray_sphere.cpp)
target_link_libraries(RTC_RaySphereIntersection PRIVATE RTC_rtc)

add_executable(RTC_RayTransformedSphereIntersection ray_transformed_sphere.cpp)
target_link_libraries(RTC_RayTransformedSphereIntersection PRIVATE RTC_rtc)

add_executable(RTC_TrackingIntersections tracking_intersections.cpp)
target_link_libraries(RTC_TrackingIntersections PRIVATE RTC_rtc)

add_executable(RTC_HitIntersections hit_intersections.cpp)
target_link_libraries(RTC_HitIntersections PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Intersection.RaySphere COMMAND RTC_RaySphereIntersection)
add_test(NAME RTC.Intersection.RayTransformedSphere COMMAND RTC_RayTransformedSphereIntersection)
add_test(NAME RTC.Intersection.Track COMMAND RTC_TrackingIntersections)
add_test(NAME RTC.Intersection.Hit COMMAND RTC_HitIntersections)
