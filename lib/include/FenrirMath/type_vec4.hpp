#ifndef VEC4_H
#define	VEC4_H

namespace fenm {

	template <typename _T> class type_vec2;
	template <typename _T> class type_vec3;


	template <typename _T>
	class type_vec4 {

	public:
		type_vec4();
		type_vec4(_T x, _T y, _T z, _T _w);
		type_vec4(const type_vec2<_T>& v, _T z, _T _w);
		type_vec4(const type_vec3<_T>& v, _T _w);
		type_vec4(const type_vec4<_T>& v);
		virtual ~type_vec4();

		void setPosition(_T x, _T y, _T z, _T _w);
		void setPosition(const type_vec2<_T>& v, _T z, _T _w);
		void setPosition(const type_vec3<_T>& v, _T _w);
		void setPosition(const type_vec4<_T>& v);
		void setX(_T x);
		void setY(_T y);
		void setZ(_T z);
		void setW(_T w);

		type_vec4<_T> getPosition();
		
		_T x() const;
		_T y() const;
		_T z() const;
		_T w() const;

		type_vec2<_T> xy() const;
		type_vec2<_T> xz() const;
		type_vec2<_T> xw() const;
		type_vec2<_T> yz() const;
		type_vec2<_T> yw() const;
		type_vec2<_T> zw() const;

		type_vec3<_T> xyz() const;
		type_vec3<_T> xyw() const;
		type_vec3<_T> xzw() const;
		type_vec3<_T> yzw() const;

		type_vec4<_T> xyzw() const;

		type_vec4<_T> operator +(const type_vec4<_T>& v);
		type_vec4<_T>& operator +=(const type_vec4<_T>& v);
		type_vec4<_T> operator -(const type_vec4<_T>& v);
		type_vec4<_T>& operator -=(const type_vec4<_T>& v);
		type_vec4<_T> operator *(const type_vec4<_T>& v);
		type_vec4<_T>& operator *=(const type_vec4<_T>& v);
		type_vec4<_T> operator *(const long& constant);
		type_vec4<_T>& operator *=(const long& constant);
		type_vec4<_T> operator *(const double& constant);
		type_vec4<_T>& operator *=(const double& constant);
		bool operator ==(const type_vec4<_T>& v);
		bool operator !=(const type_vec4<_T>& v);

	protected:
		union {_T _x, _r, _s;};
		union {_T _y, _g, _t;};
		union {_T _z, _b, _p;};
		union {_T _w, _a, _q;};

	};

	template <typename _T> double length(type_vec4<_T> v);
	template <typename _T> double dot(type_vec4<_T> v);

}

#include "type_vec4.inc"

#endif	/* VEC4_H */

