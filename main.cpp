// Student Database Management System
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include<vector>
#include<sstream>
using namespace std;

//functions
void intro();
void mainmenu();
void create_a_record();
void viewAll();
void view_Specific(string id);
void modify(string id);
void delete_record(string id);
void deleted();
string calculateGrade(float marks);
void exportToCSV();
void importFromCSV();
//functions

//structure
struct student {
    string firstname;
    string secondname;
    string id;
    float pf, ict, eng, phy, cal;
    string gradepf, gradeict, gradeEng, gradephy, gradecal;
};
//structure

//main
int main() {
    system("cls");
    system("color F1");
    int choice;
    
    intro();
    Sleep(300);
    cout << "\t\t\t\t<============ Student Database Management System ============>\n\n";
    Sleep(300);
    cout << "\t\t\t\t                      1. Main Menu\n\n";
    Sleep(300);
    cout << "\t\t\t\t                      2. Exit\n\n";
    Sleep(300);
    cout << "\t\t\t\t<=============================================================>\n\n";
    cout << "\t\t\t\t                  Enter Your Choice ==> ";
    cin >> choice;
    if (choice == 1) {
        mainmenu();
    } else {
        exit(0);
        return 0;
    }
}
//main

//introduction
void intro() {
    system("cls");
    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  ****  *     ****  ***  ***  ****\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  *     *     *     *  * * * *  *\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  ****  *     *     *  * * * *  ****\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  *     *     *     *  * * * *  *\n";
    Sleep(300);
    cout << "\t\t\t\t\t  ***  ****  ****  ****  *** * * *   ****\n";
    Sleep(300);
    cout << endl;
}
//introduction

// Calculate grades based on marks
string calculateGrade(float marks) {
    if (marks >= 90) return "A+";
    else if (marks >= 80) return "A";
    else if (marks >= 70) return "B";
    else if (marks >= 60) return "C";
    else if (marks >= 50) return "D";
    else return "F";
}
//Calculated grades
