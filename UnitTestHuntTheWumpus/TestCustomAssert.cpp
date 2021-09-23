#include <TestHarness.h>

#include <CustomAssert.h>

TEST(CustomAssertSuite, TestCustomAssert_Throws)
{
	auto exceptionThrown = false;
	const auto x = 5;

	try
	{
		CustomAssert ca([&]() {return x > 10; });
	}
	catch (const std::logic_error& e)
	{
		exceptionThrown = true;
	}

	CHECK(exceptionThrown);
}

TEST(customAssertSuite, TestCustomAssert_NoThrow)
{
	auto exceptionThrown = false;
	const auto x = 5;

	try
	{
		CustomAssert ca([&]() {return x > 0; });
	}
	catch (const std::logic_error& e)
	{
		exceptionThrown = true;
	}

	CHECK(!exceptionThrown);
}