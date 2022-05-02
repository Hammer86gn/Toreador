#ifndef TOREADOR_MATRIX3X3_HPP
#define TOREADOR_MATRIX3X3_HPP

#include <vector>

namespace toreador {
    namespace math {

        struct Matrix3x3 {
            float a;
            float b;
            float c;

            float d;
            float e;
            float f;

            float g;
            float h;
            float i;

            Matrix3x3 operator+( float );
            Matrix3x3 operator+( Matrix3x3 );

            Matrix3x3 operator-( float );
            Matrix3x3 operator-( Matrix3x3 );

            Matrix3x3 operator*( float );
            Matrix3x3 operator*( Matrix3x3 );

            Matrix3x3 operator/( float );
            /* Note: You cannot dived a matrix by a matrix */

            Matrix3x3 invert() const;

            std::vector<float> toArray() const;

            float determinant() const;

            float trace() const;

        };

    }
}

#endif// TOREADOR_MATRIX3X3_HPP
