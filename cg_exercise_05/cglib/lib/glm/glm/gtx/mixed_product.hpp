/// @ref gtx_mixed_product
/// @file glm/gtx/mixed_product.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_mixed_product GLM_GTX_mixed_producte
/// @ingroup gtx
///
/// Include <glm/gtx/mixed_product.hpp> to use the features of this extension.
///
/// Mixed product of 3 vectors.

#pragma once

// Dependency:
#include "../glm.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_mixed_product is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#endif

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_mixed_product extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_mixed_product
	/// @{

	/// @brief Mixed product of 3 vectors (from GLM_GTX_mixed_product extension)
	template<typename T, qualifier Q>
	GLM_FUNC_DECL T mixedProduct(
		vec<3, T, Q> const& v1,
		vec<3, T, Q> const& v2,
		vec<3, T, Q> const& v3);

	/// @}
}// namespace glm

#include "mixed_product.inl"
// CG_REVISION 96a4891075b8226ae4d98732875b35e3ec5e7bed
