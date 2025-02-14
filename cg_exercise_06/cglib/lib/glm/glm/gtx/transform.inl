/// @ref gtx_transform
/// @file glm/gtx/transform.inl

namespace glm
{
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> translate(vec<3, T, Q> const& v)
	{
		return translate(mat<4, 4, T, Q>(static_cast<T>(1)), v);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> rotate(T angle, vec<3, T, Q> const& v)
	{
		return rotate(mat<4, 4, T, Q>(static_cast<T>(1)), angle, v);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER mat<4, 4, T, Q> scale(vec<3, T, Q> const& v)
	{
		return scale(mat<4, 4, T, Q>(static_cast<T>(1)), v);
	}

}//namespace glm
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
