#include <TestHarness.h>

#include "Pit.h"

namespace TestHuntTheWumpus
{
	TEST(PitSuite, Pit_HasProperAttributes)
	{
		const HuntTheWumpus::Pit pit(1);

		const auto &properties = pit.Properties();

		CHECK(!properties.m_carryableByBats);
        CHECK(!properties.m_isEdible);
        CHECK(!properties.m_reportMovement);
        CHECK(properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

        const auto& id = pit.GetIdentifier();

        CHECK_EQUAL(HuntTheWumpus::Category::Pit, id.m_category);
    	CHECK_EQUAL(1, id.m_instance);
	}
}
