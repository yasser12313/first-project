#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;
int bookCount = 0;
int bookIDs[MAX_BOOKS];
string bookTitles[MAX_BOOKS];
string bookAuthors[MAX_BOOKS];
bool isBorrowed[MAX_BOOKS]; 

void addBook() {
    if (bookCount < MAX_BOOKS) {
        cout << "Enter book ID: ";
        cin >> bookIDs[bookCount];
        cout << "Enter book title: ";
        cin >> bookTitles[bookCount];
        cout << "Enter author name: ";
        cin >> bookAuthors[bookCount];
        isBorrowed[bookCount] = false; 
        bookCount++;
        cout << "Book added successfully!"<<endl;
    }
    else {
        cout << "Library is full!"<<endl;
    }
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "No books available in the library."<<endl;
        return;
    }
    cout << "\nLibrary Books:"<<endl;
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << bookIDs[i] << ", Title: " << bookTitles[i]
            << ", Author: " << bookAuthors[i]
            << ", Status: " << (isBorrowed[i] ? "Borrowed" : "Available") << endl;
    }
}

void borrowBook() {
    int id;
    cout << "Enter book ID to borrow: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (bookIDs[i] == id) {
            if (isBorrowed[i] == true) {
                cout << "Book is already borrowed."<<endl;
            }
            else {
                isBorrowed[i] = true; 
                cout << "Book borrowed successfully!"<<endl;
            }
            return;
        }
    }
    cout << "Book not found."<<endl;
}

void returnBook() {
    int id;
    cout << "Enter book ID to return: ";
    cin >> id;
    for (int i = 0; i < bookCount; i++) {
        if (bookIDs[i] == id) {
            if (isBorrowed[i] == false) {
                cout << "Book is not borrowed."<<endl;
            }
            else {
                isBorrowed[i] = false;
                cout << "Book returned successfully!"<<endl;
            }
            return;
        }
    }
    cout << "Book not found."<<endl;
}

int menu() {
    int choice = 0;
    while (choice != 5) {
        cout << "1. Add Book"<<endl;
        cout << "2. Display Books"<<endl;
        cout << "3. Borrow Book"<<endl;
        cout << "4. Return Book"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addBook();
            break;
        case 2: displayBooks();
            break;
        case 3: borrowBook();
            break;
        case 4: returnBook();
            break;
        case 5: cout << "GoodBye";
            break;
        default: cout << "Invalid choice. Try again."<<endl;
        }
    }
    return 0;
}

int main() {
     menu();
}