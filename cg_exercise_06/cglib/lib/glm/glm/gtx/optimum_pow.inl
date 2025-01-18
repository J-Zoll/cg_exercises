/// @ref gtx_optimum_pow
/// @file glm/gtx/optimum_pow.inl

namespace glm
{
	template<typename genType>
	GLM_FUNC_QUALIFIER genType pow2(genType const& x)
	{
		return x * x;
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType pow3(genType const& x)
	{
		return x * x * x;
	}

	template<typename genType>
	GLM_FUNC_QUALIFIER genType pow4(genType const& x)
	{
		return (x * x) * (x * x);
	}
}//namespace glm
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
