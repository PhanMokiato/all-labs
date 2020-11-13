#include <iostream>
#include <string>
//#include <fstream>
// В этой программе я пыталась в изначальную строку добавить в ее начало цифры, но большинство времени ушло на попытки подключить файл


using namespace std;
int main() {
//    cout << "Here is the string that you may need:" << endl;
    const int maxsize = 300;
//    char str[maxsize];
//    ifstream fin("sentence.txt", ios::in);
//    fin.open("sentence.txt");
//    if (!fin.is_open()) {
//        cout << "Sorry we couldn't find your file";
//        return 1;
//    } else {
//        cout << "File is open, so it's ok to work with it!";
//        while (fin.getline(str, maxsize)) {
//            cout << str;
//        }
//    }
//    fin.close();
    cout << "Please, enter your string:" << endl;
    char *str1 = new char[maxsize];
    cin.getline(str1, maxsize);
    cout << "What number would you like to input in the beginning of your string?" << endl;
    int n1 = 0;
    while (str1[n1] != '\0') {
        n1 = ++n1;
    }
    char *str2 = new char[maxsize - n1];
    cin.getline (str2, maxsize - n1);
    int n2 = 0;
    while (str2[n2] != '\0') {
        n2 = ++n2;
    }
    char *str3 = new char[n1 + n2];
    for (int i = 0; i < n2; ++i) {
        str3[i] = str2[i];
    }
    for (int j = n2, e = 0; j < n1 + n2; ++j, ++e) {
        str3[j] = str1[e];
    }
    int n3 = n1 + n2;
    str3[n3] = '\0';
    cout << "And here we have the changed variant:" << endl;
    cout << str3;
    return 0;
}

