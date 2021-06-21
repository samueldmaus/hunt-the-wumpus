﻿#include "UserNotification.h"

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

        const auto* callbackFunc = std::get_if<std::function<void()>>(&callback->second);
        (*callbackFunc)();
    }

    template<typename Callback, typename CallbackArg> void DoCallback(const std::unordered_map<UserNotification::Notification, UserNotification::CallbackData>& callbacks, const UserNotification::Notification callbackId, const CallbackArg& arg)
    {
        const auto callback = callbacks.find(callbackId);

        const auto* callbackFunc = std::get_if<Callback>(&callback->second);
	     (*callbackFunc)(arg);
    }

    void UserNotification::Notify(const Notification category, const int arg) const
    {
        DoCallback<std::function<void(int)>, int>(m_callbacks, category, arg);
    }

    void UserNotification::Notify(const Notification category, const std::vector<int>& arg) const
    {
        DoCallback<std::function<void(const std::vector<int> &)>, std::vector<int>>(m_callbacks, category, arg);
    }
}
