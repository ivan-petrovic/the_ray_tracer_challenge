include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_RaySphereIntersection ray_sphere.cpp)
target_link_libraries(RTC_RaySphereIntersection PRIVATE RTC_rtc)

add_executable(RTC_RayPlaneIntersection ray_plane.cpp)
target_link_libraries(RTC_RayPlaneIntersection PRIVATE RTC_rtc)

add_executable(RTC_RayCubeIntersection ray_cube.cpp)
target_link_libraries(RTC_RayCubeIntersection PRIVATE RTC_rtc)

add_executable(RTC_RayCylinderIntersection ray_cylinder.cpp)
target_link_libraries(RTC_RayCylinderIntersection PRIVATE RTC_rtc)

add_executable(RTC_RayConeIntersection ray_cone.cpp)
target_link_libraries(RTC_RayConeIntersection PRIVATE RTC_rtc)

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

add_executable(RTC_RayGroupIntersection ray_group.cpp)
target_link_libraries(RTC_RayGroupIntersection PRIVATE RTC_rtc)

add_executable(RTC_RayTriangleIntersection ray_triangle.cpp)
target_link_libraries(RTC_RayTriangleIntersection PRIVATE RTC_rtc)

add_executable(RTC_RaySmoothTriangleIntersection ray_smooth_triangle.cpp)
target_link_libraries(RTC_RaySmoothTriangleIntersection PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Intersection.RaySphere COMMAND RTC_RaySphereIntersection)
add_test(NAME RTC.Intersection.RayPlane COMMAND RTC_RayPlaneIntersection)
add_test(NAME RTC.Intersection.RayCube COMMAND RTC_RayCubeIntersection)
add_test(NAME RTC.Intersection.RayCylinder COMMAND RTC_RayCylinderIntersection)
add_test(NAME RTC.Intersection.RayCone COMMAND RTC_RayConeIntersection)
add_test(NAME RTC.Intersection.RayTransformedSphere COMMAND RTC_RayTransformedSphereIntersection)
add_test(NAME RTC.Intersection.Track COMMAND RTC_TrackingIntersections)
add_test(NAME RTC.Intersection.Hit COMMAND RTC_HitIntersections)
add_test(NAME RTC.Intersection.RayWorld COMMAND RTC_RayWorldIntersection)
add_test(NAME RTC.Intersection.PrepareComputations COMMAND RTC_PrepareComputations)
add_test(NAME RTC.Intersection.RayTransformedObject COMMAND RTC_RayTransformedObjectIntersection)
add_test(NAME RTC.Intersection.RayGroup COMMAND RTC_RayGroupIntersection)
add_test(NAME RTC.Intersection.RayTriangle COMMAND RTC_RayTriangleIntersection)
add_test(NAME RTC.Intersection.RaySmoothTriangle COMMAND RTC_RaySmoothTriangleIntersection)
