#include <Toreador/Core/Math/Matrix/Matrix2x2.hpp>

toreador::math::Matrix2x2 toreador::math::Matrix2x2::operator+( float scalar )
{
    return { this->a + scalar, this->b + scalar, this->c + scalar, this->d + scalar };
}

toreador::math::Matrix2x2 toreador::math::Matrix2x2::operator+( toreador::math::Matrix2x2 matrix )
{
    return { this->a + matrix.a, this->b + matrix.b, this->c + matrix.c, this->d + matrix.d };
}

toreador::math::Matrix2x2 toreador::math::Matrix2x2::operator-( float scalar )
{
    return { this->a - scalar, this->b - scalar, this->c - scalar, this->d - scalar };
}

toreador::math::Matrix2x2 toreador::math::Matrix2x2::operator-( toreador::math::Matrix2x2 matrix )
{
    return { this->a - matrix.a, this->b - matrix.b, this->c - matrix.c, this->d - matrix.d };
}

toreador::math::Matrix2x2 toreador::math::Matrix2x2::operator*( float scalar )
{
    return { this->a * scalar, this->b * scalar, this->c * scalar, this->d * scalar };
}

toreador::math::Matrix2x2 toreador::math::Matrix2x2::operator*( toreador::math::Matrix2x2 matrix )
{
    float a = ( this->a * matrix.a ) + ( this->b * matrix.c );
    float b = ( this->a * matrix.b ) + ( this->b * matrix.d );
    float c = ( this->c * matrix.a ) + ( this->d * matrix.c );
    float d = ( this->c * matrix.b ) + ( this->d * matrix.d );

    return { a, b, c, d };
}

toreador::math::Matrix2x2 toreador::math::Matrix2x2::operator/( float scalar )
{
    return { this->a / scalar, this->b / scalar, this->c / scalar, this->d / scalar };
}

toreador::math::Matrix2x2 toreador::math::Matrix2x2::invert() const
{
    return { this->a * -1, this->b * -1, this->c * -1, this->d * -1 };
}

std::vector<float> toreador::math::Matrix2x2::toArray() const
{
    std::vector<float> vector{};
    vector.insert( vector.cend(), this->a );
    vector.insert( vector.cend(), this->b );
    vector.insert( vector.cend(), this->c );
    vector.insert( vector.cend(), this->d );

    return vector;
}


float toreador::math::Matrix2x2::determinant() const
{
    return ( this->a * this->d ) - ( this->b * this->c );
}

float getElementsNotZero( toreador::math::Matrix2x2 matrix2X2 )
{
    float total = 0;
    for ( float f: matrix2X2.toArray() ) {
        if ( f != 0 ) {
            total++;
        }
    }
    return total;
}

float toreador::math::Matrix2x2::rank()
{
    /* Pivot Element */
    float pivotElemC = ( ( this->a * this->c ) - ( this->c * this->a ) ) / 1;
    float pivotElemD = ( ( this->a * this->d ) - ( this->c * this->b ) ) / 1;

    Matrix2x2 pivot = { this->a, this->b, pivotElemC, pivotElemD };

    return getElementsNotZero( pivot ); /* I think this is how it works */
}

float toreador::math::Matrix2x2::trace() const
{
    return this->a + this->d;
}