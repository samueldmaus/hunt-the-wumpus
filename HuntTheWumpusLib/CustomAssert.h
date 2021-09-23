#pragma once

#include <functional>
#include <stdexcept>


class CustomAssert
{
public:
	CustomAssert(std::function<bool()>&& f) : assertExp(std::move(f))
	{
		if (assertExp())
		{
		}
		else
		{
			throw std::logic_error("Boolean expression is false");
		}
	}

	~CustomAssert() = default;

	CustomAssert(const CustomAssert&) = delete;
	CustomAssert(CustomAssert&&) = delete;
	CustomAssert& operator=(const CustomAssert&) = delete;
	CustomAssert& operator=(CustomAssert&&) = delete;

private:
	std::function<bool()> assertExp;
};
