#pragma once

#include "Dungeon.h"

namespace TestHuntTheWumpus
{
    class TestDungeon final : public HuntTheWumpus::IDungeon
    {
    public:
        TestDungeon() = default;
        ~TestDungeon() override = default;

        const std::shared_ptr<HuntTheWumpus::Cave>& FindCave(int) override
        {
            return m_emptyCave;
        }

        std::shared_ptr<HuntTheWumpus::Cave> m_emptyCave = {};

        TestDungeon(const TestDungeon&) = delete;
        TestDungeon(TestDungeon&&) = delete;
        TestDungeon& operator=(const TestDungeon&) = delete;
        TestDungeon& operator=(TestDungeon&&) = delete;
    };
}

