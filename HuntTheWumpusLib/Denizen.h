#pragma once

#include <compare>
#include <memory>

namespace HuntTheWumpus
{
    class Cave;
    class IRandomProvider;
    struct Context;

    enum class Category
    {
        Wumpus,
        Pit,
        Bat,
        Hunter,
        Arrow
    };

    struct DenizenIdentifier
    {
        Category m_category;
        int m_instance;

        bool operator==(const DenizenIdentifier &other) const;
        std::strong_ordering operator <=>(const DenizenIdentifier &other) const;
    };

    struct DenizenIdentifierHasher
    {
        size_t operator()(const DenizenIdentifier &id) const;
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
        Denizen(const DenizenIdentifier& identifier, DenizenProperties &&properties, Context& providers);
        virtual ~Denizen() = default;

        // Properties of Thing
        [[nodiscard]] const DenizenProperties &Properties() const { return m_properties; }

        [[nodiscard]] const DenizenIdentifier &GetIdentifier() const { return m_identifier; }

    	[[nodiscard]] virtual int GetPriority() const = 0;

		static int EnterCave(const Cave& cave);

        Denizen(const Denizen&) = delete;
        Denizen(Denizen&&) = delete;
        Denizen& operator=(const Denizen&) = delete;
        Denizen& operator=(Denizen&&) = delete;

    protected:

        DenizenIdentifier m_identifier;
        DenizenProperties m_properties;

        Context& m_providers;
    };

    std::ostream& operator<<(std::ostream& out, const Category& value);
}
