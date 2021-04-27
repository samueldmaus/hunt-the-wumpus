#pragma once

#include <vector>

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Hunter : public HuntTheWumpus::Denizen
	{
	public:
		explicit Hunter(const int i);

		~Hunter() override = default;

		void EnterCave() override;

		void ObserveCaveEntrance() override;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const;

	private:
		DenizenIdentifier m_denizen_identifier_;

		DenizenProperties m_denizen_properties_;
		
	};
}