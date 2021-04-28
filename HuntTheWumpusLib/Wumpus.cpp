#include "Wumpus.h"

namespace HuntTheWumpus
{
	Wumpus::Wumpus(const int i)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Wumpus, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(false, false, true, false, false))
	{
	}

	Wumpus::Wumpus(Wumpus&& src) noexcept
		: m_denizen_identifier_(std::move(src.m_denizen_identifier_)), m_denizen_properties_(std::move(src.m_denizen_properties_))
	{
	}

	Wumpus& Wumpus::operator=(Wumpus&& src) noexcept
	{
		if(&src != this)
		{
			Wumpus::swap(src);
		}
		return *this;
	}

	void Wumpus::swap(Wumpus& src) noexcept
	{
		std::swap(m_denizen_identifier_, src.m_denizen_identifier_);
		std::swap(m_denizen_properties_, src.m_denizen_properties_);
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
