#include <iostream>
#include <string>
using namespace std;

string comparing_of_strings(char* &str1, char* &str2) {
    int n1 = 0;
    int n2 = 0;
    while (str1[n1] != '\0') {
        n1 = ++n1;
    }
    while (str2[n2] != '\0') {
        n2 = ++n2;
    }
    if (n1 > n2) {
        return "first";
    }
    if (n1 < n2) {
        return "string";
    }
    if (n1 == n2) {
        return "equal";
    }
}

int main() {
    cout << "Please, enter your strings:" << endl;
    char *str1 = new char[300];
    char *str2 = new char[300];
    cin.getline(str1, 300);
    cin.getline (str2, 300);
    cout << endl;
    if (comparing_of_strings(str1, str2) == "first") {
        cout << "The first string is bigger";
    }
    if (comparing_of_strings(str1, str2) == "second") {
        cout << "The second string is bigger";
    }
    if (comparing_of_strings(str1, str2) == "equal") {
        cout << "These strings are equal.";
    }
    return 0;
}
