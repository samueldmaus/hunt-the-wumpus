#pragma once

#include <vector>

#include "Arrow.h"
#include "Denizen.h"

namespace HuntTheWumpus
{
	class Hunter : public Denizen
	{
	public:
		explicit Hunter(const int i);

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