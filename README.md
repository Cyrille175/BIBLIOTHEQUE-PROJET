# BIBLIOTHEQUE-PROJET

BIBLIOTHEQUE-PROJET is a console-based C++ application that simulates a small library management system.

The project is designed around object-oriented programming and models the main entities of a library: books, members and loans. In addition to standard borrowing and returning operations, it also includes reservation queues, late-return fines, event logging and simple book recommendations based on user borrowing history.

## Main Features

- Book and member management
- Borrowing and returning system
- Automatic due dates
- Reservation queue when a book is unavailable
- Late return fine calculation
- Event log for traceability
- Book recommendations based on favorite genres
- Console notifications when a reserved book becomes available

## Project Structure

```text
BIBLIOTHEQUE-PROJET/
├── CMakeLists.txt
├── .gitignore
├── README.md
├── include/
└── src/