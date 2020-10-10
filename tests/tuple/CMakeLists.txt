include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_PointTuple create_point_tuple.cpp)
target_link_libraries(RTC_PointTuple PRIVATE RTC_rtc)

add_executable(RTC_VectorTuple create_vector_tuple.cpp)
target_link_libraries(RTC_VectorTuple PRIVATE RTC_rtc)

add_executable(RTC_FactoryPoint factory_point_tuple.cpp)
target_link_libraries(RTC_FactoryPoint PRIVATE RTC_rtc)

add_executable(RTC_FactoryVector factory_vector_tuple.cpp)
target_link_libraries(RTC_FactoryVector PRIVATE RTC_rtc)

add_executable(RTC_AddingTuples adding_tuples.cpp)
target_link_libraries(RTC_AddingTuples PRIVATE RTC_rtc)

add_executable(RTC_SubtractingTuples subtracting_tuples.cpp)
target_link_libraries(RTC_SubtractingTuples PRIVATE RTC_rtc)

add_executable(RTC_NegatingTuples negating_tuples.cpp)
target_link_libraries(RTC_NegatingTuples PRIVATE RTC_rtc)

add_executable(RTC_MultiplyingByScalar multiplying_by_scalar.cpp)
target_link_libraries(RTC_MultiplyingByScalar PRIVATE RTC_rtc)

add_executable(RTC_DividingByScalar dividing_by_scalar.cpp)
target_link_libraries(RTC_DividingByScalar PRIVATE RTC_rtc)

add_executable(RTC_MagnitudeOfVector magnitude_of_vector.cpp)
target_link_libraries(RTC_MagnitudeOfVector PRIVATE RTC_rtc)

add_executable(RTC_NormalizeVector normalizing_vector.cpp)
target_link_libraries(RTC_NormalizeVector PRIVATE RTC_rtc)

add_executable(RTC_DotProduct dot_product.cpp)
target_link_libraries(RTC_DotProduct PRIVATE RTC_rtc)

add_executable(RTC_CrossProduct cross_product.cpp)
target_link_libraries(RTC_CrossProduct PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Tuple.Create.Point COMMAND RTC_PointTuple)
add_test(NAME RTC.Tuple.Create.Vector COMMAND RTC_VectorTuple)
add_test(NAME RTC.Tuple.Factory.Point COMMAND RTC_FactoryPoint)
add_test(NAME RTC.Tuple.Factory.Vector COMMAND RTC_FactoryVector)
add_test(NAME RTC.Tuple.Add COMMAND RTC_AddingTuples)
add_test(NAME RTC.Tuple.Subtract COMMAND RTC_SubtractingTuples)
add_test(NAME RTC.Tuple.Negate COMMAND RTC_NegatingTuples)
add_test(NAME RTC.Tuple.MultiplyByScalar COMMAND RTC_MultiplyingByScalar)
add_test(NAME RTC.Tuple.DivideByScalar COMMAND RTC_DividingByScalar)
add_test(NAME RTC.Tuple.Magnitude COMMAND RTC_MagnitudeOfVector)
add_test(NAME RTC.Tuple.Normalize COMMAND RTC_NormalizeVector)
add_test(NAME RTC.Tuple.DotProduct COMMAND RTC_DotProduct)
add_test(NAME RTC.Tuple.CrossProduct COMMAND RTC_CrossProduct)
