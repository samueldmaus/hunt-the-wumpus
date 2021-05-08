#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Hunter final : public Denizen
	{
	public:
		explicit Hunter();

		~Hunter() override = default;

		Hunter(const Hunter&) = delete;

		Hunter& operator=(const Hunter&) = delete;

		Hunter(Hunter&& src) noexcept = delete;

		Hunter& operator=(Hunter&& src) noexcept = delete;

		void EnterCave() override;

		void ObserveCaveEntrance() override;

		void GetPriority() override;
	};
}