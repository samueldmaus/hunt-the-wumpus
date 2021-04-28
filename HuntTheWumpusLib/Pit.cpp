#include "Pit.h"

namespace HuntTheWumpus
{
	Pit::Pit(const int i)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Pit, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(false, false, true, false, false))
	{
	}

	Pit::Pit(const Pit& src)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(src.m_denizen_identifier_->m_category, src.m_denizen_identifier_->m_instance)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(src.m_denizen_properties_->m_carryableByBats, src.m_denizen_properties_->m_fatalToWumpus, src.m_denizen_properties_->m_fatalToHunter,
			src.m_denizen_properties_->m_isEdible, src.m_denizen_properties_->m_reportMovement))
	{
	}

	Pit& Pit::operator=(const Pit& src)
	{
		if (&src != this)
		{
			*m_denizen_identifier_ = *src.m_denizen_identifier_;
			*m_denizen_properties_ = *src.m_denizen_properties_;
		}
		return *this;
	}

	Pit::Pit(Pit&& src) noexcept
		: m_denizen_identifier_(std::move(src.m_denizen_identifier_)), m_denizen_properties_(std::move(src.m_denizen_properties_))
	{
	}

	Pit& Pit::operator=(Pit&& src) noexcept
	{
		if (&src != this)
		{
			Pit::swap(src);
		}
		return *this;
	}

	void Pit::swap(Pit& src) noexcept
	{
		std::swap(m_denizen_identifier_, src.m_denizen_identifier_);
		std::swap(m_denizen_properties_, src.m_denizen_properties_);
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