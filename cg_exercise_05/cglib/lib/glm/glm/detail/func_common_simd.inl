/// @ref core
/// @file glm/detail/func_common_simd.inl

#if GLM_ARCH & GLM_ARCH_SSE2_BIT

#include "../simd/common.h"

#include <immintrin.h>

namespace glm{
namespace detail
{
	template<qualifier Q>
	struct compute_abs_vector<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& v)
		{
			vec<4, float, Q> result;
			result.data = glm_vec4_abs(v.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_abs_vector<4, int, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, int, Q> call(vec<4, int, Q> const& v)
		{
			vec<4, int, Q> result;
			result.data = glm_ivec4_abs(v.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_floor<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& v)
		{
			vec<4, float, Q> result;
			result.data = glm_vec4_floor(v.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_ceil<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& v)
		{
			vec<4, float, Q> result;
			result.data = glm_vec4_ceil(v.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_fract<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& v)
		{
			vec<4, float, Q> result;
			result.data = glm_vec4_fract(v.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_round<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& v)
		{
			vec<4, float, Q> result;
			result.data = glm_vec4_round(v.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_mod<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& x, vec<4, float, Q> const& y)
		{
			vec<4, float, Q> result;
			result.data = glm_vec4_mod(x.data, y.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_min_vector<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& v1, vec<4, float, Q> const& v2)
		{
			vec<4, float, Q> result;
			result.data = _mm_min_ps(v1.data, v2.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_min_vector<4, int32, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, int32, Q> call(vec<4, int32, Q> const& v1, vec<4, int32, Q> const& v2)
		{
			vec<4, int32, Q> result;
			result.data = _mm_min_epi32(v1.data, v2.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_min_vector<4, uint32, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, int32, Q> call(vec<4, uint32, Q> const& v1, vec<4, uint32, Q> const& v2)
		{
			vec<4, uint32, Q> result;
			result.data = _mm_min_epu32(v1.data, v2.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_max_vector<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& v1, vec<4, float, Q> const& v2)
		{
			vec<4, float, Q> result;
			result.data = _mm_max_ps(v1.data, v2.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_max_vector<4, int32, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, int32, Q> call(vec<4, int32, Q> const& v1, vec<4, int32, Q> const& v2)
		{
			vec<4, int32, Q> result;
			result.data = _mm_max_epi32(v1.data, v2.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_max_vector<4, uint32, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, uint32, Q> call(vec<4, uint32, Q> const& v1, vec<4, uint32, Q> const& v2)
		{
			vec<4, uint32, Q> result;
			result.data = _mm_max_epu32(v1.data, v2.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_clamp_vector<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& x, vec<4, float, Q> const& minVal, vec<4, float, Q> const& maxVal)
		{
			vec<4, float, Q> result;
			result.data = _mm_min_ps(_mm_max_ps(x.data, minVal.data), maxVal.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_clamp_vector<4, int32, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, int32, Q> call(vec<4, int32, Q> const& x, vec<4, int32, Q> const& minVal, vec<4, int32, Q> const& maxVal)
		{
			vec<4, int32, Q> result;
			result.data = _mm_min_epi32(_mm_max_epi32(x.data, minVal.data), maxVal.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_clamp_vector<4, uint32, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, uint32, Q> call(vec<4, uint32, Q> const& x, vec<4, uint32, Q> const& minVal, vec<4, uint32, Q> const& maxVal)
		{
			vec<4, uint32, Q> result;
			result.data = _mm_min_epu32(_mm_max_epu32(x.data, minVal.data), maxVal.data);
			return result;
		}
	};

	template<qualifier Q>
	struct compute_mix_vector<4, float, bool, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& x, vec<4, float, Q> const& y, vec<4, bool, Q> const& a)
		{
			__m128i const Load = _mm_set_epi32(-static_cast<int>(a.w), -static_cast<int>(a.z), -static_cast<int>(a.y), -static_cast<int>(a.x));
			__m128 const Mask = _mm_castsi128_ps(Load);

			vec<4, float, Q> Result;
#			if 0 && GLM_ARCH & GLM_ARCH_AVX
				Result.data = _mm_blendv_ps(x.data, y.data, Mask);
#			else
				Result.data = _mm_or_ps(_mm_and_ps(Mask, y.data), _mm_andnot_ps(Mask, x.data));
#			endif
			return Result;
		}
	};
/* FIXME
	template<qualifier Q>
	struct compute_step_vector<float, Q, tvec4>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& edge, vec<4, float, Q> const& x)
		{
			vec<4, float, Q> Result;
			result.data = glm_vec4_step(edge.data, x.data);
			return result;
		}
	};
*/
	template<qualifier Q>
	struct compute_smoothstep_vector<4, float, Q, true>
	{
		GLM_FUNC_QUALIFIER static vec<4, float, Q> call(vec<4, float, Q> const& edge0, vec<4, float, Q> const& edge1, vec<4, float, Q> const& x)
		{
			vec<4, float, Q> Result;
			Result.data = glm_vec4_smoothstep(edge0.data, edge1.data, x.data);
			return Result;
		}
	};
}//namespace detail
}//namespace glm

#endif//GLM_ARCH & GLM_ARCH_SSE2_BIT
// CG_REVISION 96a4891075b8226ae4d98732875b35e3ec5e7bed
