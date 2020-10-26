include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_RaySphereIntersection ray_sphere.cpp)
target_link_libraries(RTC_RaySphereIntersection PRIVATE RTC_rtc)

add_executable(RTC_RayPlaneIntersection ray_plane.cpp)
target_link_libraries(RTC_RayPlaneIntersection PRIVATE RTC_rtc)

add_executable(RTC_TrackingIntersections tracking_intersections.cpp)
target_link_libraries(RTC_TrackingIntersections PRIVATE RTC_rtc)

add_executable(RTC_HitIntersections hit_intersections.cpp)
target_link_libraries(RTC_HitIntersections PRIVATE RTC_rtc)

add_executable(RTC_RayWorldIntersection ray_world.cpp)
target_link_libraries(RTC_RayWorldIntersection PRIVATE RTC_rtc)

add_executable(RTC_PrepareComputations prepare_computations_test.cpp)
target_link_libraries(RTC_PrepareComputations PRIVATE RTC_rtc)

add_executable(RTC_RayTransformedObjectIntersection ray_transformed_object.cpp)
target_link_libraries(RTC_RayTransformedObjectIntersection PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Intersection.RaySphere COMMAND RTC_RaySphereIntersection)
add_test(NAME RTC.Intersection.RayPlane COMMAND RTC_RayPlaneIntersection)
add_test(NAME RTC.Intersection.RayTransformedSphere COMMAND RTC_RayTransformedSphereIntersection)
add_test(NAME RTC.Intersection.Track COMMAND RTC_TrackingIntersections)
add_test(NAME RTC.Intersection.Hit COMMAND RTC_HitIntersections)
add_test(NAME RTC.Intersection.RayWorld COMMAND RTC_RayWorldIntersection)
add_test(NAME RTC.Intersection.PrepareComputations COMMAND RTC_PrepareComputations)
add_test(NAME RTC.Intersection.RayTransformedObject COMMAND RTC_RayTransformedObjectIntersection)
