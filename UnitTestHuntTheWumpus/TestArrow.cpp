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

	TEST(ArrowSuite, Arrow_Copy_Constructor)
	{
		const HuntTheWumpus::Arrow arrow(0);

		const auto arrowCopy(arrow);

		CHECK_EQUAL(arrow.GetIdentifier().m_instance, arrowCopy.GetIdentifier().m_instance);

		CHECK_EQUAL(arrow.Properties().m_carryableByBats, arrowCopy.Properties().m_carryableByBats);
		CHECK_EQUAL(arrow.Properties().m_fatalToHunter, arrowCopy.Properties().m_fatalToHunter);
		CHECK_EQUAL(arrow.Properties().m_fatalToWumpus, arrowCopy.Properties().m_fatalToWumpus);
		CHECK_EQUAL(arrow.Properties().m_isEdible, arrowCopy.Properties().m_isEdible);
		CHECK_EQUAL(arrow.Properties().m_reportMovement, arrowCopy.Properties().m_reportMovement);
	}

	TEST(ArrowSuite, Arrow_Copy_Assignment)
	{
		const HuntTheWumpus::Arrow arrow(0);

		const auto arrowCopy = arrow;

		CHECK_EQUAL(arrow.GetIdentifier().m_instance, arrowCopy.GetIdentifier().m_instance);

		CHECK_EQUAL(arrow.Properties().m_carryableByBats, arrowCopy.Properties().m_carryableByBats);
		CHECK_EQUAL(arrow.Properties().m_fatalToHunter, arrowCopy.Properties().m_fatalToHunter);
		CHECK_EQUAL(arrow.Properties().m_fatalToWumpus, arrowCopy.Properties().m_fatalToWumpus);
		CHECK_EQUAL(arrow.Properties().m_isEdible, arrowCopy.Properties().m_isEdible);
		CHECK_EQUAL(arrow.Properties().m_reportMovement, arrowCopy.Properties().m_reportMovement);
	}

	TEST(ArrowSuite, Arrow_Move_Constructor)
	{
		HuntTheWumpus::Arrow arrow(0);

		const auto arrowMove(std::move(arrow));

		CHECK_EQUAL(0, arrowMove.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Arrow, arrowMove.GetIdentifier().m_category);

		CHECK(!arrowMove.Properties().m_carryableByBats);
		CHECK(!arrowMove.Properties().m_isEdible);
		CHECK(!arrowMove.Properties().m_reportMovement);
		CHECK(arrowMove.Properties().m_fatalToHunter);
		CHECK(arrowMove.Properties().m_fatalToWumpus);
	}

	TEST(ArrowSuite, Arrow_Move_Assignment)
	{
		HuntTheWumpus::Arrow arrow(0);

		const auto arrowMove = std::move(arrow);

		CHECK_EQUAL(0, arrowMove.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Arrow, arrowMove.GetIdentifier().m_category);

		CHECK(!arrowMove.Properties().m_carryableByBats);
		CHECK(!arrowMove.Properties().m_isEdible);
		CHECK(!arrowMove.Properties().m_reportMovement);
		CHECK(arrowMove.Properties().m_fatalToHunter);
		CHECK(arrowMove.Properties().m_fatalToWumpus);
	}
}
