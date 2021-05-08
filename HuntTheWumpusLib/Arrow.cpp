#include "Arrow.h"

namespace HuntTheWumpus
{
	Arrow::Arrow(const int i)
		: Denizen({ Category::Arrow, i }, { false, true, true, false, false })
	{
	}
	
	void Arrow::GetPriority()
	{
	}
}
