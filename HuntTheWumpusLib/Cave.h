﻿#pragma once

#include "Denizen.h"

#include <memory>
#include <set>
#include <unordered_map>
#include <vector>

namespace HuntTheWumpus
{
    class IDungeon;

    struct CompareThings
    {
        bool operator()(const std::shared_ptr<Denizen> &thing1, const std::shared_ptr<Denizen> &thing2) const;
    };

    class Cave
    {
    public:
        explicit Cave(int caveId, IDungeon &dungeon);
        ~Cave() = default;

        void ConnectTo(const std::shared_ptr<Cave> &destination);

        const std::weak_ptr<Cave> &GetConnectedCave(int caveId);

        int GetCaveId() const { return m_caveId; }

        std::vector<int> GetConnectedIds() const;

        void AddDenizen(const std::shared_ptr<Denizen> &newDenizen, bool observeEntrance);
        void RemoveDenizen(const DenizenIdentifier &identifier);
        void ReportDenizens() const;

        bool HasDenizens() const { return !m_denizens.empty(); }
        bool HasDenizen(const DenizenIdentifier &identifier) const;

        IDungeon &GetDungeon() const { return m_dungeon; }

        Cave() = delete;
        Cave(const Cave&) = delete;
        Cave(Cave&&) = delete;
        Cave& operator=(const Cave&) = delete;
        Cave& operator=(Cave&&) = delete;

    private:
        int m_caveId;
        IDungeon &m_dungeon;

        std::set<std::shared_ptr<Denizen>, CompareThings> m_denizens;
        std::unordered_map<int, std::weak_ptr<Cave>> m_tunnels;
    };
}
