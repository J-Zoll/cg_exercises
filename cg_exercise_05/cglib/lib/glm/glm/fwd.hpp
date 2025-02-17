/// @ref core
/// @file glm/fwd.hpp

#include "detail/setup.hpp"

#pragma once

#include "detail/type_int.hpp"
#include "detail/type_float.hpp"
#include "detail/type_vec.hpp"
#include "detail/type_mat.hpp"

//////////////////////
// GLM_GTC_quaternion
namespace glm
{
	template<typename T, qualifier Q> struct tquat;

	/// Quaternion of low single-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef tquat<float, lowp>		lowp_quat;

	/// Quaternion of medium single-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef tquat<float, mediump>	mediump_quat;

	/// Quaternion of high single-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef tquat<float, highp>		highp_quat;

#if(defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	typedef highp_quat			quat;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	typedef mediump_quat		quat;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && defined(GLM_PRECISION_LOWP_FLOAT))
	typedef lowp_quat			quat;
#elif(!defined(GLM_PRECISION_HIGHP_FLOAT) && !defined(GLM_PRECISION_MEDIUMP_FLOAT) && !defined(GLM_PRECISION_LOWP_FLOAT))
	/// Quaternion of default single-qualifier floating-point numbers.
	typedef highp_quat			quat;
#endif

	/// Quaternion of low single-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef lowp_quat			lowp_fquat;

	/// Quaternion of medium single-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef mediump_quat		mediump_fquat;

	/// Quaternion of high single-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef highp_quat			highp_fquat;

	/// Quaternion of default single-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef quat				fquat;


	/// Quaternion of low double-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef tquat<double, lowp>		lowp_dquat;

	/// Quaternion of medium double-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef tquat<double, mediump>	mediump_dquat;

	/// Quaternion of high double-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef tquat<double, highp>	highp_dquat;

#if(defined(GLM_PRECISION_HIGHP_DOUBLE) && !defined(GLM_PRECISION_MEDIUMP_DOUBLE) && !defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef highp_dquat			dquat;
#elif(!defined(GLM_PRECISION_HIGHP_DOUBLE) && defined(GLM_PRECISION_MEDIUMP_DOUBLE) && !defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef mediump_dquat		dquat;
#elif(!defined(GLM_PRECISION_HIGHP_DOUBLE) && !defined(GLM_PRECISION_MEDIUMP_DOUBLE) && defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef lowp_dquat			dquat;
#elif(!defined(GLM_PRECISION_HIGHP_DOUBLE) && !defined(GLM_PRECISION_MEDIUMP_DOUBLE) && !defined(GLM_PRECISION_LOWP_DOUBLE))
	/// Quaternion of default double-qualifier floating-point numbers.
	///
	/// @see gtc_quaternion
	typedef highp_dquat			dquat;
#endif

}//namespace glm

//////////////////////
// GLM_GTC_precision
namespace glm
{
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



	/// Low qualifier 8 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i8, lowp> lowp_i8vec1;

	/// Low qualifier 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i8, lowp> lowp_i8vec2;

	/// Low qualifier 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i8, lowp> lowp_i8vec3;

	/// Low qualifier 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i8, lowp> lowp_i8vec4;


	/// Medium qualifier 8 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i8, mediump> mediump_i8vec1;

	/// Medium qualifier 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i8, mediump> mediump_i8vec2;

	/// Medium qualifier 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i8, mediump> mediump_i8vec3;

	/// Medium qualifier 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i8, mediump> mediump_i8vec4;


	/// High qualifier 8 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i8, highp> highp_i8vec1;

	/// High qualifier 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i8, highp> highp_i8vec2;

	/// High qualifier 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i8, highp> highp_i8vec3;

	/// High qualifier 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i8, highp> highp_i8vec4;

#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_i8vec1				i8vec1;
	typedef lowp_i8vec2				i8vec2;
	typedef lowp_i8vec3				i8vec3;
	typedef lowp_i8vec4				i8vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_i8vec1			i8vec1;
	typedef mediump_i8vec2			i8vec2;
	typedef mediump_i8vec3			i8vec3;
	typedef mediump_i8vec4			i8vec4;
#else
	/// Default qualifier 8 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef highp_i8vec1			i8vec1;

	/// Default qualifier 8 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_i8vec2			i8vec2;

	/// Default qualifier 8 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_i8vec3			i8vec3;

	/// Default qualifier 8 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_i8vec4			i8vec4;
#endif


	/// Low qualifier 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i16, lowp>		lowp_i16vec1;

	/// Low qualifier 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i16, lowp>		lowp_i16vec2;

	/// Low qualifier 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i16, lowp>		lowp_i16vec3;

	/// Low qualifier 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i16, lowp>		lowp_i16vec4;


	/// Medium qualifier 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i16, mediump>		mediump_i16vec1;

	/// Medium qualifier 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i16, mediump>		mediump_i16vec2;

	/// Medium qualifier 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i16, mediump>		mediump_i16vec3;

	/// Medium qualifier 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i16, mediump>		mediump_i16vec4;


	/// High qualifier 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i16, highp>		highp_i16vec1;

	/// High qualifier 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i16, highp>		highp_i16vec2;

	/// High qualifier 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i16, highp>		highp_i16vec3;

	/// High qualifier 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i16, highp>		highp_i16vec4;


#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_i16vec1			i16vec1;
	typedef lowp_i16vec2			i16vec2;
	typedef lowp_i16vec3			i16vec3;
	typedef lowp_i16vec4			i16vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_i16vec1			i16vec1;
	typedef mediump_i16vec2			i16vec2;
	typedef mediump_i16vec3			i16vec3;
	typedef mediump_i16vec4			i16vec4;
#else
	/// Default qualifier 16 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef highp_i16vec1			i16vec1;

	/// Default qualifier 16 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_i16vec2			i16vec2;

	/// Default qualifier 16 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_i16vec3			i16vec3;

	/// Default qualifier 16 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_i16vec4			i16vec4;
#endif


	/// Low qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i32, lowp>		lowp_i32vec1;

	/// Low qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i32, lowp>		lowp_i32vec2;

	/// Low qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i32, lowp>		lowp_i32vec3;

	/// Low qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i32, lowp>		lowp_i32vec4;


	/// Medium qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i32, mediump>		mediump_i32vec1;

	/// Medium qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i32, mediump>		mediump_i32vec2;

	/// Medium qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i32, mediump>		mediump_i32vec3;

	/// Medium qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i32, mediump>		mediump_i32vec4;


	/// High qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i32, highp>		highp_i32vec1;

	/// High qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i32, highp>		highp_i32vec2;

	/// High qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i32, highp>		highp_i32vec3;

	/// High qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i32, highp>		highp_i32vec4;

#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_i32vec1			i32vec1;
	typedef lowp_i32vec2			i32vec2;
	typedef lowp_i32vec3			i32vec3;
	typedef lowp_i32vec4			i32vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_i32vec1			i32vec1;
	typedef mediump_i32vec2			i32vec2;
	typedef mediump_i32vec3			i32vec3;
	typedef mediump_i32vec4			i32vec4;
#else
	/// Default qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef highp_i32vec1			i32vec1;

	/// Default qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_i32vec2			i32vec2;

	/// Default qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_i32vec3			i32vec3;

	/// Default qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_i32vec4			i32vec4;
#endif


	/// Low qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i32, lowp>		lowp_i32vec1;

	/// Low qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i32, lowp>		lowp_i32vec2;

	/// Low qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i32, lowp>		lowp_i32vec3;

	/// Low qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i32, lowp>		lowp_i32vec4;


	/// Medium qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i32, mediump>		mediump_i32vec1;

	/// Medium qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i32, mediump>		mediump_i32vec2;

	/// Medium qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i32, mediump>		mediump_i32vec3;

	/// Medium qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i32, mediump>		mediump_i32vec4;


	/// High qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i32, highp>		highp_i32vec1;

	/// High qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i32, highp>		highp_i32vec2;

	/// High qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i32, highp>		highp_i32vec3;

	/// High qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i32, highp>		highp_i32vec4;

#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_i32vec1			i32vec1;
	typedef lowp_i32vec2			i32vec2;
	typedef lowp_i32vec3			i32vec3;
	typedef lowp_i32vec4			i32vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_i32vec1			i32vec1;
	typedef mediump_i32vec2			i32vec2;
	typedef mediump_i32vec3			i32vec3;
	typedef mediump_i32vec4			i32vec4;
#else
	/// Default qualifier 32 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef highp_i32vec1			i32vec1;

	/// Default qualifier 32 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_i32vec2			i32vec2;

	/// Default qualifier 32 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_i32vec3			i32vec3;

	/// Default qualifier 32 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_i32vec4			i32vec4;
#endif



	/// Low qualifier 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i64, lowp>		lowp_i64vec1;

	/// Low qualifier 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i64, lowp>		lowp_i64vec2;

	/// Low qualifier 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i64, lowp>		lowp_i64vec3;

	/// Low qualifier 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i64, lowp>		lowp_i64vec4;


	/// Medium qualifier 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i64, mediump>		mediump_i64vec1;

	/// Medium qualifier 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i64, mediump>		mediump_i64vec2;

	/// Medium qualifier 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i64, mediump>		mediump_i64vec3;

	/// Medium qualifier 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i64, mediump>		mediump_i64vec4;


	/// High qualifier 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, i64, highp>		highp_i64vec1;

	/// High qualifier 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, i64, highp>		highp_i64vec2;

	/// High qualifier 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, i64, highp>		highp_i64vec3;

	/// High qualifier 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, i64, highp>		highp_i64vec4;

#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_i64vec1			i64vec1;
	typedef lowp_i64vec2			i64vec2;
	typedef lowp_i64vec3			i64vec3;
	typedef lowp_i64vec4			i64vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_i64vec1			i64vec1;
	typedef mediump_i64vec2			i64vec2;
	typedef mediump_i64vec3			i64vec3;
	typedef mediump_i64vec4			i64vec4;
#else
	/// Default qualifier 64 bit signed integer scalar type.
	/// @see gtc_type_precision
	typedef highp_i64vec1			i64vec1;

	/// Default qualifier 64 bit signed integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_i64vec2			i64vec2;

	/// Default qualifier 64 bit signed integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_i64vec3			i64vec3;

	/// Default qualifier 64 bit signed integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_i64vec4			i64vec4;
#endif


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



	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 highp_uint8;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 highp_uint16;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 highp_uint32;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 highp_uint64;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 highp_uint8_t;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 highp_uint16_t;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 highp_uint32_t;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 highp_uint64_t;

	/// Medium qualifier 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 highp_u8;

	/// Medium qualifier 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 highp_u16;

	/// Medium qualifier 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 highp_u32;

	/// Medium qualifier 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 highp_u64;



	/// 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 uint8;

	/// 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 uint16;

	/// 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 uint32;

	/// 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 uint64;

#if GLM_HAS_EXTENDED_INTEGER_TYPE
	using std::uint8_t;
	using std::uint16_t;
	using std::uint32_t;
	using std::uint64_t;
#else
	/// 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 uint8_t;

	/// 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 uint16_t;

	/// 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 uint32_t;

	/// 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 uint64_t;
#endif

	/// 8 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint8 u8;

	/// 16 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint16 u16;

	/// 32 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint32 u32;

	/// 64 bit unsigned integer type.
	/// @see gtc_type_precision
	typedef detail::uint64 u64;



	/// Low qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u8, lowp> lowp_u8vec1;

	/// Low qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u8, lowp> lowp_u8vec2;

	/// Low qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u8, lowp> lowp_u8vec3;

	/// Low qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u8, lowp> lowp_u8vec4;


	/// Medium qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u8, mediump> mediump_u8vec1;

	/// Medium qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u8, mediump> mediump_u8vec2;

	/// Medium qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u8, mediump> mediump_u8vec3;

	/// Medium qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u8, mediump> mediump_u8vec4;


	/// High qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u8, highp> highp_u8vec1;

	/// High qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u8, highp> highp_u8vec2;

	/// High qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u8, highp> highp_u8vec3;

	/// High qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u8, highp> highp_u8vec4;

#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_u8vec1				u8vec1;
	typedef lowp_u8vec2				u8vec2;
	typedef lowp_u8vec3				u8vec3;
	typedef lowp_u8vec4				u8vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_u8vec1			u8vec1;
	typedef mediump_u8vec2			u8vec2;
	typedef mediump_u8vec3			u8vec3;
	typedef mediump_u8vec4			u8vec4;
#else
	/// Default qualifier 8 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef highp_u8vec1			u8vec1;

	/// Default qualifier 8 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_u8vec2			u8vec2;

	/// Default qualifier 8 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_u8vec3			u8vec3;

	/// Default qualifier 8 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_u8vec4			u8vec4;
#endif


	/// Low qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u16, lowp>		lowp_u16vec1;

	/// Low qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u16, lowp>		lowp_u16vec2;

	/// Low qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u16, lowp>		lowp_u16vec3;

	/// Low qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u16, lowp>		lowp_u16vec4;


	/// Medium qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u16, mediump>		mediump_u16vec1;

	/// Medium qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u16, mediump>		mediump_u16vec2;

	/// Medium qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u16, mediump>		mediump_u16vec3;

	/// Medium qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u16, mediump>		mediump_u16vec4;


	/// High qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u16, highp>		highp_u16vec1;

	/// High qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u16, highp>		highp_u16vec2;

	/// High qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u16, highp>		highp_u16vec3;

	/// High qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u16, highp>		highp_u16vec4;


#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_u16vec1			u16vec1;
	typedef lowp_u16vec2			u16vec2;
	typedef lowp_u16vec3			u16vec3;
	typedef lowp_u16vec4			u16vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_u16vec1			u16vec1;
	typedef mediump_u16vec2			u16vec2;
	typedef mediump_u16vec3			u16vec3;
	typedef mediump_u16vec4			u16vec4;
#else
	/// Default qualifier 16 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef highp_u16vec1			u16vec1;

	/// Default qualifier 16 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_u16vec2			u16vec2;

	/// Default qualifier 16 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_u16vec3			u16vec3;

	/// Default qualifier 16 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_u16vec4			u16vec4;
#endif


	/// Low qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u32, lowp>		lowp_u32vec1;

	/// Low qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u32, lowp>		lowp_u32vec2;

	/// Low qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u32, lowp>		lowp_u32vec3;

	/// Low qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u32, lowp>		lowp_u32vec4;


	/// Medium qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u32, mediump>		mediump_u32vec1;

	/// Medium qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u32, mediump>		mediump_u32vec2;

	/// Medium qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u32, mediump>		mediump_u32vec3;

	/// Medium qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u32, mediump>		mediump_u32vec4;


	/// High qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u32, highp>		highp_u32vec1;

	/// High qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u32, highp>		highp_u32vec2;

	/// High qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u32, highp>		highp_u32vec3;

	/// High qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u32, highp>		highp_u32vec4;

#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_u32vec1			u32vec1;
	typedef lowp_u32vec2			u32vec2;
	typedef lowp_u32vec3			u32vec3;
	typedef lowp_u32vec4			u32vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_u32vec1			u32vec1;
	typedef mediump_u32vec2			u32vec2;
	typedef mediump_u32vec3			u32vec3;
	typedef mediump_u32vec4			u32vec4;
#else
	/// Default qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef highp_u32vec1			u32vec1;

	/// Default qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_u32vec2			u32vec2;

	/// Default qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_u32vec3			u32vec3;

	/// Default qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_u32vec4			u32vec4;
#endif


	/// Low qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u32, lowp>		lowp_u32vec1;

	/// Low qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u32, lowp>		lowp_u32vec2;

	/// Low qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u32, lowp>		lowp_u32vec3;

	/// Low qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u32, lowp>		lowp_u32vec4;


	/// Medium qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u32, mediump>		mediump_u32vec1;

	/// Medium qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u32, mediump>		mediump_u32vec2;

	/// Medium qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u32, mediump>		mediump_u32vec3;

	/// Medium qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u32, mediump>		mediump_u32vec4;


	/// High qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u32, highp>		highp_u32vec1;

	/// High qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u32, highp>		highp_u32vec2;

	/// High qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u32, highp>		highp_u32vec3;

	/// High qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u32, highp>		highp_u32vec4;

#if(defined(GLM_PRECISION_LOWP_INT))
	typedef lowp_u32vec1			u32vec1;
	typedef lowp_u32vec2			u32vec2;
	typedef lowp_u32vec3			u32vec3;
	typedef lowp_u32vec4			u32vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_INT))
	typedef mediump_u32vec1			u32vec1;
	typedef mediump_u32vec2			u32vec2;
	typedef mediump_u32vec3			u32vec3;
	typedef mediump_u32vec4			u32vec4;
#else
	/// Default qualifier 32 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef highp_u32vec1			u32vec1;

	/// Default qualifier 32 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_u32vec2			u32vec2;

	/// Default qualifier 32 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_u32vec3			u32vec3;

	/// Default qualifier 32 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_u32vec4			u32vec4;
#endif



	/// Low qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u64, lowp>		lowp_u64vec1;

	/// Low qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u64, lowp>		lowp_u64vec2;

	/// Low qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u64, lowp>		lowp_u64vec3;

	/// Low qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u64, lowp>		lowp_u64vec4;


	/// Medium qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u64, mediump>		mediump_u64vec1;

	/// Medium qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u64, mediump>		mediump_u64vec2;

	/// Medium qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u64, mediump>		mediump_u64vec3;

	/// Medium qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u64, mediump>		mediump_u64vec4;


	/// High qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef vec<1, u64, highp>		highp_u64vec1;

	/// High qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef vec<2, u64, highp>		highp_u64vec2;

	/// High qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef vec<3, u64, highp>		highp_u64vec3;

	/// High qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef vec<4, u64, highp>		highp_u64vec4;

#if(defined(GLM_PRECISION_LOWP_UINT))
	typedef lowp_u64vec1			u64vec1;
	typedef lowp_u64vec2			u64vec2;
	typedef lowp_u64vec3			u64vec3;
	typedef lowp_u64vec4			u64vec4;
#elif(defined(GLM_PRECISION_MEDIUMP_UINT))
	typedef mediump_u64vec1			u64vec1;
	typedef mediump_u64vec2			u64vec2;
	typedef mediump_u64vec3			u64vec3;
	typedef mediump_u64vec4			u64vec4;
#else
	/// Default qualifier 64 bit unsigned integer scalar type.
	/// @see gtc_type_precision
	typedef highp_u64vec1			u64vec1;

	/// Default qualifier 64 bit unsigned integer vector of 2 components type.
	/// @see gtc_type_precision
	typedef highp_u64vec2			u64vec2;

	/// Default qualifier 64 bit unsigned integer vector of 3 components type.
	/// @see gtc_type_precision
	typedef highp_u64vec3			u64vec3;

	/// Default qualifier 64 bit unsigned integer vector of 4 components type.
	/// @see gtc_type_precision
	typedef highp_u64vec4			u64vec4;
#endif


	//////////////////////
	// Float vector types

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 lowp_float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 lowp_float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 lowp_float32_t;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 lowp_float64_t;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float32 lowp_f32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float64 lowp_f64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 lowp_float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 lowp_float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 lowp_float32_t;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 lowp_float64_t;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float32 lowp_f32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float64 lowp_f64;


	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 lowp_float32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 lowp_float64;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 lowp_float32_t;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 lowp_float64_t;

	/// Low 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float32 lowp_f32;

	/// Low 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float64 lowp_f64;


	/// Medium 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 mediump_float32;

	/// Medium 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 mediump_float64;

	/// Medium 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 mediump_float32_t;

	/// Medium 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 mediump_float64_t;

	/// Medium 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float32 mediump_f32;

	/// Medium 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float64 mediump_f64;


	/// High 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 highp_float32;

	/// High 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 highp_float64;

	/// High 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float32 highp_float32_t;

	/// High 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef detail::float64 highp_float64_t;

	/// High 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float32 highp_f32;

	/// High 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef float64 highp_f64;


#if(defined(GLM_PRECISION_LOWP_FLOAT))
	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef lowp_float32 float32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef lowp_float64 float64;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef lowp_float32_t float32_t;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef lowp_float64_t float64_t;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef lowp_f32 f32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef lowp_f64 f64;

#elif(defined(GLM_PRECISION_MEDIUMP_FLOAT))

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef mediump_float32 float32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef mediump_float64 float64;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef mediump_float32 float32_t;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef mediump_float64 float64_t;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef mediump_float32 f32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef mediump_float64 f64;

#else//(defined(GLM_PRECISION_HIGHP_FLOAT))

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef highp_float32 float32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef highp_float64 float64;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef highp_float32_t float32_t;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef highp_float64_t float64_t;

	/// Default 32 bit single-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef highp_float32_t f32;

	/// Default 64 bit double-qualifier floating-point scalar.
	/// @see gtc_type_precision
	typedef highp_float64_t f64;
#endif


	/// Low single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, float, lowp> lowp_vec1;

	/// Low single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	typedef vec<2, float, lowp> lowp_vec2;

	/// Low single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	typedef vec<3, float, lowp> lowp_vec3;

	/// Low single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	typedef vec<4, float, lowp> lowp_vec4;

	/// Low single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, float, lowp> lowp_fvec1;

	/// Low single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, float, lowp> lowp_fvec2;

	/// Low single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, float, lowp> lowp_fvec3;

	/// Low single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, float, lowp> lowp_fvec4;


	/// Medium single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, float, mediump> mediump_vec1;

	/// Medium Single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	typedef vec<2, float, mediump> mediump_vec2;

	/// Medium Single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	typedef vec<3, float, mediump> mediump_vec3;

	/// Medium Single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	typedef vec<4, float, mediump> mediump_vec4;

	/// Medium single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, float, mediump> mediump_fvec1;

	/// Medium Single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, float, mediump> mediump_fvec2;

	/// Medium Single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, float, mediump> mediump_fvec3;

	/// Medium Single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, float, mediump> mediump_fvec4;


	/// High single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, float, highp> highp_vec1;

	/// High Single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	typedef vec<2, float, highp> highp_vec2;

	/// High Single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	typedef vec<3, float, highp> highp_vec3;

	/// High Single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	typedef vec<4, float, highp> highp_vec4;

	/// High single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, float, highp> highp_fvec1;

	/// High Single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	typedef vec<2, float, highp> highp_fvec2;

	/// High Single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	typedef vec<3, float, highp> highp_fvec3;

	/// High Single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	typedef vec<4, float, highp> highp_fvec4;


	/// Low single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, f32, lowp> lowp_f32vec1;

	/// Low single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	typedef vec<2, f32, lowp> lowp_f32vec2;

	/// Low single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	typedef vec<3, f32, lowp> lowp_f32vec3;

	/// Low single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	typedef vec<4, f32, lowp> lowp_f32vec4;

	/// Medium single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, f32, mediump> mediump_f32vec1;

	/// Medium single-qualifier floating-point vector of 2 components.
	/// @see core_precision
	typedef vec<2, f32, mediump> mediump_f32vec2;

	/// Medium single-qualifier floating-point vector of 3 components.
	/// @see core_precision
	typedef vec<3, f32, mediump> mediump_f32vec3;

	/// Medium single-qualifier floating-point vector of 4 components.
	/// @see core_precision
	typedef vec<4, f32, mediump> mediump_f32vec4;

	/// High single-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, f32, highp> highp_f32vec1;

	/// High single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, f32, highp> highp_f32vec2;

	/// High single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, f32, highp> highp_f32vec3;

	/// High single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, f32, highp> highp_f32vec4;


	/// Low double-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, f64, lowp> lowp_f64vec1;

	/// Low double-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, f64, lowp> lowp_f64vec2;

	/// Low double-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, f64, lowp> lowp_f64vec3;

	/// Low double-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, f64, lowp> lowp_f64vec4;

	/// Medium double-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, f64, mediump> mediump_f64vec1;

	/// Medium double-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, f64, mediump> mediump_f64vec2;

	/// Medium double-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, f64, mediump> mediump_f64vec3;

	/// Medium double-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, f64, mediump> mediump_f64vec4;

	/// High double-qualifier floating-point vector of 1 component.
	/// @see gtc_type_precision
	typedef vec<1, f64, highp> highp_f64vec1;

	/// High double-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef vec<2, f64, highp> highp_f64vec2;

	/// High double-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef vec<3, f64, highp> highp_f64vec3;

	/// High double-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef vec<4, f64, highp> highp_f64vec4;


	//////////////////////
	// Float matrix types

	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef lowp_f32 lowp_fmat1x1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, lowp> lowp_fmat2x2;

	/// Low single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, lowp> lowp_fmat2x3;

	/// Low single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, lowp> lowp_fmat2x4;

	/// Low single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, lowp> lowp_fmat3x2;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, lowp> lowp_fmat3x3;

	/// Low single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, lowp> lowp_fmat3x4;

	/// Low single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, lowp> lowp_fmat4x2;

	/// Low single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, lowp> lowp_fmat4x3;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, lowp> lowp_fmat4x4;

	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef lowp_fmat1x1 lowp_fmat1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef lowp_fmat2x2 lowp_fmat2;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef lowp_fmat3x3 lowp_fmat3;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef lowp_fmat4x4 lowp_fmat4;


	/// Medium single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef mediump_f32 mediump_fmat1x1;

	/// Medium single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, mediump> mediump_fmat2x2;

	/// Medium single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, mediump> mediump_fmat2x3;

	/// Medium single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, mediump> mediump_fmat2x4;

	/// Medium single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, mediump> mediump_fmat3x2;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, mediump> mediump_fmat3x3;

	/// Medium single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, mediump> mediump_fmat3x4;

	/// Medium single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, mediump> mediump_fmat4x2;

	/// Medium single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, mediump> mediump_fmat4x3;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, mediump> mediump_fmat4x4;

	/// Medium single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef mediump_fmat1x1 mediump_fmat1;

	/// Medium single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mediump_fmat2x2 mediump_fmat2;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mediump_fmat3x3 mediump_fmat3;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mediump_fmat4x4 mediump_fmat4;


	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef highp_f32 highp_fmat1x1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, highp> highp_fmat2x2;

	/// High single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, highp> highp_fmat2x3;

	/// High single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, highp> highp_fmat2x4;

	/// High single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, highp> highp_fmat3x2;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, highp> highp_fmat3x3;

	/// High single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, highp> highp_fmat3x4;

	/// High single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, highp> highp_fmat4x2;

	/// High single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, highp> highp_fmat4x3;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, highp> highp_fmat4x4;

	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef highp_fmat1x1 highp_fmat1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef highp_fmat2x2 highp_fmat2;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef highp_fmat3x3 highp_fmat3;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef highp_fmat4x4 highp_fmat4;


	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 lowp_f32mat1x1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, lowp> lowp_f32mat2x2;

	/// Low single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, lowp> lowp_f32mat2x3;

	/// Low single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, lowp> lowp_f32mat2x4;

	/// Low single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, lowp> lowp_f32mat3x2;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, lowp> lowp_f32mat3x3;

	/// Low single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, lowp> lowp_f32mat3x4;

	/// Low single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, lowp> lowp_f32mat4x2;

	/// Low single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, lowp> lowp_f32mat4x3;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, lowp> lowp_f32mat4x4;

	/// Low single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, lowp> lowp_f32mat1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef lowp_f32mat2x2 lowp_f32mat2;

	/// Low single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef lowp_f32mat3x3 lowp_f32mat3;

	/// Low single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef lowp_f32mat4x4 lowp_f32mat4;


	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 mediump_f32mat1x1;

	/// Low single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, mediump> mediump_f32mat2x2;

	/// Medium single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, mediump> mediump_f32mat2x3;

	/// Medium single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, mediump> mediump_f32mat2x4;

	/// Medium single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, mediump> mediump_f32mat3x2;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, mediump> mediump_f32mat3x3;

	/// Medium single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, mediump> mediump_f32mat3x4;

	/// Medium single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, mediump> mediump_f32mat4x2;

	/// Medium single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, mediump> mediump_f32mat4x3;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, mediump> mediump_f32mat4x4;

	/// Medium single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, mediump> f32mat1;

	/// Medium single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mediump_f32mat2x2 mediump_f32mat2;

	/// Medium single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mediump_f32mat3x3 mediump_f32mat3;

	/// Medium single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mediump_f32mat4x4 mediump_f32mat4;


	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f32 highp_f32mat1x1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f32, highp> highp_f32mat2x2;

	/// High single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f32, highp> highp_f32mat2x3;

	/// High single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f32, highp> highp_f32mat2x4;

	/// High single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f32, highp> highp_f32mat3x2;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f32, highp> highp_f32mat3x3;

	/// High single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f32, highp> highp_f32mat3x4;

	/// High single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f32, highp> highp_f32mat4x2;

	/// High single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f32, highp> highp_f32mat4x3;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f32, highp> highp_f32mat4x4;

	/// High single-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef detail::tmat1x1<f32, highp> f32mat1;

	/// High single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat2x2 highp_f32mat2;

	/// High single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat3x3 highp_f32mat3;

	/// High single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat4x4 highp_f32mat4;


	/// Low double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 lowp_f64mat1x1;

	/// Low double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f64, lowp> lowp_f64mat2x2;

	/// Low double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f64, lowp> lowp_f64mat2x3;

	/// Low double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f64, lowp> lowp_f64mat2x4;

	/// Low double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f64, lowp> lowp_f64mat3x2;

	/// Low double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f64, lowp> lowp_f64mat3x3;

	/// Low double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f64, lowp> lowp_f64mat3x4;

	/// Low double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f64, lowp> lowp_f64mat4x2;

	/// Low double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f64, lowp> lowp_f64mat4x3;

	/// Low double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f64, lowp> lowp_f64mat4x4;

	/// Low double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef lowp_f64mat1x1 lowp_f64mat1;

	/// Low double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef lowp_f64mat2x2 lowp_f64mat2;

	/// Low double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef lowp_f64mat3x3 lowp_f64mat3;

	/// Low double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef lowp_f64mat4x4 lowp_f64mat4;


	/// Medium double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 Highp_f64mat1x1;

	/// Medium double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f64, mediump> mediump_f64mat2x2;

	/// Medium double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f64, mediump> mediump_f64mat2x3;

	/// Medium double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f64, mediump> mediump_f64mat2x4;

	/// Medium double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f64, mediump> mediump_f64mat3x2;

	/// Medium double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f64, mediump> mediump_f64mat3x3;

	/// Medium double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f64, mediump> mediump_f64mat3x4;

	/// Medium double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f64, mediump> mediump_f64mat4x2;

	/// Medium double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f64, mediump> mediump_f64mat4x3;

	/// Medium double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f64, mediump> mediump_f64mat4x4;

	/// Medium double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef mediump_f64mat1x1 mediump_f64mat1;

	/// Medium double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mediump_f64mat2x2 mediump_f64mat2;

	/// Medium double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mediump_f64mat3x3 mediump_f64mat3;

	/// Medium double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mediump_f64mat4x4 mediump_f64mat4;

	/// High double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef f64 highp_f64mat1x1;

	/// High double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 2, f64, highp> highp_f64mat2x2;

	/// High double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 3, f64, highp> highp_f64mat2x3;

	/// High double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef mat<2, 4, f64, highp> highp_f64mat2x4;

	/// High double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 2, f64, highp> highp_f64mat3x2;

	/// High double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 3, f64, highp> highp_f64mat3x3;

	/// High double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef mat<3, 4, f64, highp> highp_f64mat3x4;

	/// High double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 2, f64, highp> highp_f64mat4x2;

	/// High double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 3, f64, highp> highp_f64mat4x3;

	/// High double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef mat<4, 4, f64, highp> highp_f64mat4x4;

	/// High double-qualifier floating-point 1x1 matrix.
	/// @see gtc_type_precision
	//typedef highp_f64mat1x1 highp_f64mat1;

	/// High double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat2x2 highp_f64mat2;

	/// High double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat3x3 highp_f64mat3;

	/// High double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat4x4 highp_f64mat4;

	//////////////////////////
	// Quaternion types

	/// Low single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f32, lowp> lowp_f32quat;

	/// Low double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f64, lowp> lowp_f64quat;

	/// Medium single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f32, mediump> mediump_f32quat;

	/// Medium double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f64, mediump> mediump_f64quat;

	/// High single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f32, highp> highp_f32quat;

	/// High double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef tquat<f64, highp> highp_f64quat;


#if(defined(GLM_PRECISION_LOWP_FLOAT))
	typedef lowp_f32vec1			fvec1;
	typedef lowp_f32vec2			fvec2;
	typedef lowp_f32vec3			fvec3;
	typedef lowp_f32vec4			fvec4;
	typedef lowp_f32mat2			fmat2;
	typedef lowp_f32mat3			fmat3;
	typedef lowp_f32mat4			fmat4;
	typedef lowp_f32mat2x2			fmat2x2;
	typedef lowp_f32mat3x2			fmat3x2;
	typedef lowp_f32mat4x2			fmat4x2;
	typedef lowp_f32mat2x3			fmat2x3;
	typedef lowp_f32mat3x3			fmat3x3;
	typedef lowp_f32mat4x3			fmat4x3;
	typedef lowp_f32mat2x4			fmat2x4;
	typedef lowp_f32mat3x4			fmat3x4;
	typedef lowp_f32mat4x4			fmat4x4;
	typedef lowp_f32quat			fquat;

	typedef lowp_f32vec1			f32vec1;
	typedef lowp_f32vec2			f32vec2;
	typedef lowp_f32vec3			f32vec3;
	typedef lowp_f32vec4			f32vec4;
	typedef lowp_f32mat2			f32mat2;
	typedef lowp_f32mat3			f32mat3;
	typedef lowp_f32mat4			f32mat4;
	typedef lowp_f32mat2x2			f32mat2x2;
	typedef lowp_f32mat3x2			f32mat3x2;
	typedef lowp_f32mat4x2			f32mat4x2;
	typedef lowp_f32mat2x3			f32mat2x3;
	typedef lowp_f32mat3x3			f32mat3x3;
	typedef lowp_f32mat4x3			f32mat4x3;
	typedef lowp_f32mat2x4			f32mat2x4;
	typedef lowp_f32mat3x4			f32mat3x4;
	typedef lowp_f32mat4x4			f32mat4x4;
	typedef lowp_f32quat			f32quat;
#elif(defined(GLM_PRECISION_MEDIUMP_FLOAT))
	typedef mediump_f32vec1			fvec1;
	typedef mediump_f32vec2			fvec2;
	typedef mediump_f32vec3			fvec3;
	typedef mediump_f32vec4			fvec4;
	typedef mediump_f32mat2			fmat2;
	typedef mediump_f32mat3			fmat3;
	typedef mediump_f32mat4			fmat4;
	typedef mediump_f32mat2x2		fmat2x2;
	typedef mediump_f32mat3x2		fmat3x2;
	typedef mediump_f32mat4x2		fmat4x2;
	typedef mediump_f32mat2x3		fmat2x3;
	typedef mediump_f32mat3x3		fmat3x3;
	typedef mediump_f32mat4x3		fmat4x3;
	typedef mediump_f32mat2x4		fmat2x4;
	typedef mediump_f32mat3x4		fmat3x4;
	typedef mediump_f32mat4x4		fmat4x4;
	typedef mediump_f32quat			fquat;

	typedef mediump_f32vec1			f32vec1;
	typedef mediump_f32vec2			f32vec2;
	typedef mediump_f32vec3			f32vec3;
	typedef mediump_f32vec4			f32vec4;
	typedef mediump_f32mat2			f32mat2;
	typedef mediump_f32mat3			f32mat3;
	typedef mediump_f32mat4			f32mat4;
	typedef mediump_f32mat2x2		f32mat2x2;
	typedef mediump_f32mat3x2		f32mat3x2;
	typedef mediump_f32mat4x2		f32mat4x2;
	typedef mediump_f32mat2x3		f32mat2x3;
	typedef mediump_f32mat3x3		f32mat3x3;
	typedef mediump_f32mat4x3		f32mat4x3;
	typedef mediump_f32mat2x4		f32mat2x4;
	typedef mediump_f32mat3x4		f32mat3x4;
	typedef mediump_f32mat4x4		f32mat4x4;
	typedef mediump_f32quat			f32quat;
#else//if(defined(GLM_PRECISION_HIGHP_FLOAT))
	/// Default single-qualifier floating-point vector of 1 components.
	/// @see gtc_type_precision
	typedef highp_f32vec1			fvec1;

	/// Default single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef highp_f32vec2			fvec2;

	/// Default single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef highp_f32vec3			fvec3;

	/// Default single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef highp_f32vec4			fvec4;

	/// Default single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat2x2			fmat2x2;

	/// Default single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat2x3			fmat2x3;

	/// Default single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat2x4			fmat2x4;

	/// Default single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat3x2			fmat3x2;

	/// Default single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat3x3			fmat3x3;

	/// Default single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat3x4			fmat3x4;

	/// Default single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat4x2			fmat4x2;

	/// Default single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat4x3			fmat4x3;

	/// Default single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat4x4			fmat4x4;

	/// Default single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef fmat2x2					fmat2;

	/// Default single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef fmat3x3					fmat3;

	/// Default single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef fmat4x4					fmat4;

	/// Default single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef highp_fquat				fquat;



	/// Default single-qualifier floating-point vector of 1 components.
	/// @see gtc_type_precision
	typedef highp_f32vec1			f32vec1;

	/// Default single-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef highp_f32vec2			f32vec2;

	/// Default single-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef highp_f32vec3			f32vec3;

	/// Default single-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef highp_f32vec4			f32vec4;

	/// Default single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat2x2			f32mat2x2;

	/// Default single-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat2x3			f32mat2x3;

	/// Default single-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat2x4			f32mat2x4;

	/// Default single-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat3x2			f32mat3x2;

	/// Default single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat3x3			f32mat3x3;

	/// Default single-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat3x4			f32mat3x4;

	/// Default single-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat4x2			f32mat4x2;

	/// Default single-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat4x3			f32mat4x3;

	/// Default single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f32mat4x4			f32mat4x4;

	/// Default single-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef f32mat2x2				f32mat2;

	/// Default single-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef f32mat3x3				f32mat3;

	/// Default single-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef f32mat4x4				f32mat4;

	/// Default single-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef highp_f32quat			f32quat;
#endif

#if(defined(GLM_PRECISION_LOWP_DOUBLE))
	typedef lowp_f64vec1			f64vec1;
	typedef lowp_f64vec2			f64vec2;
	typedef lowp_f64vec3			f64vec3;
	typedef lowp_f64vec4			f64vec4;
	typedef lowp_f64mat2			f64mat2;
	typedef lowp_f64mat3			f64mat3;
	typedef lowp_f64mat4			f64mat4;
	typedef lowp_f64mat2x2			f64mat2x2;
	typedef lowp_f64mat3x2			f64mat3x2;
	typedef lowp_f64mat4x2			f64mat4x2;
	typedef lowp_f64mat2x3			f64mat2x3;
	typedef lowp_f64mat3x3			f64mat3x3;
	typedef lowp_f64mat4x3			f64mat4x3;
	typedef lowp_f64mat2x4			f64mat2x4;
	typedef lowp_f64mat3x4			f64mat3x4;
	typedef lowp_f64mat4x4			f64mat4x4;
	typedef lowp_f64quat			f64quat;
#elif(defined(GLM_PRECISION_MEDIUMP_DOUBLE))
	typedef mediump_f64vec1			f64vec1;
	typedef mediump_f64vec2			f64vec2;
	typedef mediump_f64vec3			f64vec3;
	typedef mediump_f64vec4			f64vec4;
	typedef mediump_f64mat2			f64mat2;
	typedef mediump_f64mat3			f64mat3;
	typedef mediump_f64mat4			f64mat4;
	typedef mediump_f64mat2x2		f64mat2x2;
	typedef mediump_f64mat3x2		f64mat3x2;
	typedef mediump_f64mat4x2		f64mat4x2;
	typedef mediump_f64mat2x3		f64mat2x3;
	typedef mediump_f64mat3x3		f64mat3x3;
	typedef mediump_f64mat4x3		f64mat4x3;
	typedef mediump_f64mat2x4		f64mat2x4;
	typedef mediump_f64mat3x4		f64mat3x4;
	typedef mediump_f64mat4x4		f64mat4x4;
	typedef mediump_f64quat			f64quat;
#else
	/// Default double-qualifier floating-point vector of 1 components.
	/// @see gtc_type_precision
	typedef highp_f64vec1			f64vec1;

	/// Default double-qualifier floating-point vector of 2 components.
	/// @see gtc_type_precision
	typedef highp_f64vec2			f64vec2;

	/// Default double-qualifier floating-point vector of 3 components.
	/// @see gtc_type_precision
	typedef highp_f64vec3			f64vec3;

	/// Default double-qualifier floating-point vector of 4 components.
	/// @see gtc_type_precision
	typedef highp_f64vec4			f64vec4;

	/// Default double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat2x2			f64mat2x2;

	/// Default double-qualifier floating-point 2x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat2x3			f64mat2x3;

	/// Default double-qualifier floating-point 2x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat2x4			f64mat2x4;

	/// Default double-qualifier floating-point 3x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat3x2			f64mat3x2;

	/// Default double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat3x3			f64mat3x3;

	/// Default double-qualifier floating-point 3x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat3x4			f64mat3x4;

	/// Default double-qualifier floating-point 4x2 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat4x2			f64mat4x2;

	/// Default double-qualifier floating-point 4x3 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat4x3			f64mat4x3;

	/// Default double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef highp_f64mat4x4			f64mat4x4;

	/// Default double-qualifier floating-point 2x2 matrix.
	/// @see gtc_type_precision
	typedef f64mat2x2				f64mat2;

	/// Default double-qualifier floating-point 3x3 matrix.
	/// @see gtc_type_precision
	typedef f64mat3x3				f64mat3;

	/// Default double-qualifier floating-point 4x4 matrix.
	/// @see gtc_type_precision
	typedef f64mat4x4				f64mat4;

	/// Default double-qualifier floating-point quaternion.
	/// @see gtc_type_precision
	typedef highp_f64quat			f64quat;
#endif

}//namespace glm
// CG_REVISION 96a4891075b8226ae4d98732875b35e3ec5e7bed
