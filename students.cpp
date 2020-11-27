//
// Created by Zver on 13.11.2020.
//
#include <iostream>
#include <string>
#include "students.h"
int Student::Count = 0;
    char* Student :: Get_name() {
        return name;
    }
    int Student :: Get_id() {
        return ID;
    }
    int Student :: Get_course() {
        return course;
    }
    int Student :: Get_group() {
        return group;
    }
    int Student :: Get_recbook() {
        return record_book;
    }
    int Student :: Get1SMark(int n) {
        if (n <= 0 || n > 4) {
            std::cout << "Lol, just what were you trying to get?" << std::endl;
        }
        return 0;
    }
    int Student :: Get2SMark(int n) {
        if (n <= 0 || n > 5) {
            std::cout << "Lol, just what were you trying to get?" << std::endl;
        }
    return 0;
    }
    void Student :: Set_course(int cour) {
        if (cour > 0) {
            course = cour;
        } else {
            std::cout << "Hey, what are you trying to do? That is actually inappropriate." << std::endl;
        }
    }
    void Student :: Set_group(int gr) {
        if (gr > 0) {
            group = gr;
        } else {
            std::cout << "Hey, what are you trying to do? That is actually inappropriate." << std::endl;
        }
    }
    void Student :: Set_name(char* nam) {
        if (strlen(nam) == 0) {
            std::cout << "Hey, what are you trying to do? That is actually inappropriate." << std::endl;
        } else {
            name = nam;
        }
    }
    double Student :: AverageScore() {
        return 0;
    }
    std::ostream& operator << (std::ostream& out, Student& st) {
        out << "Name - " << st.name << "," << " ID - " << st.ID << "," << " course - "
            << st.course << "," << " group - " << "," << st.group << " number of the record book - " << st.record_book << ".";
        return out;
    }





    double Student_1S :: AverageScore() {
        double sum = 0;
        for (int i = 0; i < 4; ++i) {
            sum = sum + marks_1S[i];
        }
        return sum / 4;
    }




    int Student_1S :: Get1SMark(int n) {
        if (n > 0 && n < 5) {
            return marks_1S[n - 1];
        } else {
            std::cout << "Hey, what are you trying to do? That is actually inappropriate." << std::endl;
        }
    }
    void Student_1S :: Set1SMark (int mark, int n) {
        if (n > 0 && n < 5 && mark >= 0) {
            marks_1S[n - 1] = mark;
        } else {
            std::cout << "Hey, what are you trying to do? That is actually inappropriate." << std::endl;
        }
    }

    std::ostream& operator << (std::ostream& out, Student_1S& st) {
        out << "Name - " << st.Get_name() << "," << " ID - " << st.Get_id() << "," << " course - " << st.Get_course() << "," << " group - " << st.Get_group() << ","
            << " number of the record book - " << st.Get_recbook() << "." << std::endl
            << "Marks for the first session:" << st.marks_1S[0] << ", " << st.marks_1S[1] << ", " << st.marks_1S[2] << ", " << st.marks_1S[3] << ".";
        return out;
    }




 double Student_2S ::AverageScore() {
        double sum = 0.0;
        for (int i = 0; i < 4; ++i) {
            sum = sum + marks_1S[i];
        }
        for (int i = 0; i < 5; ++i) {
            sum = sum + marks_2S[i];
        }
        return sum / 9;
    }



    int Student_2S :: Get2SMark(int n) {
        if (n > 0 && n < 6) {
            return marks_2S[n - 1];
        } else {
            std::cout << "Hey, what are you trying to do? That is actually inappropriate." << std::endl;
        }
    }
    void Student_2S :: Set2SMark (int mark, int n) {
        if (n > 0 && n < 6 && mark >= 0) {
            marks_2S[n - 1] = mark;
        } else {
            std::cout << "Hey, what are you trying to do? That is actually inappropriate." << std::endl;
        }
    }

    std::ostream& operator << (std::ostream& out, Student_2S& st) {
        out << "Name - " << st.Get_name() << "," << " ID - " << st.Get_id() << "," << " course - " << st.Get_course() << ","
            << " group - " << st.Get_group() << "," << " number of the record book - " << st.Get_recbook() << "." << std::endl
            << "Marks for the first session:" << st.marks_1S[0] << ", " << st.marks_1S[1] << ", " << st.marks_1S[2] << ", " << st.marks_1S[3] << "." << std::endl
            << "Marks for the second session:" << st.marks_2S[0] << ", " << st.marks_2S[1] << ", " << st.marks_2S[2] << ", " << st.marks_2S[3] << ", " << st.marks_2S[4] << ".";
        return out;
    }


