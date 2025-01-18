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
// CG_REVISION 96a4891075b8226ae4d98732875b35e3ec5e7bed
