#ifndef VEC3_H
#define	VEC3_H

namespace fenm {

	template <typename _T> class type_vec2;

	template <typename _T>
	class type_vec3 {

	public:
		type_vec3();
		type_vec3(_T x, _T y, _T z);
		type_vec3(const type_vec2<_T>& v, _T z);
		type_vec3(const type_vec3<_T>& v);
		virtual ~type_vec3();

		void setPosition(_T x, _T y, _T z);
		void setPosition(const type_vec3<_T>& v);
		void setPosition(const type_vec2<_T>& v, _T z);
		void setX(_T x);
		void setY(_T y);
		void setZ(_T z);

		type_vec3<_T> getPosition();
		_T x() const;
		_T y() const;
		_T z() const;

		type_vec2<_T> xy() const;
		type_vec2<_T> xz() const;
		type_vec2<_T> yz() const;

		type_vec3<_T> operator +(const type_vec3<_T>& v);
		type_vec3<_T>& operator +=(const type_vec3<_T>& v);
		type_vec3<_T> operator -(const type_vec3<_T>& v);
		type_vec3<_T>& operator -=(const type_vec3<_T>& v);
		type_vec3<_T> operator *(const type_vec3<_T>& vec);
		type_vec3<_T>& operator *=(const type_vec3<_T>& vec);
		type_vec3<_T> operator *(const long long& constant);
		type_vec3<_T>& operator *=(const long long& constant);
		type_vec3<_T> operator *(const double& constant);
		type_vec3<_T>& operator *=(const double& constant);
		bool operator ==(const type_vec3<_T>& vec);
		bool operator !=(const type_vec3<_T>& vec);

	protected:
		_T _x, _y, _z;

	};

	template <typename _T> _T length(type_vec3<_T> v);

	template <typename _T> type_vec3<_T> crossP(type_vec3<_T> v1, type_vec3<_T> v2);

}

#include "type_vec3.inc"

#endif	/* VEC3_H */

