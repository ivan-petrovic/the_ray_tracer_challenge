include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_SphereNormals sphere_normals.cpp)
target_link_libraries(RTC_SphereNormals PRIVATE RTC_rtc)

add_executable(RTC_PlaneNormal plane_normal.cpp)
target_link_libraries(RTC_PlaneNormal PRIVATE RTC_rtc)

add_executable(RTC_ObjectTransformation object_transformation.cpp TestObject.h)
target_link_libraries(RTC_ObjectTransformation PRIVATE RTC_rtc)

add_executable(RTC_ObjectMaterial object_material.cpp TestObject.h)
target_link_libraries(RTC_ObjectMaterial PRIVATE RTC_rtc)

add_executable(RTC_ObjectNormals object_normals.cpp TestObject.h)
target_link_libraries(RTC_ObjectNormals PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Sphere.Normals COMMAND RTC_SphereNormals)
add_test(NAME RTC.Plane.Normal COMMAND RTC_PlaneNormal)
add_test(NAME RTC.Object.Transformation COMMAND RTC_ObjectTransformation)
add_test(NAME RTC.Object.Material COMMAND RTC_ObjectMaterial)
add_test(NAME RTC.Object.Normals COMMAND RTC_ObjectNormals)
