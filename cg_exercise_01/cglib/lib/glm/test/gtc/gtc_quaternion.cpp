#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/epsilon.hpp>
#include <glm/vector_relational.hpp>
#include <vector>

int test_quat_angle()
{
	int Error = 0;

	{
		glm::quat Q = glm::angleAxis(glm::pi<float>() * 0.25f, glm::vec3(0, 0, 1));
		glm::quat N = glm::normalize(Q);
		float L = glm::length(N);
		Error += glm::epsilonEqual(L, 1.0f, 0.01f) ? 0 : 1;
		float A = glm::angle(N);
		Error += glm::epsilonEqual(A, glm::pi<float>() * 0.25f, 0.01f) ? 0 : 1;
	}
	{
		glm::quat Q = glm::angleAxis(glm::pi<float>() * 0.25f, glm::normalize(glm::vec3(0, 1, 1)));
		glm::quat N = glm::normalize(Q);
		float L = glm::length(N);
		Error += glm::epsilonEqual(L, 1.0f, 0.01f) ? 0 : 1;
		float A = glm::angle(N);
		Error += glm::epsilonEqual(A, glm::pi<float>() * 0.25f, 0.01f) ? 0 : 1;
	}
	{
		glm::quat Q = glm::angleAxis(glm::pi<float>() * 0.25f, glm::normalize(glm::vec3(1, 2, 3)));
		glm::quat N = glm::normalize(Q);
		float L = glm::length(N);
		Error += glm::epsilonEqual(L, 1.0f, 0.01f) ? 0 : 1;
		float A = glm::angle(N);
		Error += glm::epsilonEqual(A, glm::pi<float>() * 0.25f, 0.01f) ? 0 : 1;
	}

	return Error;
}

int test_quat_angleAxis()
{
	int Error = 0;

	glm::quat A = glm::angleAxis(0.f, glm::vec3(0.f, 0.f, 1.f));
	glm::quat B = glm::angleAxis(glm::pi<float>() * 0.5f, glm::vec3(0, 0, 1));
	glm::quat C = glm::mix(A, B, 0.5f);
	glm::quat D = glm::angleAxis(glm::pi<float>() * 0.25f, glm::vec3(0, 0, 1));

	Error += glm::epsilonEqual(C.x, D.x, 0.01f) ? 0 : 1;
	Error += glm::epsilonEqual(C.y, D.y, 0.01f) ? 0 : 1;
	Error += glm::epsilonEqual(C.z, D.z, 0.01f) ? 0 : 1;
	Error += glm::epsilonEqual(C.w, D.w, 0.01f) ? 0 : 1;

	return Error;
}

int test_quat_mix()
{
	int Error = 0;

	glm::quat A = glm::angleAxis(0.f, glm::vec3(0.f, 0.f, 1.f));
	glm::quat B = glm::angleAxis(glm::pi<float>() * 0.5f, glm::vec3(0, 0, 1));
	glm::quat C = glm::mix(A, B, 0.5f);
	glm::quat D = glm::angleAxis(glm::pi<float>() * 0.25f, glm::vec3(0, 0, 1));

	Error += glm::epsilonEqual(C.x, D.x, 0.01f) ? 0 : 1;
	Error += glm::epsilonEqual(C.y, D.y, 0.01f) ? 0 : 1;
	Error += glm::epsilonEqual(C.z, D.z, 0.01f) ? 0 : 1;
	Error += glm::epsilonEqual(C.w, D.w, 0.01f) ? 0 : 1;

	return Error;
}

int test_quat_precision()
{
	int Error = 0;

	Error += sizeof(glm::lowp_quat) <= sizeof(glm::mediump_quat) ? 0 : 1;
	Error += sizeof(glm::mediump_quat) <= sizeof(glm::highp_quat) ? 0 : 1;

	return Error;
}

int test_quat_normalize()
{
	int Error(0);

	{
		glm::quat Q = glm::angleAxis(glm::pi<float>() * 0.25f, glm::vec3(0, 0, 1));
		glm::quat N = glm::normalize(Q);
		float L = glm::length(N);
		Error += glm::epsilonEqual(L, 1.0f, 0.000001f) ? 0 : 1;
	}
	{
		glm::quat Q = glm::angleAxis(glm::pi<float>() * 0.25f, glm::vec3(0, 0, 2));
		glm::quat N = glm::normalize(Q);
		float L = glm::length(N);
		Error += glm::epsilonEqual(L, 1.0f, 0.000001f) ? 0 : 1;
	}
	{
		glm::quat Q = glm::angleAxis(glm::pi<float>() * 0.25f, glm::vec3(1, 2, 3));
		glm::quat N = glm::normalize(Q);
		float L = glm::length(N);
		Error += glm::epsilonEqual(L, 1.0f, 0.000001f) ? 0 : 1;
	}

	return Error;
}

int test_quat_euler()
{
	int Error = 0;

	{
		glm::quat q(1.0f, 0.0f, 0.0f, 1.0f);
		float Roll = glm::roll(q);
		float Pitch = glm::pitch(q);
		float Yaw = glm::yaw(q);
		glm::vec3 Angles = glm::eulerAngles(q);
		Error += glm::all(glm::epsilonEqual(Angles, glm::vec3(Pitch, Yaw, Roll), 0.000001f)) ? 0 : 1;
	}

	{
		glm::dquat q(1.0, 0.0, 0.0, 1.0);
		double Roll = glm::roll(q);
		double Pitch = glm::pitch(q);
		double Yaw = glm::yaw(q);
		glm::dvec3 Angles = glm::eulerAngles(q);
		Error += glm::all(glm::epsilonEqual(Angles, glm::dvec3(Pitch, Yaw, Roll), 0.000001)) ? 0 : 1;
	}

	return Error;
}

int test_quat_slerp()
{
	int Error = 0;

	float const Epsilon = 0.0001f;//glm::epsilon<float>();

	float sqrt2 = std::sqrt(2.0f)/2.0f;
	glm::quat id(static_cast<float>(1), static_cast<float>(0), static_cast<float>(0), static_cast<float>(0));
	glm::quat Y90rot(sqrt2, 0.0f, sqrt2, 0.0f);
	glm::quat Y180rot(0.0f, 0.0f, 1.0f, 0.0f);

	// Testing a == 0
	// Must be id
	glm::quat id2 = glm::slerp(id, Y90rot, 0.0f);
	Error += glm::all(glm::epsilonEqual(id, id2, Epsilon)) ? 0 : 1;

	// Testing a == 1
	// Must be 90� rotation on Y : 0 0.7 0 0.7
	glm::quat Y90rot2 = glm::slerp(id, Y90rot, 1.0f);
	Error += glm::all(glm::epsilonEqual(Y90rot, Y90rot2, Epsilon)) ? 0 : 1;

	// Testing standard, easy case
	// Must be 45� rotation on Y : 0 0.38 0 0.92
	glm::quat Y45rot1 = glm::slerp(id, Y90rot, 0.5f);

	// Testing reverse case
	// Must be 45� rotation on Y : 0 0.38 0 0.92
	glm::quat Ym45rot2 = glm::slerp(Y90rot, id, 0.5f);

	// Testing against full circle around the sphere instead of shortest path
	// Must be 45� rotation on Y
	// certainly not a 135� rotation
	glm::quat Y45rot3 = glm::slerp(id , -Y90rot, 0.5f);
	float Y45angle3 = glm::angle(Y45rot3);
	Error += glm::epsilonEqual(Y45angle3, glm::pi<float>() * 0.25f, Epsilon) ? 0 : 1;
	Error += glm::all(glm::epsilonEqual(Ym45rot2, Y45rot3, Epsilon)) ? 0 : 1;

	// Same, but inverted
	// Must also be 45� rotation on Y :  0 0.38 0 0.92
	// -0 -0.38 -0 -0.92 is ok too
	glm::quat Y45rot4 = glm::slerp(-Y90rot, id, 0.5f);
	Error += glm::all(glm::epsilonEqual(Ym45rot2, -Y45rot4, Epsilon)) ? 0 : 1;

	// Testing q1 = q2
	// Must be 90� rotation on Y : 0 0.7 0 0.7
	glm::quat Y90rot3 = glm::slerp(Y90rot, Y90rot, 0.5f);
	Error += glm::all(glm::epsilonEqual(Y90rot, Y90rot3, Epsilon)) ? 0 : 1;

	// Testing 180� rotation
	// Must be 90� rotation on almost any axis that is on the XZ plane
	glm::quat XZ90rot = glm::slerp(id, -Y90rot, 0.5f);
	float XZ90angle = glm::angle(XZ90rot); // Must be PI/4 = 0.78;
	Error += glm::epsilonEqual(XZ90angle, glm::pi<float>() * 0.25f, Epsilon) ? 0 : 1;

	// Testing almost equal quaternions (this test should pass through the linear interpolation)
	// Must be 0 0.00X 0 0.99999
	glm::quat almostid = glm::slerp(id, glm::angleAxis(0.1f, glm::vec3(0.0f, 1.0f, 0.0f)), 0.5f);

	// Testing quaternions with opposite sign
	{
		glm::quat a(-1, 0, 0, 0);

		glm::quat result = glm::slerp(a, id, 0.5f);

		Error += glm::epsilonEqual(glm::pow(glm::dot(id, result), 2.f), 1.f, 0.01f) ? 0 : 1;
	}

	return Error;
}

int test_quat_mul()
{
	int Error(0);

	glm::quat temp1 = glm::normalize(glm::quat(1.0f, glm::vec3(0.0, 1.0, 0.0)));
	glm::quat temp2 = glm::normalize(glm::quat(0.5f, glm::vec3(1.0, 0.0, 0.0)));

	glm::vec3 transformed0 = (temp1 * glm::vec3(0.0, 1.0, 0.0) * glm::inverse(temp1));
	glm::vec3 temp4 = temp2 * transformed0 * glm::inverse(temp2);

	glm::quat temp5 = glm::normalize(temp1 * temp2);
	glm::vec3 temp6 = temp5 * glm::vec3(0.0, 1.0, 0.0) * glm::inverse(temp5);

	glm::quat temp7(1.0f, glm::vec3(0.0, 1.0, 0.0));

	temp7 *= temp5;
	temp7 *= glm::inverse(temp5);

	Error += temp7 != glm::quat(1.0f, glm::vec3(0.0, 1.0, 0.0));

	return Error;
}

int test_quat_two_axis_ctr()
{
	int Error = 0;

	glm::quat const q1(glm::vec3(1, 0, 0), glm::vec3(0, 1, 0));
	glm::vec3 const v1 = q1 * glm::vec3(1, 0, 0);
	Error += glm::all(glm::epsilonEqual(v1, glm::vec3(0, 1, 0), 0.0001f)) ? 0 : 1;

	glm::quat const q2 = q1 * q1;
	glm::vec3 const v2 = q2 * glm::vec3(1, 0, 0);
	Error += glm::all(glm::epsilonEqual(v2, glm::vec3(-1, 0, 0), 0.0001f)) ? 0 : 1;

	glm::quat const q3(glm::vec3(1, 0, 0), glm::vec3(-1, 0, 0));
	glm::vec3 const v3 = q3 * glm::vec3(1, 0, 0);
	Error += glm::all(glm::epsilonEqual(v3, glm::vec3(-1, 0, 0), 0.0001f)) ? 0 : 1;

	glm::quat const q4(glm::vec3(0, 1, 0), glm::vec3(0, -1, 0));
	glm::vec3 const v4 = q4 * glm::vec3(0, 1, 0);
	Error += glm::all(glm::epsilonEqual(v4, glm::vec3(0, -1, 0), 0.0001f)) ? 0 : 1;

	glm::quat const q5(glm::vec3(0, 0, 1), glm::vec3(0, 0, -1));
	glm::vec3 const v5 = q5 * glm::vec3(0, 0, 1);
	Error += glm::all(glm::epsilonEqual(v5, glm::vec3(0, 0, -1), 0.0001f)) ? 0 : 1;

	return Error;
}

int test_quat_mul_vec()
{
	int Error(0);

	glm::quat q = glm::angleAxis(glm::pi<float>() * 0.5f, glm::vec3(0, 0, 1));
	glm::vec3 v(1, 0, 0);
	glm::vec3 u(q * v);
	glm::vec3 w(u * q);

	Error += glm::all(glm::epsilonEqual(v, w, 0.01f)) ? 0 : 1;

	return Error;
}

int test_quat_ctr()
{
	int Error(0);

#	if GLM_HAS_TRIVIAL_QUERIES
	//	Error += std::is_trivially_default_constructible<glm::quat>::value ? 0 : 1;
	//	Error += std::is_trivially_default_constructible<glm::dquat>::value ? 0 : 1;
	//	Error += std::is_trivially_copy_assignable<glm::quat>::value ? 0 : 1;
	//	Error += std::is_trivially_copy_assignable<glm::dquat>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::quat>::value ? 0 : 1;
		Error += std::is_trivially_copyable<glm::dquat>::value ? 0 : 1;

		Error += std::is_copy_constructible<glm::quat>::value ? 0 : 1;
		Error += std::is_copy_constructible<glm::dquat>::value ? 0 : 1;
#	endif

#	if GLM_HAS_INITIALIZER_LISTS
	{
		glm::quat A{0, 1, 2, 3};

		std::vector<glm::quat> B{
			{0, 1, 2, 3},
			{0, 1, 2, 3}};
	}
#	endif//GLM_HAS_INITIALIZER_LISTS

	return Error;
}

int test_size()
{
	int Error = 0;

	Error += 16 == sizeof(glm::quat) ? 0 : 1;
	Error += 32 == sizeof(glm::dquat) ? 0 : 1;
	Error += glm::quat().length() == 4 ? 0 : 1;
	Error += glm::dquat().length() == 4 ? 0 : 1;
	Error += glm::quat::length() == 4 ? 0 : 1;
	Error += glm::dquat::length() == 4 ? 0 : 1;

	return Error;
}

int main()
{
	int Error = 0;

	Error += test_quat_ctr();
	Error += test_quat_mul_vec();
	Error += test_quat_two_axis_ctr();
	Error += test_quat_mul();
	Error += test_quat_precision();
	Error += test_quat_angle();
	Error += test_quat_angleAxis();
	Error += test_quat_mix();
	Error += test_quat_normalize();
	Error += test_quat_euler();
	Error += test_quat_slerp();
	Error += test_size();

	return Error;
}
// CG_REVISION 8c58412a25ac2367c053bfa840ee81b320bdd315
