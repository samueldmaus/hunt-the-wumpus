#pragma once

#include "Denizen.h"

#include <memory>
#include <set>
#include <unordered_map>
#include <vector>
#include <ostream>

namespace HuntTheWumpus
{
    class IDungeon;

    class Cave
    {
    public:
        explicit Cave(int caveId, IDungeon &dungeon);
        ~Cave() = default;

        [[nodiscard]] bool HasDenizens() const { return !m_denizens.empty(); }
        [[nodiscard]] bool HasDenizen(const DenizenIdentifier &identifier) const;

        [[nodiscard]] IDungeon &GetDungeon() const { return m_dungeon; }

    	[[nodiscard]] int GetCaveId() const;

    	void ConnectTo(const std::shared_ptr<Cave>& connect_cave);

    	[[nodiscard]] std::vector<int> GetConnectedIds() const;

    	std::weak_ptr<Cave> GetConnectedCave(int caveId);

    	void AddDenizen(const std::shared_ptr<Denizen>& denizen);

    	void ReportDenizens(std::ostream& os);

        Cave() = delete;
        Cave(const Cave&) = delete;
        Cave(Cave&&) = delete;
        Cave& operator=(const Cave&) = delete;
        Cave& operator=(Cave&&) = delete;

    private:
    	int m_caveId;
    	
        IDungeon &m_dungeon;

    	std::set<std::shared_ptr<Denizen>, decltype([](const auto& a, const auto& b){ return a->GetPriority() < b->GetPriority(); })> m_denizens;

    	std::unordered_map<int, std::weak_ptr<Cave>> cave_tunnels;
    };
}
