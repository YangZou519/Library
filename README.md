# Library Management System

This project implements a simple Library Management System in C++, which allows users to manage books and patrons within a library. It includes functionalities for adding, renting, and returning books, as well as managing the records of people using the library.

## Files in the Project

### 1. `library.h`
This header file defines the classes and functions necessary for managing the library. Key classes include:

- **Book**: Represents a book in the library with attributes like title, code, available copies, and rented copies.
- **Person**: Represents a library user with details like name, ID, and the books they have rented.
- **Library**: Manages the collection of books and patrons, including functions to add books, rent books to patrons, and return books.

### 2. `library.cpp`
This source file contains the implementation of the classes and functions declared in `library.h`. It handles the logic for:

- **Adding Books**: Inserting new books into the library’s collection.
- **Renting Books**: Allowing patrons to rent books, with checks on availability and user limits.
- **Returning Books**: Managing the return of books and updating the library’s records.
- **Sorting Records**: Sorting the books and patrons in the library based on certain criteria.

### 3. `main.cpp`
The main file serves as the entry point to the program. It interacts with the user, providing a menu to:

- **Add Books**: Allows the user to add new books to the library.
- **Rent Books**: Facilitates the process of renting a book to a library user.
- **Return Books**: Handles the return process of rented books.
- **Display Records**: Outputs the current state of the library, including available and rented books, as well as patron information.
