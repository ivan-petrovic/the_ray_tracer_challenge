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
