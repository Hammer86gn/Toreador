#ifndef TOREADOR_VECTOR4_HPP
#define TOREADOR_VECTOR4_HPP

namespace toreador {
    namespace math {
        struct Vector4 {
            float x;
            float y;
            float z;
            float w;

            Vector4 operator+( float ) const;
            Vector4 operator+( Vector4 ) const;

            Vector4 operator-( float ) const;
            Vector4 operator-( Vector4 ) const;

            Vector4 operator*( float ) const;
            Vector4 operator*( Vector4 ) const;

            Vector4 operator/( float ) const;
            Vector4 operator/( Vector4 ) const;

            /**
             *
             * @param vector4 the vector to get the magnitude of
             * @return the magnitude of the vector
             */
            float magnitude() const;

            /**
             *
             * @param vector4 the vector to get the magnitude of
             * @return the multiplicative inverse of the magnitude
             */
            float inverseMagnitude() const;

            /**
             *
             * @param vector4 the vector to normalize
             * @return a vector that is the normalized version of the input
             */
            Vector4 normalize() const;

        };
    }
}

#endif// TOREADOR_VECTOR4_HPP
