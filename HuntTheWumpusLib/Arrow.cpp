#include "Arrow.h"

namespace HuntTheWumpus
{
	Arrow::Arrow(const int i)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Arrow, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(false, true, true, false, false))
	{
	}
	
	Arrow::Arrow(const Arrow& src)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(src.m_denizen_identifier_->m_category, src.m_denizen_identifier_->m_instance)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(src.m_denizen_properties_->m_carryableByBats, src.m_denizen_properties_->m_fatalToWumpus, src.m_denizen_properties_->m_fatalToHunter,
			src.m_denizen_properties_->m_isEdible, src.m_denizen_properties_->m_reportMovement))
	{
	}

	Arrow& Arrow::operator=(const Arrow& src) 
	{
		if(&src != this)
		{
			*m_denizen_identifier_ = *src.m_denizen_identifier_;
			*m_denizen_properties_ = *src.m_denizen_properties_;
		}
		return *this;
	}

	Arrow::Arrow(Arrow&& src) noexcept
		: m_denizen_identifier_(std::move(src.m_denizen_identifier_)), m_denizen_properties_(std::move(src.m_denizen_properties_))
	{
	}

	Arrow& Arrow::operator=(Arrow&& src) noexcept
	{
		if(&src != this)
		{
			Arrow::swap(src);
		}
		return *this;
	}

	void Arrow::swap(Arrow& src) noexcept
	{
		std::swap(m_denizen_identifier_, src.m_denizen_identifier_);
		std::swap(m_denizen_properties_, src.m_denizen_properties_);
	}
	
	void Arrow::GetPriority()
	{
	}
	
	const DenizenProperties& Arrow::Properties() const
	{
		return *m_denizen_properties_;
	}
	
	const DenizenIdentifier& Arrow::GetIdentifier() const
	{
		return *m_denizen_identifier_;
	}
}
