/// @ref gtx_projection
/// @file glm/gtx/projection.inl

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType proj(genType const& x, genType const& Normal)
	{
		return glm::dot(x, Normal) / glm::dot(Normal, Normal) * Normal;
	}
}//namespace glm
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
