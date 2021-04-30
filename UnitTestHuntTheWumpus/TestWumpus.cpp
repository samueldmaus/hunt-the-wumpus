#include <TestHarness.h>

#include "Wumpus.h"

namespace TestHuntTheWumpus
{
	TEST(WumpusSuite, Wumpus_HasProperAttributes)
	{
		const HuntTheWumpus::Wumpus wumpus(0);

		const auto& properties = wumpus.Properties();

		CHECK(!properties.m_carryableByBats);
		CHECK(!properties.m_isEdible);
		CHECK(!properties.m_reportMovement);
		CHECK(properties.m_fatalToHunter);
		CHECK(!properties.m_fatalToWumpus);

		const auto& id = wumpus.GetIdentifier();

		CHECK_EQUAL(HuntTheWumpus::Category::Wumpus, id.m_category);
		CHECK_EQUAL(0, id.m_instance);
	}

	TEST(WumpusSuite, Wumpus_Hashing_UniqueHashes)
	{
		const HuntTheWumpus::Wumpus wumpus(0);

		const HuntTheWumpus::Wumpus wumpusExtra(1);

		const HuntTheWumpus::Wumpus wumpusExtraExtra(1);

		const HuntTheWumpus::DenizenIdentifierHasher hasher;

		const auto hash1 = hasher(wumpus.GetIdentifier());
		const auto hash2 = hasher(wumpusExtra.GetIdentifier());
		const auto hash3 = hasher(wumpusExtraExtra.GetIdentifier());

		CHECK(hash1 != hash2);
		CHECK(hash1 != hash3);
		CHECK_EQUAL(hash2, hash3);
	}

	TEST(WumpusSuite, Wumpus_Comparison_ProperSorting)
	{
		const HuntTheWumpus::Wumpus wumpus(0);

		const HuntTheWumpus::Wumpus wumpusExtra(1);

		const HuntTheWumpus::Wumpus wumpusExtraExtra(1);

		CHECK(wumpus.GetIdentifier() <=> wumpusExtra.GetIdentifier() == std::strong_ordering::less);

		CHECK(wumpusExtra.GetIdentifier() == wumpusExtraExtra.GetIdentifier());
	}
}
