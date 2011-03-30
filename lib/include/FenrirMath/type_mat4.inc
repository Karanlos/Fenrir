#include "FenrirMath.hpp"

namespace fenm {

	template <typename _T>
	type_mat4<_T>::type_mat4() {
		*this = identityMatrix(*this);
	}

	template <typename _T>
	type_mat4<_T>::type_mat4(_T* data) {
		for(int i = 0; i < 16; i++)
			this->data[i] = data[i];
	}

	template <typename _T>
	type_mat4<_T>::type_mat4(const type_vec4<_T>& v1, const type_vec4<_T>& v2, const type_vec4<_T>& v3, const type_vec4<_T>& v4) {
		data[0] = v1.x();
		data[1] = v1.y();
		data[2] = v1.z();
		data[3] = v1.w();

		data[4] = v2.x();
		data[5] = v2.y();
		data[6] = v2.z();
		data[7] = v2.w();

		data[8] = v3.x();
		data[9] = v3.y();
		data[10] = v3.z();
		data[11] = v3.w();

		data[12] = v4.x();
		data[13] = v4.y();
		data[14] = v4.z();
		data[15] = v4.w();
	}

	template <typename _T>
	type_mat4<_T>::~type_mat4() {
		
	}

	template <typename _T>
	_T type_mat4<_T>::operator ()(unsigned int col, unsigned int row) const {
		return data[col * 4 + row];
	}

	template <typename _T>
	_T type_mat4<_T>::operator ()(unsigned int n) const {
		return data[n];
	}

	template <typename _T>
	_T& type_mat4<_T>::operator [](unsigned int n) {
		return data[n];
	}

	template <typename _T>
	type_mat4<_T> type_mat4<_T>::operator *(const type_mat4<_T>& m) {
		type_mat4<_T> tempM;

		for(int x = 0; x < 4; x++)
			for(int y = 0; y < 4; y++)
				tempM[x * 4 + y] = m(x,0) * (*this)(0,y) + m(x,1) * (*this)(1,y) + m(x,2) * (*this)(2,y) + m(x,3) * (*this)(3,y);

		return tempM;
	}

	template <typename _T>
	type_vec4<_T> type_mat4<_T>::operator *(const type_vec4<_T>& v) {
		return type_vec4<_T>(v.x() * data[0] + v.y() * data[4] + v.z() * data[8] + v.w() * data[12],
							v.x() * data[1] + v.y() * data[5] + v.z() * data[9] + v.w() * data[13],
							v.x() * data[2] + v.y() * data[6] + v.z() * data[10] + v.w() * data[14],
							v.x() * data[3] + v.y() * data[7] + v.z() * data[11] + v.w() * data[15]);
	}

	template <typename _T>
	type_mat4<_T> type_mat4<_T>::operator *(const _T& constant) {
		type_mat4<_T> temp;

		for(int i = 0; i < 16; i++)
			temp[i] = data[i] * constant;

		return temp;
	}

	template <typename _T>
	type_mat4<_T> inverse(const type_mat4<_T>& m) {
		double temp = determinantInl(m);

		std::cout << "det: " << temp << std::endl;

		if((double)temp < 0.0000001d && (double)temp > -0.0000001d)
			return m;

		temp = 1 / temp;

		type_mat4<_T> tempM;

		tempM[0] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(5),m(6),m(7)),
												type_vec3<_T>(m(9),m(10),m(11)),
												type_vec3<_T>(m(13),m(14),m(15))));

		tempM[1] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),
												type_vec3<_T>(m(9),m(10),m(11)),
												type_vec3<_T>(m(13),m(14),m(15))));

		tempM[2] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),
												type_vec3<_T>(m(5),m(6),m(7)),
												type_vec3<_T>(m(13),m(14),m(15))));

		tempM[3] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),
												type_vec3<_T>(m(5),m(6),m(7)),
												type_vec3<_T>(m(9),m(10),m(11))));

		tempM[4] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(4),m(6),m(7)),
												type_vec3<_T>(m(8),m(10),m(11)),
												type_vec3<_T>(m(12),m(14),m(15))));

		tempM[5] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(2),m(3)),
												type_vec3<_T>(m(8),m(10),m(11)),
												type_vec3<_T>(m(12),m(14),m(15))));

		tempM[6] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(2),m(3)),
												type_vec3<_T>(m(4),m(6),m(7)),
												type_vec3<_T>(m(12),m(14),m(15))));

		tempM[7] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(2),m(3)),
												type_vec3<_T>(m(4),m(6),m(7)),
												type_vec3<_T>(m(8),m(10),m(11))));

		tempM[8] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(4),m(5),m(7)),
												type_vec3<_T>(m(8),m(9),m(11)),
												type_vec3<_T>(m(12),m(13),m(15))));

		tempM[9] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(1),m(3)),
												type_vec3<_T>(m(8),m(9),m(11)),
												type_vec3<_T>(m(12),m(14),m(15))));

		tempM[10] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(1),m(3)),
												type_vec3<_T>(m(4),m(5),m(7)),
												type_vec3<_T>(m(12),m(13),m(15))));

		tempM[11] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(1),m(3)),
												type_vec3<_T>(m(4),m(5),m(7)),
												type_vec3<_T>(m(8),m(9),m(11))));

		tempM[12] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(4),m(5),m(6)),
												type_vec3<_T>(m(8),m(9),m(10)),
												type_vec3<_T>(m(12),m(13),m(14))));

		tempM[13] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(1),m(2)),
												type_vec3<_T>(m(8),m(9),m(10)),
												type_vec3<_T>(m(12),m(13),m(14))));

		tempM[14] = -temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(1),m(2)),
												type_vec3<_T>(m(4),m(5),m(6)),
												type_vec3<_T>(m(12),m(13),m(14))));

		tempM[15] = temp * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(0),m(1),m(2)),
												type_vec3<_T>(m(4),m(5),m(6)),
												type_vec3<_T>(m(8),m(9),m(10))));

		return tempM;

	}

	template <typename _T>
	type_mat4<_T> transpose(const type_mat4<_T>& m) {
		type_mat4<_T> tempM;

		for(int x = 0; x < 4; x++)
			for(int y = 0; y < 4; y++)
				tempM[x*4+y] = m(y,x);

		return tempM;

	}

	template <typename _T>
	double determinantInl(const type_mat4<_T>& m) {
		return m(0) * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(5),m(6),m(7)),type_vec3<_T>(m(9),m(10),m(11)),type_vec3<_T>(m(13),m(14),m(15))))
			- m(4) * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),type_vec3<_T>(m(9),m(10),m(11)),type_vec3<_T>(m(13),m(14),m(15))))
			+ m(8) * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),type_vec3<_T>(m(5),m(6),m(7)),type_vec3<_T>(m(13),m(14),m(15))))
			- m(12) * determinantInl(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),type_vec3<_T>(m(5),m(6),m(7)),type_vec3<_T>(m(9),m(10),m(11))));

	}

	template <typename _T>
	double determinant(const type_mat4<_T>& m) {
		return m(0) * determinant(type_mat3<_T>(	type_vec3<_T>(m(5),m(6),m(7)),type_vec3<_T>(m(9),m(10),m(11)),type_vec3<_T>(m(13),m(14),m(15))))
			- m(4) * determinant(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),type_vec3<_T>(m(9),m(10),m(11)),type_vec3<_T>(m(13),m(14),m(15))))
			+ m(8) * determinant(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),type_vec3<_T>(m(5),m(6),m(7)),type_vec3<_T>(m(13),m(14),m(15))))
			- m(12) * determinant(type_mat3<_T>(	type_vec3<_T>(m(1),m(2),m(3)),type_vec3<_T>(m(5),m(6),m(7)),type_vec3<_T>(m(9),m(10),m(11))));
	}

	template <typename _T>
	type_mat4<_T> identityMatrix(const type_mat4<_T>& m) {
		_T temp[] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};

		return type_mat4<_T>(temp);
	}

}
