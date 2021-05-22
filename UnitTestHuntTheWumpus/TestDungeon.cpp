#include <TestHarness.h>


#include "Bat.h"
#include "Dungeon.h"

#include "Cave.h"
#include "Hunter.h"
#include "Pit.h"

#include "TestHelperTestEnvironment.h"

namespace TestHuntTheWumpus
{
	TEST(DungeonSuite, TestDungeonInitialize)
	{
		TestEnvironment env;
		env.m_provider.SetCaveSequence({2, 5, 6, 9, 10, 13, 14, 15, 16, 19});
		
		HuntTheWumpus::Dungeon dungeon(env.m_context);

		const auto cave_one = dungeon.FindCave(1);
		const auto connected_caves_one = cave_one->GetConnectedIds();

		CHECK_EQUAL(3, connected_caves_one.size());
		
		CHECK_EQUAL(2, connected_caves_one.at(0));
		CHECK_EQUAL(5, connected_caves_one.at(1));
		CHECK_EQUAL(8, connected_caves_one.at(2));

		const auto cave_ten = dungeon.FindCave(10);
		const auto connected_caves_ten = cave_ten->GetConnectedIds();

		CHECK_EQUAL(3, connected_caves_ten.size());
		
		CHECK_EQUAL(2, connected_caves_ten.at(0));
		CHECK_EQUAL(9, connected_caves_ten.at(1));
		CHECK_EQUAL(11, connected_caves_ten.at(2));
	}

	TEST(DungeonSuite, TestDungeonInitializeDenizens)
	{
		TestEnvironment env;
		env.m_provider.SetCaveSequence({2, 5, 6, 9, 10, 13, 14, 15, 16, 19});
		
		HuntTheWumpus::Dungeon dungeon(env.m_context);

		CHECK(dungeon.FindCave(2)->HasDenizens());
		CHECK(dungeon.FindCave(13)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Hunter, 1}));
		
		CHECK(dungeon.FindCave(2)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Bat, 1}));
		CHECK(dungeon.FindCave(5)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Bat, 2}));
		CHECK(dungeon.FindCave(6)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Pit, 1}));
		CHECK(dungeon.FindCave(9)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Pit, 2}));
		CHECK(dungeon.FindCave(10)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Wumpus, 1}));
	}

	TEST(DungeonSuite, TestDungeonInitializeDenizensSkip)
	{
		TestEnvironment env;
		env.m_provider.SetCaveSequence({2, 5, 5, 5, 10, 13, 13, 5, 16, 19});

		HuntTheWumpus::Dungeon dungeon(env.m_context);

		CHECK(dungeon.FindCave(2)->HasDenizens());
		CHECK(dungeon.FindCave(2)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Bat, 1}));
		CHECK(dungeon.FindCave(5)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Bat, 2}));
		CHECK(dungeon.FindCave(5)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Pit, 1}));
		CHECK(dungeon.FindCave(10)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Pit, 2}));
		CHECK(dungeon.FindCave(13)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Wumpus, 1}));
		CHECK(dungeon.FindCave(16)->HasDenizen(HuntTheWumpus::DenizenIdentifier{HuntTheWumpus::Category::Hunter, 1}));
	}
}

