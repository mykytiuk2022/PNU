#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <ctime>
#include <chrono>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


struct member {
    string name;
    member* left;
    member* right;
};


void insertMember(member*& root, string name) {
    if (root == NULL) {
        root = new member;
        root->name = name;
        root->left = NULL;
        root->right = NULL;
    }
    else if (root->name > name) {
        insertMember(root->left, name);
    }
    else {
        insertMember(root->right, name);
    }
}



void printTree(member* root, string prefix = "", bool isLeft = true) {
    if (root == NULL)return;

    cout << prefix;
    cout << (isLeft ? "|--" : "'--");
    cout << "[" << root->name << "]\n";

    printTree(root->left, prefix + (isLeft ? "|   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}

void main() {
    member* root = NULL;
    ifstream file;
    file.open("fTree.txt");
    while (!file.eof()) {
        string name;
        file >> name;
        insertMember(root, name);
    }
    printTree(root);
}
