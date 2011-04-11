#ifndef TYPE_MAT3_H
#define	TYPE_MAT3_H

namespace fenm {

	template <typename _T>
	class type_mat3 {

	public:
		type_mat3();
		type_mat3(_T* data);
		type_mat3(const type_vec3<_T>& v1, const type_vec3<_T>& v2, const type_vec3<_T>& v3);
		~type_mat3();

		_T operator ()(unsigned int col, unsigned int row) const;
		_T operator ()(unsigned int n) const;
		_T& operator [](unsigned int n);
		type_mat3<_T> operator *(const type_mat3<_T>& m);
		type_mat3<_T>& operator *=(const type_mat3<_T>& m);
		type_vec3<_T> operator *(const type_vec3<_T>& m);
		type_mat3<_T> operator *(const double& constant);
		type_mat3<_T>& operator *=(const double& constant);
		type_mat3<_T> operator *(const long long& constant);
		type_mat3<_T>& operator *=(const long long& constant);


	protected:
		_T data[9];

	};

	template <typename _T> type_mat3<_T> inverse(const type_mat3<_T>& m);
	template <typename _T> type_mat3<_T> transpose(const type_mat3<_T>& m);
	template <typename _T> inline double determinantInl(const type_mat3<_T>& m);
	template <typename _T> inline double determinant(const type_mat3<_T>& m);
	template <typename _T> type_mat3<_T> identityMatrix(const type_mat3<_T>& m);

}

#include "type_mat3.inc"

#endif	/* TYPE_MAT3_H */

