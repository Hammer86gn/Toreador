#ifndef TOREADOR_VECTOR2_HPP
#define TOREADOR_VECTOR2_HPP

namespace toreador {
    namespace math {

        struct Vector2 {
            float x;
            float y;

            Vector2 operator+( float ) const;
            Vector2 operator+( Vector2 ) const;

            Vector2 operator-( float ) const;
            Vector2 operator-( Vector2 ) const;

            Vector2 operator*( float ) const;
            Vector2 operator*( Vector2 ) const;

            Vector2 operator/( float ) const;
            Vector2 operator/( Vector2 ) const;

            /**
             *
             * @param vector2 the vector to get the magnitude of
             * @return the magnitude of the vector
             */
            float magnitude() const;

            /**
             *
             * @param vector2 the vector to get the magnitude of
             * @return the multiplicative inverse of the magnitude
             */
            float inverseMagnitude() const;

            /**
             *
             * @param vector2 the vector to normalize
             * @return a vector that is the normalized version of the input
             */
            Vector2 normalize() const;

        };

    }
}

#endif// TOREADOR_VECTOR2_HPP
