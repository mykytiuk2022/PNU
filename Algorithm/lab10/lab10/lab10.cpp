#include <iostream>
#include <string>
#include <ctime>
#include <set>
#include <algorithm>
#include <Windows.h>

using namespace std;
void printSchedule(const set<string>& schedule) {
    for (const auto& subject : schedule) {
        cout << "- " << subject << endl;
    }
    cout << endl;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //���� �� �����:��� �� ��.
    set<string> IPZ = {"������ ������", "Front-end ��������", "��������� �� ��������� �����", "������������ �����", "��������� ����"};
    set<string> KN = {"������ ������", "������������ �����", "�������������", "��������� ����", "����������� �����"};
    while (true) {
        cout << "1. ��������� ������ �������� ���� ����." << endl;
        cout << "2. ��������� ��������." << endl;
        cout << "3. ��������� ��������." << endl;
        cout << "4. ��'������� ������ ��������. ��������� �������" << endl;
        cout << "5. ������� ������ �������. ����� �������� ��� ���� ����" << endl;
        cout << "6. г����� ������. �������� ���, ��� �������� ��" << endl;
        cout << "7. ���������� ������. ��������, �� �� � ��������" << endl;
        cout << "8. ���������� ������ ��������" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "�:" << endl;

            cout << "������� ���:" << endl;
            printSchedule(IPZ);
            cout << "������� ��:" << endl;
            printSchedule(KN);
            break;
        }
        case 2: {
            string choiceAdd, subject;
            cout << "������� �����, � ��� ������ ������ �������: " << endl;
            cin >> choiceAdd;
            if (choiceAdd == "���") {
                cout << "������ �������: " << endl;
                cin.ignore();
                getline(cin, subject);
                IPZ.insert(subject);
                cout << "������� ������." << endl;
            }
            else if (choiceAdd == "��") {
                cout << "������ �������: " << endl;
                cin.ignore();
                getline(cin, subject);
                KN.insert(subject);
                cout << "������� ������." << endl;
            }
            else {
                cout << "�������: ������������ ���.";
            }
            break;
        }
        case 3: {
            string choiceDel, subject;
            cout << "������� �����, � ��� ������ �������� �������: " << endl;
            cin >> choiceDel;
            if (choiceDel == "���") {
                cout << "������ �������: " << endl;
                cin.ignore();
                getline(cin, subject);
                IPZ.erase(subject);
                cout << "������� ��������." << endl;

            }
            else if (choiceDel == "��") {
                cout << "������ �������: " << endl;
                cin.ignore();
                getline(cin, subject);
                KN.erase(subject);
                cout << "������� ��������." << endl;

            }
            else {
                cout << "�������: ������������ ���.";
            }
            break;
        }
        case 4: {
            cout << "4. ��'������� ������ ��������. ��������� �������" << endl;
            set<string> unionGroup;
            set_union(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(unionGroup, unionGroup.end()));
            printSchedule(unionGroup);
            break;
        }
        case 5: {
            cout << "5. ������� ������ �������. ����� �������� ��� ���� ����" << endl;
            set<string> intersectionGroup;
            set_intersection(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(intersectionGroup, intersectionGroup.begin()));
            printSchedule(intersectionGroup);
            break;
        }
        case 6: {
            cout << "6. г����� ������. �������� ���, ��� �������� ��" << endl;
            set<string> differenceGroup;
            set_difference(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(differenceGroup, differenceGroup.begin()));
            printSchedule(differenceGroup);
            break;
        }
        case 7: {
            cout << "7. ���������� ������. ��������, �� �� � ��������" << endl;
            set <string> symmetricGroup;
            set_symmetric_difference(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(symmetricGroup, symmetricGroup.begin()));
            printSchedule(symmetricGroup);
            break;
        }
        case 8: {
            cout << "�����..." << endl;
            return 0;
        }
        default: {
            cout << "�������: ������������ ���. ��������� �� ���." << endl;
            break;
        }
        }
    }
}