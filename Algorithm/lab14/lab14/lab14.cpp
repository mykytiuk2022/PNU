#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Passenger {
    string lastName;
    float baggageWeight;
    Date date;
    Passenger* left;
    Passenger* right;
};


void printB(const string& prefix, Passenger* parent, bool isLeft, bool isRoot) {
    if (parent == nullptr)
        return;

    if (isRoot) {
        cout << "─────";
    }
    else {
        cout << prefix <<
            (isLeft ? "L├────" : "R└───");
    }
    cout << parent->baggageWeight << endl;

    printB(prefix + (isLeft ? " │   " : "    "),
        parent->left, true, false);
    printB(prefix + (isLeft ? " │   " : "    "),
        parent->right, false, false);
}
void printB(Passenger* root) {
    printB("", root, false, true);
}
void printTree(Passenger* root, string prefix = "", bool isLeft = true) {
    if (root == NULL)return;

    cout << prefix;
    cout << (isLeft ? "|--" : "'--");
    cout << "[" << root->lastName << " (" << root->baggageWeight << "кг)"<<" " << root->date.day << "." << root->date.month << "." << root->date.year << "]\n";
    //cout << "[" << root->date.day << "." << root->date.month << "." << root->date.year << "]\n";

    printTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}

void printPTree(Passenger* root, int depth) {
    if (root != nullptr) {
        printPTree(root->right, depth + 1);
        for (int i = 0; i < depth; i++) {
            cout << "\t";
        }
        cout << root->lastName <<" ("<<root->baggageWeight <<"кг)" << endl;
        for (int i = 0; i < depth; i++) {
            cout << "\t";
        }
        cout << right << setw(2) << setfill('0') << root->date.day << "."
            << setw(2) << setfill('0') << root->date.month << "." << setfill(' ')
            << left << setw(6) << root->date.year << endl;
        printPTree(root->left, depth + 1);
    }
}
void addPassenger(Passenger*& root, Passenger* newPassenger) {
    if (root == nullptr) {
        root = newPassenger;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (newPassenger->lastName < root->lastName) {
        addPassenger(root->left, newPassenger);
    }
    else {
        addPassenger(root->right, newPassenger);
    }
}
void deleteTree(Passenger*& root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}
void avarageBaggageWeight(Passenger* root, int& i, float& weight) {
    if (root == nullptr){
        return;
    }
    avarageBaggageWeight(root->left, i, weight);
    avarageBaggageWeight(root->right, i, weight);
    i++;
    weight += root->baggageWeight;

}
void addByWeight(Passenger*& root, Passenger* newPassenger) {
    if (root == nullptr) {
        root = newPassenger;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    if (newPassenger->baggageWeight < root->baggageWeight) {
        addByWeight(root->left, newPassenger);
    }
    else {
        addByWeight(root->right, newPassenger);
    }
}

void copyTreeByWeight(Passenger* root, Passenger*& newRoot) {
    if (root != nullptr) {
        Passenger* newPassenger = new Passenger;
        newPassenger->lastName = root->lastName;
        newPassenger->baggageWeight = root->baggageWeight;
        newPassenger->date = root->date;
        addByWeight(newRoot, newPassenger);

        copyTreeByWeight(root->left, newRoot);
        copyTreeByWeight(root->right, newRoot);
    }
}
void readDataFromFile(Passenger*& root, string fileName) {
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Помилка при відкритті файлу!\n";
        root = nullptr;
        return;
    }
    while (!inputFile.eof()) {
        Passenger* newPassenger = new Passenger();
        inputFile >> newPassenger->lastName >> newPassenger->baggageWeight;
        inputFile >> newPassenger->date.year >> newPassenger->date.month >> newPassenger->date.day;
        addPassenger(root, newPassenger);
    }
}
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Passenger* root = nullptr;
    while (true) {
        int choice;
        cout << "Виберіть дію:" << endl;
        cout << "0. Зчитати дані з файлу." << endl;
        cout << "1. Додати нового подорожнього до дерева." << endl;
        cout << "2. Вивести на екран." << endl;
        cout << "3. Знайти середньє значення ваги багажу." << endl;
        cout << "4. Видалити з пам'яті все дерево." << endl;
        cout << "5. Переписати дані з першого дерева в інше, за вагою багажу." << endl;
        cout << "6. Вийти." << endl;
        cin >> choice;
        switch (choice) {
        case 0: {
            readDataFromFile(root, "passengers_data.txt");
            break;
        }
        case 1: {
            Passenger* newPassenger = new Passenger;
            cout << "Введіть прізвище: ";
            cin >> newPassenger->lastName;
            cout << "Введіть вагу багажу: ";
            cin >> newPassenger->baggageWeight;
            cout << "Введіть дату приїзду (ДД-ММ-РР): ";
            cin >> newPassenger->date.day >> newPassenger->date.month >> newPassenger->date.year;

            addPassenger(root, newPassenger);
            break;
        }
        case 2: {
            cout << "\nДерево: " << endl;
            printTree(root);
            break;
        }
        case 3: {
            int i = 0;
            float weight = 0;
            avarageBaggageWeight(root, i, weight);
            cout << "Середня вага багажу: " << weight / i << endl;
            break;
        }
        case 4: {
            deleteTree(root);
            break;
        }
        case 5: {
            Passenger* newRoot = nullptr;
            copyTreeByWeight(root, newRoot);
            printTree(newRoot);
            deleteTree(root);
            break;
        }

        case 6: {
            exit(0);
        }
        default: {
            cout << "Помилка, неправильний ввід" << endl;
            break;
        }
        }
    }

    return 0;
}