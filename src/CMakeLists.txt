#=========================
# Define targets
#=========================
add_library(RTC_rtc
    math_util.h
    Tuple.h
    Canvas.h
    canvas_to_file/PPM.cpp canvas_to_file/PPM.h
    Matrix4x4.cpp Matrix4x4.h
    Ray.h model/Sphere.h)
