#include "Dungeon.h"

#include <iostream>


#include "Cave.h"
#include "Bat.h"
#include "Wumpus.h"
#include "Hunter.h"
#include "Pit.h"

#include "Context.h"
#include "RandomProvider.h"

#include <stdexcept>
#include <string>

namespace HuntTheWumpus
{
    Dungeon::Dungeon(Context& providers)
        : m_providers(providers)
    {
        Initialize(providers);
		MakeDenizen<Bat>(Category::Bat, 1);
    	MakeDenizen<Bat>(Category::Bat, 2);
    	MakeDenizen<Pit>(Category::Pit, 1);
    	MakeDenizen<Pit>(Category::Pit, 2);
    	MakeDenizen<Wumpus>(Category::Wumpus, 1);
    	const auto hunter = m_denizens.find(DenizenIdentifier{Category::Hunter, 0});
		auto cave = FindCave(m_providers.m_random.MakeRandomCave());
    	while(cave->HasDenizens())
    	{
    		cave = FindCave(m_providers.m_random.MakeRandomCave());
    	}
    	cave->AddDenizen(hunter->second);
    }

    const std::shared_ptr<Cave>& Dungeon::FindCave(int caveId)
    {
    	return m_caves.find(caveId)->second;
    }

	void Dungeon::Initialize(Context& providers)
	{
		for (auto i = 1; i <= 20; ++i)
		{
			m_caves.emplace(i, std::make_shared<Cave>(i, *this));
		}
		MakeTunnels();
    	const auto hunter = std::make_shared<Hunter>(providers);
        m_denizens.insert({hunter->GetIdentifier(), hunter});
	}

    void Dungeon::MakeTunnels()
    {
        // The set of tunnels to realize the collapsed dodecahedron
        const std::vector<std::pair<int, std::vector<int> > > tunnelPairs = {
            { 1, {2, 5, 8} },
            { 2, {1, 3, 10} },
            { 3, {2, 4, 12} },
            { 4, {3, 5, 14} },
            { 5, {1, 4, 6} },
            { 6, { 5, 7, 15} },
            { 7, {6, 8, 17} },
            { 8, {1, 7, 9} },
            { 9, {8, 10, 18} },
            { 10, {2, 9, 11} },
            { 11, {10, 12, 19} },
            { 12, {3, 11, 13} },
            { 13, {12, 14, 20 }  },
            { 14, {4, 13, 15} },
            { 15, {6, 14, 16} },
            { 16, {15, 17, 20} },
            { 17, {7, 16, 18} },
            { 18, {9, 17, 19} },
            { 19, {11, 18, 20} },
            { 20, {13, 16, 19} }
        };
		for(auto&& [key, value] : tunnelPairs)
    	{
			auto cave = Dungeon::FindCave(key);
			for(const auto& i : value)
			{
				cave->ConnectTo(Dungeon::FindCave(i));
			}
    	}
    }

   void Dungeon::AddToCave(const std::shared_ptr<Denizen>& denizen, const int caveId)
    {
    	FindCave(caveId)->AddDenizen(denizen);
    }
}

