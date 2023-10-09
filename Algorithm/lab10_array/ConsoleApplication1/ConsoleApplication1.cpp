#include <iostream>
#include <string>
#include <ctime>
#include <set>
#include <algorithm>
#include <Windows.h>

using namespace std;
bool containsElement(string* arr, int size, string element) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == element) {
			return true;
		}
	}
	return false;
}
void printSchedule(string* group, int size) {
	for (int i = 0; i < size; i++) {
		cout << "- " << group[i] << endl;
	}
	cout << endl;
}

void addSubject(string*& group, int& size, string subject) {
	if (!containsElement(group, size, subject)) {
		int insertIndex = 0;
		while (insertIndex < size && group[insertIndex] < subject) {
			insertIndex++;
		}

		string* newGroup = new string[size + 1];
		for (int i = 0; i < insertIndex; i++) {
			newGroup[i] = group[i];
		}
		newGroup[insertIndex] = subject;
		for (int i = insertIndex + 1; i < size + 1; i++) {
			newGroup[i] = group[i - 1];
		}
		size++;
		delete[] group;
		group = newGroup;
	}
}

void delSubject(string*& group, int& size) {
	string subject;
	if (containsElement(group, size, subject)) {
		string* newGroup = new string[size - 1];
		for (int i = 0, j = 0; i < size; i++) {
			if (group[i] != subject) {
				newGroup[j] = group[i];
				j++;
			}
		}
		size--;
		delete[] group;
		group = newGroup;
	}
	cout << "������� ��������." << endl;
}

void UnionSet(string* Set, int SIZE, string* Set_1, int SIZE_1, string*& Set_0, int& SIZE_0) {
	for (int i = 0; i < SIZE; i++)
		Set_0[i] = Set[i];
	for (int i = 0; i < SIZE_1; i++)
		addSubject(Set_0, SIZE_0, Set_1[i]);
}
void IntersectSet(string* group1, int size1, string* group2, int size2, string*& intersectionGroup, int& intersectionSize) {
	int index = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (group1[i] == group2[j]) {
				intersectionGroup[index] = group1[i];
				index++;
			}
		}
	}
	intersectionSize = index;
}
void DifferenceSet(string* group1, int size1, string* group2, int size2, string*& differenceGroup, int& differenceSize) {
	int index = 0;
	for (int i = 0; i < size1; i++) {
		if (!containsElement(group2, size2, group1[i])) {
			differenceGroup[index] = group1[i];
			index++;
		}
	}
	differenceSize = index;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int IPZ_size = 5;
	int KN_size = 5;
	string* IPZ = new string[IPZ_size]{"������ ������", "Front-end ��������", "��������� �� ��������� �����", "������������ �����", "ͳ������ ����"};
	string* KN = new string[KN_size]{"������ ������", "������������ �����", "�������������", "��������� ����", "����������� �����"};
	sort(IPZ, IPZ + IPZ_size);
	sort(KN, KN + KN_size);
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
			cout << "������� ���:" << endl;
			printSchedule(IPZ, IPZ_size);
			cout << "������� ��:" << endl;
			printSchedule(KN, KN_size);
			break;
		}
		case 2: {
			string choiceAdd;
			cout << "������� �����, � ��� ������ ������ �������: " << endl;
			cin >> choiceAdd;
			if (choiceAdd == "���") {
				string subject;
				cout << "������ �������: " << endl;
				cin.ignore();
				getline(cin, subject);
				addSubject(IPZ, IPZ_size, subject);
			}
			else if (choiceAdd == "��") {
				string subject;
				cout << "������ �������: " << endl;
				cin.ignore();
				getline(cin, subject);
				addSubject(KN, KN_size, subject);
			}
			else {
				cout << "�������: ������������ ���.";
			}
			break;
		}
		case 3: {
			string choiceDel;
			cout << "������� �����, � ��� ������ �������� �������: " << endl;
			cin >> choiceDel;
			if (choiceDel == "���") {
				string subject;
				cout << "������ �������: " << endl;
				cin.ignore();
				getline(cin, subject);
				delSubject(IPZ, IPZ_size);
			}
			else if (choiceDel == "��") {
				string subject;
				cout << "������ �������: " << endl;
				cin.ignore();
				getline(cin, subject);
				delSubject(IPZ, IPZ_size);
				delSubject(KN, KN_size);
			}
			else {
				cout << "�������: ������������ ���.";
			}
			break;
		}
		case 4: {
			cout << "4. ��'������� ������ ��������. ��������� �������" << endl;
			int unionSize = IPZ_size;
			string* unionGroup = new string[unionSize];
			UnionSet(IPZ, IPZ_size, KN, KN_size, unionGroup, unionSize);
			printSchedule(unionGroup, unionSize);
			delete[] unionGroup;
			break;
		}
		case 5: {
			cout << "5. ������� ������ �������. ����� �������� ��� ���� ����" << endl;
			int intersectionSize = min(IPZ_size, KN_size);
			string* intersectionGroup = new string[intersectionSize];
			IntersectSet(IPZ, IPZ_size, KN, KN_size, intersectionGroup, intersectionSize);
			printSchedule(intersectionGroup, intersectionSize);
			delete[] intersectionGroup;
			break;
		}
		case 6: {
			cout << "6. г����� ������. �������� ���, ��� �������� ��" << endl;
			int differenceSize = IPZ_size;
			string* differenceGroup = new string[differenceSize];
			DifferenceSet(IPZ, IPZ_size, KN, KN_size, differenceGroup, differenceSize);
			printSchedule(differenceGroup, differenceSize);
			delete[] differenceGroup;
			break;
		}
		case 7: {
			cout << "7. ���������� ������. ��������, �� �� � ��������" << endl;
			int symmetricSize = IPZ_size + KN_size;
			string* symmetricGroup = new string[symmetricSize];

			int unionSize = IPZ_size;
			string* unionGroup = new string[unionSize];
			UnionSet(IPZ, IPZ_size, KN, KN_size, unionGroup, unionSize);

			int intersectionSize = min(IPZ_size, KN_size);
			string* intersectionGroup = new string[intersectionSize];
			IntersectSet(IPZ, IPZ_size, KN, KN_size, intersectionGroup, intersectionSize);

			DifferenceSet(unionGroup, unionSize, intersectionGroup, intersectionSize, symmetricGroup, symmetricSize);
			printSchedule(symmetricGroup, symmetricSize);
			delete[] unionGroup;
			delete[] intersectionGroup;
			delete[] symmetricGroup;
			break;
		}
		}
	}
}