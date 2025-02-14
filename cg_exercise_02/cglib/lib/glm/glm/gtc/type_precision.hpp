/// @ref gtc_type_precision
/// @file glm/gtc/type_precision.hpp
///
/// @see core (dependence)
/// @see gtc_quaternion (dependence)
///
/// @defgroup gtc_type_precision GLM_GTC_type_precision
/// @ingroup gtc
///
/// Include <glm/gtc/type_precision.hpp> to use the features of this extension.
///
/// Defines specific C++-based qualifier types.
///
/// @ref core_precision defines types based on GLSL's qualifier qualifiers. This
/// extension defines types based on explicitly-sized C++ data types.

#pragma once

// Dependency:
#include "../gtc/quaternion.hpp"
#include "../gtc/vec1.hpp"
#include "../vec2.hpp"
#include "../vec3.hpp"
#include "../vec4.hpp"
#include "../mat2x2.hpp"
#include "../mat2x3.hpp"
#include "../mat2x4.hpp"
#include "../mat3x2.hpp"
#include "../mat3x3.hpp"
#include "../mat3x4.hpp"
#include "../mat4x2.hpp"
#include "../mat4x3.hpp"
#include "../mat4x4.hpp"

#if GLM_MESSAGES == GLM_MESSAGES_ENABLED && !defined(GLM_EXT_INCLUDED)
#	pragma message("GLM: GLM_GTC_type_precision extension included")
#endif

namespace glm
{
	///////////////////////////
	// Signed int vector types

	/// @addtogroup gtc_type_precision
	/// @{

	/// Low qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 lowp_int8;

	/// Low qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 lowp_int16;

	/// Low qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 lowp_int32;

	/// Low qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 lowp_int64;

	/// Low qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 lowp_int8_t;

	/// Low qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 lowp_int16_t;

	/// Low qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 lowp_int32_t;

	/// Low qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 lowp_int64_t;

	/// Low qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 lowp_i8;

	/// Low qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 lowp_i16;

	/// Low qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 lowp_i32;

	/// Low qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 lowp_i64;

	/// Medium qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 mediump_int8;

	/// Medium qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 mediump_int16;

	/// Medium qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 mediump_int32;

	/// Medium qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 mediump_int64;

	/// Medium qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 mediump_int8_t;

	/// Medium qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 mediump_int16_t;

	/// Medium qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 mediump_int32_t;

	/// Medium qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 mediump_int64_t;

	/// Medium qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 mediump_i8;

	/// Medium qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 mediump_i16;

	/// Medium qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 mediump_i32;

	/// Medium qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 mediump_i64;

	/// High qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 highp_int8;

	/// High qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 highp_int16;

	/// High qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 highp_int32;

	/// High qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 highp_int64;

	/// High qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 highp_int8_t;

	/// High qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 highp_int16_t;

	/// 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 highp_int32_t;

	/// High qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 highp_int64_t;

	/// High qualifier 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 highp_i8;

	/// High qualifier 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 highp_i16;

	/// High qualifier 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 highp_i32;

	/// High qualifier 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 highp_i64;


	/// 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 int8;

	/// 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 int16;

	/// 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 int32;

	/// 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 int64;

#if GLM_HAS_EXTENDED_INTEGER_TYPE
	using std::int8_t;
	using std::int16_t;
	using std::int32_t;
	using std::int64_t;
#else
	/// 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 int8_t;

	/// 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 int16_t;

	/// 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 int32_t;

	/// 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 int64_t;
#endif

	/// 8 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int8 i8;

	/// 16 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int16 i16;

	/// 32 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int32 i32;

	/// 64 bit signed integer type.
	/// @see gtc_type_precision
	typedef detail::int64 i64;


	/// 8 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i8, defaultp> i8vec1;

	/// 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i8, defaultp> i8vec2;

	/// 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i8, defaultp> i8vec3;

	/// 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i8, defaultp> i8vec4;


	/// 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i16, defaultp> i16vec1;

	/// 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i16, defaultp> i16vec2;

	/// 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i16, defaultp> i16vec3;

	/// 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i16, defaultp> i16vec4;


	/// 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i32, defaultp> i32vec1;

	/// 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i32, defaultp> i32vec2;

	/// 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i32, defaultp> i32vec3;

	/// 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i32, defaultp> i32vec4;


	/// 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i64, defaultp> i64vec1;

	/// 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i64, defaultp> i64vec2;

	/// 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i64, defaultp> i64vec3;

	/// 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i64, defaultp> i64vec4;


	/////////////////////////////
	// Unsigned int vector types

	/// Low qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 lowp_uint8;

	/// Low qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 lowp_uint16;

	/// Low qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 lowp_uint32;

	/// Low qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 lowp_uint64;

	/// Low qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 lowp_uint8_t;

	/// Low qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 lowp_uint16_t;

	/// Low qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 lowp_uint32_t;

	/// Low qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 lowp_uint64_t;

	/// Low qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 lowp_u8;

	/// Low qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 lowp_u16;

	/// Low qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 lowp_u32;

	/// Low qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 lowp_u64;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 mediump_uint8;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 mediump_uint16;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 mediump_uint32;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 mediump_uint64;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 mediump_uint8_t;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 mediump_uint16_t;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 mediump_uint32_t;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 mediump_uint64_t;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 mediump_u8;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 mediump_u16;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 mediump_u32;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 mediump_u64;

	/// High qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 highp_uint8;

	/// High qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 highp_uint16;

	/// High qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 highp_uint32;

	/// High qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 highp_uint64;

	/// High qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 highp_uint8_t;

	/// High qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 highp_uint16_t;

	/// High qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 highp_uint32_t;

	/// High qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 highp_uint64_t;

	/// High qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 highp_u8;

	/// High qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 highp_u16;

	/// High qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 highp_u32;

	/// High qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 highp_u64;

	/// Default qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 uint8;

	/// Default qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 uint16;

	/// Default qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 uint32;

	/// Default qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 uint64;

#if GLM_HAS_EXTENDED_INTEGER_TYPE
	using std::uint8_t;
	using std::uint16_t;
	using std::uint32_t;
	using std::uint64_t;
#else
	/// Default qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 uint8_t;

	/// Default qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 uint16_t;

	/// Default qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 uint32_t;

	/// Default qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 uint64_t;
#endif

	/// Default qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 u8;

	/// Default qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 u16;

	/// Default qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 u32;

	/// Default qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 u64;



	/// Default qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u8, defaultp> u8vec1;

	/// Default qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u8, defaultp> u8vec2;

	/// Default qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u8, defaultp> u8vec3;

	/// Default qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u8, defaultp> u8vec4;


	/// Default qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u16, defaultp> u16vec1;

	/// Default qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u16, defaultp> u16vec2;

	/// Default qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u16, defaultp> u16vec3;

	/// Default qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u16, defaultp> u16vec4;


	/// Default qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u32, defaultp> u32vec1;

	/// Default qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u32, defaultp> u32vec2;

	/// Default qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u32, defaultp> u32vec3;

	/// Default qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u32, defaultp> u32vec4;


	/// Default qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u64, defaultp> u64vec1;

	/// Default qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u64, defaultp> u64vec2;

	/// Default qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u64, defaultp> u64vec3;

	/// Default qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u64, defaultp> u64vec4;


	//////////////////////
	// Float vector types

	/// 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 float32;

	/// 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 float32_t;

	/// 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float32 f32;

#	ifndef GLM_FORCE_SINGLE_ONLY
		/// 64 bit double-qualifier floating-point scalar.
		/// @see gtc_type_precision
		typedef detail::float64 float64;

		/// 64 bit double-qualifier floating-point scalar.
		/// @see gtc_type_precision
		typedef detail::float64 float64_t;

		/// 64 bit double-qualifier floating-point scalar.
		/// @see gtc_type_precision
		typedef float64 f64;
#	endif//GLM_FORCE_SINGLE_ONLY

	/// Single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, float, defaultp> fvec1;

	/// Single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, float, defaultp> fvec2;

	/// Single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, float, defaultp> fvec3;

	/// Single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, float, defaultp> fvec4;


	/// Single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, f32, defaultp> f32vec1;

	/// Single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, f32, defaultp> f32vec2;

	/// Single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, f32, defaultp> f32vec3;

	/// Single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, f32, defaultp> f32vec4;

#	ifndef GLM_FORCE_SINGLE_ONLY
		/// Double-qualifier floating-point vector of 1 component.
		/// @see gtc_type_precision
		typedef vec<1, f64, defaultp> f64vec1;

		/// Double-qualifier floating-point vector of 2 components.
		/// @see gtc_type_precision
		typedef vec<2, f64, defaultp> f64vec2;

		/// Double-qualifier floating-point vector of 3 components.
		/// @see gtc_type_precision
		typedef vec<3, f64, defaultp> f64vec3;

		/// Double-qualifier floating-point vector of 4 components.
		/// @see gtc_type_precision
		typedef vec<4, f64, defaultp> f64vec4;
#	endif//GLM_FORCE_SINGLE_ONLY


	//////////////////////
	// Float matrix types

	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32> fmat1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, defaultp> fmat2;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, defaultp> fmat3;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, defaultp> fmat4;


	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 fmat1x1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, defaultp> fmat2x2;

	/// Single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, defaultp> fmat2x3;

	/// Single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, defaultp> fmat2x4;

	/// Single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, defaultp> fmat3x2;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, defaultp> fmat3x3;

	/// Single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, defaultp> fmat3x4;

	/// Single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, defaultp> fmat4x2;

	/// Single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, defaultp> fmat4x3;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, defaultp> fmat4x4;


	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, defaultp> f32mat1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, defaultp> f32mat2;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, defaultp> f32mat3;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, defaultp> f32mat4;


	/// Single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 f32mat1x1;

	/// Single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, defaultp> f32mat2x2;

	/// Single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, defaultp> f32mat2x3;

	/// Single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, defaultp> f32mat2x4;

	/// Single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, defaultp> f32mat3x2;

	/// Single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, defaultp> f32mat3x3;

	/// Single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, defaultp> f32mat3x4;

	/// Single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, defaultp> f32mat4x2;

	/// Single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, defaultp> f32mat4x3;

	/// Single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, defaultp> f32mat4x4;


#	ifndef GLM_FORCE_SINGLE_ONLY

	/// Double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f64, defaultp> f64mat1;

	/// Double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f64, defaultp> f64mat2;

	/// Double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f64, defaultp> f64mat3;

	/// Double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f64, defaultp> f64mat4;


	/// Double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 f64mat1x1;

	/// Double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f64, defaultp> f64mat2x2;

	/// Double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f64, defaultp> f64mat2x3;

	/// Double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f64, defaultp> f64mat2x4;

	/// Double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f64, defaultp> f64mat3x2;

	/// Double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f64, defaultp> f64mat3x3;

	/// Double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f64, defaultp> f64mat3x4;

	/// Double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f64, defaultp> f64mat4x2;

	/// Double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f64, defaultp> f64mat4x3;

	/// Double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f64, defaultp> f64mat4x4;

#	endif//GLM_FORCE_SINGLE_ONLY

	//////////////////////////
	// Quaternion types

	/// Single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f32, defaultp> f32quat;

#	ifndef GLM_FORCE_SINGLE_ONLY

	/// Double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f64, defaultp> f64quat;

#	endif//GLM_FORCE_SINGLE_ONLY

	/// @}
}//namespace glm

#include "type_precision.inl"
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
