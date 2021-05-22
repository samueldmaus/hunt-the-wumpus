#pragma once

#include <map>

#include "Cave.h"
#include "Context.h"
#include "Denizen.h"
#include "RandomProvider.h"

namespace HuntTheWumpus
{
    class IDungeon
    {
    public:
        
        IDungeon() = default;
        virtual ~IDungeon() = default;

        virtual const std::shared_ptr<Cave> &FindCave(int caveId) = 0;

        IDungeon(const IDungeon &) = default;
        IDungeon(IDungeon &&) = default;
        IDungeon &operator=(const IDungeon &) = default;
        IDungeon &operator=(IDungeon &&) = default;
    };

    class Dungeon final : public IDungeon
    {
    public:

        explicit Dungeon(Context &providers);
        ~Dungeon() override = default;

        Dungeon(const Dungeon &) = delete;
        Dungeon(Dungeon &&) = delete;
        Dungeon &operator=(const Dungeon &) = delete;
        Dungeon &operator=(Dungeon &&) = delete;

    	const std::shared_ptr<Cave> &FindCave(int caveId) override;
    	
    private:

        void Initialize(Context &providers);
        void MakeTunnels();
        void AddToCave(const std::shared_ptr<Denizen> &denizen, int caveId);

    	template<class T>
    	void MakeDenizen(Category category, int instance)
    	{
            const auto denizen_pair_it = m_denizens.emplace(DenizenIdentifier{category, instance}, std::make_shared<T>(instance, m_providers));
    		auto random_cave = FindCave(m_providers.m_random.MakeRandomCave());
			while(random_cave->HasDenizen(denizen_pair_it.first->second->GetIdentifier()))
    		{
				random_cave = FindCave(m_providers.m_random.MakeRandomCave());
    		}
    		AddToCave(denizen_pair_it.first->second, random_cave->GetCaveId());
    	}

        Context &m_providers;

    	std::map<int, std::shared_ptr<Cave>> m_caves;

    	std::unordered_map<DenizenIdentifier, std::shared_ptr<Denizen>, DenizenIdentifierHasher> m_denizens;
    };
}
