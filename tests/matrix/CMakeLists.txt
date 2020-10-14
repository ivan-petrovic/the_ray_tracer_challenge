include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(RTC_CreateMatrix4x4 create_matrix4x4.cpp)
target_link_libraries(RTC_CreateMatrix4x4 PRIVATE RTC_rtc)

add_executable(RTC_Matrix4x4Equality matrix4x4_equality.cpp)
target_link_libraries(RTC_Matrix4x4Equality PRIVATE RTC_rtc)

add_executable(RTC_Matrix4x4Inequality matrix4x4_inequality.cpp)
target_link_libraries(RTC_Matrix4x4Inequality PRIVATE RTC_rtc)

add_executable(RTC_Matrix4x4Multiplication multiply_matrices4x4.cpp)
target_link_libraries(RTC_Matrix4x4Multiplication PRIVATE RTC_rtc)

add_executable(RTC_Matrix4x4TupleMultiplication multiply_matrix4x4_and_tuple.cpp)
target_link_libraries(RTC_Matrix4x4TupleMultiplication PRIVATE RTC_rtc)

add_executable(RTC_IdentityMatrixMultiplication identity_matrix_multiplication.cpp)
target_link_libraries(RTC_IdentityMatrixMultiplication PRIVATE RTC_rtc)

add_executable(RTC_TransposingMatrix transposing_matrix.cpp)
target_link_libraries(RTC_TransposingMatrix PRIVATE RTC_rtc)

add_executable(RTC_MatrixDeterminant matrix4x4_determinant.cpp)
target_link_libraries(RTC_MatrixDeterminant PRIVATE RTC_rtc)

add_executable(RTC_MatrixInverse matrix_inverse.cpp)
target_link_libraries(RTC_MatrixInverse PRIVATE RTC_rtc)

#=========================
# Testing
#=========================
add_test(NAME RTC.Matrix4x4.Create COMMAND RTC_CreateMatrix4x4)
add_test(NAME RTC.Matrix4x4.Equality COMMAND RTC_Matrix4x4Equality)
add_test(NAME RTC.Matrix4x4.Inequality COMMAND RTC_Matrix4x4Inequality)
add_test(NAME RTC.Matrix4x4.Multiply COMMAND RTC_Matrix4x4Multiplication)
add_test(NAME RTC.Matrix4x4.MultiplyTuple COMMAND RTC_Matrix4x4TupleMultiplication)
add_test(NAME RTC.Matrix4x4.Identity COMMAND RTC_IdentityMatrixMultiplication)
add_test(NAME RTC.Matrix4x4.Transpose COMMAND RTC_TransposingMatrix)
add_test(NAME RTC.Matrix4x4.Determinant COMMAND RTC_MatrixDeterminant)
add_test(NAME RTC.Matrix4x4.Inverse COMMAND RTC_MatrixInverse)
