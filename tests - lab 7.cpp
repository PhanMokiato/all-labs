#include <gtest/gtest.h>
#include "students.h"

TEST(Student0, Subject) {
    Student S01("Man", 5, 6);
    EXPECT_STREQ("Man", S01.Get_name());
    EXPECT_EQ(5, S01.Get_course());
    EXPECT_EQ(6, S01.Get_group());
    EXPECT_EQ(1, S01.Get_id());
    EXPECT_EQ(1, S01.Get_recbook());
}

TEST(Student0, SubjectWithWrongParametres) {
    Student S01("Man", -5, 0);
    EXPECT_STREQ("Man", S01.Get_name());
    EXPECT_EQ(5, S01.Get_course());
    EXPECT_EQ(1, S01.Get_group());
    EXPECT_EQ(1, S01.Get_id());
    EXPECT_EQ(1, S01.Get_recbook());
}

TEST(Student0, Copying) {
    Student S01("Man", 5, 6);
    Student S02 (S01);
    EXPECT_STREQ("Man", S02.Get_name());
    EXPECT_EQ(5, S02.Get_course());
    EXPECT_EQ(6, S02.Get_group());
    EXPECT_EQ(2, S02.Get_id());
    EXPECT_EQ(1, S02.Get_recbook());
}

TEST (Student0, Setters) {
    Student S01("Man", 5, 6);
    S01.Set_name("Mate");
    S01.Set_group(3);
    S01.Set_course(4);
    EXPECT_STREQ("Mate", S01.Get_name());
    EXPECT_EQ(3, S01.Get_group());
    EXPECT_EQ(4, S01.Get_course());
}

TEST (Student0, SettersWithWrongParameters) {
    Student S01("Man", 5, 6);
    S01.Set_name("");
    S01.Set_group(-3);
    S01.Set_course(0);
    EXPECT_STREQ("Man", S01.Get_name());
    EXPECT_EQ(6, S01.Get_group());
    EXPECT_EQ(5, S01.Get_course());
}

TEST (Student0, GettingMarks) {
    Student S01("Man", 5, 6);
    EXPECT_EQ(0, S01.Get1SMark(2));
    EXPECT_EQ(0, S01.Get2SMark(5));
}

TEST (Student0, GettingWrongMarks) {
    Student S01("Man", 5, 6);
    EXPECT_EQ(0, S01.Get1SMark(-2));
    EXPECT_EQ(0, S01.Get2SMark(0));
}

TEST (Student0, AverageScore) {
    Student S01("Man", 5, 6);
    EXPECT_EQ(0, S01.AverageScore());
}

TEST (Student1, Subject) {
    Student_1S S11 ("Dude", 1, 6, 9, 5, 8, 9);
    EXPECT_STREQ("Dude", S11.Get_name());
    EXPECT_EQ(1, S11.Get_course());
    EXPECT_EQ(6, S11.Get_group());
    EXPECT_EQ(1, S11.Get_id());
    EXPECT_EQ(1, S11.Get_recbook());
    EXPECT_EQ(9, S11.Get1SMark(1));
    EXPECT_EQ(5, S11.Get1SMark(2));
    EXPECT_EQ(8, S11.Get1SMark(3));
    EXPECT_EQ(9, S11.Get1SMark(4));
}

TEST (Student1, SubjectWithWrongParametres) {
    Student_1S S11 ("Dude", 0, -6, -9, -5, -8, -9);
    EXPECT_STREQ("Dude", S11.Get_name());
    EXPECT_EQ(1, S11.Get_course());
    EXPECT_EQ(6, S11.Get_group());
    EXPECT_EQ(1, S11.Get_id());
    EXPECT_EQ(1, S11.Get_recbook());
    EXPECT_EQ(9, S11.Get1SMark(1));
    EXPECT_EQ(5, S11.Get1SMark(2));
    EXPECT_EQ(8, S11.Get1SMark(3));
    EXPECT_EQ(9, S11.Get1SMark(4));
}

TEST (Student1, Copying) {
    Student_1S S11 ("Dude", 1, 6, 9, 5, 8, 9);
    Student_1S S12 (S11);
    EXPECT_STREQ("Dude", S12.Get_name());
    EXPECT_EQ(1, S12.Get_course());
    EXPECT_EQ(6, S12.Get_group());
    EXPECT_EQ(2, S12.Get_id());
    EXPECT_EQ(1, S12.Get_recbook());
    EXPECT_EQ(9, S12.Get1SMark(1));
    EXPECT_EQ(5, S12.Get1SMark(2));
    EXPECT_EQ(8, S12.Get1SMark(3));
    EXPECT_EQ(9, S12.Get1SMark(4));
}

TEST (Student1, Setters) {
    Student_1S S11 ("Dude", 1, 6, 9, 5, 8, 9);
    S11.Set_name("Mate");
    S11.Set_group(4);
    S11.Set_course(2);
    S11.Set1SMark(8, 1);
    S11.Set1SMark(7, 2);
    S11.Set1SMark(9, 3);
    S11.Set1SMark(10, 4);
    EXPECT_STREQ("Mate", S11.Get_name());
    EXPECT_EQ(2, S11.Get_course());
    EXPECT_EQ(4, S11.Get_group());
    EXPECT_EQ(8, S11.Get1SMark(1));
    EXPECT_EQ(7, S11.Get1SMark(2));
    EXPECT_EQ(9, S11.Get1SMark(3));
    EXPECT_EQ(10, S11.Get1SMark(4));
}

TEST (Student1, SettersWithWrongParameters) {
    Student_1S S11 ("Dude", 1, 6, 9, 5, 8, 9);
    S11.Set_name("");
    S11.Set_group(-4);
    S11.Set_course(0);
    S11.Set1SMark(8, 0);
    S11.Set1SMark(-7, 2);
    S11.Set1SMark(9, -3);
    S11.Set1SMark(-10, 4);
    EXPECT_STREQ("Dude", S11.Get_name());
    EXPECT_EQ(1, S11.Get_course());
    EXPECT_EQ(6, S11.Get_group());
    EXPECT_EQ(9, S11.Get1SMark(1));
    EXPECT_EQ(5, S11.Get1SMark(2));
    EXPECT_EQ(8, S11.Get1SMark(3));
    EXPECT_EQ(9, S11.Get1SMark(4));
}

TEST (Student1, GettingMarksFromSecondSession) {
    Student_1S S11 ("Dude", 1, 6, 9, 5, 8, 9);
    EXPECT_EQ(0, S11.Get2SMark(1));
}

TEST (Student1, GettingWrongMarksFromSecondSession) {
    Student_1S S11 ("Dude", 1, 6, 9, 5, 8, 9);
    EXPECT_EQ(0, S11.Get2SMark(6));
}

TEST (Student1, AverageScore) {
    Student_1S S11 ("Dude", 1, 6, 9, 5, 8, 9);
    EXPECT_DOUBLE_EQ(7.75, S11.AverageScore());
}

TEST (Student2, Subject) {
    Student_2S S21 ("Guy", 2, 3, 6, 9, 8, 8, 10, 7, 9, 10, 8);
    EXPECT_STREQ("Guy", S21.Get_name());
    EXPECT_EQ(2, S21.Get_course());
    EXPECT_EQ(3, S21.Get_group());
    EXPECT_EQ(1, S21.Get_id());
    EXPECT_EQ(1, S21.Get_recbook());
    EXPECT_EQ(6, S21.Get1SMark(1));
    EXPECT_EQ(9, S21.Get1SMark(2));
    EXPECT_EQ(8, S21.Get1SMark(3));
    EXPECT_EQ(8, S21.Get1SMark(4));
    EXPECT_EQ(10, S21.Get2SMark(1));
    EXPECT_EQ(7, S21.Get2SMark(2));
    EXPECT_EQ(9, S21.Get2SMark(3));
    EXPECT_EQ(10, S21.Get2SMark(4));
    EXPECT_EQ(8, S21.Get2SMark(5));
}

TEST (Student2, SubjectWithWrongParametres) {
    Student_2S S21 ("Guy", -2, 0, -6, -9, -8, -8, -10, -7, -9, -10, -8);
    EXPECT_STREQ("Guy", S21.Get_name());
    EXPECT_EQ(2, S21.Get_course());
    EXPECT_EQ(1, S21.Get_group());
    EXPECT_EQ(1, S21.Get_id());
    EXPECT_EQ(1, S21.Get_recbook());
    EXPECT_EQ(6, S21.Get1SMark(1));
    EXPECT_EQ(9, S21.Get1SMark(2));
    EXPECT_EQ(8, S21.Get1SMark(3));
    EXPECT_EQ(8, S21.Get1SMark(4));
    EXPECT_EQ(10, S21.Get2SMark(1));
    EXPECT_EQ(7, S21.Get2SMark(2));
    EXPECT_EQ(9, S21.Get2SMark(3));
    EXPECT_EQ(10, S21.Get2SMark(4));
    EXPECT_EQ(8, S21.Get2SMark(5));
}

TEST (Student2, Copying) {
    Student_2S S21 ("Guy", 2, 3, 6, 9, 8, 8, 10, 7, 9, 10, 8);
    Student_2S S22(S21);
    EXPECT_STREQ("Guy", S22.Get_name());
    EXPECT_EQ(2, S22.Get_course());
    EXPECT_EQ(3, S22.Get_group());
    EXPECT_EQ(2, S22.Get_id());
    EXPECT_EQ(1, S22.Get_recbook());
    EXPECT_EQ(6, S22.Get1SMark(1));
    EXPECT_EQ(9, S22.Get1SMark(2));
    EXPECT_EQ(8, S22.Get1SMark(3));
    EXPECT_EQ(8, S22.Get1SMark(4));
    EXPECT_EQ(10, S22.Get2SMark(1));
    EXPECT_EQ(7, S22.Get2SMark(2));
    EXPECT_EQ(9, S22.Get2SMark(3));
    EXPECT_EQ(10, S22.Get2SMark(4));
    EXPECT_EQ(8, S22.Get2SMark(5));
}

TEST (Student2, Setters) {
    Student_2S S21 ("Guy", 2, 3, 6, 9, 8, 8, 10, 7, 9, 10, 8);
    S21.Set_name("Mate");
    S21.Set_group(4);
    S21.Set_course(3);
    S21.Set1SMark(8, 1);
    S21.Set1SMark(7, 2);
    S21.Set1SMark(9, 3);
    S21.Set1SMark(10, 4);
    S21.Set2SMark(10,1);
    S21.Set2SMark(9,2);
    S21.Set2SMark(9,3);
    S21.Set2SMark(10,4);
    S21.Set2SMark(10,5);
    EXPECT_STREQ("Mate", S21.Get_name());
    EXPECT_EQ(3, S21.Get_course());
    EXPECT_EQ(4, S21.Get_group());
    EXPECT_EQ(8, S21.Get1SMark(1));
    EXPECT_EQ(7, S21.Get1SMark(2));
    EXPECT_EQ(9, S21.Get1SMark(3));
    EXPECT_EQ(10, S21.Get1SMark(4));
    EXPECT_EQ(10, S21.Get2SMark(1));
    EXPECT_EQ(9, S21.Get2SMark(2));
    EXPECT_EQ(9, S21.Get2SMark(3));
    EXPECT_EQ(10, S21.Get2SMark(4));
    EXPECT_EQ(10, S21.Get2SMark(5));
}

TEST (Student2, SettersWithWrongParametres) {
    Student_2S S21 ("Guy", 2, 3, 6, 9, 8, 8, 10, 7, 9, 10, 8);
    S21.Set_name("");
    S21.Set_group(-4);
    S21.Set_course(-3);
    S21.Set1SMark(-8, 1);
    S21.Set1SMark(7, -2);
    S21.Set1SMark(-9, 3);
    S21.Set1SMark(10, 0);
    S21.Set2SMark(10,0);
    S21.Set2SMark(9,-2);
    S21.Set2SMark(-9,0);
    S21.Set2SMark(-10,4);
    S21.Set2SMark(10,6);
    EXPECT_STREQ("Guy", S21.Get_name());
    EXPECT_EQ(2, S21.Get_course());
    EXPECT_EQ(3, S21.Get_group());
    EXPECT_EQ(6, S21.Get1SMark(1));
    EXPECT_EQ(9, S21.Get1SMark(2));
    EXPECT_EQ(8, S21.Get1SMark(3));
    EXPECT_EQ(8, S21.Get1SMark(4));
    EXPECT_EQ(10, S21.Get2SMark(1));
    EXPECT_EQ(7, S21.Get2SMark(2));
    EXPECT_EQ(9, S21.Get2SMark(3));
    EXPECT_EQ(10, S21.Get2SMark(4));
    EXPECT_EQ(8, S21.Get2SMark(5));
}

TEST (Student2, AverageScore) {
    Student_2S S21 ("Guy", 2, 3, 6, 9, 8, 8, 10, 7, 9, 10, 8);
    double m = (6.0 + 9.0 + 8.0 + 8.0 + 10.0 + 7.0 + 9.0 + 10.0 + 8.0) / 9.0;
    EXPECT_DOUBLE_EQ(m, S21.AverageScore());
}