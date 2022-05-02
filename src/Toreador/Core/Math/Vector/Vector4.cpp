#include <Toreador/Core/Math/Vector/Vector4.hpp>
#include <cmath>


toreador::math::Vector4 toreador::math::Vector4::operator+( float scalar ) const
{
    return { this->x + scalar, this->y + scalar, this->z + scalar, this->w + scalar };
}

toreador::math::Vector4 toreador::math::Vector4::operator+( toreador::math::Vector4 other ) const
{
    return { this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w };
}

toreador::math::Vector4 toreador::math::Vector4::operator-( float scalar ) const
{
    return { this->x - scalar, this->y - scalar, this->z - scalar, this->w - scalar };
}

toreador::math::Vector4 toreador::math::Vector4::operator-( toreador::math::Vector4 other ) const
{
    return { this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w };
}

toreador::math::Vector4 toreador::math::Vector4::operator*( float scalar ) const
{
    return { this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar };
}

toreador::math::Vector4 toreador::math::Vector4::operator*( toreador::math::Vector4 other ) const
{
    return { this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w };
}

toreador::math::Vector4 toreador::math::Vector4::operator/( float scalar ) const
{
    return { this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar };
}

toreador::math::Vector4 toreador::math::Vector4::operator/( toreador::math::Vector4 other ) const
{
    return { this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w };
}

float toreador::math::Vector4::magnitude() const
{
    return std::sqrt( this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w ); // yes
}

float toreador::math::Vector4::inverseMagnitude() const
{
    return 1 / this->magnitude();
}

toreador::math::Vector4 toreador::math::Vector4::normalize() const
{
    float magnitude = this->magnitude();
    return this->operator/(magnitude);
}
