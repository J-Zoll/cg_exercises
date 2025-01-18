#include <glm/gtc/constants.hpp>

int test_epsilon()
{
	int Error = 0;

	{
		float Test = glm::epsilon<float>();
		Error += Test > 0.0f ? 0 : 1;
	}

	{
		double Test = glm::epsilon<double>();
		Error += Test > 0.0 ? 0 : 1;
	}

	return Error;
}

int main()
{
	int Error(0);

	//float MinHalf = 0.0f;
	//while (glm::half(MinHalf) == glm::half(0.0f))
	//	MinHalf += std::numeric_limits<float>::epsilon();
	Error += test_epsilon();
	
	return Error;
}
// CG_REVISION 96a4891075b8226ae4d98732875b35e3ec5e7bed
