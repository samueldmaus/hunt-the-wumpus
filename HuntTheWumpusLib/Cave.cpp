#include "Cave.h"
#include "Denizen.h"

namespace HuntTheWumpus
{
    Cave::Cave(const int caveId, IDungeon& dungeon)
        : m_caveId(caveId),
        m_dungeon(dungeon)
    {
    }

    bool Cave::HasDenizen(const DenizenIdentifier &identifier) const
    {
        const auto found = std::find_if(m_denizens.begin(), m_denizens.end(), [&](const std::shared_ptr<Denizen> &denizen)
        {
            return denizen->GetIdentifier().m_category == identifier.m_category;
        });

        return found != m_denizens.end();
    }
	
    int Cave::GetCaveId() const
    {
        return m_caveId;
    }

    void Cave::ConnectTo(const std::shared_ptr<Cave>& connect_cave)
    {
    	cave_tunnels.emplace(connect_cave->GetCaveId(), std::weak_ptr<Cave>(connect_cave));
    }
	
    std::vector<int> Cave::GetConnectedIds() const
    {
    	std::vector<int> connected_caves;
        for(auto&& [key, value] : cave_tunnels)
        {
	        connected_caves.push_back(key);
        }
    	return connected_caves;
    }

	std::weak_ptr<Cave> Cave::GetConnectedCave(int caveId)
    {
    	return cave_tunnels.at(caveId);
    }
	
    void Cave::AddDenizen(const std::shared_ptr<Denizen>& denizen)
    {
    	m_denizens.insert(denizen);
    	denizen->EnterCave(*this);
    }
	
    void Cave::ReportDenizens(std::ostream& os)
    {
    	for(const auto& denizen : m_denizens)
    	{
    		os << denizen->GetIdentifier().m_category;
    	}
    	
    }
}
