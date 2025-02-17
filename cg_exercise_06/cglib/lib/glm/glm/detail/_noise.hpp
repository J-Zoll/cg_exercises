/// @ref core
/// @file glm/detail/_noise.hpp

#pragma once

#include "../vec2.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"
#include "../common.hpp"

namespace glm{
namespace detail
{
	template<typename T>
	GLM_FUNC_QUALIFIER T mod289(T const& x)
	{
		return x - floor(x * (static_cast<T>(1.0) / static_cast<T>(289.0))) * static_cast<T>(289.0);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T permute(T const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> permute(vec<2, T, Q> const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> permute(vec<3, T, Q> const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> permute(vec<4, T, Q> const& x)
	{
		return mod289(((x * static_cast<T>(34)) + static_cast<T>(1)) * x);
	}

	template<typename T>
	GLM_FUNC_QUALIFIER T taylorInvSqrt(T const& r)
	{
		return T(1.79284291400159) - T(0.85373472095314) * r;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> taylorInvSqrt(vec<2, T, Q> const& r)
	{
		return T(1.79284291400159) - T(0.85373472095314) * r;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> taylorInvSqrt(vec<3, T, Q> const& r)
	{
		return T(1.79284291400159) - T(0.85373472095314) * r;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> taylorInvSqrt(vec<4, T, Q> const& r)
	{
		return T(1.79284291400159) - T(0.85373472095314) * r;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> fade(vec<2, T, Q> const& t)
	{
		return (t * t * t) * (t * (t * T(6) - T(15)) + T(10));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> fade(vec<3, T, Q> const& t)
	{
		return (t * t * t) * (t * (t * T(6) - T(15)) + T(10));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> fade(vec<4, T, Q> const& t)
	{
		return (t * t * t) * (t * (t * T(6) - T(15)) + T(10));
	}
}//namespace detail
}//namespace glm

// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
