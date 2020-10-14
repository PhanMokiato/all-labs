#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool search_numbers(char *&str1, int &k, bool &number){
    for (int i = k; (str1[i] != ' ' && str1[i] != '\0'); ++i) {
        if ((str1[i] == '1') || (str1[i] == '2') || (str1[i] == '3') || (str1[i] == '4') || (str1[i] == '5')
            || (str1[i] == '6') || (str1[i] == '7') || (str1[i] == '8') || (str1[i] == '9') || (str1[i] == '0')) {
            number = true;
        } else {
            number = false;
            break;
        }
    }
    return number;
}
void adding_elements(char *&str1, char *&str2, int &l, int &k) {
    for (int i = l; (str1[i] != ' ' && str1[i] != '\0'); ++i, ++k) {
        str2[k] = str1[i];
    }
}


int main() {
    //cout << "Please, enter your string:" << endl;
    char *str1 = new char[300];
    ifstream file("wordnumber.txt");
    file.getline(str1, 300); cout << endl;
    file.close();
    //cin.getline(str1, 300); cout << endl;
    cout << "Here is the string that you might need:" << endl << str1 << endl;
    int n1 = 0;
    while (str1[n1] != '\0') {
        n1 = ++n1;
    }
    char *str2 = new char[300];
    int first = 0; int k = 0; bool number = true;
if (search_numbers(str1, first, number) == true) {
    adding_elements(str1, str2, first, k);
    str2[k] = ' ';
    k = k + 1;
    for (int l = 0; l < n1; ++l) {
        if ( str1[l] == ' ') {
            int l3 = l + 1;
            if (search_numbers(str1, l3 , number) == true) {
                int l1 = l + 1;
                adding_elements(str1, str2, l1, k);
                str2[k] = ' ';
                k = k + 1;

            }
        }
    }
    str2[k] = '\0';
    k = k + 1;
} else {
    for (int l = 0; l < n1; ++l) {
        if ( str1[l] == ' ') {
            int l3 = l + 1;
            if (search_numbers(str1, l3, number) == true) {
                int l1 = l + 1;
                adding_elements(str1, str2, l1, k);
                str2[k] = ' ';
                k = k + 1;
            }
        }
    }
    str2[k] = '\0';
    k = k + 1;
}
int n2 = 0;
    while (str2[n2] != '\0') {
        n2 = ++n2;
    }
char *str3 = new char[300 - n2];
    int f = 0;
    if (search_numbers(str1, first, number) == false) {
        adding_elements(str1, str3, first, f);
        str3[f] = ' ';
        f = f + 1;
        for (int l = 0; l < n1; ++l) {
            if ( str1[l] == ' ') {
                int l3 = l + 1;
                if (search_numbers(str1, l3 , number) == false) {
                    int l1 = l + 1;
                    adding_elements(str1, str3, l1, f);
                    str3[f] = ' ';
                    f = f + 1;
                }
            }
        }
        str3[f] = '\0';
        f = f + 1;
    } else {
        for (int l = 0; l < n1; ++l) {
            if ( str1[l] == ' ') {
                int l3 = l + 1;
                if (search_numbers(str1, l3, number) == false) {
                    int l1 = l + 1;
                    adding_elements(str1, str3, l1, f);
                    str3[f] = ' ';
                    f = f + 1;
                }
            }
        }
        str3[f] = '\0';
        f = f + 1;
    }
    cout << "And here is the changed variant:" << endl << str2 << str3;
    delete [] str1;
    delete [] str2;
    delete [] str3;
    return 0;
}
