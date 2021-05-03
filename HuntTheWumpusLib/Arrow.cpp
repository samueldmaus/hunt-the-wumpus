#include "Arrow.h"

namespace HuntTheWumpus
{
	Arrow::Arrow(const int i)
		: m_denizen_identifier_(Category::Arrow, i),
		m_denizen_properties_(false, true, true, false, false)
	{
	}
	
	void Arrow::GetPriority()
	{
	}
	
	const DenizenProperties& Arrow::Properties() const
	{
		return m_denizen_properties_;
	}
	
	const DenizenIdentifier& Arrow::GetIdentifier() const
	{
		return m_denizen_identifier_;
	}
}
