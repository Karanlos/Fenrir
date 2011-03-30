#include "FenrirMath.hpp"

namespace fenm {

	template <typename _T>
	type_mat2<_T>::type_mat2() {
		for(int i = 0; i < 4; i++)
			data[i] = 0;
	}

	template <typename _T>
	type_mat2<_T>::type_mat2(_T* data) {
		for(int i = 0; i < 4; i++)
			this->data[i] = data[i];
	}

	template <typename _T>
	type_mat2<_T>::~type_mat2() {
		
	}

	template <typename _T>
	type_mat2<_T>::type_mat2(const type_vec2<_T>& v1, const type_vec2<_T>& v2) {
		data[0] = v1.x();
		data[1] = v1.y();
		data[2] = v2.x();
		data[3] = v2.y();
	}

	template <typename _T>
	_T type_mat2<_T>::operator ()(unsigned int n) const {
		return data[n];
	}

	template <typename _T>
	_T type_mat2<_T>::operator ()(unsigned int col, unsigned int row) const {
		return data[2 * col + row];
	}

	template <typename _T>
	_T& type_mat2<_T>::operator [](unsigned int n) {
		return data[n];
	}

	template <typename _T>
	type_mat2<_T> type_mat2<_T>::operator *(const type_mat2<_T>& m) {
		type_mat2<_T> tempM;

		for(int x = 0; x < 2; x++)
			for(int y = 0; y < 2; y++)
				tempM[x * 2 + y] = m(x,0) * (*this)(0,y) + m(x,1) * (*this)(1,y);

		return tempM;
	}

	template <typename _T>
	type_mat2<_T>& type_mat2<_T>::operator *=(const type_mat2<_T>& m) {
		type_mat2<_T> tempM;

		for(int x = 0; x < 2; x++)
			for(int y = 0; y < 2; y++)
				tempM[x * 2 + y] = m(x,0) * (*this)(0,y) + m(x,1) * (*this)(1,y);

		*this = tempM;

		return *this;
	}

	template <typename _T>
	type_vec2<_T> type_mat2<_T>::operator *(const type_vec2<_T>& v) {
		return type_vec2<_T>(data[0] * v.x() + data[2] * v.y(), data[1] * v.x() + data[3] * v.y());
	}

	template <typename _T>
	type_mat2<_T> type_mat2<_T>::operator *(const double& constant) {
		type_mat2<_T> tempM;

		for(int i = 0; i < 4; i++)
			tempM[i] = data[i] * constant;

		return tempM;

	}

	template <typename _T>
	type_mat2<_T>& type_mat2<_T>::operator *=(const double& constant) {
		for(int i = 0; i < 4; i++)
			data[i] *= constant;

		return *this;

	}

	template <typename _T>
	type_mat2<_T> type_mat2<_T>::operator *(const long long& constant) {
		type_mat2<_T> tempM;

		for(int i = 0; i < 4; i++)
			tempM[i] = data[i] * constant;

		return tempM;

	}

	template <typename _T>
	type_mat2<_T>& type_mat2<_T>::operator *=(const long long& constant) {
		for(int i = 0; i < 4; i++)
			data[i] *= constant;

		return *this;

	}

	template <typename _T>
	type_mat2<_T> inverse(const type_mat2<_T>& m) {
		double temp = determinant(m);

		std::cout << "Det: " << temp << std::endl;

		type_mat2<_T> tempM;

		tempM[0] = m(3) / temp;
		tempM[1] = m(1) / -temp;
		tempM[2] = m(2) / -temp;
		tempM[3] = m(0) / temp;

		return tempM;

	}

	template <typename _T>
	type_mat2<_T> transpose(const type_mat2<_T>& m) {
		type_mat2<_T> temp;

		temp[1] = m(2);
		temp[2] = m(1);

		return temp;

	}

	template <typename _T>
	double determinantInl(const type_mat2<_T>& m) {
		return m(0) * m(3) - m(1) * m(2);
	}

	template <typename _T>
	double determinant(const type_mat2<_T>& m) {
		return m(0) * m(3) - m(1) * m(2);
	}

	template <typename _T>
	type_mat2<_T> identityMatrix(const type_mat2<_T>& m) {
		type_mat2<_T> temp;
		temp[0] = 1;
		temp[1] = 0;
		temp[2] = 0;
		temp[3] = 1;

		return temp;
	}

}