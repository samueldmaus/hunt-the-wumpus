#include "Bat.h"

#include "Cave.h"
#include "Context.h"

namespace HuntTheWumpus
{
    Bat::Bat(const int batInstance, Context& providers)
        : Denizen(DenizenIdentifier{ Category::Bat, batInstance }, { false, false, false, false, false }, providers)
    {
    }
    int Bat::GetPriority() const
    {
        return 1;
    }
}
