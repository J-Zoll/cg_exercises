/// @ref core
/// @file glm/detail/type_int.hpp

#pragma once

#include "setup.hpp"
#if GLM_HAS_MAKE_SIGNED
#	include <type_traits>
#endif

#if GLM_HAS_EXTENDED_INTEGER_TYPE
#	include <cstdint>
#endif

namespace glm{
namespace detail
{
#	if GLM_HAS_EXTENDED_INTEGER_TYPE
		typedef std::int8_t					int8;
		typedef std::int16_t				int16;
		typedef std::int32_t				int32;
		typedef std::int64_t				int64;

		typedef std::uint8_t				uint8;
		typedef std::uint16_t				uint16;
		typedef std::uint32_t				uint32;
		typedef std::uint64_t				uint64;
#	else
#		if(defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) // C99 detected, 64 bit types available
			typedef int64_t					sint64;
			typedef uint64_t				uint64;

#		elif GLM_COMPILER & GLM_COMPILER_VC
			typedef signed __int64			sint64;
			typedef unsigned __int64		uint64;

#		elif GLM_COMPILER & GLM_COMPILER_GCC
#			pragma GCC diagnostic ignored "-Wlong-long"
			__extension__ typedef signed long long		sint64;
			__extension__ typedef unsigned long long	uint64;

#		elif (GLM_COMPILER & GLM_COMPILER_CLANG)
#			pragma clang diagnostic ignored "-Wc++11-long-long"
			typedef signed long	long		sint64;
			typedef unsigned long long		uint64;

#		else//unknown compiler
			typedef signed long	long		sint64;
			typedef unsigned long long		uint64;
#		endif//GLM_COMPILER

		typedef signed char					int8;
		typedef signed short				int16;
		typedef signed int					int32;
		typedef sint64						int64;

		typedef unsigned char				uint8;
		typedef unsigned short				uint16;
		typedef unsigned int				uint32;
		typedef uint64						uint64;
#endif//

	typedef signed int						lowp_int_t;
	typedef signed int						mediump_int_t;
	typedef signed int						highp_int_t;

	typedef unsigned int					lowp_uint_t;
	typedef unsigned int					mediump_uint_t;
	typedef unsigned int					highp_uint_t;

#	if GLM_HAS_MAKE_SIGNED
		using std::make_signed;
		using std::make_unsigned;

#	else//GLM_HAS_MAKE_SIGNED
		template<typename genType>
		struct make_signed
		{};

		template<>
		struct make_signed<char>
		{
			typedef char type;
		};

		template<>
		struct make_signed<short>
		{
			typedef short type;
		};

		template<>
		struct make_signed<int>
		{
			typedef int type;
		};

		template<>
		struct make_signed<long>
		{
			typedef long type;
		};

		template<>
		struct make_signed<unsigned char>
		{
			typedef char type;
		};

		template<>
		struct make_signed<unsigned short>
		{
			typedef short type;
		};

		template<>
		struct make_signed<unsigned int>
		{
			typedef int type;
		};

		template<>
		struct make_signed<unsigned long>
		{
			typedef long type;
		};

		template<typename genType>
		struct make_unsigned
		{};

		template<>
		struct make_unsigned<char>
		{
			typedef unsigned char type;
		};

		template<>
		struct make_unsigned<short>
		{
			typedef unsigned short type;
		};

		template<>
		struct make_unsigned<int>
		{
			typedef unsigned int type;
		};

		template<>
		struct make_unsigned<long>
		{
			typedef unsigned long type;
		};

		template<>
		struct make_unsigned<unsigned char>
		{
			typedef unsigned char type;
		};

		template<>
		struct make_unsigned<unsigned short>
		{
			typedef unsigned short type;
		};

		template<>
		struct make_unsigned<unsigned int>
		{
			typedef unsigned int type;
		};

		template<>
		struct make_unsigned<unsigned long>
		{
			typedef unsigned long type;
		};

		template<>
		struct make_signed<long long>
		{
			typedef long long type;
		};

		template<>
		struct make_signed<unsigned long long>
		{
			typedef long long type;
		};

		template<>
		struct make_unsigned<long long>
		{
			typedef unsigned long long type;
		};

		template<>
		struct make_unsigned<unsigned long long>
		{
			typedef unsigned long long type;
		};
#	endif//GLM_HAS_MAKE_SIGNED
}//namespace detail

	typedef detail::int8					int8;
	typedef detail::int16					int16;
	typedef detail::int32					int32;
	typedef detail::int64					int64;

	typedef detail::uint8					uint8;
	typedef detail::uint16					uint16;
	typedef detail::uint32					uint32;
	typedef detail::uint64					uint64;

	/// @addtogroup core_precision
	/// @{

	/// Low qualifier signed integer.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.3 Integers</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef detail::lowp_int_t				lowp_int;

	/// Medium qualifier signed integer.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.3 Integers</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef detail::mediump_int_t			mediump_int;

	/// High qualifier signed integer.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.3 Integers</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef detail::highp_int_t				highp_int;

	/// Low qualifier unsigned integer.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.3 Integers</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef detail::lowp_uint_t				lowp_uint;

	/// Medium qualifier unsigned integer.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.3 Integers</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef detail::mediump_uint_t			mediump_uint;

	/// High qualifier unsigned integer.
	/// There is no guarantee on the actual qualifier.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.3 Integers</a>
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.7.2 Precision Qualifier</a>
	typedef detail::highp_uint_t			highp_uint;

#if(!defined(GLM_PRECISION_HIGHP_INT) && !defined(GLM_PRECISION_MEDIUMP_INT) && !defined(GLM_PRECISION_LOWP_INT))
	typedef mediump_int					int_t;
#elif(defined(GLM_PRECISION_HIGHP_INT) && !defined(GLM_PRECISION_MEDIUMP_INT) && !defined(GLM_PRECISION_LOWP_INT))
	typedef highp_int					int_t;
#elif(!defined(GLM_PRECISION_HIGHP_INT) && defined(GLM_PRECISION_MEDIUMP_INT) && !defined(GLM_PRECISION_LOWP_INT))
	typedef mediump_int					int_t;
#elif(!defined(GLM_PRECISION_HIGHP_INT) && !defined(GLM_PRECISION_MEDIUMP_INT) && defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_int					int_t;
#else
#	error "GLM error: multiple default precision requested for signed integer types"
#endif

#if(!defined(GLM_PRECISION_HIGHP_UINT) && !defined(GLM_PRECISION_MEDIUMP_UINT) && !defined(GLM_PRECISION_LOWP_UINT))
	typedef mediump_uint				uint_t;
#elif(defined(GLM_PRECISION_HIGHP_UINT) && !defined(GLM_PRECISION_MEDIUMP_UINT) && !defined(GLM_PRECISION_LOWP_UINT))
	typedef highp_uint					uint_t;
#elif(!defined(GLM_PRECISION_HIGHP_UINT) && defined(GLM_PRECISION_MEDIUMP_UINT) && !defined(GLM_PRECISION_LOWP_UINT))
	typedef mediump_uint				uint_t;
#elif(!defined(GLM_PRECISION_HIGHP_UINT) && !defined(GLM_PRECISION_MEDIUMP_UINT) && defined(GLM_PRECISION_LOWP_UINT))
	typedef lowp_uint					uint_t;
#else
#	error "GLM error: multiple default precision requested for unsigned integer types"
#endif

	/// Unsigned integer type.
	///
	/// @see <a href="http://www.opengl.org/registry/doc/GLSLangSpec.4.20.8.pdf">GLSL 4.20.8 specification, section 4.1.3 Integers</a>
	typedef unsigned int				uint;

	/// @}

////////////////////
// check type sizes
#ifndef GLM_STATIC_ASSERT_NULL
	GLM_STATIC_ASSERT(sizeof(glm::int8) == 1, "int8 size isn't 1 byte on this platform");
	GLM_STATIC_ASSERT(sizeof(glm::int16) == 2, "int16 size isn't 2 bytes on this platform");
	GLM_STATIC_ASSERT(sizeof(glm::int32) == 4, "int32 size isn't 4 bytes on this platform");
	GLM_STATIC_ASSERT(sizeof(glm::int64) == 8, "int64 size isn't 8 bytes on this platform");

	GLM_STATIC_ASSERT(sizeof(glm::uint8) == 1, "uint8 size isn't 1 byte on this platform");
	GLM_STATIC_ASSERT(sizeof(glm::uint16) == 2, "uint16 size isn't 2 bytes on this platform");
	GLM_STATIC_ASSERT(sizeof(glm::uint32) == 4, "uint32 size isn't 4 bytes on this platform");
	GLM_STATIC_ASSERT(sizeof(glm::uint64) == 8, "uint64 size isn't 8 bytes on this platform");
#endif//GLM_STATIC_ASSERT_NULL

}//namespace glm
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
