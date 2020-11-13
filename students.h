//
// Created by Zver on 13.11.2020.
//

#ifndef LAB_7_STUDENTS_H
#define LAB_7_STUDENTS_H

class Student {
protected:
    static int Count;
    int ID;
    char* name;
    int course;
    int group;
    int record_book;
public:
    Student(char* name, int course, int group){
        this->name = name;
        this->course = course;
        this->group = group;
        Count++;
        ID = Count;
        record_book = Count;
    }
    Student(Student &st) {
        name = st.name;
        course = st.course;
        group = st.group;
        record_book = st.record_book;
        Count++;
        ID = Count;
    }
    char* Get_name();
    int Get_id();
    int Get_course();
    int Get_group();
    int Get_recbook();
    void Set_course(int cour);
    void Set_group(int gr);
    virtual double AverageScore();
    virtual int Get1SMark(int n);
    virtual int Get2SMark(int n);
    friend std::ostream& operator << (std::ostream& out, Student& st);
};


class Student_1S : public Student {
protected:
    static int Count;
    int ID;
    char* name;
    int course;
    int group;
    int record_book;
public:
    int marks_1S[4];
    double AverageScore();
    Student_1S(char* name, int course, int group, int mark1,
                             int mark2, int mark3, int mark4) : Student(name, course, group)
    {
        marks_1S[0] = mark1;
        marks_1S[1] = mark2;
        marks_1S[2] = mark3;
        marks_1S[3] = mark4;
    }
    Student_1S (Student_1S &student1S) : Student(student1S) {
        marks_1S[0] = student1S.marks_1S[0];
        marks_1S[1] = student1S.marks_1S[1];
        marks_1S[2] = student1S.marks_1S[2];
        marks_1S[3] = student1S.marks_1S[3];
    }
    int Get1SMark(int n);
    void Set1SMark (int mark, int n);
    friend std::ostream& operator << (std::ostream& out, Student_1S& st);
};




class Student_2S : public Student_1S {
public:
    int marks_2S[5];
    double AverageScore();
    Student_2S(char *name, int course, int group,int mark1,
                             int mark2, int mark3, int mark4, int mark5,
                             int mark6, int mark7, int mark8, int mark9)
            : Student_1S(name, course, group, mark1, mark2, mark3, mark4)
    {
        marks_2S[0] = mark5;
        marks_2S[1] = mark6;
        marks_2S[2] = mark7;
        marks_2S[3] = mark8;
        marks_2S[4] = mark9;
    }
    Student_2S (Student_2S &student1S) : Student_1S(student1S) {
        marks_2S[0] = student1S.marks_2S[0];
        marks_2S[1] = student1S.marks_2S[1];
        marks_2S[2] = student1S.marks_2S[2];
        marks_2S[3] = student1S.marks_2S[3];
        marks_2S[4] = student1S.marks_2S[4];
    }
    int Get2SMark(int n);
    void Set2SMark (int mark, int n);
    friend std::ostream& operator << (std::ostream& out, Student_2S& st);
};

#endif //LAB_7_STUDENTS_H
