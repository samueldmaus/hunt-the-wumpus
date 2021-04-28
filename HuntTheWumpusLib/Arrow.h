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

		Arrow(const Arrow& src);

		Arrow& operator=(const Arrow& src);

		Arrow(Arrow&& src) noexcept;

		Arrow& operator=(Arrow&& src) noexcept;

		void swap(Arrow& src) noexcept;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const override;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const override;

	private:
		std::unique_ptr<DenizenIdentifier> m_denizen_identifier_;

		std::unique_ptr<DenizenProperties> m_denizen_properties_;
	};
}