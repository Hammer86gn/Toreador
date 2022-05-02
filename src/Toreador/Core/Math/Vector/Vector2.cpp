#include <Toreador/Core/Math/Vector/Vector2.hpp>
#include <cmath>


toreador::math::Vector2 toreador::math::Vector2::operator+( float scalar ) const
{
    return { this->x + scalar, this->y + scalar };
}

toreador::math::Vector2 toreador::math::Vector2::operator+( toreador::math::Vector2 other ) const
{
    return { this->x + other.x, this->y + other.y };
}

toreador::math::Vector2 toreador::math::Vector2::operator-( float scalar ) const
{
    return { this->x - scalar, this->y - scalar };
}

toreador::math::Vector2 toreador::math::Vector2::operator-( toreador::math::Vector2 other ) const
{
    return { this->x - other.x, this->y - other.y };
}

toreador::math::Vector2 toreador::math::Vector2::operator*( float scalar ) const
{
    return { this->x * scalar, this->y * scalar };
}

toreador::math::Vector2 toreador::math::Vector2::operator*( toreador::math::Vector2 other ) const
{
    return { this->x * other.x, this->y * other.y };
}

toreador::math::Vector2 toreador::math::Vector2::operator/( float scalar ) const
{
    return { this->x / scalar, this->y / scalar };
}

toreador::math::Vector2 toreador::math::Vector2::operator/( toreador::math::Vector2 other ) const
{
    return { this->x / other.x, this->y / other.y };
}

float toreador::math::Vector2::magnitude() const
{
    return std::sqrt( this->x * this->x + this->y * this->y );
}

float toreador::math::Vector2::inverseMagnitude() const
{
    return 1 / this->magnitude();
}

toreador::math::Vector2 toreador::math::Vector2::normalize() const
{
    float magnitude = this->magnitude();
    return this->operator/(magnitude);
}
