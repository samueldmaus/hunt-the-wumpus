#include "Pit.h"

#include "Context.h"

namespace HuntTheWumpus
{
    Pit::Pit(const int pitInstance, Context& providers)
        : Denizen({ Category::Pit, pitInstance }, { false, false, true, false, false }, providers)
    {
    }
    int Pit::GetPriority() const
    {
        return 2;
    }
}
