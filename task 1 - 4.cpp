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
    int compare = 0;
    for(int i = 0, j = 0; ((str1[i] != '\0') && (str2[j] != '\0')); ++i, ++j) {
    if (str1[i] == str2[j]){
        compare = 0;
        continue;
    }
    if (str1[i] > str2[j]){
        compare = 1;
        break;
    }
    if (str1[i] < str2[j]){
        compare = -1;
        break;
    }
}
    if ((n1 > n2) && (compare == 0)) {
        compare = 1;
    }
    if ((n1 < n2) && (compare == 0)) {
        compare = -1;
    }
switch (compare) {
    case 0: return "equal";
    case 1: return "first";
    case -1: return "second";
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
    delete [] str1;
    delete [] str2;
    return 0;
}