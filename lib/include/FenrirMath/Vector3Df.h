#ifndef VECTOR3DF_H
#define	VECTOR3DF_H

namespace FenrirMath {

	class Vector3Df {

	public:
		Vector3Df();
		Vector3Df(float x, float y, float z);
		virtual ~Vector3Df();

		void setPosition(float x, float y, float z);
		void setPosition(Vector3Df vec);
		void setX(float x);
		void setY(float y);
		void setZ(float z);

		Vector3Df getPosition();
		float getX();
		float getY();
		float getZ();

		Vector3Df operator +(const Vector3Df& vec);
		Vector3Df& operator +=(const Vector3Df& vec);
		Vector3Df operator -(const Vector3Df& vec);
		Vector3Df& operator -=(const Vector3Df& vec);
		float operator *(const Vector3Df& vec);
		Vector3Df operator *(const int& constant);
		Vector3Df operator *(const float& constant);

	protected:
		float x,y,z;

	};

}

#endif	/* VECTOR3DF_H */

