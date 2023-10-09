#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

// ���������� ��������� ��� ��������� ����� ��� �����
struct Book {
    string title;
    string author;
    int year;
};

// ������� ��� ������ ������ ����
void printBooks(Book* books, int size) {
    cout << "������ ����:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << books[i].title << " (" << books[i].author << ", " << books[i].year << ")" << endl;
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Book* books=nullptr; // ���������� �������� �� ����� ����
    int size = 0; // ����� ������ ����
    
    while (true) {
        // ���� ���� �����������
        cout << "�� �� ������ �������?" << endl;
        cout << "1. ������ �����" << endl;
        cout << "2. �������� �����" << endl;
        cout << "3. ������� ������ ����" << endl;
        cout << "4. ����� � ��������" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            // ��������� ���� �����
            Book book;
            cout << "������ ����� �����: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "������ ������ �����: ";
            getline(cin, book.author);
            cout << "������ �� ������� �����: ";
            cin >> book.year;

            // ��������� ������ ������ ���� �� 1
            Book* newBooks = new Book[size + 1];
            for (int i = 0; i < size; i++) {
                newBooks[i] = books[i];
            }
            newBooks[size] = book;
            size++;

            // ��������� ���'�� ������������ ������ �� ��������� ��������� ������ ������ ������
            delete[] books;
            books = newBooks;

            cout << "����� ������ �� ������." << endl;
            break;
        }
        case 2: {
            // ��������� ����� �� �������
            int index;
            cout << "������ ����� �����, ��� �� ������ ��������: ";
            cin >> index;
            if (index > 0 && index <= size) {
                // ��������� ������ ������ ���� �� 1
                Book* newBooks = new Book[size - 1];
                for (int i = 0, j = 0; i < size; i++) {
                    if (i + 1 != index) {
                        newBooks[j] = books[i];
                        j++;
                    }
                }
                size--;

                // ��������� ���'�� ������������ ������ �� ��������� ��������� ������ ������ ������
                delete[] books;
                books = newBooks;
                
                cout << "����� �������� � ������." << endl;
            }
            else {
                cout << "�������: ������������ ����� �����." << endl;
            }
            break;
        }
        case 3: {
            // ���� ������ ����
            printBooks(books, size);
            break;
        }
        case 4: {
            // ����� � ��������
            cout << "�����..." << endl;

            // ��������� ���'�� ���������� ������
            delete[] books;

            return 0;
        }
        default: {
            // ���������� ���
            cout << "�������: ������������ ���. ��������� �� ���." << endl;
            break;
        }
        }
    }
    return 0;
}
