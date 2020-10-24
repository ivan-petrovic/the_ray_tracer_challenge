//
// Created by ivan on 22.10.2020..
//

#ifndef THE_RAY_TRACER_CHALLENGE_CAMERA_H
#define THE_RAY_TRACER_CHALLENGE_CAMERA_H

#include "Tuple.h"
#include "Matrix4x4.h"
#include "Ray.h"

namespace mn {

    class Camera {
    public:
        Camera(int h, int v, double fov) :
                _h_size(h), _v_size(v), _field_of_view(fov),
                _half_width{}, _half_height{}, _pixel_size{},
                _transform{}, _inverse_transform{} {
            _transform.identity();
            _inverse_transform.identity();
            compute_pixel_size();
        }

        [[nodiscard]] int horizontal_size() const { return _h_size; }

        [[nodiscard]] int vertical_size() const { return _v_size; }

        [[nodiscard]] double pixel_size() const { return _pixel_size; }

        [[nodiscard]] double field_of_view() const { return _field_of_view; }

        [[nodiscard]] const Matrix4x4 &transform() const { return _transform; }

        void transform(const Matrix4x4 &m) {
            _transform = m;
            _inverse_transform = inverse(_transform);
        }

        [[nodiscard]] Ray ray_for_pixel(int px, int py) const {
            // the offset from the edge of the canvas to the pixel's center
            double x_offset = (px + 0.5) * _pixel_size;
            double y_offset = (py + 0.5) * _pixel_size;

            // the untransformed coordinates of the pixel in world space
            // (remember that the camera looks toward -z, so +x is to the left)
            double world_x = _half_width - x_offset;
            // if py = 0 is at the top then world_y would be: _half_height - y_offset;
            // but I want to py = 0 be at the bottom of the canvas
            double world_y = -_half_height + y_offset;

            // using the camera matrix, transform the canvas point and the origin,
            // and than compute the ray's direction vector
            // (remember that the canvas is at z = -1)
            Point pixel = _inverse_transform * make_point(world_x, world_y, -1);
            Point origin = _inverse_transform * make_point(0.0, 0.0, 0.0);
            Vector direction = normalize(pixel - origin);

            return Ray(origin, direction);
        }

    protected:
        int _h_size, _v_size; // horizontal and vertical size of canvas in pixels
        double _field_of_view; // in radians
        double _half_width, _half_height;
        double _pixel_size;
        Matrix4x4 _transform; // view transform
        Matrix4x4 _inverse_transform; // inverse view transform for optimization

        void compute_pixel_size() {
            double half_view = std::tan(_field_of_view / 2.0);
            double aspect = static_cast<double>(_h_size) / _v_size;
            if (aspect >= 1.0) {
                _half_width = half_view;
                _half_height = half_view / aspect;
            } else {
                _half_width = half_view * aspect;
                _half_height = half_view;
            }
            _pixel_size = _half_width * 2.0 / _h_size;
        }

    };

}

#endif //THE_RAY_TRACER_CHALLENGE_CAMERA_H
