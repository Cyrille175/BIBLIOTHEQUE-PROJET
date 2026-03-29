#include "NotificationService.hpp"

#include <iostream>

void ConsoleNotificationService::notify(const std::string& memberName, const std::string& message) {
    std::cout << "\n[Notification] " << memberName << " -> " << message << "\n";
}