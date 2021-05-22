#include "Hunter.h"

namespace HuntTheWumpus
{
    Hunter::Hunter(Context& providers)
        : Denizen({ Category::Hunter, 0 }, { true, false, false, true, true }, providers)
    {
    }
    int Hunter::GetPriority() const
    {
        return 4;
    }
}