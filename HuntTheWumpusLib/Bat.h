#pragma once

#include <memory>

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Bat : public Denizen
	{
	public:
		explicit Bat(const int i);

		~Bat() override = default;

		Bat(const Bat& src) = delete;

		Bat& operator=(const Bat& src) = delete;

		Bat(Bat&& src) noexcept = delete;

		Bat& operator=(Bat&& src) noexcept = delete;

		void ObserveCaveEntrance() override;

		void ReportPresence() override;

		void GetPriority() override;
	};
}
