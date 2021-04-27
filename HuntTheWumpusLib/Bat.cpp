#include "Bat.h"

namespace HuntTheWumpus
{
	HuntTheWumpus::Bat::Bat(const int i)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Bat, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(false, false, false, false, false))
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
		return *m_denizen_properties_;
	}

	const DenizenIdentifier& Bat::GetIdentifier() const
	{
		return *m_denizen_identifier_;
	}
}
