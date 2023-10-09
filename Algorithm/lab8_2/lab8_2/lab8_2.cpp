#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

// Оголошення структури для зберігання даних про книгу
struct Book {
    string title;
    string author;
    int year;
};

// Функція для виводу списку книг
void printBooks(Book* books, int size) {
    cout << "Список книг:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << books[i].title << " (" << books[i].author << ", " << books[i].year << ")" << endl;
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Book* books=nullptr; // Ініціалізуємо вказівник на масив книг
    int size = 0; // Розмір масиву книг
    
    while (true) {
        // Вивід меню користувачу
        cout << "Що ви хочете зробити?" << endl;
        cout << "1. Додати книгу" << endl;
        cout << "2. Видалити книгу" << endl;
        cout << "3. Вивести список книг" << endl;
        cout << "4. Вийти з програми" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // Додавання нової книги
            Book book;
            cout << "Введіть назву книги: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "Введіть автора книги: ";
            getline(cin, book.author);
            cout << "Введіть рік видання книги: ";
            cin >> book.year;

            // Збільшення розміру масиву книг на 1
            Book* newBooks = new Book[size + 1];
            for (int i = 0; i < size; i++) {
                newBooks[i] = books[i];
            }
            newBooks[size] = book;
            size++;

            // Звільнення пам'яті попереднього масиву та присвоєння вказівнику адреси нового масиву
            delete[] books;
            books = newBooks;

            cout << "Книгу додано до списку." << endl;
            break;
        }
        case 2: {
            // Видалення книги за номером
            int index;
            cout << "Введіть номер книги, яку ви хочете видалити: ";
            cin >> index;
            if (index > 0 && index <= size) {
                // Зменшення розміру масиву книг на 1
                Book* newBooks = new Book[size - 1];
                for (int i = 0, j = 0; i < size; i++) {
                    if (i + 1 != index) {
                        newBooks[j] = books[i];
                        j++;
                    }
                }
                size--;

                // Звільнення пам'яті попереднього масиву та присвоєння вказівнику адреси нового масиву
                delete[] books;
                books = newBooks;
                
                cout << "Книгу видалено зі списку." << endl;
            }
            else {
                cout << "Помилка: неправильний номер книги." << endl;
            }
            break;
        }
        case 3: {
            // Вивід списку книг
            printBooks(books, size);
            break;
        }
        case 4: {
            // Вихід з програми
            cout << "Вихід..." << endl;

            // Звільнення пам'яті динамічного масиву
            delete[] books;

            return 0;
        }
        default: {
            // Помилковий ввід
            cout << "Помилка: неправильний ввід. Спробуйте ще раз." << endl;
            break;
        }
        }
    }
    return 0;
}
