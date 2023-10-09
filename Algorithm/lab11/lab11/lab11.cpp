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
};
Passenger* readDataFromFile(string fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "������� ��� ������� �����!\n";
        return nullptr;
    }

    Passenger* head = nullptr;
    Passenger* current = head;
    while (!inputFile.eof()) {
        
        Passenger* newPassenger = new Passenger();
        inputFile >> newPassenger->ticketCode  >> newPassenger->lastName  >> newPassenger->baggageCount >> newPassenger->baggageWeight;
        inputFile >> newPassenger->date.year >> newPassenger->date.month >> newPassenger->date.day;
        newPassenger->next = nullptr;
        if (head == nullptr) {
            head = newPassenger;
            current = newPassenger;
        }
        else {
            current->next = newPassenger;

            current = newPassenger;
        }
    }

    inputFile.close();
    return head;
}
void print(Passenger* head) {

    if (head == nullptr) {
        cout << "������ �������!\n";
        return;
    }
    Passenger* current = head;

    cout << left << setw(13) << "��� �����"
        << setw(20) << "�������"
        << setw(18) << "ʳ������ ������"
        << setw(18) << "���� ������"
        << setw(12) << "���� ������" << endl << endl;
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
void sortByTicket(Passenger* head) {
    Passenger* current = head;
    Passenger* search = nullptr;

    while (current != nullptr) {
        search = current;
        Passenger* minNode = current;

        while (search != nullptr) {
            if (search->ticketCode < minNode->ticketCode) {
                minNode = search;
            }
            search = search->next;
        }

        Passenger* tmp = new Passenger();
        tmp->ticketCode = current->ticketCode;
        tmp->lastName = current->lastName;
        tmp->baggageCount = current->baggageCount;
        tmp->baggageWeight = current->baggageWeight;
        tmp->date = current->date;

        current->ticketCode = minNode->ticketCode;
        current->lastName = minNode->lastName;
        current->baggageCount = minNode->baggageCount;
        current->baggageWeight = minNode->baggageWeight;
        current->date = minNode->date;

        minNode->ticketCode = tmp->ticketCode;
        minNode->lastName = tmp->lastName;
        minNode->baggageCount = tmp->baggageCount;
        minNode->baggageWeight = tmp->baggageWeight;
        minNode->date = tmp->date;

        current = current->next;
        delete tmp;
    }
}


Passenger* mergeLists(Passenger* list1, Passenger* list2) {
    // ����������, �� ���� � ������ �������. ���� ���, �� ��������� ����� 
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    // ��������� ����� ������ �� ���������� ����� 
    Passenger* headMerged = nullptr;
    Passenger* current = nullptr;

    if (list1->ticketCode <= list2->ticketCode) {
        headMerged = list1;
        list1 = list1->next;
    }
    else {
        headMerged = list2;
        list2 = list2->next;
    }
    // �������� � ������� ����� headMerged � �� ���� ������ ����� � ������ list1 �� list2.
    // �������� � �����, ���� ���� � ������ ���������.
    current = headMerged;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->ticketCode <= list2->ticketCode) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    // ������ �� �����, �� ���������� � ������ � ������.
    if (list1 == nullptr) {
        current->next = list2;
    }
    else {
        current->next = list1;
    }
    // ��������� ���������� ����� ������ ������.
    return headMerged;
}
void addElement(Passenger* head, Passenger* newPassenger) {
    if (head == nullptr) {
        newPassenger->next = nullptr;
        head = newPassenger;
    }
    else {
        Passenger* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        newPassenger->next = nullptr;
        current->next = newPassenger;
    }
}
void addElement(Passenger* head, Passenger* newPassenger, int pos) {
    pos--;
    if (pos == 0) {
        newPassenger->next = head;
        head = newPassenger;
    }
    else {
        Passenger* current = head;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        newPassenger->next = current->next;
        current->next = newPassenger;
    }
}
void delElement(Passenger* head, string lastName) {
    Passenger* prev = nullptr;
    Passenger* current = head;
    while (current != nullptr) {
        if (current->lastName == lastName) {
            if (current == head) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;

    }
}
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Passenger* head1 = readDataFromFile("passengers_data.txt");
    int choice;

    while (true) {
        cout << "������� ��: "<<endl;
        cout << "1. ������� ������ �� �����. " << endl;
        cout << "2. �������� ����� ������� � ������. " << endl;
        cout << "3. �������� ������� � ������. " << endl;
        cout << "4. ³���������� ������ �� ����� �����. " << endl;
        cout << "5. ��������� ����� ������, ����������� �� ��'������ � ��� ��������. " << endl;
        cout << "6. ��������� ������ �������� " << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            print(head1);
            break;
        }
        case 2: {
            Passenger* newPassenger = new Passenger();
            cout << "������ ����� �����: ";
            cin >> newPassenger->ticketCode;
            cout << "������ �������: ";
            cin >> newPassenger->lastName;
            cout << "������ ������� ������: ";
            cin >> newPassenger->baggageCount;
            cout << "������ ���� ������: ";
            cin >> newPassenger->baggageWeight;
            cout << "������ ��: ";
            cin >> newPassenger->date.year;
            cout << "������ �����: ";
            cin >> newPassenger->date.month;
            cout << "������ ����: ";
            cin >> newPassenger->date.day;
           /* int pos;
            cin >> pos;*/
            addElement(head1, newPassenger);
            break;
        }
        case 3: {
            string lastName;
            cout << "������ �������: ";
            cin >> lastName;
            delElement(head1, lastName);
            break;
        }
        case 4: {
            sortByTicket(head1);
            print(head1);
            break;
        }
        case 5: {
            Passenger* head2 = readDataFromFile("passengers_data2.txt");
            sortByTicket(head2);
            cout << "����� ������: " << endl;
            print(head2);
            cout << "��'������� ������: " << endl;
            Passenger* headM = mergeLists(head1, head2);
            print(headM);
            break;
        }
        case 6: {
            cout << "�����." << endl;
            exit(0);
        }
        default: {
            cout << "�������. ������������ ���." << endl;
            break;
        }
        }
    }
    
    return 1;
}