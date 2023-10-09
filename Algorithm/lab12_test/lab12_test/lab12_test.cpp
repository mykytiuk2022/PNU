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

Passenger* head = nullptr;
Passenger* tail = nullptr;

Passenger* readDataFromFile(string fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "������� �������� �����!\\\\\\\\n";
        return nullptr;
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
    return head;
}

void printList(Passenger* head) {
    Passenger* current = head;
    while (current != nullptr) {
        cout << "��� ������: " << current->ticketCode << endl;
        cout << "�������: " << current->lastName << endl;
        cout << "���� ������: " << current->baggageWeight << endl;
        cout << "ʳ������ ���� ������: " << current->baggageCount << endl;
        cout << "����: " << current->date.day << "/" << current->date.month << "/" << current->date.year << endl;
        cout << endl;
        current = current->next;
    }
}

int countNodes(Passenger* head) {
    int count = 0;
    Passenger* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}



void insertBeforeKthNode(Passenger* head, int k, Passenger* newNode) {
    if (k == 1) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        Passenger* current = head;
        for (int i = 1; i < k - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
        if (newNode->next != nullptr) {
            newNode->next->prev = newNode;
        }
    }
}

Passenger* accessKthNode(Passenger* head, int k) {
    Passenger* current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }
    return current;
}

void mergeLists(Passenger* head1, Passenger* head2) {
    Passenger* current = head1;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = head2;
    head2->prev = current;
}

void splitList(Passenger* head, int k) {
    Passenger* current = head;
    for (int i = 1; i < k; i++) {
        current = current->next;
    }
    current->prev->next = nullptr;
    current->prev = nullptr;
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
        newNode->prev = newTail;
        if (newHead == nullptr) {
            newHead = newNode;
            newTail = newNode;
        }
        else {
            newTail->next = newNode;
            newTail = newNode;
        }
        current = current->next;
    }
    return newHead;
}

Passenger* findNode(Passenger* head, string lastName) {
    Passenger* current = head;
    while (current != nullptr) {
        if (current->lastName == lastName) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Passenger* head1 = readDataFromFile("file1.txt");
    Passenger* head2 = readDataFromFile("file2.txt");

    int choice;
    cout << "������ ��� ����: " << endl;
    cout << "1. ������ �� k-�� �������� ������." << endl;
    cout << "2. ������� ������ �������� ����� k-� ���������." << endl;
    cout << "3. ������ ���� ��� ����� ������ � ���� ������." << endl;
    cout << "4. ��������� ������ �� ��� ��� ����� ������." << endl;
    cout << "5. ��������� ������." << endl;
    cout << "6. ϳ�������� ������� �������� � ������." << endl;
    cout << "7. ����� �������� � ������ �� ������ �����." << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        // ������ �� k-�� �������� ������
        Passenger* kthNode = accessKthNode(head1, 3);
        cout << "K-� ������� ������: " << kthNode->lastName << endl;
        break;
    }
    case 2: {
        // ������� ������ �������� ����� k-� ���������
        Passenger* newNode = new Passenger();
        newNode->ticketCode = 1234;
        newNode->lastName = "Smith";
        newNode->baggageWeight = 23.5;
        newNode->baggageCount = 2;
        newNode->date.day = 12;
        newNode->date.month = 6;
        newNode->date.year = 2021;
        insertBeforeKthNode(head1, 3, newNode);
        break;
    }
    case 3: {
        // ������ ���� ��� ����� ������ � ���� ������
        mergeLists(head1, head2);
        break;
    }
    case 4: {
        // ��������� ������ �� ��� ��� ����� ������
        splitList(head1, 5);
        break;
    }
    case 5: {
        // ��������� ������
        Passenger* copyHead = copyList(head2);
        break;
    }
    case 6: {
        // ϳ�������� ������� �������� � ������
        int numNodes = countNodes(head1);
        cout << "ʳ������ �������� � ������: " << numNodes << endl;
        break;
    }
    case 7: {
        // ����� �������� � ������ �� ������ �����
        Passenger* foundNode = findNode(head1, "Johnson");
        if (foundNode != nullptr) {
            cout << "�������� ������� � ����� ������: " << foundNode->ticketCode << endl;
        }
        else {
            cout << "������� � �������� �������� �� ��������." << endl;
        }
        break;
    }
    default: {
        cout << "������������ ����!" << endl;
        break;
    }
    }

    // ��������� ��'������� ������ �� �����
    printList(head1);

    return 0;
}
