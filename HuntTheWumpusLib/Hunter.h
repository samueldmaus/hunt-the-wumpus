#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
    class Arrow;

    class Hunter final : public Denizen
    {
    public:
        explicit Hunter(Context& providers);
        ~Hunter() override = default;

    	[[nodiscard]] int GetPriority() const override;

        Hunter(const Hunter&) = delete;
        Hunter(Hunter&&) = delete;
        Hunter& operator=(const Hunter&) = delete;
        Hunter& operator=(Hunter&&) = delete;
    };
}