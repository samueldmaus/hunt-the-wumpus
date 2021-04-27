#include "Wumpus.h"

namespace HuntTheWumpus
{
	Wumpus::Wumpus(const int i)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Wumpus, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(false, false, true, false, false))
	{
	}

	void Wumpus::ObserveCaveEntrance()
	{
	}

	void Wumpus::ReportPresence()
	{
	}

	void Wumpus::GetPriority()
	{
	}

	const DenizenProperties& Wumpus::Properties() const
	{
		return *m_denizen_properties_;
	}

	const DenizenIdentifier& Wumpus::GetIdentifier() const
	{
		return *m_denizen_identifier_;
	}
}
