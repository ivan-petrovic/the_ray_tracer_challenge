include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(EXAMPLE_Projectile example01.cpp)
target_link_libraries(EXAMPLE_Projectile PRIVATE RTC_rtc)

add_executable(EXAMPLE_Trajectory example02.cpp)
target_link_libraries(EXAMPLE_Trajectory PRIVATE RTC_rtc)

add_executable(EXAMPLE_ClockFaceBackground example03.cpp)
target_link_libraries(EXAMPLE_ClockFaceBackground PRIVATE RTC_rtc)

add_executable(EXAMPLE_SphereSilhouette example04.cpp)
target_link_libraries(EXAMPLE_SphereSilhouette PRIVATE RTC_rtc)

add_executable(EXAMPLE_Sphere3D example05.cpp)
target_link_libraries(EXAMPLE_Sphere3D PRIVATE RTC_rtc)

add_executable(EXAMPLE_3Spheres example06.cpp)
target_link_libraries(EXAMPLE_3Spheres PRIVATE RTC_rtc)

add_executable(EXAMPLE_3SpheresAndPlane example07.cpp)
target_link_libraries(EXAMPLE_3SpheresAndPlane PRIVATE RTC_rtc)

add_executable(EXAMPLE_Patterns example08.cpp)
target_link_libraries(EXAMPLE_Patterns PRIVATE RTC_rtc)

add_executable(EXAMPLE_Reflection example09.cpp)
target_link_libraries(EXAMPLE_Reflection PRIVATE RTC_rtc)

add_executable(EXAMPLE_Cubes example10.cpp)
target_link_libraries(EXAMPLE_Cubes PRIVATE RTC_rtc)

add_executable(EXAMPLE_Cylinders example11.cpp)
target_link_libraries(EXAMPLE_Cylinders PRIVATE RTC_rtc)

add_executable(EXAMPLE_Groups example12.cpp)
target_link_libraries(EXAMPLE_Groups PRIVATE RTC_rtc)

add_executable(EXAMPLE_Triangles example13.cpp)
target_link_libraries(EXAMPLE_Triangles PRIVATE RTC_rtc)

add_executable(EXAMPLE_SmoothTriangles example14.cpp)
target_link_libraries(EXAMPLE_SmoothTriangles PRIVATE RTC_rtc)

add_executable(EXAMPLE_CSG example15.cpp)
target_link_libraries(EXAMPLE_CSG PRIVATE RTC_rtc)

add_executable(EXAMPLE_COVER cover.cpp)
target_link_libraries(EXAMPLE_COVER PRIVATE RTC_rtc)
