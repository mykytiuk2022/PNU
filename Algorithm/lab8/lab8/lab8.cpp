#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
};

void printBooks(vector<Book>& books) {
    cout << "Список книг:" << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i].title << " (" << books[i].author << ", " << books[i].year << ")" << endl;
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Book> books; // Створення порожнього вектора для зберігання книг

    while (true) {
       
        cout << "Що ви хочете зробити?" << endl;
        cout << "1. Додати книгу" << endl;
        cout << "2. Видалити книгу" << endl;
        cout << "3. Вивести список книг" << endl;
        cout << "4. Вийти з програми" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            Book book;
            cout << "Введіть назву книги: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "Введіть автора книги: ";
            getline(cin, book.author);
            cout << "Введіть рік видання книги: ";
            cin >> book.year;
            books.push_back(book);
            cout << "Книгу додано до списку." << endl;
            break;
        }
        case 2: {
            int index;
            cout << "Введіть номер книги, яку ви хочете видалити: ";
            cin >> index;
            if (index > 0 && index <= books.size()) {
                books.erase(books.begin() + index - 1);
                cout << "Книгу видалено зі списку." << endl;
            }
            else {
                cout << "Помилка: неправильний номер книги." << endl;
            }
            break;
        }
        case 3: {
            printBooks(books);
            break;
        }
        case 4: {
            cout << "Вихід..." << endl;
            return 0;
        }
        default: {
            cout << "Помилка: неправильний ввід. Спробуйте ще раз." << endl;
            break;
        }
        }
    }
    return 0;
}
