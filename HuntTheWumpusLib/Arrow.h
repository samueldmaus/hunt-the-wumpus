#pragma once

#include <memory>

#include "Denizen.h"

namespace HuntTheWumpus
{
	class Arrow : public Denizen
	{
	public:
		explicit Arrow(const int i);

		~Arrow() override = default;

		Arrow(const Arrow& src) = delete;

		Arrow& operator=(const Arrow& src) = delete;

		Arrow(Arrow&& src) noexcept = delete;

		Arrow& operator=(Arrow&& src) noexcept = delete;

		void GetPriority() override;

		[[nodiscard]] const DenizenProperties& Properties() const override;

		[[nodiscard]] const DenizenIdentifier& GetIdentifier() const override;

	private:
		DenizenIdentifier m_denizen_identifier_;

		DenizenProperties m_denizen_properties_;
	};
}