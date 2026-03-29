#ifndef BOOK_HPP
#define BOOK_HPP

#include <deque>
#include <string>

class Book {
public:
    Book(std::string id,
         std::string title,
         std::string author,
         std::string genre,
         int totalCopies);

    const std::string& id() const;
    const std::string& title() const;
    const std::string& author() const;
    const std::string& genre() const;

    int totalCopies() const;
    int availableCopies() const;
    bool isAvailable() const;

    bool borrowOne();
    void returnOne();

    bool addReservation(const std::string& memberId);
    bool hasReservations() const;
    std::string popNextReservation();
    const std::deque<std::string>& reservationQueue() const;

private:
    std::string id_;
    std::string title_;
    std::string author_;
    std::string genre_;
    int totalCopies_;
    int availableCopies_;
    std::deque<std::string> reservationQueue_;
};

#endif