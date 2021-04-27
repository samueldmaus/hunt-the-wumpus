#include "Bat.h"

namespace HuntTheWumpus
{
	HuntTheWumpus::Bat::Bat(const int i)
		: m_denizen_identifier_(HuntTheWumpus::DenizenIdentifier(HuntTheWumpus::Category::Bat, i)),
		m_denizen_properties_(HuntTheWumpus::DenizenProperties(false, false, false, false, false))
	{
	}

	void HuntTheWumpus::Bat::ObserveCaveEntrance()
	{
	}

	void HuntTheWumpus::Bat::ReportPresence()
	{
	}

	void HuntTheWumpus::Bat::GetPriority()
	{
	}

	const DenizenProperties& HuntTheWumpus::Bat::Properties() const
	{
		return m_denizen_properties_;
	}

	const DenizenIdentifier& HuntTheWumpus::Bat::GetIdentifier() const
	{
		return m_denizen_identifier_;
	}
}
