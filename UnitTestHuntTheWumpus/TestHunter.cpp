#include <TestHarness.h>

#include "Hunter.h"

#include "Arrow.h"

#include "TestHelperTestEnvironment.h"

namespace TestHuntTheWumpus
{
    TEST(HunterSuite, Hunter_HasProperAttributes)
    {
        TestEnvironment env;

        const HuntTheWumpus::Hunter hunter(env.m_context);

        const auto &properties = hunter.Properties();

        CHECK(properties.m_carryableByBats);
        CHECK(properties.m_isEdible);
        CHECK(properties.m_reportMovement);
        CHECK(!properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        const auto& id = hunter.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Hunter, id.m_category);
    }

	TEST(HunterSuite, Hunter_GetPriority)
    {
		TestEnvironment env;

        const HuntTheWumpus::Hunter hunter(env.m_context);
    	CHECK_EQUAL(4, hunter.GetPriority());
    }
}
