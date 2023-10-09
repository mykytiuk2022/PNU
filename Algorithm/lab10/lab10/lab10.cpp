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
    //дано дві групи:ІПЗ та КН.
    set<string> IPZ = {"Історія України", "Front-end розробка", "Алгоритми та структури даних", "Математичний аналіз", "Англійська мова"};
    set<string> KN = {"Історія України", "Математичний аналіз", "Програмування", "Англійська мова", "Математична логіка"};
    while (true) {
        cout << "1. Виведення списку предметів обох груп." << endl;
        cout << "2. Додавання предмета." << endl;
        cout << "3. Видалення предмета." << endl;
        cout << "4. Об'єднання списку предметів. Загальний розклад" << endl;
        cout << "5. Перетин списку предетів. Спільні предмети для обох груп" << endl;
        cout << "6. Різниця занять. Предмети ІПЗ, без предметів КН" << endl;
        cout << "7. Симетрична різниця. Предмети, що не є спільними" << endl;
        cout << "8. Завершення роботи програми" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "А:" << endl;

            cout << "Розклад ІПЗ:" << endl;
            printSchedule(IPZ);
            cout << "Розклад КН:" << endl;
            printSchedule(KN);
            break;
        }
        case 2: {
            string choiceAdd, subject;
            cout << "Виберіть групу, в яку хочете додати предмет: " << endl;
            cin >> choiceAdd;
            if (choiceAdd == "ІПЗ") {
                cout << "Введіть предмет: " << endl;
                cin.ignore();
                getline(cin, subject);
                IPZ.insert(subject);
                cout << "Предмет додано." << endl;
            }
            else if (choiceAdd == "КН") {
                cout << "Введіть предмет: " << endl;
                cin.ignore();
                getline(cin, subject);
                KN.insert(subject);
                cout << "Предмет додано." << endl;
            }
            else {
                cout << "Помилка: неправильний ввід.";
            }
            break;
        }
        case 3: {
            string choiceDel, subject;
            cout << "Виберіть групу, з якої бажаєте видалити заняття: " << endl;
            cin >> choiceDel;
            if (choiceDel == "ІПЗ") {
                cout << "Введіть заняття: " << endl;
                cin.ignore();
                getline(cin, subject);
                IPZ.erase(subject);
                cout << "Предмет видалено." << endl;

            }
            else if (choiceDel == "КН") {
                cout << "Введіть заняття: " << endl;
                cin.ignore();
                getline(cin, subject);
                KN.erase(subject);
                cout << "Предмет видалено." << endl;

            }
            else {
                cout << "Помилка: неправильний ввід.";
            }
            break;
        }
        case 4: {
            cout << "4. Об'єднання списку предметів. Загальний розклад" << endl;
            set<string> unionGroup;
            set_union(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(unionGroup, unionGroup.end()));
            printSchedule(unionGroup);
            break;
        }
        case 5: {
            cout << "5. Перетин списку предетів. Спільні предмети для обох груп" << endl;
            set<string> intersectionGroup;
            set_intersection(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(intersectionGroup, intersectionGroup.begin()));
            printSchedule(intersectionGroup);
            break;
        }
        case 6: {
            cout << "6. Різниця занять. Предмети ІПЗ, без предметів КН" << endl;
            set<string> differenceGroup;
            set_difference(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(differenceGroup, differenceGroup.begin()));
            printSchedule(differenceGroup);
            break;
        }
        case 7: {
            cout << "7. Симетрична різниця. Предмети, що не є спільними" << endl;
            set <string> symmetricGroup;
            set_symmetric_difference(IPZ.begin(), IPZ.end(), KN.begin(), KN.end(), inserter(symmetricGroup, symmetricGroup.begin()));
            printSchedule(symmetricGroup);
            break;
        }
        case 8: {
            cout << "Вихід..." << endl;
            return 0;
        }
        default: {
            cout << "Помилка: неправильний ввід. Спробуйте ще раз." << endl;
            break;
        }
        }
    }
}