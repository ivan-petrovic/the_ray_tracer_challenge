include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_SphereNormals sphere_normals.cpp)
target_link_libraries(RTC_SphereNormals PRIVATE RTC_rtc)

add_executable(RTC_CubeNormals cube_normals.cpp)
target_link_libraries(RTC_CubeNormals PRIVATE RTC_rtc)

add_executable(RTC_CylinderNormals cylinder_normals.cpp)
target_link_libraries(RTC_CylinderNormals PRIVATE RTC_rtc)

add_executable(RTC_CylinderBounds cylinder_bounds.cpp)
target_link_libraries(RTC_CylinderBounds PRIVATE RTC_rtc)

add_executable(RTC_ConeNormals cone_normals.cpp)
target_link_libraries(RTC_ConeNormals PRIVATE RTC_rtc)

add_executable(RTC_GlassSphere create_glass_sphere.cpp)
target_link_libraries(RTC_GlassSphere PRIVATE RTC_rtc)

add_executable(RTC_PlaneNormal plane_normal.cpp)
target_link_libraries(RTC_PlaneNormal PRIVATE RTC_rtc)

add_executable(RTC_ObjectTransformation object_transformation.cpp TestObject.h)
target_link_libraries(RTC_ObjectTransformation PRIVATE RTC_rtc)

add_executable(RTC_ObjectMaterial object_material.cpp TestObject.h)
target_link_libraries(RTC_ObjectMaterial PRIVATE RTC_rtc)

add_executable(RTC_ObjectNormals object_normals.cpp TestObject.h)
target_link_libraries(RTC_ObjectNormals PRIVATE RTC_rtc)

add_executable(RTC_Group create_group.cpp)
target_link_libraries(RTC_Group PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Sphere.Normals COMMAND RTC_SphereNormals)
add_test(NAME RTC.Sphere.Glass COMMAND RTC_GlassSphere)
add_test(NAME RTC.Cube.Normals COMMAND RTC_CubeNormals)
add_test(NAME RTC.Cylinder.Normals COMMAND RTC_CylinderNormals)
add_test(NAME RTC.Cylinder.Bounds COMMAND RTC_CylinderBounds)
add_test(NAME RTC.Cone.Normals COMMAND RTC_ConeNormals)
add_test(NAME RTC.Plane.Normal COMMAND RTC_PlaneNormal)
add_test(NAME RTC.Object.Transformation COMMAND RTC_ObjectTransformation)
add_test(NAME RTC.Object.Material COMMAND RTC_ObjectMaterial)
add_test(NAME RTC.Object.Normals COMMAND RTC_ObjectNormals)
add_test(NAME RTC.Group.Create COMMAND RTC_Group)
