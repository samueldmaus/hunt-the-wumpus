#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Pit : public Denizen
	{
	public:
		explicit Pit(const int i);

		~Pit() override = default;

		Pit(const Pit& src) = delete;

		Pit& operator=(const Pit& src) = delete;

		Pit(Pit&& src) noexcept = delete;

		Pit& operator=(Pit&& src) noexcept = delete;

		void ObserveCaveEntrance() override;

		void ReportPresence() override;

		void GetPriority() override;

	};
}