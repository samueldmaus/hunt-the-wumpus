#include "Denizen.h"

#include <bit>
#include <functional>
#include <iostream>

namespace HuntTheWumpus
{
    // See https://stackoverflow.com/questions/35985960/c-why-is-boosthash-combine-the-best-way-to-combine-hash-values/50978188
    size_t xorshift(const size_t n, const int i)
    {
        return n ^ (n >> i);
    }

    uint32_t distribute(const uint32_t n)
    {
        constexpr uint32_t p = 0x55555555ul; // pattern of alternating 0 and 1
        constexpr uint32_t c = 3423571495ul; // random uneven integer constant; 
        return static_cast<uint32_t>(c * xorshift(p * xorshift(n, 16), 16));
    }

    size_t hash_combine(const std::size_t seed, const size_t v)
    {
        return std::rotl(seed, std::numeric_limits<size_t>::digits / 3) ^ distribute(static_cast<uint32_t>(v));
    }

	std::strong_ordering operator<=>(Category& lhs, Category& rhs)
    {

    	return static_cast<int>(lhs) <=> static_cast<int>(rhs);
    }

	
	// DENIZEN IDENTIFIER
    DenizenIdentifier::DenizenIdentifier(const Category c, const int i)
	    : m_category(c), m_instance(i)
    {
    }

    std::strong_ordering DenizenIdentifier::operator<=>(const DenizenIdentifier& rhs) const
    {
        if(m_category == rhs.m_category)
    	{
    		return m_instance <=> rhs.m_instance;
    	}
        return m_category <=> rhs.m_category;
    }

	
	// DENIZEN IDENTIFIER HASHING
	size_t DenizenIdentifierHasher::operator()(const DenizenIdentifier& d) const
    {
        return hash_combine(static_cast<size_t>(d.m_category), d.m_instance);
    }

	
	// DENIZEN PROPERTIES
	DenizenProperties::DenizenProperties(const bool c, const bool fW, const bool fH, const bool e, const bool r)
        : m_carryableByBats(c), m_fatalToWumpus(fW), m_fatalToHunter(fH), m_isEdible(e), m_reportMovement(r)
	{
	}

	// DENIZEN
    void Denizen::ObserveCaveEntrance()
    {
    }

    void Denizen::ReportPresence()
    {
    }

    void Denizen::EnterCave()
    {
    }

    void Denizen::RemoveFromCave()
    {
    }

    void Denizen::GetPriority()
    {
    }
	
    std::ostream& operator<<(std::ostream& out, const Category& value)
    {
        static std::unordered_map<Category, std::string> s_valueMap =
        {
            {Category::Arrow, "Arrow" },
            {Category::Bat, "Bat" },
            {Category::Hunter, "Hunter" },
            {Category::Pit, "Pit" },
            {Category::Wumpus, "Wumpus" }
        };

        out << s_valueMap[value];
        return out;
    }

}
