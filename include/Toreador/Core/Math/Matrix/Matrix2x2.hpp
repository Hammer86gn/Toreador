#ifndef TOREADOR_MATRIX2X2_HPP
#define TOREADOR_MATRIX2X2_HPP

#include <vector>

namespace toreador {
    namespace math {
        struct Matrix2x2 {
            float a;
            float b;

            float c;
            float d;

            Matrix2x2 operator+( float );
            Matrix2x2 operator+( Matrix2x2 );

            Matrix2x2 operator-( float );
            Matrix2x2 operator-( Matrix2x2 );

            Matrix2x2 operator*( float );
            Matrix2x2 operator*( Matrix2x2 );

            Matrix2x2 operator/( float );
            /* Note: You cannot dived a matrix by a matrix */

            Matrix2x2 invert() const;

            std::vector<float> toArray() const;

            float determinant() const;

            float rank();

            float trace() const;

        };
    }
}

#endif// TOREADOR_MATRIX2X2_HPP
