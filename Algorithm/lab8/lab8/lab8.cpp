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
    cout << "������ ����:" << endl;
    for (int i = 0; i < books.size(); i++) {
        cout << i + 1 << ". " << books[i].title << " (" << books[i].author << ", " << books[i].year << ")" << endl;
    }
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<Book> books; // ��������� ���������� ������� ��� ��������� ����

    while (true) {
       
        cout << "�� �� ������ �������?" << endl;
        cout << "1. ������ �����" << endl;
        cout << "2. �������� �����" << endl;
        cout << "3. ������� ������ ����" << endl;
        cout << "4. ����� � ��������" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            Book book;
            cout << "������ ����� �����: ";
            cin.ignore();
            getline(cin, book.title);
            cout << "������ ������ �����: ";
            getline(cin, book.author);
            cout << "������ �� ������� �����: ";
            cin >> book.year;
            books.push_back(book);
            cout << "����� ������ �� ������." << endl;
            break;
        }
        case 2: {
            int index;
            cout << "������ ����� �����, ��� �� ������ ��������: ";
            cin >> index;
            if (index > 0 && index <= books.size()) {
                books.erase(books.begin() + index - 1);
                cout << "����� �������� � ������." << endl;
            }
            else {
                cout << "�������: ������������ ����� �����." << endl;
            }
            break;
        }
        case 3: {
            printBooks(books);
            break;
        }
        case 4: {
            cout << "�����..." << endl;
            return 0;
        }
        default: {
            cout << "�������: ������������ ���. ��������� �� ���." << endl;
            break;
        }
        }
    }
    return 0;
}
