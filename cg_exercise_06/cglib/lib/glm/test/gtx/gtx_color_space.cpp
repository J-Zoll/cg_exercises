#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/color_space.hpp>

int test_saturation()
{
	int Error(0);
	
	glm::vec4 Color = glm::saturation(1.0f, glm::vec4(1.0, 0.5, 0.0, 1.0));

	return Error;
}

int main()
{
	int Error(0);

	Error += test_saturation();

	return Error;
}
// CG_REVISION d4ab32bd208749f2d2b1439e25d16e642b039298
