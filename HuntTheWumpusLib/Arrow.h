#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
    class Arrow final : public Denizen
    {
    public:
        Arrow(int arrowInstance, Context& providers);
        ~Arrow() override = default;

    	[[nodiscard]] int GetPriority() const override;
    	
        Arrow(const Arrow&) = delete;
        Arrow(Arrow&&) = delete;
        Arrow& operator=(const Arrow&) = delete;
        Arrow& operator=(Arrow&&) = delete;
    };
}
