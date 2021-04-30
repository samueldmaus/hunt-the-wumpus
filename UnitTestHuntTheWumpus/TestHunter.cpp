#include <TestHarness.h>

#include "Hunter.h"

namespace TestHuntTheWumpus
{
	TEST(HunterSuite, Hunter_HasProperAttributes)
	{
		const HuntTheWumpus::Hunter hunter(0);

		const auto& properties = hunter.Properties();

		CHECK(properties.m_carryableByBats);
		CHECK(properties.m_isEdible);
		CHECK(properties.m_reportMovement);
		CHECK(!properties.m_fatalToHunter);
		CHECK(!properties.m_fatalToWumpus);

		const auto& id = hunter.GetIdentifier();

		CHECK_EQUAL(HuntTheWumpus::Category::Hunter, id.m_category);
		CHECK_EQUAL(0, id.m_instance);
	}

	TEST(HunterSuite, Hunter_Hashing_UniqueHashes)
	{
		const HuntTheWumpus::Hunter hunter(0);

		const HuntTheWumpus::Hunter hunterExtra(1);

		const HuntTheWumpus::Hunter hunterExtraExtra(1);

		const HuntTheWumpus::DenizenIdentifierHasher hasher;

		const auto hash1 = hasher(hunter.GetIdentifier());
		const auto hash2 = hasher(hunterExtra.GetIdentifier());
		const auto hash3 = hasher(hunterExtraExtra.GetIdentifier());

		CHECK(hash1 != hash2);
		CHECK(hash1 != hash3);
		CHECK_EQUAL(hash2, hash3);
	}

	TEST(HunterSuite, Hunter_Comparison_ProperSorting)
	{
		const HuntTheWumpus::Hunter hunter(0);

		const HuntTheWumpus::Hunter hunterExtra(1);

		const HuntTheWumpus::Hunter hunterExtraExtra(1);

		CHECK(hunter.GetIdentifier() <=> hunterExtra.GetIdentifier() == std::strong_ordering::less);

		CHECK(hunterExtra.GetIdentifier() == hunterExtraExtra.GetIdentifier());
	}

	TEST(HunterSuite, Hunter_Move_Constructor)
	{
		HuntTheWumpus::Hunter hunter(0);

		const auto hunterExtra(std::move(hunter));

		const auto& properties = hunterExtra.Properties();

		CHECK_EQUAL(0, hunterExtra.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Hunter, hunterExtra.GetIdentifier().m_category);

		CHECK(properties.m_carryableByBats);
		CHECK(properties.m_isEdible);
		CHECK(properties.m_reportMovement);
		CHECK(!properties.m_fatalToHunter);
		CHECK(!properties.m_fatalToWumpus);
	}

	TEST(HunterSuite, Hunter_Move_Assignment)
	{
		HuntTheWumpus::Hunter hunter(0);

		const auto hunterExtra = std::move(hunter);

		const auto& properties = hunterExtra.Properties();

		CHECK_EQUAL(0, hunterExtra.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Hunter, hunterExtra.GetIdentifier().m_category);

		CHECK(properties.m_carryableByBats);
		CHECK(properties.m_isEdible);
		CHECK(properties.m_reportMovement);
		CHECK(!properties.m_fatalToHunter);
		CHECK(!properties.m_fatalToWumpus);
	}
}
