#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;
struct Date {
    int day;
    int month;
    int year;
};
struct Passenger {
    int ticketCode;
    string lastName;
    float baggageWeight;
    int baggageCount;
    Date date;
    Passenger* next;
    Passenger* prev;
};

int listSize = 0;

void readDataFromFile(Passenger*& head, Passenger*& tail, string fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Помилка при відкритті файлу!\n";
        head = nullptr;
        return;
    }
    
    while (!inputFile.eof()) {

        Passenger* newPassenger = new Passenger();
        inputFile >> newPassenger->ticketCode >> newPassenger->lastName >> newPassenger->baggageCount >> newPassenger->baggageWeight;
        inputFile >> newPassenger->date.year >> newPassenger->date.month >> newPassenger->date.day;
        newPassenger->next = nullptr;
        newPassenger->prev = nullptr;
        if (head == nullptr) {
            head = newPassenger;
            tail = newPassenger;
        }
        else {
            tail->next = newPassenger;
            newPassenger->prev = tail;
            tail = newPassenger;
        }
    }
    inputFile.close();
}

void print(Passenger*head) {
    if (head == nullptr) {
        cout << "Список порожній!\n";
        return;
    }
    Passenger* current = head;

    cout << left << setw(13) << "Код білета"
        << setw(20) << "Прізвище"
        << setw(18) << "Кількість багажу"
        << setw(18) << "Вага багажу"
        << setw(12) << "Дата приїзду" << endl << endl;
    while (current != nullptr) {
        cout << left << setw(13) << current->ticketCode
            << setw(20) << current->lastName
            << setw(18) << current->baggageCount
            << setw(18) << current->baggageWeight;
        cout << right << setw(2) << setfill('0') << current->date.day << "."
            << setw(2) << setfill('0') << current->date.month << "." << setfill(' ')
            << left << setw(6) << current->date.year << endl;
        current = current->next;
    }
}
void printR(Passenger* tail) {
    if (tail == nullptr) {
        cout << "Список порожній!\n";
        return;
    }
    Passenger* current = tail;

    cout << left << setw(13) << "Код білета"
        << setw(20) << "Прізвище"
        << setw(18) << "Кількість багажу"
        << setw(18) << "Вага багажу"
        << setw(12) << "Дата приїзду" << endl << endl;
    while (current != nullptr) {
        cout << left << setw(13) << current->ticketCode
            << setw(20) << current->lastName
            << setw(18) << current->baggageCount
            << setw(18) << current->baggageWeight;
        cout << right << setw(2) << setfill('0') << current->date.day << "."
            << setw(2) << setfill('0') << current->date.month << "." << setfill(' ')
            << left << setw(6) << current->date.year << endl;
        current = current->prev;
    }
}
void count(Passenger* head) {
    Passenger* current = head;
    for (listSize = 0; current != nullptr; listSize++)
        current = current->next;
}
void insertBeforeKNode(Passenger*& head, Passenger* newPassenger, int k) {
    if (k == 1 || k== 2) {
        newPassenger->next = head;
        if (head != nullptr) {
            head->prev = newPassenger;
        }
        head = newPassenger;
    }
    else {
        Passenger* current = head;
        for (int i = 1; i < k - 1; i++) {
            current = current->next;
        }
        newPassenger->next = current;
        newPassenger->prev = current->prev;
        current->prev->next = newPassenger;
        current->prev = newPassenger;
    }
}

Passenger* copyList(Passenger* head) {
    Passenger* current = head;
    Passenger* newHead = nullptr;
    Passenger* newTail = nullptr;
    while (current != nullptr) {
        Passenger* newNode = new Passenger();
        newNode->ticketCode = current->ticketCode;
        newNode->lastName = current->lastName;
        newNode->baggageWeight = current->baggageWeight;
        newNode->baggageCount = current->baggageCount;
        newNode->date.day = current->date.day;
        newNode->date.month = current->date.month;
        newNode->date.year = current->date.year;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        if (newHead == nullptr) {
            newHead = newNode;
            newTail = newNode;
        }
        else {
            newTail->next = newNode;
            newNode->prev = newTail;
            newTail = newNode;
        }
        current = current->next;
    }
    return newHead;
}
Passenger* findNode(Passenger* head, string lastName) {
    Passenger* current = head;
    if (head==nullptr) {
        return nullptr;
    }
    while (current != nullptr) {
        if (current->lastName == lastName) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
void merge(Passenger*& head1, Passenger*& tail1,Passenger*& head2, Passenger*& tail2) {
    if (head2 == nullptr) {
        return;
    }
    else if (head1 == nullptr) {
        head1 = head2;
        tail1 = tail2;
    }
    else {
        tail1->next = head2;
        head2->prev = tail1;
        tail1 = tail2;
    }
}

void splitList(Passenger* head, Passenger*tail, int pos) {
    Passenger* head1 = nullptr;
    Passenger* head2 = nullptr;
    Passenger* current = nullptr;
    int mid = listSize / 2;
    if (pos <= mid) {
        current = head;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
    }
    else {
        current = tail;
        for (int i = 1; i <= listSize - pos; i++) {
            current = current->prev;
        }
    }
    head1 = head;
    current->prev->next = nullptr;
    head2 = current;
    head2->prev = nullptr;

    cout << "Розділені списки " << endl;
    cout << "Список 1: " << endl;
    print(head1);
    cout << "Список 2: " << endl;
    print(head2);
}
Passenger* accessNode(Passenger* head, int k) {
    Passenger* current = head;
    for (int i = 0; i < k-1; i++) {
        current = current->next;
    }
    return current;
}
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Passenger* head=nullptr;
    Passenger* tail=nullptr;
    readDataFromFile(head, tail, "passengers_data.txt");
    print(head);
    int choice;
    while (true) {
        cout << "1. Одержати доступ до k-го вузла списку." << endl;
        cout << "2. Включити новий вузол безпосередньо перед k-им вузлом." << endl;
        cout << "3. Об'єднати два лінійних списки в один список." << endl;
        cout << "4. Розбити лінійний список на два списки." << endl;
        cout << "5. Зробити копію лінійного списку." << endl;
        cout << "6. Визначити кількість вузлів у списку." << endl;
        cout << "7. Знайти в списку вузол із заданим значенням у деякім полі." << endl;
        cout << "8. Вихід. " << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            int k;
            cout << "Введіть позицію для пошуку: " << endl;
            cin >> k;
            Passenger* current = accessNode(head, k);
            if (current == nullptr) {
                cout << "Помилка. Список порожній, або елемент не знайдено" << endl;
            }
            else {
                cout << left << setw(13) << current->ticketCode
                    << setw(20) << current->lastName
                    << setw(18) << current->baggageCount
                    << setw(18) << current->baggageWeight;
                cout << right << setw(2) << setfill('0') << current->date.day << "."
                    << setw(2) << setfill('0') << current->date.month << "." << setfill(' ')
                    << left << setw(6) << current->date.year << endl;
            }
            break;
        }
        case 2: {
            Passenger* newPassenger = new Passenger();
            cout << "Введіть позицію: ";
            int pos;
            cin >> pos;
            cout << "Введіть номер білета: ";
            cin >> newPassenger->ticketCode;
            cout << "Введіть прізвище: ";
            cin >> newPassenger->lastName;
            cout << "Введіть кількість багажу: ";
            cin >> newPassenger->baggageCount;
            cout << "Введіть вагу багажу: ";
            cin >> newPassenger->baggageWeight;
            cout << "Введіть рік: ";
            cin >> newPassenger->date.year;
            cout << "Введіть місяць: ";
            cin >> newPassenger->date.month;
            cout << "Введіть день: ";
            cin >> newPassenger->date.day;
            
            insertBeforeKNode(head, newPassenger, pos);
            print(head);
            break;
        }
        case 3: {
            Passenger* head2=nullptr;
            Passenger* tail2=nullptr;
            readDataFromFile(head2, tail2, "passengers_data2.txt");
            merge(head, tail, head2, tail2);
            print(head);
            break;

        }
        case 4: {
            int pos;
            cout << "Введіть позицію для розділення: ";
            cin >> pos;
            splitList(head, tail, pos);
            break;
        }
        case 5: {
            Passenger* newHead = copyList(head);
            print(newHead);
            break;
        }
        case 6: {
            count(head);
            cout << "Кількість вузлів в списку: " << listSize << endl;
            break;
        }
        case 7: {
            string lastName;
            cout << "Введіть прізвище для пошуку: " << endl;
            cin >> lastName;

            Passenger* current = findNode(head, lastName);
            if (current==nullptr) {
                cout << "Помилка. Список порожній, або елемент не знайдено" << endl;
            }
            else {
                cout << left << setw(13) << current->ticketCode
                    << setw(20) << current->lastName
                    << setw(18) << current->baggageCount
                    << setw(18) << current->baggageWeight;
                cout << right << setw(2) << setfill('0') << current->date.day << "."
                    << setw(2) << setfill('0') << current->date.month << "." << setfill(' ')
                    << left << setw(6) << current->date.year << endl;
            }
            break;
        }
        case 8: {
            exit(0);
        }
        default: {
            cout << "Помилка. Спробуйте ще раз" << endl;
            break;
        }
        }
    }
    return 0;
}