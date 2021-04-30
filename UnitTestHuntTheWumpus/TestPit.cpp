#include <TestHarness.h>

#include "Pit.h"

namespace TestHuntTheWumpus
{
	TEST(PitSuite, Pit_HasProperAttributes)
	{
		const HuntTheWumpus::Pit pit(1);

		const auto& properties = pit.Properties();

		CHECK(!properties.m_carryableByBats);
		CHECK(!properties.m_isEdible);
		CHECK(!properties.m_reportMovement);
		CHECK(properties.m_fatalToHunter);
		CHECK(!properties.m_fatalToWumpus);

		const auto& id = pit.GetIdentifier();

		CHECK_EQUAL(HuntTheWumpus::Category::Pit, id.m_category);
		CHECK_EQUAL(1, id.m_instance);
	}

	TEST(PitSuite, Pit_Hashing_UniqueHashes)
	{
		const HuntTheWumpus::Pit pit(0);

		const HuntTheWumpus::Pit pitExtra(1);

		const HuntTheWumpus::Pit pitExtraExtra(1);

		const HuntTheWumpus::DenizenIdentifierHasher hasher;

		const auto hash1 = hasher(pit.GetIdentifier());
		const auto hash2 = hasher(pitExtra.GetIdentifier());
		const auto hash3 = hasher(pitExtraExtra.GetIdentifier());

		CHECK(hash1 != hash2);
		CHECK_EQUAL(hash2, hash3);
	}

	TEST(PitSuite, Pit_Comparison_ProperSorting)
	{
		const HuntTheWumpus::Pit pit(1);

		const HuntTheWumpus::Pit pitExtra(0);

		const HuntTheWumpus::Pit pitExtraExtra(1);

		CHECK(pit.GetIdentifier() <=> pitExtra.GetIdentifier() == std::strong_ordering::greater);

		CHECK(pit.GetIdentifier() == pitExtraExtra.GetIdentifier());
	}
}
