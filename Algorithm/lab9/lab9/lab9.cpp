#include <iostream>
#include <fstream>
using namespace std;

double computeFraction(int n) {
    if (n == 0) { 
        return 0;
    }
    else {
        return 2 / (1 + computeFraction(n - 1));
    }
}

int main() {
    int n; 
    ifstream inputFile("input.txt"); 
    if (!inputFile.is_open()) {
        cout << "Error opening file.\n";
        return 1; 
    }
    inputFile >> n; 
    cout << "Number of members of the fraction: " << n<< endl;
    inputFile.close(); 
    double result = computeFraction(n); 

    ofstream outputFile("input.txt", ios_base::app); 
    outputFile << endl << "Result: " << result << endl; 
    outputFile.close(); 

    cout << "Result: " << result << endl; 

    return 0;
}
