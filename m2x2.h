#ifndef _M2x2_INCLUDE_
#define _M2x2_INCLUDE_

class M2x2 {
public:
    M2x2();
    void set_by_row(
        float m00, float m01,
        float m10, float m11
    );
    float get(int row, int col) const;
private:
    float
        _m00, _m01,
        _m10, _m11;
};

#endif // _M2x2_INCLUDE_
