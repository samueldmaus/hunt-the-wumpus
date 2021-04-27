#include "Pit.h"

namespace HuntTheWumpus
{
	Pit::Pit(const int i)
		:  m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Pit, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(false, false, true, false, false))
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
		return *m_denizen_properties_;
	}

	const DenizenIdentifier& Pit::GetIdentifier() const
	{
		return *m_denizen_identifier_;
	}
}