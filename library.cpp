#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

vector<Book> library;

void addBook() {
    Book b;
    cout << "\nEnter Book ID: ";
    cin >> b.id;
    cin.ignore(); // Clear buffer
    cout << "Enter Book Title: ";
    getline(cin, b.title);
    cout << "Enter Author Name: ";
    getline(cin, b.author);

    library.push_back(b);
    cout << "-> Book added successfully!\n";
}

void showBooks() {
    if (library.empty()) {
        cout << "\nNo books available in the library!\n";
        return;
    }
    cout << "\n=== LIBRARY BOOKS ===\n";
    for (const auto &b : library) {
        cout << "ID: " << b.id << " | Title: " << b.title << " | Author: " << b.author << "\n";
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n-- LIBRARY MANAGEMENT SYSTEM --\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: showBooks(); break;
            case 3: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
