/// @ref gtx_matrix_interpolation
/// @file glm/gtx/matrix_interpolation.hpp

#include "../gtc/constants.hpp"

namespace glm
{
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER void axisAngle(mat<4, 4, T, Q> const& mat, vec<3, T, Q> & axis, T & angle)
	{
		T epsilon = static_cast<T>(0.01);
		T epsilon2 = static_cast<T>(0.1);

		if((abs(mat[1][0] - mat[0][1]) < epsilon) && (abs(mat[2][0] - mat[0][2]) < epsilon) && (abs(mat[2][1] - mat[1][2]) < epsilon))
		{
			if ((abs(mat[1][0] + mat[0][1]) < epsilon2) && (abs(mat[2][0] + mat[0][2]) < epsilon2) && (abs(mat[2][1] + mat[1][2]) < epsilon2) && (abs(mat[0][0] + mat[1][1] + mat[2][2] - static_cast<T>(3.0)) < epsilon2))
			{
				angle = static_cast<T>(0.0);
				axis.x = static_cast<T>(1.0);
				axis.y = static_cast<T>(0.0);
				axis.z = static_cast<T>(0.0);
				return;
			}
			angle = static_cast<T>(3.1415926535897932384626433832795);
			T xx = (mat[0][0] + static_cast<T>(1.0)) * static_cast<T>(0.5);
			T yy = (mat[1][1] + static_cast<T>(1.0)) * static_cast<T>(0.5);
			T zz = (mat[2][2] + static_cast<T>(1.0)) * static_cast<T>(0.5);
			T xy = (mat[1][0] + mat[0][1]) * static_cast<T>(0.25);
			T xz = (mat[2][0] + mat[0][2]) * static_cast<T>(0.25);
			T yz = (mat[2][1] + mat[1][2]) * static_cast<T>(0.25);
			if((xx > yy) && (xx > zz))
			{
				if(xx < epsilon)
				{
					axis.x = static_cast<T>(0.0);
					axis.y = static_cast<T>(0.7071);
					axis.z = static_cast<T>(0.7071);
				}
				else
				{
					axis.x = sqrt(xx);
					axis.y = xy / axis.x;
					axis.z = xz / axis.x;
				}
			}
			else if (yy > zz)
			{
				if(yy < epsilon)
				{
					axis.x = static_cast<T>(0.7071);
					axis.y = static_cast<T>(0.0);
					axis.z = static_cast<T>(0.7071);
				}
				else
				{
					axis.y = sqrt(yy);
					axis.x = xy / axis.y;
					axis.z = yz / axis.y;
				}
			}
			else
			{
				if (zz < epsilon)
				{
					axis.x = static_cast<T>(0.7071);
					axis.y = static_cast<T>(0.7071);
					axis.z = static_cast<T>(0.0);
				}
				else
				{
					axis.z = sqrt(zz);
					axis.x = xz / axis.z;
					axis.y = yz / axis.z;
				}
			}
			return;
		}
		T s = sqrt((mat[2][1] - mat[1][2]) * (mat[2][1] - mat[1][2]) + (mat[2][0] - mat[0][2]) * (mat[2][0] - mat[0][2]) + (mat[1][0] - mat[0][1]) * (mat[1][0] - mat[0][1]));
		if (glm::abs(s) < T(0.001))
			s = static_cast<T>(1);
		T const angleCos = (mat[0][0] + mat[1][1] + mat[2][2] - static_cast<T>(1)) * static_cast<T>(0.5);
		if(angleCos - static_cast<T>(1) < epsilon)
			angle = pi<T>() * static_cast<T>(0.25);
		else
			angle = acos(angleCos);
		axis.x = (mat[1][2] - mat[2][1]) / s;
		axis.y = (mat[2][0] - mat[0][2]) / s;
		axis.z = (mat[0][1] - mat[1][0]) / s;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> axisAngleMatrix(vec<3, T, Q> const& axis, T const angle)
	{
		T c = cos(angle);
		T s = sin(angle);
		T t = static_cast<T>(1) - c;
		vec<3, T, Q> n = normalize(axis);

		return mat<4, 4, T, Q>(
			t * n.x * n.x + c,          t * n.x * n.y + n.z * s,    t * n.x * n.z - n.y * s,    static_cast<T>(0.0),
			t * n.x * n.y - n.z * s,    t * n.y * n.y + c,          t * n.y * n.z + n.x * s,    static_cast<T>(0.0),
			t * n.x * n.z + n.y * s,    t * n.y * n.z - n.x * s,    t * n.z * n.z + c,          static_cast<T>(0.0),
			static_cast<T>(0.0),        static_cast<T>(0.0),        static_cast<T>(0.0),        static_cast<T>(1.0));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> extractMatrixRotation(mat<4, 4, T, Q> const& m)
	{
		return mat<4, 4, T, Q>(
			m[0][0], m[0][1], m[0][2], static_cast<T>(0.0),
			m[1][0], m[1][1], m[1][2], static_cast<T>(0.0),
			m[2][0], m[2][1], m[2][2], static_cast<T>(0.0),
			static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(1.0));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> interpolate(mat<4, 4, T, Q> const& m1, mat<4, 4, T, Q> const& m2, T const delta)
	{
		mat<4, 4, T, Q> m1rot = extractMatrixRotation(m1);
		mat<4, 4, T, Q> dltRotation = m2 * transpose(m1rot);
		vec<3, T, Q> dltAxis;
		T dltAngle;
		axisAngle(dltRotation, dltAxis, dltAngle);
		mat<4, 4, T, Q> out = axisAngleMatrix(dltAxis, dltAngle * delta) * m1rot;
		out[3][0] = m1[3][0] + delta * (m2[3][0] - m1[3][0]);
		out[3][1] = m1[3][1] + delta * (m2[3][1] - m1[3][1]);
		out[3][2] = m1[3][2] + delta * (m2[3][2] - m1[3][2]);
		return out;
	}
}//namespace glm
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
