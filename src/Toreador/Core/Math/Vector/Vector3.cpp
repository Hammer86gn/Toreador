#include <Toreador/Core/Math/Vector/Vector3.hpp>
#include <cmath>


toreador::math::Vector3 toreador::math::Vector3::operator+( float scalar ) const
{
    return { this->x + scalar, this->y + scalar, this->z + scalar };
}

toreador::math::Vector3 toreador::math::Vector3::operator+( toreador::math::Vector3 other ) const
{
    return { this->x + other.x, this->y + other.y, this->z + other.z };
}

toreador::math::Vector3 toreador::math::Vector3::operator-( float scalar ) const
{
    return { this->x - scalar, this->y - scalar, this->z - scalar };
}

toreador::math::Vector3 toreador::math::Vector3::operator-( toreador::math::Vector3 other ) const
{
    return { this->x - other.x, this->y - other.y, this->z - other.z };
}

toreador::math::Vector3 toreador::math::Vector3::operator*( float scalar ) const
{
    return { this->x * scalar, this->y * scalar, this->z * scalar };
}

toreador::math::Vector3 toreador::math::Vector3::operator*( toreador::math::Vector3 other ) const
{
    return { this->x * other.x, this->y * other.y, this->z * other.z };
}

toreador::math::Vector3 toreador::math::Vector3::operator/( float scalar ) const
{
    return { this->x / scalar, this->y / scalar, this->z / scalar };
}

toreador::math::Vector3 toreador::math::Vector3::operator/( toreador::math::Vector3 other ) const
{
    return { this->x / other.x, this->y / other.y, this->z / other.z };
}

float toreador::math::Vector3::magnitude() const
{
    return std::sqrt( this->x * this->x + this->y * this->y + this->z * this->z ); // yes
}

float toreador::math::Vector3::inverseMagnitude() const
{
    return 1 / this->magnitude();
}

toreador::math::Vector3 toreador::math::Vector3::normalize() const
{
    float magnitude = this->magnitude();
    return this->operator/(magnitude);
}
