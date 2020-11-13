#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int main() {
    cout << "In the original file we have:" << endl;
    cout << endl;
    ifstream beginning("origin");
    ofstream two("two words");
    ofstream six("six words");
    if (!beginning) {
        cout << "I'm sorry, but there is something wrong. This file can't be found";
        return 0;
    }
    while (beginning) {
        string text;
        getline(beginning, text, '\n');
        cout << text << endl;
    }
    beginning.close();
    beginning.open("origin");
    while (beginning) {
        string text1;
        int let_num = 0;
        int words = 0;
        getline(beginning, text1, '\n');
        cout << text1 << endl;
        for (int i = 0; i < text1.length(); ++i){
            if ( isalnum(text1[i]) != 0) {
               ++let_num;
               continue;
            } else {
                if (let_num > 0) {
                    ++words;
                    let_num = 0;
                } else {
                    continue;
                }
            }
        }
        if (let_num > 0) {
            ++words;
        }
        if (words <= 2) {
            two << text1 << endl;
        }
        if (3 <= words && words <= 6) {
            six << text1 << endl;
        }
    }
    cout << "So, in the first file you will have something like this:" << endl;
    ifstream two_output("two words");
    while (two_output) {
        string text;
        getline(two_output, text, '\n');
        cout << text << endl;
    }

    cout << "And in the second file you will have something like this:" << endl;
    ifstream six_output("six words");
    while (six_output) {
        string text;
        getline(six_output, text, '\n');
        cout << text << endl;
    }
    two_output.close();
    six_output.close();
    two.close();
    six.close();
    beginning.close();
    return 0;
}
