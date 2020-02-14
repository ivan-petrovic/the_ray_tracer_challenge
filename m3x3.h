#ifndef _M3x3_INCLUDE_
#define _M3x3_INCLUDE_

class M3x3 {
public:
    M3x3();
    void set_by_row(
        float m00, float m01, float m02,
        float m10, float m11, float m12,
        float m20, float m21, float m22
    );
    float get(int row, int col) const;
private:
    float
        _m00, _m01, _m02,
        _m10, _m11, _m12,
        _m20, _m21, _m22;
};

#endif // _M3x3_INCLUDE_
