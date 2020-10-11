#=========================
# Define targets
#=========================
add_library(RTC_rtc
    Tuple.h
    constants.h
    rtc.cpp rtc.h
    Canvas.h
    canvas_to_file/PPM.cpp canvas_to_file/PPM.h)
