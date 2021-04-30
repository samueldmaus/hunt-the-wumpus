#include <TestHarness.h>

#include "Bat.h"

namespace TestHuntTheWumpus
{
	TEST(BatSuite, Bat_HasProperAttributes)
	{
		const HuntTheWumpus::Bat bat(0);

		const auto& properties = bat.Properties();

		CHECK(!properties.m_carryableByBats);
		CHECK(!properties.m_isEdible);
		CHECK(!properties.m_reportMovement);
		CHECK(!properties.m_fatalToHunter);
		CHECK(!properties.m_fatalToWumpus);

		const auto& id = bat.GetIdentifier();

		CHECK_EQUAL(HuntTheWumpus::Category::Bat, id.m_category);
		CHECK_EQUAL(0, id.m_instance);
	}

	TEST(BatSuite, Bat_Hashing_UniqueHashes)
	{
		const HuntTheWumpus::Bat bat(1);

		const HuntTheWumpus::Bat batExtra(2);

		const HuntTheWumpus::Bat batExtraExtra(1);

		const HuntTheWumpus::DenizenIdentifierHasher hasher;

		const auto hash1 = hasher(bat.GetIdentifier());
		const auto hash2 = hasher(batExtra.GetIdentifier());
		const auto hash3 = hasher(batExtraExtra.GetIdentifier());

		CHECK(hash1 != hash2);
		CHECK_EQUAL(hash1, hash3);
	}

	TEST(BatSuite, Bat_Comparison_Proper_Sorting)
	{
		const HuntTheWumpus::Bat bat(1);

		const HuntTheWumpus::Bat batExtra(0);

		const HuntTheWumpus::Bat batExtraExtra(0);

		CHECK(bat.GetIdentifier() <=> batExtra.GetIdentifier() == std::strong_ordering::greater);

		CHECK(batExtra.GetIdentifier() == batExtraExtra.GetIdentifier());
	}
}