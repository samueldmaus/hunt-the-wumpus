#include <TestHarness.h>

#include "Bat.h"

namespace TestHuntTheWumpus
{
	TEST(BatSuite, Bat_HasProperAttributes)
	{
		const HuntTheWumpus::Bat bat(0);

		const auto &properties = bat.Properties();

		CHECK(!properties.m_carryableByBats);
        CHECK(!properties.m_isEdible);
        CHECK(!properties.m_reportMovement);
        CHECK(!properties.m_fatalToHunter);
        CHECK(!properties.m_fatalToWumpus);

		const auto& id = bat.GetIdentifier();

		CHECK_EQUAL(HuntTheWumpus::Category::Bat, id.m_category);
		CHECK_EQUAL(0, id.m_instance);
	}
}