include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_SphereTransformation sphere_transformation.cpp)
target_link_libraries(RTC_SphereTransformation PRIVATE RTC_rtc)

add_executable(RTC_SphereNormals sphere_normals.cpp)
target_link_libraries(RTC_SphereNormals PRIVATE RTC_rtc)

add_executable(RTC_SphereMaterial sphere_material.cpp)
target_link_libraries(RTC_SphereMaterial PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Sphere.Transformation COMMAND RTC_SphereTransformation)
add_test(NAME RTC.Sphere.Normals COMMAND RTC_SphereNormals)
add_test(NAME RTC.Sphere.Material COMMAND RTC_SphereMaterial)
