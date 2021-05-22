﻿#include <TestHarness.h>

#include "Pit.h"

#include "Hunter.h"

#include "TestHelperTestEnvironment.h"

namespace TestHuntTheWumpus
{
    TEST(PitSuite, Pit_HasProperAttributes)
    {
        TestEnvironment env;

        const HuntTheWumpus::Pit pit(0, env.m_context);

        const auto &properties = pit.Properties();

        CHECK(!properties.m_carryableByBats);
        CHECK(!properties.m_isEdible);
        CHECK(!properties.m_reportMovement);
        CHECK(properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        const auto& id = pit.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Pit, id.m_category);
    }

	TEST(PitSuite, Pit_GetPriority)
    {
		TestEnvironment env;

        const HuntTheWumpus::Pit pit(0, env.m_context);
    	CHECK_EQUAL(2, pit.GetPriority());
    }
}
