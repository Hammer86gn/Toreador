#include <Toreador/Core/Math/Matrix/Matrix3x3.hpp>

toreador::math::Matrix3x3 toreador::math::Matrix3x3::operator+( float scalar )
{
    return { this->a + scalar, this->b + scalar, this->c + scalar, this->d + scalar, this->e + scalar,
             this->f + scalar, this->g + scalar, this->h + scalar, this->i + scalar };
}

toreador::math::Matrix3x3 toreador::math::Matrix3x3::operator+( toreador::math::Matrix3x3 matrix )
{
    return { this->a + matrix.a, this->b + matrix.b, this->c + matrix.c, this->d + matrix.d, this->e + matrix.e,
             this->f + matrix.f, this->g + matrix.g, this->h + matrix.h, this->i + matrix.i };
}

toreador::math::Matrix3x3 toreador::math::Matrix3x3::operator-( float scalar )
{
    return { this->a - scalar, this->b - scalar, this->c - scalar, this->d - scalar, this->e - scalar,
             this->f - scalar, this->g - scalar, this->h - scalar, this->i - scalar };
}

toreador::math::Matrix3x3 toreador::math::Matrix3x3::operator-( toreador::math::Matrix3x3 matrix )
{
    return { this->a - matrix.a, this->b - matrix.b, this->c - matrix.c, this->d - matrix.d, this->e - matrix.e,
             this->f - matrix.f, this->g - matrix.g, this->h - matrix.h, this->i - matrix.i };
}

toreador::math::Matrix3x3 toreador::math::Matrix3x3::operator*( float scalar )
{
    return { this->a * scalar, this->b * scalar, this->c * scalar, this->d * scalar, this->e * scalar,
             this->f * scalar, this->g * scalar, this->h * scalar, this->i * scalar };
    ;
}

toreador::math::Matrix3x3 toreador::math::Matrix3x3::operator*( toreador::math::Matrix3x3 matrix3X3 )
{

    float nA = ( ( this->a * matrix3X3.a ) + ( this->b * matrix3X3.d ) + ( this->c * matrix3X3.g ) );
    float nB = ( ( this->a * matrix3X3.b ) + ( this->b * matrix3X3.e ) + ( this->c * matrix3X3.h ) );
    float nC = ( ( this->a * matrix3X3.c ) + ( this->b * matrix3X3.f ) + ( this->c * matrix3X3.i ) );

    float nD = ( ( this->d * matrix3X3.a ) + ( this->e * matrix3X3.d ) + ( this->f * matrix3X3.g ) );
    float nE = ( ( this->d * matrix3X3.b ) + ( this->e * matrix3X3.e ) + ( this->f * matrix3X3.h ) );
    float nF = ( ( this->d * matrix3X3.c ) + ( this->e * matrix3X3.f ) + ( this->f * matrix3X3.i ) );

    float nG = ( ( this->g * matrix3X3.a ) + ( this->h * matrix3X3.d ) + ( this->i * matrix3X3.g ) );
    float nH = ( ( this->g * matrix3X3.b ) + ( this->h * matrix3X3.e ) + ( this->i * matrix3X3.h ) );
    float nI = ( ( this->g * matrix3X3.c ) + ( this->h * matrix3X3.f ) + ( this->i * matrix3X3.i ) );

    return { nA, nB, nC, nD, nE, nF, nG, nH, nI };
}
toreador::math::Matrix3x3 toreador::math::Matrix3x3::operator/( float scalar )
{
    return { this->a / scalar, this->b / scalar, this->c / scalar, this->d / scalar, this->e / scalar,
             this->f / scalar, this->g / scalar, this->h / scalar, this->i / scalar };
}

toreador::math::Matrix3x3 toreador::math::Matrix3x3::invert() const
{
    return { this->a * -1, this->b * -1, this->c * -1, this->d * -1, this->e * -1,
             this->f * -1, this->g * -1, this->h * -1, this->i * -1 };
}

std::vector<float> toreador::math::Matrix3x3::toArray() const
{
    std::vector<float> matrix{};
    matrix.insert( matrix.end(), this->a );
    matrix.insert( matrix.end(), this->b );
    matrix.insert( matrix.end(), this->c );
    matrix.insert( matrix.end(), this->d );
    matrix.insert( matrix.end(), this->e );
    matrix.insert( matrix.end(), this->f );
    matrix.insert( matrix.end(), this->g );
    matrix.insert( matrix.end(), this->h );
    matrix.insert( matrix.end(), this->i );

    return matrix;
}

float toreador::math::Matrix3x3::determinant() const
{
    return ( this->i * -1 ) * ( this->b * this->g ) + ( this->b * this->f * this->g ) + ( this->c * this->d * this->h ) -
           ( this->a * this->f * this->h ) + this->i * ( this->a * this->e ) - ( this->c * this->g * this->e );
}

float toreador::math::Matrix3x3::trace() const
{
    return this->a * this->e * this->i;
}