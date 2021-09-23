#include "UserNotification.h"

#include <iostream>
#include <stdexcept>
#include <string>

namespace HuntTheWumpus
{
	void UserNotification::AddCallback(const Notification category, std::function<void()>&& callback)
	{
		m_callbacks.insert_or_assign(category, std::move(callback));
	}

	void UserNotification::AddCallback(const Notification category, std::function<void(int)>&& callback)
	{
		m_callbacks.insert_or_assign(category, std::move(callback));
	}

	void UserNotification::AddCallback(const Notification category, std::function<void(const std::vector<int>&)>&& callback)
	{
		m_callbacks.insert_or_assign(category, std::move(callback));
	}

	void UserNotification::Notify(const Notification category) const
	{

		const auto callback = m_callbacks.find(category);

		if (callback != m_callbacks.end())
		{
			const auto* callbackFunc = std::get_if<std::function<void()>>(&callback->second);
			(*callbackFunc)();
		}
		else
		{
			throw std::invalid_argument("Callback function is not defined; please define a callback function for missing User Notification");
		}
	}

	template<typename Callback, typename CallbackArg> void DoCallback(const std::unordered_map<UserNotification::Notification, UserNotification::CallbackData>& callbacks, const UserNotification::Notification callbackId, const CallbackArg& arg)
	{

		const auto callback = callbacks.find(callbackId);

		if (callback != callbacks.end())
		{
			const auto* callbackFunc = std::get_if<Callback>(&callback->second);
			(*callbackFunc)(arg);
		}
		else
		{
			throw std::invalid_argument("Callback function is not defined; please define a callback function for missing User Notification");
		}
	}

	void UserNotification::Notify(const Notification category, const int arg) const
	{
		DoCallback<std::function<void(int)>, int>(m_callbacks, category, arg);
	}

	void UserNotification::Notify(const Notification category, const std::vector<int>& arg) const
	{
		DoCallback<std::function<void(const std::vector<int>&)>, std::vector<int>>(m_callbacks, category, arg);
	}

}
