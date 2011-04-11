#include "FenrirMath.hpp"

namespace fenm {

	template <typename _T>
	type_vec4<_T>::type_vec4() {
		_x = 0;
		_y = 0;
		_z = 0;
		_w = 0;
	}

	template <typename _T>
	type_vec4<_T>::type_vec4(_T x, _T y, _T z, _T w) {
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}

	template <typename _T>
	type_vec4<_T>::type_vec4(const type_vec2<_T>& v, _T z, _T w) {
		_x = v.x();
		_y = v.y();
		_z = z;
		_w = w;
	}

	template <typename _T>
	type_vec4<_T>::type_vec4(const type_vec3<_T>& v, _T w) {
		_x = v.x();
		_y = v.y();
		_z = v.z();
		_w = w;
	}

	template <typename _T>
	type_vec4<_T>::type_vec4(const type_vec4<_T>& v) {
		_x = v._x;
		_y = v._y;
		_z = v._z;
		_w = v._w;
	}

	template <typename _T>
	type_vec4<_T>::~type_vec4() {
		
	}

	template <typename _T>
	void type_vec4<_T>::setPosition(_T x, _T y, _T z, _T w) {
		_x = x;
		_y = y;
		_z = z;
		_w = w;
	}

	template <typename _T>
	void type_vec4<_T>::setPosition(const type_vec2<_T>& v, _T z, _T w) {
		_x = v.x();
		_y = v.y();
		_z = z;
		_w = w;
	}

	template <typename _T>
	void type_vec4<_T>::setPosition(const type_vec3<_T>& v, _T w) {
		_x = v.x();
		_y = v.y();
		_z = v.z();
		_w = w;
	}

	template <typename _T>
	void type_vec4<_T>::setPosition(const type_vec4<_T>& v) {
		_x = v._x;
		_y = v._y;
		_z = v._z;
		_w = v._w;
	}

	template <typename _T>
	void type_vec4<_T>::setX(_T x) {
		_x = x;
	}

	template <typename _T>
	void type_vec4<_T>::setY(_T y) {
		_y = y;
	}

	template <typename _T>
	void type_vec4<_T>::setZ(_T z) {
		_z = z;
	}

	template <typename _T>
	void type_vec4<_T>::setW(_T w) {
		_w = w;
	}

	template <typename _T>
	type_vec4<_T> type_vec4<_T>::getPosition() {
		return type_vec4<_T>(_x, _y, _z, _w);
	}

	template <typename _T>
	_T type_vec4<_T>::x() const {
		return _x;
	}

	template <typename _T>
	_T type_vec4<_T>::y() const {
		return _y;
	}

	template <typename _T>
	_T type_vec4<_T>::z() const {
		return _z;
	}

	template <typename _T>
	_T type_vec4<_T>::w() const {
		return _w;
	}

	template <typename _T>
	type_vec2<_T> type_vec4<_T>::xy() const {
		return type_vec2<_T>(_x, _y);
	}

	template <typename _T>
	type_vec2<_T> type_vec4<_T>::xz() const {
		return type_vec2<_T>(_x, _z);
	}

	template <typename _T>
	type_vec2<_T> type_vec4<_T>::xw() const {
		return type_vec2<_T>(_x, _w);
	}

	template <typename _T>
	type_vec2<_T> type_vec4<_T>::yz() const {
		return type_vec2<_T>(_y, _z);
	}

	template <typename _T>
	type_vec2<_T> type_vec4<_T>::yw() const {
		return type_vec2<_T>(_y, _w);
	}

	template <typename _T>
	type_vec2<_T> type_vec4<_T>::zw() const {
		return type_vec2<_T>(_z, _w);
	}

	template <typename _T>
	type_vec3<_T> type_vec4<_T>::xyz() const {
		return type_vec3<_T>(_z, _y, _z);
	}

	template <typename _T>
	type_vec3<_T> type_vec4<_T>::xyw() const {
		return type_vec3<_T>(_z, _y, _w);
	}

	template <typename _T>
	type_vec3<_T> type_vec4<_T>::xzw() const {
		return type_vec3<_T>(_x, _y, _w);
	}

	template <typename _T>
	type_vec3<_T> type_vec4<_T>::yzw() const {
		return type_vec3<_T>(_y, _z, _w);
	}

	template <typename _T>
	type_vec4<_T> type_vec4<_T>::xyzw() const {
		return *this;
	}

	template <typename _T>
	type_vec4<_T> type_vec4<_T>::operator +(const type_vec4<_T>& v) {
		return type_vec4<_T>(_x + v._x, _y + v._y, _z + v._z, _w + v._w);
	}

	template <typename _T>
	type_vec4<_T>& type_vec4<_T>::operator +=(const type_vec4<_T>& v) {
		_x += v._x;
		_y += v._y;
		_z += v._z;
		_w += v._w;
		return *this;
	}

	template <typename _T>
	type_vec4<_T> type_vec4<_T>::operator -(const type_vec4<_T>& v) {
		return type_vec4<_T>(_x - v._x, _y - v._y, _z - v._z, _w - v._w);
	}

	template <typename _T>
	type_vec4<_T>& type_vec4<_T>::operator -=(const type_vec4<_T>& v) {
		_x -= v._x;
		_y -= v._y;
		_z -= v._z;
		_w -= v._w;
		return *this;
	}

	template <typename _T>
	type_vec4<_T> type_vec4<_T>::operator *(const type_vec4<_T>& v) {
		return type_vec4<_T>(_x * v._x, _y * v._y, _z * v._z, _w * v._w);
	}

	template <typename _T>
	type_vec4<_T>& type_vec4<_T>::operator *=(const type_vec4<_T>& v) {
		_x *= v._x;
		_y *= v._y;
		_z *= v._z;
		_w *= v._w;

		return *this;
	}

	template <typename _T>
	type_vec4<_T> type_vec4<_T>::operator *(const long& constant) {
		return type_vec4(_x * constant, _y * constant+ _z * constant, _w * constant);
	}

	template <typename _T>
	type_vec4<_T>& type_vec4<_T>::operator *=(const long& constant) {
		_x *= constant;
		_y *= constant;
		_z *= constant;
		_w *= constant;
		return *this;
	}

	template <typename _T>
	type_vec4<_T> type_vec4<_T>::operator *(const double& constant) {
		return type_vec4(_x * constant, _y * constant+ _z * constant, _w * constant);
	}

	template <typename _T>
	type_vec4<_T>& type_vec4<_T>::operator *=(const double& constant) {
		_x *= constant;
		_y *= constant;
		_z *= constant;
		_w *= constant;
		return *this;
	}

	template <typename _T>
	bool type_vec4<_T>::operator ==(const type_vec4<_T>& v) {
		return (_x == v._x && _y == v._y && _z == v._z && _w == v._w);
	}

	template <typename _T>
	bool type_vec4<_T>::operator !=(const type_vec4<_T>& v) {
		return (_x != v._x || _y != v._y || _z != v._z || _w != v._w);
	}

	template <typename _T>
	_T length(type_vec4<_T> v) {
		return v.x() * v.x() + v.y() * v.y() + v.z() * v.z() + v.w() * v.w();
	}

}
