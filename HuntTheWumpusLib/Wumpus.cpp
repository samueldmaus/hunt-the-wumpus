#include "Wumpus.h"

#include "Cave.h"

namespace HuntTheWumpus
{
    Wumpus::Wumpus(const int instance, Context& providers)
        : Denizen({ Category::Wumpus, instance }, { false, false, true, false, false }, providers)
    {
    }
    int Wumpus::GetPriority() const
    {
        return 3;
    }
}