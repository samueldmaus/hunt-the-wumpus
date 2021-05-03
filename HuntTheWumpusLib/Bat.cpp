#include "Bat.h"

namespace HuntTheWumpus
{
	HuntTheWumpus::Bat::Bat(const int i)
		: m_denizen_identifier_(Category::Bat, i),
		m_denizen_properties_(false, false, false, false, false)
	{
	}

	void Bat::ObserveCaveEntrance()
	{
	}

	void Bat::ReportPresence()
	{
	}

	void Bat::GetPriority()
	{
	}

	const DenizenProperties& Bat::Properties() const
	{
		return m_denizen_properties_;
	}

	const DenizenIdentifier& Bat::GetIdentifier() const
	{
		return m_denizen_identifier_;
	}
}
