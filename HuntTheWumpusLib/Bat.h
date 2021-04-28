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

		Bat(const Bat& src);

		Bat& operator=(const Bat& src);

		Bat(Bat&& src) noexcept;

		Bat& operator=(Bat&& src) noexcept;

		void swap(Bat& src) noexcept;

		void ObserveCaveEntrance() override;

		void ReportPresence() override;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const override;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const override;

	private:
		std::unique_ptr<DenizenIdentifier> m_denizen_identifier_;
		
		std::unique_ptr<DenizenProperties> m_denizen_properties_;
	};
}
