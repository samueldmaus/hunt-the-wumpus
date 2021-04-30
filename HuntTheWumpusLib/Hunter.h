#pragma once

#include <vector>
#include <memory>

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

		[[nodiscard]] const DenizenProperties& Properties() const override;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const override;

	private:
		std::unique_ptr<DenizenIdentifier> m_denizen_identifier_;

		std::unique_ptr<DenizenProperties> m_denizen_properties_;

		std::vector<std::unique_ptr<Arrow>> m_quiver_ = {};
	};
}