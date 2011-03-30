#include "FenrirMath.hpp"

namespace fenm {

	template <typename _T>
	type_mat3<_T>::type_mat3() {
		*this = identityMatrix(*this);
	}

	template <typename _T>
	type_mat3<_T>::type_mat3(_T* data) {
		for(int i = 0; i < 9; i++)
			this->data[i] = data[i];
	}

	template <typename _T>
	type_mat3<_T>::type_mat3(const type_vec3<_T>& v1, const type_vec3<_T>& v2, const type_vec3<_T>& v3) {
		data[0] = v1.x();
		data[1] = v1.y();
		data[2] = v1.z();

		data[3] = v2.x();
		data[4] = v2.y();
		data[5] = v2.z();

		data[6] = v3.x();
		data[7] = v3.y();
		data[8] = v3.z();
	}

	template <typename _T>
	type_mat3<_T>::~type_mat3() {
		
	}

	template <typename _T>
	_T type_mat3<_T>::operator ()(unsigned int col, unsigned int row) const {
		return data[col * 3 + row];
	}

	template <typename _T>
	_T type_mat3<_T>::operator ()(unsigned int n) const {
		return data[n];
	}

	template <typename _T>
	_T& type_mat3<_T>::operator [](unsigned int n) {
		return data[n];
	}

	template <typename _T>
	type_mat3<_T> type_mat3<_T>::operator *(const type_mat3<_T>& m) {
		type_mat3<_T> tempM;

		for(int x = 0; x < 3; x++)
			for(int y = 0; y < 3; y++)
				tempM[x * 3 + y] = m(x,0) * (*this)(0,y) + m(x,1) * (*this)(1,y) + m(x,2) * (*this)(2,y);

		return tempM;
	}

	template <typename _T>
	type_mat3<_T>& type_mat3<_T>::operator *=(const type_mat3<_T>& m) {
		type_mat3<_T> tempM;

		for(int x = 0; x < 3; x++)
			for(int y = 0; y < 3; y++)
				tempM[x * 3 + y] = m(x,0) * (*this)(0,y) + m(x,1) * (*this)(1,y) + m(x,2) * (*this)(2,y);

		*this = tempM;

		return *this;
	}

	template <typename _T>
	type_vec3<_T> type_mat3<_T>::operator *(const type_vec3<_T>& v) {
		return type_vec3<_T>(v.x() * data[0] + v.y() * data[3] + v.z() * data[6],
							v.x() * data[1] + v.y() * data[4] + v.z() * data[7],
							v.x() * data[2] + v.y() * data[5] + v.z() * data[8]);
	}

	template <typename _T>
	type_mat3<_T> type_mat3<_T>::operator *(const double& constant) {
		type_mat3<_T> tempM;

		for(int i = 0; i < 9; i++)
			tempM[i] = data[i] * constant;

		return tempM;

	}

	template <typename _T>
	type_mat3<_T>& type_mat3<_T>::operator *=(const double& constant) {

		for(int i = 0; i < 9; i++)
			data[i] *= constant;

		return *this;

	}

	template <typename _T>
	type_mat3<_T> type_mat3<_T>::operator *(const long long& constant) {
		type_mat3<_T> tempM;

		for(int i = 0; i < 9; i++)
			tempM[i] = data[i] * constant;

		return tempM;

	}

	template <typename _T>
	type_mat3<_T>& type_mat3<_T>::operator *=(const long long& constant) {

		for(int i = 0; i < 9; i++)
			data[i] *= constant;

		return *this;

	}

	template <typename _T>
	type_mat3<_T> identityMatrix(const type_mat3<_T>& m) {
		_T temp[] = {1,0,0,0,1,0,0,0,1};

		return type_mat3<_T>(temp);
	}

	template <typename _T>
	type_mat3<_T> inverse(const type_mat3<_T>& m) {
		double temp = determinant(m);

		type_mat3<_T> tempM;

		tempM[0] = (m(4) * m(8) - m(5) * m(7)) / temp;
		tempM[1] = (m(1) * m(8) - m(2) * m(7)) / -temp;
		tempM[2] = (m(1) * m(5) - m(2) * m(4)) / temp;

		tempM[3] = (m(3) * m(8) - m(2) * m(6)) / -temp;
		tempM[4] = (m(0) * m(8) - m(2) * m(6)) / temp;
		tempM[5] = (m(0) * m(5) - m(2) * m(3)) / -temp;

		tempM[6] = (m(3) * m(7) - m(4) * m(6)) / temp;
		tempM[7] = (m(0) * m(7) - m(1) * m(6)) / -temp;
		tempM[8] = (m(0) * m(4) - m(1) * m(3)) / temp;

		return tempM;

	}

	template <typename _T>
	type_mat3<_T> transpose(const type_mat3<_T>& m) {
		type_mat3<_T> tempM;

		for(int x = 0; x < 3; x++)
			for(int y = 0; y < 3; y++)
				tempM[x*3+y] = m(y,x);

		return tempM;

	}

	template <typename _T>
	double determinantInl(const type_mat3<_T>& m) {

		return m(0) * m(4) * m(8)
				+ m(3) * m(7) * m(2)
				+ m(6) * m(1) * m(5)
				- m(2) * m(4) * m(6)
				- m(5) * m(7) * m(0)
				- m(8) * m(1) * m(3);
	}

	template <typename _T>
	double determinant(const type_mat3<_T>& m) {

		return m(0) * m(4) * m(8)
				+ m(3) * m(7) * m(2)
				+ m(6) * m(1) * m(5)
				- m(2) * m(4) * m(6)
				- m(5) * m(7) * m(0)
				- m(8) * m(1) * m(3);
	}

}