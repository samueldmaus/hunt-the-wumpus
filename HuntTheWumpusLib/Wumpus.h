#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Wumpus : public Denizen
	{
	public:
		explicit Wumpus(const int i);

		~Wumpus() override = default;

		Wumpus(const Wumpus&) = delete;

		Wumpus& operator=(const Wumpus&) = delete;
		
		Wumpus(Wumpus&& src) noexcept = delete;

		Wumpus& operator=(Wumpus&& src) noexcept = delete;

		void ObserveCaveEntrance() override;

		void ReportPresence() override;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const override;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const override;

	private:
		HuntTheWumpus::DenizenIdentifier m_denizen_identifier_;
		
		HuntTheWumpus::DenizenProperties m_denizen_properties_;
	};
}