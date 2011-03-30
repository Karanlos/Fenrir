#ifndef TYPE_MAT4_H
#define	TYPE_MAT4_H

namespace fenm {

	template <typename _T>
	class type_mat4 {

	public:
		type_mat4();
		type_mat4(_T* data);
		type_mat4(const type_vec4<_T>& v1, const type_vec4<_T>& v2, const type_vec4<_T>& v3, const type_vec4<_T>& v4);
		~type_mat4();

		_T operator ()(unsigned int col, unsigned int row) const;
		_T operator ()(unsigned int n) const;
		_T& operator [](unsigned int n);
		type_mat4<_T> operator *(const type_mat4<_T>& m);
		type_mat4<_T>& operator *=(const type_mat4<_T>& m);
		type_vec4<_T> operator *(const type_vec4<_T>& m);
		type_mat4<_T> operator *(const double& constant);
		type_mat4<_T>& operator *=(const double& constant);
		type_mat4<_T> operator *(const long long& constant);
		type_mat4<_T>& operator *=(const long long& constant);


	protected:
		_T data[16];

	};

	template <typename _T> type_mat4<_T> inverse(const type_mat4<_T>& m);
	template <typename _T> type_mat4<_T> transpose(const type_mat4<_T>& m);
	template <typename _T> inline double determinantInl(const type_mat4<_T>& m);
	template <typename _T> double determinant(const type_mat4<_T>& m);
	template <typename _T> type_mat4<_T> identityMatrix(const type_mat4<_T>& m);

}

#include "type_mat4.inc"

#endif	/* TYPE_MAT4_H */

