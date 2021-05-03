#include "Pit.h"

namespace HuntTheWumpus
{
	Pit::Pit(const int i)
		: Denizen(Category::Pit, i, false, false, true, false, false)
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
}