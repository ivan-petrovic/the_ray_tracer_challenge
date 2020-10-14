include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_CreateCanvas create_canvas.cpp create_canvas.cpp)
target_link_libraries(RTC_CreateCanvas PRIVATE RTC_rtc)

add_executable(RTC_WritingCanvas writing_canvas.cpp)
target_link_libraries(RTC_WritingCanvas PRIVATE RTC_rtc)

add_executable(RTC_CanvasToPPM canvas_to_ppm.cpp)
target_link_libraries(RTC_CanvasToPPM PRIVATE RTC_rtc)

##=========================
## Testing
##=========================
add_test(NAME RTC.Canvas.Create COMMAND RTC_CreateCanvas)
add_test(NAME RTC.Canvas.Write COMMAND RTC_WritingCanvas)
add_test(NAME RTC.Canvas.ToPPM COMMAND RTC_CanvasToPPM)
