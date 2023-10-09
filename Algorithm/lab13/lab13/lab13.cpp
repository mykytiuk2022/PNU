#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
struct Stack {
    Node<T>* root;

    Stack() {
        root = nullptr;
    }

    void push(T x) {
        Node<T>* temp = new Node<T>;
        temp->data = x;
        temp->next = root;
        root = temp;
    }
    void display() {
        while (root != nullptr) {  
            cout << root->data << " ";
            root = root->next;
        }
        cout << endl;
    }
    void pop() {
        if (root == nullptr) return;
        Node<T>* temp = root;
        root = root->next;
        delete temp;
    }

    T Top() {
        return root->data;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    int size() {
        int count = 0;
        while (root != nullptr) {
            count++;
            root = root->next;
        }
        return count;
    }

    bool isFull() {
        Node<T>* temp = new Node<T>;
        if (temp == nullptr) {
            return true;
        }
        else {
            delete temp;
            return false;
        }
    }

    void clear() {
        while (root != nullptr) {
            Node<T>* temp = root;
            root = root->next;
            delete temp;
        }
    }

};


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice;
    while (true) {
        cout << "1. Введення в стек цілих чисел клавіатури та виведення на екран." << endl;
        cout << "2. Створити і роздрукувати два стеки – з парними та непарними числами " << endl;
        cout << "3. Ввести послідовність круглих і квадратних дужок" << endl;
        cout << "4. Вихід." << endl;
        cin >> choice;
        switch (choice) {
        case 1: {
            Stack<int> stack;
            int size;
            cout << "Введіть кількість числ: ";
            cin >> size;
            for (int i = 0; i < size; i++)
            {
                int num;
                cin >> num;
                stack.push(num);
            }
            stack.display();
            break;
        }
        case 2: {
            Stack<int> evenNum, oddNum;
            int num;
            cout << "Введіть числа (0 - щоб зупинитись)" << endl;
            while (true) {
                cin >> num;
                if (num == 0) {
                    break;  
                }
                if (num % 2 == 0) {
                    evenNum.push(num);
                }
                else {
                    oddNum.push(num);
                }
            }
            cout << "Парні числа: " << endl;
            evenNum.display();
            cout << "Непарні числа: " << endl;
            oddNum.display();
            break;
        }
        case 3: {
            string str;
            cout << "Введіть послідовність дужок: ";
            cin >> str;
            Stack<char> brackets;
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == '(' || str[i] == '[') {
                    brackets.push(str[i]);
                }
                else {
                    if (str[i] == ')' && brackets.Top() == '(')
                        brackets.pop();
                    if (str[i] == ']' && brackets.Top() == '[')
                        brackets.pop();
                }
            }
            if (brackets.isEmpty()) {
                cout << "Послідовність дужок є правильною." << endl;
            }
            else {
                cout << "Послідовність дужок є неправильною." << endl;
            }
            break;
        }
        default:
            break;

        }
    }
    return 0;
}
