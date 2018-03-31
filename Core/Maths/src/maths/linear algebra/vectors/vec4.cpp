#include "vec4.h"

namespace advent { namespace maths {

vec4::vec4()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->w = 0.0f;
	this->magnitude = 0.0f;
}

vec4::vec4(const float& x, const float& y, const float& z, const float& w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	calculateMagnitude();
}

//operations
vec4& vec4::add(const vec4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	calculateMagnitude();

	return *this;
}

vec4& vec4::subtract(const vec4& other)
{
	x -= other.x;
	y -= other.y;
	z += other.z;
	w -= other.w;
	calculateMagnitude();

	return *this;
}

vec4& vec4::multiply(const vec4& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	calculateMagnitude();

	return *this;
}

vec4& vec4::divide(const vec4& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	calculateMagnitude();

	return *this;
}

//operators
vec4& operator+ (vec4& left, const vec4& right)
{
	return left.add(right);
}

vec4& operator- (vec4& left, const vec4& right)
{
	return left.subtract(right);
}

vec4& operator* (vec4& left, const vec4& right)
{
	return left.multiply(right);
}

vec4& operator/ (vec4& left, const vec4& right)
{
	return left.divide(right);
}

vec4& vec4::operator+= (const vec4& other)
{
	return add(other);
}

vec4& vec4::operator-= (const vec4& other)
{
	return subtract(other);
}

vec4& vec4::operator*= (const vec4& other)
{
	return multiply(other);
}

vec4& vec4::operator/= (const vec4& other)
{
	return divide(other);
}

std::ostream& operator<< (std::ostream& stream, const vec4& vector)
{
	stream << "vec4: (" << vector.x << " , " << vector.y << " , " << vector.z << " , " << vector.w << ")\n";
	stream << "magnitude: " << vector.magnitude;
	return stream;
}

//utility functions
void vec4::calculateMagnitude()
{
	magnitude = sqrt(x*x + y*y);
}

void vec4::normalize()
{
	magnitude = 1;
}	
} }