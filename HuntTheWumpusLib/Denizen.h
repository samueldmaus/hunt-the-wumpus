#pragma once

#include <compare>
#include <iosfwd>

namespace HuntTheWumpus
{
    enum class Category
    {
        Wumpus,
        Pit,
        Bat,
        Hunter,
        Arrow
    };

	std::strong_ordering operator<=>(Category& lhs, Category& rhs);

	struct DenizenIdentifier
	{
		Category m_category;
		
		int m_instance;

		std::strong_ordering operator<=>(const DenizenIdentifier& rhs) const;

		bool operator==(const DenizenIdentifier& rhs) const;

	};

	struct DenizenIdentifierHasher
	{
		size_t operator()(const DenizenIdentifier& d) const;
	};

    struct DenizenProperties
    {
        bool m_carryableByBats = false;
        bool m_fatalToWumpus = false;
        bool m_fatalToHunter = false;
        bool m_isEdible = false;
        bool m_reportMovement = false;
    };

	class Denizen
	{
	public:
		Denizen(const DenizenIdentifier& identifier, DenizenProperties&& props);

		virtual ~Denizen() = default; 

		Denizen(const Denizen&) = delete;

		Denizen& operator=(const Denizen&) = delete;

		Denizen(Denizen&&) noexcept = delete;

		Denizen& operator=(Denizen&&) noexcept = delete;
		
		virtual void ObserveCaveEntrance();
		
		virtual void ReportPresence();
		
		virtual void EnterCave();
		
		virtual void RemoveFromCave();
		
		virtual void GetPriority();

		[[nodiscard]] virtual const DenizenProperties& Properties() const;

		[[nodiscard]] virtual const DenizenIdentifier& GetIdentifier() const;

		DenizenIdentifier m_denizen_identifier_;

		DenizenProperties m_denizen_properties_;
	};

    std::ostream& operator<<(std::ostream& out, const Category& value);
}
