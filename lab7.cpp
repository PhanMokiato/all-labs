#include <iostream>
#include "students.h"

double AvScore1_1S(Student **st_ptr, int gr) {
    double AS11 = 0.0;
    int n = 0;
    for (int i = 0; i < 7; ++i) {
        if (st_ptr[i]->Get_group() == gr) {
            if (st_ptr[i]->AverageScore() == 0) {
                AS11 = AS11 + st_ptr[i]->AverageScore();
                ++n;
                continue;
            } else {
                double sum = 0.0;
                for (int j = 0; j < 4; ++j) {
                    sum = sum + st_ptr[i]->Get1SMark(1);
                }
                double as1 = sum / 4;
                AS11 = AS11 + as1;
                ++n;
            }
        } else {
            continue;
        }
    }
    if (n == 0) {
        std::cout << "There are no students from this group." << std::endl;
        return AS11;
    }
    AS11 = AS11 / n;
    return AS11;
}


double AvScore1_2S(Student **st_ptr, int gr) {
    double AS1 = 0.0;
    int n = 0;
    for (int i = 0; i < 7; ++i) {
        if (st_ptr[i]->Get_group() == gr) {
            AS1 = AS1 + st_ptr[i]->AverageScore();
            ++n;
        } else {
            continue;
        }
    }
    if (n == 0) {
        std::cout << "There are no students from this group." << std::endl;
        return AS1;
    }
    AS1 = AS1 / n;
    return AS1;
}

double AvScore2 (Student **st_ptr) {
    double AS2 = 0.0;
    for (int i = 0; i < 7; ++i) {
        AS2 = AS2 + st_ptr[i]->AverageScore();
    }
    AS2 = AS2 / 7;
    return AS2;
}

int Student::Count = 0;

int main() {

    Student st0("Ann", 1, 3);
    std::cout << st0 << std::endl << std::endl;
    std::cout << "Ann's average score is " << st0.AverageScore() << std::endl;


    Student_1S st1("Peter", 1, 3, 8, 8, 9, 6);
    Student_1S st2("Miles", 1, 2, 9, 9, 9, 7);
    Student_1S st3 ("Gwen", 1, 3, 8, 8, 9, 9);
    st2.Set_group(1);
    std::cout << st2 << std::endl;
    std::cout << "Miles' average score is " << st2.AverageScore() << std::endl << std::endl;

    Student_2S st4("Penny", 1, 1, 9, 7, 8, 6 ,5, 5, 0, 4, 9);
    Student_2S st5("May", 1, 1, 6, 7, 8, 8, 9, 9, 9, 10, 7);
    Student_2S st6("Mary", 1, 1, 8, 9 , 6, 8, 10, 8, 6, 9, 7);
    std::cout << st4 << std::endl;
    std::cout << "Penny's average score is " << st4.AverageScore() << std::endl << std::endl;


    Student *student_pointers[7];
    student_pointers[0] = &st0;
    student_pointers[1] = &st1;
    student_pointers[2] = &st2;
    student_pointers[3] = &st3;
    student_pointers[4] = &st4;
    student_pointers[5] = &st5;
    student_pointers[6] = &st6;

    std::cout << "Third group's average score after first session is "<< AvScore1_1S(student_pointers, 3) << std::endl;
    std::cout << "Third group's average score after second session is "<< AvScore1_2S(student_pointers, 3) << std::endl;
    std::cout << "Students' average score is "<< AvScore2(student_pointers) << std::endl;

    return 0;
    }
