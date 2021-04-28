#include "Hunter.h"

namespace HuntTheWumpus
{
	Hunter::Hunter(const int i)
		: m_denizen_identifier_(std::make_unique<DenizenIdentifier>(Category::Hunter, i)),
		m_denizen_properties_(std::make_unique<DenizenProperties>(true, false, false, true, true))
	{
	}

	Hunter::Hunter(Hunter&& src) noexcept
		: m_denizen_identifier_(std::move(src.m_denizen_identifier_)), m_denizen_properties_(std::move(src.m_denizen_properties_))
	{
	}

	Hunter& Hunter::operator=(Hunter&& src) noexcept
	{
		if(&src != this)
		{
			Hunter::swap(src);
		}
		return *this;
	}

	void Hunter::swap(Hunter& src) noexcept
	{
		std::swap(m_denizen_identifier_, src.m_denizen_identifier_);
		std::swap(m_denizen_properties_, src.m_denizen_properties_);
	}

	void Hunter::EnterCave()
	{
	}

	void Hunter::ObserveCaveEntrance()
	{
	}

	void Hunter::GetPriority()
	{
	}

	const DenizenProperties& Hunter::Properties() const
	{
		return *m_denizen_properties_;
	}

	const DenizenIdentifier& Hunter::GetIdentifier() const
	{
		return *m_denizen_identifier_;
	}
	
}
