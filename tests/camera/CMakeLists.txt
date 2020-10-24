include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_CreateCamera create_camera.cpp)
target_link_libraries(RTC_CreateCamera PRIVATE RTC_rtc)

add_executable(RTC_PixelSize pixel_size.cpp)
target_link_libraries(RTC_PixelSize PRIVATE RTC_rtc)

add_executable(RTC_CastRay casting_rays.cpp)
target_link_libraries(RTC_CastRay PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Camera.Create COMMAND RTC_CreateCamera)
add_test(NAME RTC.Camera.PixelSize COMMAND RTC_PixelSize)
add_test(NAME RTC.Camera.CastRay COMMAND RTC_CastRay)
