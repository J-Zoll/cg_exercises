/// @ref gtx_polar_coordinates
/// @file glm/gtx/polar_coordinates.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_polar_coordinates GLM_GTX_polar_coordinates
/// @ingroup gtx
///
/// Include <glm/gtx/polar_coordinates.hpp> to use the features of this extension.
///
/// Conversion from Euclidean space to polar space and revert.

#pragma once

// Dependency:
#include "../glm.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_polar_coordinates is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#endif

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_polar_coordinates extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_polar_coordinates
	/// @{

	/// Convert Euclidean to Polar coordinates, x is the xz distance, y, the latitude and z the longitude.
	///
	/// @see gtx_polar_coordinates
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> polar(
		vec<3, T, Q> const& euclidean);

	/// Convert Polar to Euclidean coordinates.
	///
	/// @see gtx_polar_coordinates
	template<typename T, qualifier Q>
	GLM_FUNC_DECL vec<3, T, Q> euclidean(
		vec<2, T, Q> const& polar);

	/// @}
}//namespace glm

#include "polar_coordinates.inl"
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
