/// @ref gtx_extend
/// @file glm/gtx/extend.inl

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType extend
	(
		genType const& Origin,
		genType const& Source,
		genType const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<2, T, Q> extend
	(
		vec<2, T, Q> const& Origin,
		vec<2, T, Q> const& Source,
		T const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> extend
	(
		vec<3, T, Q> const& Origin,
		vec<3, T, Q> const& Source,
		T const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}

	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<4, T, Q> extend
	(
		vec<4, T, Q> const& Origin,
		vec<4, T, Q> const& Source,
		T const& Distance
	)
	{
		return Origin + (Source - Origin) * Distance;
	}
}//namespace glm
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
