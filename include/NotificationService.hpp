#ifndef NOTIFICATION_SERVICE_HPP
#define NOTIFICATION_SERVICE_HPP

#include <string>

class NotificationService {
public:
    virtual ~NotificationService() = default;
    virtual void notify(const std::string& memberName, const std::string& message) = 0;
};

class ConsoleNotificationService : public NotificationService {
public:
    void notify(const std::string& memberName, const std::string& message) override;
};

#endif