#pragma once

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Bat : public HuntTheWumpus::Denizen
	{
	public:
		explicit Bat(const int i);

		~Bat() override = default;

		void ObserveCaveEntrance() override;

		void ReportPresence() override;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const;

	private:
		DenizenIdentifier m_denizen_identifier_;
		
		DenizenProperties m_denizen_properties_;
	};
}
