#include "Pit.h"

namespace HuntTheWumpus
{
	Pit::Pit(const int i)
		: m_denizen_identifier_(Category::Pit, i),
		m_denizen_properties_(false, false, true, false, false)
	{
	}

	void Pit::ObserveCaveEntrance()
	{
	}

	void Pit::ReportPresence()
	{
	}

	void Pit::GetPriority()
	{
	}

	const DenizenProperties& Pit::Properties() const
	{
		return m_denizen_properties_;
	}

	const DenizenIdentifier& Pit::GetIdentifier() const
	{
		return m_denizen_identifier_;
	}
}