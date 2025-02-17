/// @ref gtx_raw_data
/// @file glm/gtx/raw_data.hpp
///
/// @see core (dependence)
///
/// @defgroup gtx_raw_data GLM_GTX_raw_data
/// @ingroup gtx
///
/// Include <glm/gtx/raw_data.hpp> to use the features of this extension.
///
/// Projection of a vector to other one

#pragma once

// Dependencies
#include "../detail/setup.hpp"
#include "../detail/type_int.hpp"

#ifndef GLM_ENABLE_EXPERIMENTAL
#	error "GLM: GLM_GTX_raw_data is an experimental extension and may change in the future. Use #define GLM_ENABLE_EXPERIMENTAL before including it, if you really want to use it."
#endif

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTX_raw_data extension included")
#endif

namespace glm
{
	/// @addtogroup gtx_raw_data
	/// @{

	//! Type for byte numbers.
	//! From GLM_GTX_raw_data extension.
	typedef detail::uint8		byte;

	//! Type for word numbers.
	//! From GLM_GTX_raw_data extension.
	typedef detail::uint16		word;

	//! Type for dword numbers.
	//! From GLM_GTX_raw_data extension.
	typedef detail::uint32		dword;

	//! Type for qword numbers.
	//! From GLM_GTX_raw_data extension.
	typedef detail::uint64		qword;

	/// @}
}// namespace glm

#include "raw_data.inl"
// CG_REVISION 96a4891075b8226ae4d98732875b35e3ec5e7bed
