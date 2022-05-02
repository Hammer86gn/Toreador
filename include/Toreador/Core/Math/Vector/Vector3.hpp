#ifndef TOREADOR_VECTOR3_HPP
#define TOREADOR_VECTOR3_HPP

namespace toreador {
    namespace math {
        struct Vector3 {
            float x;
            float y;
            float z;

            Vector3 operator+( float ) const;
            Vector3 operator+( Vector3 ) const;

            Vector3 operator-( float ) const;
            Vector3 operator-( Vector3 ) const;

            Vector3 operator*( float ) const;
            Vector3 operator*( Vector3 ) const;

            Vector3 operator/( float ) const;
            Vector3 operator/( Vector3 ) const;

            /**
             *
             * @param vector3 the vector to get the magnitude of
             * @return the magnitude of the vector
             */
            float magnitude() const;

            /**
             *
             * @param vector3 the vector to get the magnitude of
             * @return the multiplicative inverse of the magnitude
             */
            float inverseMagnitude() const;

            /**
             *
             * @param vector3 the vector to normalize
             * @return a vector that is the normalized version of the input
             */
            Vector3 normalize() const;
        };
    }
}

#endif// TOREADOR_VECTOR3_HPP
