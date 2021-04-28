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

	TEST(BatSuite, Bat_Copy_Constructor)
	{
		const HuntTheWumpus::Bat bat(0);

		const auto batCopy(bat);

		CHECK_EQUAL(bat.GetIdentifier().m_instance, batCopy.GetIdentifier().m_instance);

		CHECK_EQUAL(bat.Properties().m_carryableByBats, batCopy.Properties().m_carryableByBats);
		CHECK_EQUAL(bat.Properties().m_fatalToHunter, batCopy.Properties().m_fatalToHunter);
		CHECK_EQUAL(bat.Properties().m_fatalToWumpus, batCopy.Properties().m_fatalToWumpus);
		CHECK_EQUAL(bat.Properties().m_isEdible, batCopy.Properties().m_isEdible);
		CHECK_EQUAL(bat.Properties().m_reportMovement, batCopy.Properties().m_reportMovement);
	}

	TEST(BatSuite, Bat_Copy_Assignment)
	{
		const HuntTheWumpus::Bat bat(0);

		const auto batCopy = bat;

		CHECK_EQUAL(bat.GetIdentifier().m_instance, batCopy.GetIdentifier().m_instance);

		CHECK_EQUAL(bat.Properties().m_carryableByBats, batCopy.Properties().m_carryableByBats);
		CHECK_EQUAL(bat.Properties().m_fatalToHunter, batCopy.Properties().m_fatalToHunter);
		CHECK_EQUAL(bat.Properties().m_fatalToWumpus, batCopy.Properties().m_fatalToWumpus);
		CHECK_EQUAL(bat.Properties().m_isEdible, batCopy.Properties().m_isEdible);
		CHECK_EQUAL(bat.Properties().m_reportMovement, batCopy.Properties().m_reportMovement);
	}

	TEST(BatSuite, Bat_Move_Constructor)
	{
		HuntTheWumpus::Bat bat(0);

		const auto batMove(std::move(bat));

		CHECK_EQUAL(0, batMove.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Bat, batMove.GetIdentifier().m_category);

		CHECK(!batMove.Properties().m_carryableByBats);
		CHECK(!batMove.Properties().m_isEdible);
		CHECK(!batMove.Properties().m_reportMovement);
		CHECK(!batMove.Properties().m_fatalToHunter);
		CHECK(!batMove.Properties().m_fatalToWumpus);
	}

	TEST(BatSuite, Bat_Move_Assignment)
	{
		HuntTheWumpus::Bat bat(0);

		const auto batMove = std::move(bat);

		CHECK_EQUAL(0, batMove.GetIdentifier().m_instance);
		CHECK_EQUAL(HuntTheWumpus::Category::Bat, batMove.GetIdentifier().m_category);

		CHECK(!batMove.Properties().m_carryableByBats);
		CHECK(!batMove.Properties().m_isEdible);
		CHECK(!batMove.Properties().m_reportMovement);
		CHECK(!batMove.Properties().m_fatalToHunter);
		CHECK(!batMove.Properties().m_fatalToWumpus);
	}
}