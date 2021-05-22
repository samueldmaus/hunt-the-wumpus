#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
    class Wumpus final : public Denizen
    {
    public:
        Wumpus(int instance, Context& providers);
        ~Wumpus() override = default;

        [[nodiscard]] int GetPriority() const override;
    	
        Wumpus(const Wumpus&) = delete;
        Wumpus(Wumpus&&) = delete;
        Wumpus& operator=(const Wumpus&) = delete;
        Wumpus& operator=(Wumpus&&) = delete;
    };
}
