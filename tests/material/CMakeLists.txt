include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_CreateMaterial create_material.cpp)
target_link_libraries(RTC_CreateMaterial PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Material.Create COMMAND RTC_CreateMaterial)
