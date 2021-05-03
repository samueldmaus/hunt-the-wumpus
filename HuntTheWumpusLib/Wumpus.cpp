#include "Wumpus.h"

namespace HuntTheWumpus
{
	Wumpus::Wumpus(const int i)
		: m_denizen_identifier_(Category::Wumpus, i),
		m_denizen_properties_(false, false, true, false, false)
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
		return m_denizen_properties_;
	}

	const DenizenIdentifier& Wumpus::GetIdentifier() const
	{
		return m_denizen_identifier_;
	}
}
