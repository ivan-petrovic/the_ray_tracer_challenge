#=========================
# Define targets
#=========================
add_library(RTC_rtc
    math_util.h
    Tuple.h
    Matrix4x4.cpp Matrix4x4.h
    Ray.h
    Canvas.h
    canvas_to_file/PPM.cpp canvas_to_file/PPM.h
    pattern/Pattern.h pattern/StripedPattern.h Material.h
    model/Object.h model/Sphere.h model/Plane.h
    intersection/Intersections.cpp intersection/Intersections.h
    intersection/intersect.cpp intersection/intersect.h
    light/PointLight.h
    World.cpp World.h
    Camera.h
    render.cpp render.h)
