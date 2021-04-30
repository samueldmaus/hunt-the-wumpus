#include <TestHarness.h>

#include "Arrow.h"

namespace TestHuntTheWumpus
{
	TEST(ArrowSuite, Arrow_HasProperAttributes)
	{
		const HuntTheWumpus::Arrow arrow(1);

		const auto& properties = arrow.Properties();

		CHECK(!properties.m_carryableByBats);
		CHECK(properties.m_fatalToWumpus);
		CHECK(properties.m_fatalToHunter);
		CHECK(!properties.m_isEdible);
		CHECK(!properties.m_reportMovement);

		const auto& id = arrow.GetIdentifier();

		CHECK_EQUAL(1, id.m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Arrow, id.m_category);
	}

	TEST(ArrowSuite, Arrow_Hashing_UniqueHashes)
	{
		const HuntTheWumpus::Arrow arrow(1);

		const HuntTheWumpus::Arrow arrowExtra(2);

		const HuntTheWumpus::Arrow arrowExtraExtra(1);

		const HuntTheWumpus::DenizenIdentifierHasher hasher;

		const auto hash1 = hasher(arrow.GetIdentifier());
		const auto hash2 = hasher(arrowExtra.GetIdentifier());
		const auto hash3 = hasher(arrowExtraExtra.GetIdentifier());

		CHECK(hash1 != hash2);
		CHECK_EQUAL(hash1, hash3);
	}

	TEST(ArrowSuite, Arrow_Comparison_Proper_Sorting)
	{
		const HuntTheWumpus::Arrow arrow(1);

		const HuntTheWumpus::Arrow arrowExtra(0);

		const HuntTheWumpus::Arrow arrowExtraExtra(0);

		CHECK(arrow.GetIdentifier() <=> arrowExtra.GetIdentifier() == std::strong_ordering::greater);

		CHECK(arrowExtra.GetIdentifier() == arrowExtraExtra.GetIdentifier());
	}
}
