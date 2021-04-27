#pragma once

#include <memory>

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Arrow : public Denizen
	{
	public:
		Arrow(const int i);

		~Arrow() override = default;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const override;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const override;

	private:
		std::unique_ptr<DenizenIdentifier> m_denizen_identifier_;

		std::unique_ptr<DenizenProperties> m_denizen_properties_;
	};
}