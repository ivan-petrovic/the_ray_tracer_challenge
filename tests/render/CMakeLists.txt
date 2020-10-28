include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_RenderDefaultWorld render_default_world.cpp)
target_link_libraries(RTC_RenderDefaultWorld PRIVATE RTC_rtc)

add_executable(RTC_LightingFunction lighting_function.cpp)
target_link_libraries(RTC_LightingFunction PRIVATE RTC_rtc)

add_executable(RTC_ShadeHitFunction shade_hit_function.cpp)
target_link_libraries(RTC_ShadeHitFunction PRIVATE RTC_rtc)

add_executable(RTC_ColorAtFunction color_at_function.cpp)
target_link_libraries(RTC_ColorAtFunction PRIVATE RTC_rtc)

add_executable(RTC_IsShadowedFunction is_shadowed_function.cpp)
target_link_libraries(RTC_IsShadowedFunction PRIVATE RTC_rtc)

add_executable(RTC_PatternAtObject pattern_at_object_fn.cpp)
target_link_libraries(RTC_PatternAtObject PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Render.LightingFunction COMMAND RTC_LightingFunction)
add_test(NAME RTC.Render.ShadeHit COMMAND RTC_ShadeHitFunction)
add_test(NAME RTC.Render.ColorAt COMMAND RTC_ColorAtFunction)
add_test(NAME RTC.Render.DefaultWorld COMMAND RTC_RenderDefaultWorld)
add_test(NAME RTC.Render.IsShadowed COMMAND RTC_IsShadowedFunction)
add_test(NAME RTC.Render.PatternAtObject COMMAND RTC_PatternAtObject)
