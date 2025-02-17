/// @ref gtx_polar_coordinates
/// @file glm/gtx/polar_coordinates.inl

namespace glm
{
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> polar
	(
		vec<3, T, Q> const& euclidean
	)
	{
		T const Length(length(euclidean));
		vec<3, T, Q> const tmp(euclidean / Length);
		T const xz_dist(sqrt(tmp.x * tmp.x + tmp.z * tmp.z));

		return vec<3, T, Q>(
			asin(tmp.y),	// latitude
			atan(tmp.x, tmp.z),		// longitude
			xz_dist);				// xz distance
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> euclidean
	(
		vec<2, T, Q> const& polar
	)
	{
		T const latitude(polar.x);
		T const longitude(polar.y);

		return vec<3, T, Q>(
			cos(latitude) * sin(longitude),
			sin(latitude),
			cos(latitude) * cos(longitude));
	}

}//namespace glm
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
