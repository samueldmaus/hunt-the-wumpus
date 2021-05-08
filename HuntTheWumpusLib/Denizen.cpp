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

	std::strong_ordering DenizenIdentifier::operator<=>(const DenizenIdentifier& rhs) const
	{
		if (m_category == rhs.m_category)
		{
			return m_instance <=> rhs.m_instance;
		}
		return m_category <=> rhs.m_category;
	}

	bool DenizenIdentifier::operator==(const DenizenIdentifier& rhs) const
	{
		if (m_category == rhs.m_category)
		{
			return m_instance == rhs.m_instance;
		}
		return m_category == rhs.m_category;
	}


	// DENIZEN IDENTIFIER HASHING
	size_t DenizenIdentifierHasher::operator()(const DenizenIdentifier& d) const
	{
		const auto h1 = std::hash<int>{}(static_cast<int>(d.m_category));
		const auto h2 = std::hash<int>{}(d.m_instance);
		return hash_combine(h1, h2);
	}

	// DENIZEN
	Denizen::Denizen(const DenizenIdentifier& identifier, DenizenProperties&& props)
		: m_denizen_identifier_(identifier), m_denizen_properties_(props)
	{
	}
	
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

	const DenizenProperties& Denizen::Properties() const
	{
		return m_denizen_properties_;
	}

	const DenizenIdentifier& Denizen::GetIdentifier() const
	{
		return m_denizen_identifier_;
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
