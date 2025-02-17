/// @ref gtx_functions
/// @file glm/gtx/functions.inl

#include "../exponential.hpp"

namespace glm
{
	template<typename T>
	GLM_FUNC_QUALIFIER T gauss
	(
		T x,
		T ExpectedValue,
		T StandardDeviation
	)
	{
		return exp(-((x - ExpectedValue) * (x - ExpectedValue)) / (static_cast<T>(2) * StandardDeviation * StandardDeviation)) / (StandardDeviation * sqrt(static_cast<T>(6.28318530717958647692528676655900576)));
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER T gauss
	(
		vec<2, T, Q> const& Coord,
		vec<2, T, Q> const& ExpectedValue,
		vec<2, T, Q> const& StandardDeviation
	)
	{
		vec<2, T, Q> const Squared = ((Coord - ExpectedValue) * (Coord - ExpectedValue)) / (static_cast<T>(2) * StandardDeviation * StandardDeviation);
		return exp(-(Squared.x + Squared.y));
	}
}//namespace glm

// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
