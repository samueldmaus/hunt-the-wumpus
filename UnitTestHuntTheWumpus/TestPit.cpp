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

	TEST(PitSuite, Pit_Copy_Constructor)
	{
		const HuntTheWumpus::Pit pit(0);

		const auto pitCopy(pit);

		CHECK_EQUAL(pit.GetIdentifier().m_instance, pitCopy.GetIdentifier().m_instance);

		CHECK_EQUAL(pit.Properties().m_carryableByBats, pitCopy.Properties().m_carryableByBats);
		CHECK_EQUAL(pit.Properties().m_fatalToHunter, pitCopy.Properties().m_fatalToHunter);
		CHECK_EQUAL(pit.Properties().m_fatalToWumpus, pitCopy.Properties().m_fatalToWumpus);
		CHECK_EQUAL(pit.Properties().m_isEdible, pitCopy.Properties().m_isEdible);
		CHECK_EQUAL(pit.Properties().m_reportMovement, pitCopy.Properties().m_reportMovement);
	}

	TEST(PitSuite, Pit_Copy_Assignment)
	{
		const HuntTheWumpus::Pit pit(0);

		const auto pitCopy = pit;

		CHECK_EQUAL(pit.GetIdentifier().m_instance, pitCopy.GetIdentifier().m_instance);

		CHECK_EQUAL(pit.Properties().m_carryableByBats, pitCopy.Properties().m_carryableByBats);
		CHECK_EQUAL(pit.Properties().m_fatalToHunter, pitCopy.Properties().m_fatalToHunter);
		CHECK_EQUAL(pit.Properties().m_fatalToWumpus, pitCopy.Properties().m_fatalToWumpus);
		CHECK_EQUAL(pit.Properties().m_isEdible, pitCopy.Properties().m_isEdible);
		CHECK_EQUAL(pit.Properties().m_reportMovement, pitCopy.Properties().m_reportMovement);
	}

	TEST(PitSuite, Pit_Move_Constructor)
	{
		HuntTheWumpus::Pit pit(0);

		const auto pitMove(std::move(pit));

		CHECK_EQUAL(0, pitMove.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Pit, pitMove.GetIdentifier().m_category);

		CHECK(!pitMove.Properties().m_carryableByBats);
		CHECK(!pitMove.Properties().m_isEdible);
		CHECK(!pitMove.Properties().m_reportMovement);
		CHECK(pitMove.Properties().m_fatalToHunter);
		CHECK(!pitMove.Properties().m_fatalToWumpus);
	}

	TEST(PitSuite, Pit_Move_Assignment)
	{
		HuntTheWumpus::Pit pit(0);

		const auto pitMove = std::move(pit);

		CHECK_EQUAL(0, pitMove.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Pit, pitMove.GetIdentifier().m_category);

		CHECK(!pitMove.Properties().m_carryableByBats);
		CHECK(!pitMove.Properties().m_isEdible);
		CHECK(!pitMove.Properties().m_reportMovement);
		CHECK(pitMove.Properties().m_fatalToHunter);
		CHECK(!pitMove.Properties().m_fatalToWumpus);
	}
}
