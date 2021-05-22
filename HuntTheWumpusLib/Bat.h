#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
    class Bat final : public Denizen
    {
    public:
        Bat(int batInstance, Context& providers);
        ~Bat() override = default;

    	[[nodiscard]] int GetPriority() const override;
    	
        Bat(const Bat &) = delete;
        Bat(Bat &&) = delete;
        Bat &operator=(const Bat &) = delete;
        Bat &operator=(Bat &&) = delete;
    };
}
