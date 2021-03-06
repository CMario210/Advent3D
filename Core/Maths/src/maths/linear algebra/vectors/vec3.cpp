#include "vec3.h"

namespace advent { namespace maths {

//constructors
vec3::vec3()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

vec3::vec3(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

//operations
vec3& vec3::add(const vec3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

vec3& vec3::subtract(const vec3& other)
{
	x -= other.x;
	y -= other.y;
	z += other.z;

	return *this;
}

vec3& vec3::multiply(const vec3& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;

	return *this;
}

vec3& vec3::divide(const vec3& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;

	return *this;
}

//operators
vec3& operator+ (vec3& left, const vec3& right)
{
	return left.add(right);
}

vec3& operator- (vec3& left, const vec3& right)
{
	return left.subtract(right);
}

vec3& operator* (vec3& left, const vec3& right)
{
	return left.multiply(right);
}

vec3& operator/ (vec3& left, const vec3& right)
{
	return left.divide(right);
}

vec3& vec3::operator+= (const vec3& other)
{
	return add(other);
}

vec3& vec3::operator-= (const vec3& other)
{
	return subtract(other);
}

vec3& vec3::operator*= (const vec3& other)
{
	return multiply(other);
}

vec3& vec3::operator/= (const vec3& other)
{
	return divide(other);
}

std::ostream& operator<< (std::ostream& stream, const vec3& vector)
{
	stream << "vec3: (" << vector.x << " , " << vector.y << " , " << vector.z << ")\n";
	return stream;
}

} }