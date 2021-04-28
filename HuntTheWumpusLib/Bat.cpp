#include "Bat.h"

namespace HuntTheWumpus
{
	HuntTheWumpus::Bat::Bat(const int i)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Bat, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(false, false, false, false, false))
	{
	}

	Bat::Bat(const Bat& src)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(src.m_denizen_identifier_->m_category, src.m_denizen_identifier_->m_instance)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(src.m_denizen_properties_->m_carryableByBats, src.m_denizen_properties_->m_fatalToWumpus, src.m_denizen_properties_->m_fatalToHunter,
			src.m_denizen_properties_->m_isEdible, src.m_denizen_properties_->m_reportMovement))
	{
	}

	Bat& Bat::operator=(const Bat& src)
	{
		if (&src != this)
		{
			*m_denizen_identifier_ = *src.m_denizen_identifier_;
			*m_denizen_properties_ = *src.m_denizen_properties_;
		}
		return *this;
	}

	Bat::Bat(Bat&& src) noexcept
		: m_denizen_identifier_(std::move(src.m_denizen_identifier_)), m_denizen_properties_(std::move(src.m_denizen_properties_))
	{
	}

	Bat& Bat::operator=(Bat&& src) noexcept
	{
		if (&src != this)
		{
			Bat::swap(src);
		}
		return *this;
	}

	void Bat::swap(Bat& src) noexcept
	{
		std::swap(m_denizen_identifier_, src.m_denizen_identifier_);
		std::swap(m_denizen_properties_, src.m_denizen_properties_);
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
