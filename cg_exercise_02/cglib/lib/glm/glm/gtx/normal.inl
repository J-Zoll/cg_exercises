/// @ref gtx_normal
/// @file glm/gtx/normal.inl

namespace glm
{
	template<typename T, qualifier Q>
	GLM_FUNC_QUALIFIER vec<3, T, Q> triangleNormal
	(
		vec<3, T, Q> const& p1,
		vec<3, T, Q> const& p2,
		vec<3, T, Q> const& p3
	)
	{
		return normalize(cross(p1 - p2, p1 - p3));
	}
}//namespace glm
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
