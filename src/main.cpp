#include "Library.hpp"
#include "NotificationService.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

namespace {
void printBooks(Library& library) {
    auto books = library.allBooks();

    std::cout << "\n================ BOOKS ================\n";
    std::cout << std::left
              << std::setw(8) << "ID"
              << std::setw(28) << "Title"
              << std::setw(20) << "Author"
              << std::setw(15) << "Genre"
              << std::setw(10) << "Avail"
              << "\n";

    for (auto* book : books) {
        std::cout << std::left
                  << std::setw(8) << book->id()
                  << std::setw(28) << book->title()
                  << std::setw(20) << book->author()
                  << std::setw(15) << book->genre()
                  << std::setw(10) << (std::to_string(book->availableCopies()) + "/" + std::to_string(book->totalCopies()))
                  << "\n";
    }
}

void printMembers(Library& library) {
    auto members = library.allMembers();

    std::cout << "\n================ MEMBERS ================\n";
    for (auto* member : members) {
        std::cout << member->id() << " | "
                  << member->name() << " | active loans: "
                  << member->currentLoanIds().size() << " | fine: "
                  << member->outstandingFine() << " EUR\n";
    }
}

void printLoans(Library& library) {
    auto loans = library.activeLoans();

    std::cout << "\n================ ACTIVE LOANS ================\n";
    if (loans.empty()) {
        std::cout << "No active loans.\n";
        return;
    }

    for (auto* loan : loans) {
        std::cout << loan->id()
                  << " | book: " << loan->bookId()
                  << " | member: " << loan->memberId()
                  << " | due: " << loan->dueOn().toString()
                  << "\n";
    }
}

void printRecommendations(Library& library) {
    std::string memberId;
    std::cout << "Member ID: ";
    std::cin >> memberId;

    auto recommendations = library.recommendBooks(memberId);
    if (recommendations.empty()) {
        std::cout << "No recommendation available yet.\n";
        return;
    }

    std::cout << "\nRecommendations:\n";
    for (auto* book : recommendations) {
        std::cout << "- " << book->title()
                  << " by " << book->author()
                  << " [" << book->genre() << "]\n";
    }
}

void printSearch(Library& library) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string keyword;
    std::cout << "Keyword: ";
    std::getline(std::cin, keyword);

    auto results = library.searchBooks(keyword);
    if (results.empty()) {
        std::cout << "No result.\n";
        return;
    }

    for (auto* book : results) {
        std::cout << book->id() << " | "
                  << book->title() << " | "
                  << book->author() << " | "
                  << book->genre() << "\n";
    }
}
}

int main() {
    auto notifier = std::make_shared<ConsoleNotificationService>();
    Library library(notifier);

    library.addBook(std::make_unique<Book>("B100", "Clean Code", "Robert C. Martin", "Software", 2));
    library.addBook(std::make_unique<Book>("B101", "The Pragmatic Programmer", "Andrew Hunt", "Software", 1));
    library.addBook(std::make_unique<Book>("B102", "Dune", "Frank Herbert", "Science Fiction", 2));
    library.addBook(std::make_unique<Book>("B103", "1984", "George Orwell", "Dystopia", 1));

    library.addMember(std::make_unique<Member>("M100", "Alice"));
    library.addMember(std::make_unique<Member>("M101", "Brian"));
    library.addMember(std::make_unique<Member>("M102", "Chloe"));

    bool running = true;

    while (running) {
        std::cout << "\n================ LIBRARY MANAGER ================\n";
        std::cout << "1. List books\n";
        std::cout << "2. List members\n";
        std::cout << "3. List active loans\n";
        std::cout << "4. Borrow a book\n";
        std::cout << "5. Return a book\n";
        std::cout << "6. Reserve a book\n";
        std::cout << "7. Search books\n";
        std::cout << "8. Show recommendations for a member\n";
        std::cout << "9. Show event log\n";
        std::cout << "10. Pay fine\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        int choice = -1;
        std::cin >> choice;

        switch (choice) {
            case 1:
                printBooks(library);
                break;
            case 2:
                printMembers(library);
                break;
            case 3:
                printLoans(library);
                break;
            case 4: {
                std::string bookId, memberId;
                std::cout << "Book ID: ";
                std::cin >> bookId;
                std::cout << "Member ID: ";
                std::cin >> memberId;

                if (library.borrowBook(bookId, memberId)) {
                    std::cout << "Operation completed.\n";
                } else {
                    std::cout << "Borrow failed.\n";
                }
                break;
            }
            case 5: {
                std::string loanId;
                std::cout << "Loan ID: ";
                std::cin >> loanId;

                if (library.returnBook(loanId)) {
                    std::cout << "Return completed.\n";
                } else {
                    std::cout << "Return failed.\n";
                }
                break;
            }
            case 6: {
                std::string bookId, memberId;
                std::cout << "Book ID: ";
                std::cin >> bookId;
                std::cout << "Member ID: ";
                std::cin >> memberId;

                if (library.reserveBook(bookId, memberId)) {
                    std::cout << "Reservation added.\n";
                } else {
                    std::cout << "Reservation failed.\n";
                }
                break;
            }
            case 7:
                printSearch(library);
                break;
            case 8:
                printRecommendations(library);
                break;
            case 9: {
                std::cout << "\n================ EVENT LOG ================\n";
                for (const auto& entry : library.eventLog()) {
                    std::cout << "- " << entry << "\n";
                }
                break;
            }
            case 10: {
                std::string memberId;
                double amount = 0.0;
                std::cout << "Member ID: ";
                std::cin >> memberId;
                std::cout << "Amount: ";
                std::cin >> amount;

                if (library.payFine(memberId, amount)) {
                    std::cout << "Payment recorded.\n";
                } else {
                    std::cout << "Payment failed.\n";
                }
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
                break;
        }
    }

    return 0;
}