#pragma once

#include <memory>

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
		
		Wumpus(Wumpus&& src) noexcept;

		Wumpus& operator=(Wumpus&& src) noexcept;

		void swap(Wumpus& src) noexcept;

		void ObserveCaveEntrance() override;

		void ReportPresence() override;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const override;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const override;

	private:
		std::unique_ptr<HuntTheWumpus::DenizenIdentifier> m_denizen_identifier_;
		
		std::unique_ptr<HuntTheWumpus::DenizenProperties> m_denizen_properties_;
	};
}