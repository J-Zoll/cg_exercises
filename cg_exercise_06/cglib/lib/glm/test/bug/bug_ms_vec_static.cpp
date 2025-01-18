#include <glm/glm.hpp>

#if GLM_HAS_ALIGNED_TYPE
struct vec2;

struct _swizzle
{
	char _buffer[1];
};

struct vec2
{
	GLM_CONSTEXPR_CTOR vec2() :
		x(0), y(0)
	{}

	union
	{
		struct { float x, y; };
		struct { _swizzle xx; };
	};
};
#endif

// Visual C++ has a bug generating the error: fatal error C1001: An internal error has occurred in the compiler.
// vec2 Bar;

int main()
{
	return 0;
}
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
