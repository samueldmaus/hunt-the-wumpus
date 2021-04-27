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

	class DenizenIdentifier
	{
	public:
		DenizenIdentifier(const Category c, const int i);

		std::strong_ordering operator<=>(const DenizenIdentifier& rhs) const;

		bool operator==(const DenizenIdentifier&) const = default;
		
		Category m_category;
		
		int m_instance;
	};

	class DenizenIdentifierHasher
	{
	public:
		DenizenIdentifierHasher() = default;

		size_t operator()(const DenizenIdentifier& d) const;
	};

	class DenizenProperties
	{
	public:
		DenizenProperties(const bool c, const bool fW, const bool fH, const bool e, const bool r);
		
		bool m_carryableByBats;
		bool m_fatalToWumpus;
		bool m_fatalToHunter;
		bool m_isEdible;
		bool m_reportMovement;
	};

	class Denizen
	{
	public:
		Denizen() = default;
		
		virtual ~Denizen() = default; 
		
		virtual void ObserveCaveEntrance();
		
		virtual void ReportPresence();
		
		virtual void EnterCave();
		
		virtual void RemoveFromCave();
		
		virtual void GetPriority();

		[[nodiscard]] virtual const DenizenProperties& Properties() const = 0;

		[[nodiscard]] virtual const DenizenIdentifier& GetIdentifier() const = 0;
	};

    std::ostream& operator<<(std::ostream& out, const Category& value);
}
