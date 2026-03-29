#include "Book.hpp"

#include <algorithm>

Book::Book(std::string id,
           std::string title,
           std::string author,
           std::string genre,
           int totalCopies)
    : id_(std::move(id)),
      title_(std::move(title)),
      author_(std::move(author)),
      genre_(std::move(genre)),
      totalCopies_(totalCopies > 0 ? totalCopies : 1),
      availableCopies_(totalCopies_){}

const std::string& Book::id() const { return id_; }
const std::string& Book::title() const { return title_; }
const std::string& Book::author() const { return author_; }
const std::string& Book::genre() const { return genre_; }

int Book::totalCopies() const { return totalCopies_; }
int Book::availableCopies() const { return availableCopies_; }

bool Book::isAvailable() const {
    return availableCopies_ > 0;
}

bool Book::borrowOne() {
    if (availableCopies_ <= 0) {
        return false;
    }
    --availableCopies_;
    return true;
}

void Book::returnOne() {
    if (availableCopies_ < totalCopies_) {
        ++availableCopies_;
    }
}

bool Book::addReservation(const std::string& memberId) {
    auto it = std::find(reservationQueue_.begin(), reservationQueue_.end(), memberId);
    if (it != reservationQueue_.end()) {
        return false;
    }

    reservationQueue_.push_back(memberId);
    return true;
}

bool Book::hasReservations() const {
    return !reservationQueue_.empty();
}

std::string Book::popNextReservation() {
    if (reservationQueue_.empty()) {
        return {};
    }

    std::string next = reservationQueue_.front();
    reservationQueue_.pop_front();
    return next;
}

const std::deque<std::string>& Book::reservationQueue() const {
    return reservationQueue_;
}