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


// View a specific student record
void view_Specific(string id) {
    ifstream infile("Database.txt");
    if (!infile) {
        cerr << "Error: Could not open file for reading.\n";
        return;
    }

    student s;
    bool found = false;
    cout<<"\t\t\t\t==========VIEW A PARTICULAR STUDENT DATA===========\n\n"<<endl;
    while (infile >> s.firstname >> s.secondname >> s.id >> s.pf >> s.gradepf >> s.ict >> s.gradeict >> s.eng >> s.gradeEng >> s.phy >> s.gradephy >> s.cal >> s.gradecal) {
        if (s.id == id) {
            cout << left << setw(15) << "First Name" << setw(15) << "Second Name" << setw(10) << "ID"
                 << setw(10) << "PF" << setw(8) << "Grade" << setw(10) << "ICT" << setw(8) << "Grade"
                 << setw(10) << "English" << setw(8) << "Grade" << setw(10) << "Physics" << setw(8) << "Grade"
                 << setw(10) << "Calculus" << setw(8) << "Grade" << endl;
            cout << string(120, '-') << endl<<endl;

            cout << left << setw(15) << s.firstname << setw(15) << s.secondname << setw(10) << s.id
                 << setw(10) << s.pf << setw(8) << s.gradepf << setw(10) << s.ict << setw(8) << s.gradeict
                 << setw(10) << s.eng << setw(8) << s.gradeEng << 
                 setw(10) << s.phy << setw(8) << s.gradephy
                 << setw(10) << s.cal << setw(8) << s.gradecal << endl<<endl;
                 found = true;
            break;
        }
    }
     cout<<"\t\t\t\t============================================="<<endl;

    if (!found) {
        cout << "Record not found for ID: " << id << endl;
    }

    infile.close();
}

// Modify a student record
void modify(string id) {
    ifstream infile("Database.txt");
    ofstream tempFile("TempDatabase.txt");
    if (!infile || !tempFile) {
        cerr << "Error: Could not open file.\n";
        return;
    }

    student s;
    bool found = false;

    while (infile >> s.firstname >> s.secondname >> s.id >> s.pf >> s.gradepf >> s.ict >> s.gradeict >> s.eng >> s.gradeEng >> s.phy >> s.gradephy >> s.cal >> s.gradecal) {
        if (s.id == id) {
            found = true;
            cout<<"\t\t\t\t========UPDATE STUDENT DATA==========\n\n";
            cout <<"\t\t\t\tModifying record for ID: " << id << endl;
            cout <<"\t\t\t\tEnter new First Name: ";
            cin >> s.firstname;
            cout <<"\t\t\t\tEnter new Second Name: ";
            cin >> s.secondname;

            cout <<"\t\t\t\tEnter new Programming Fundamentals Marks: ";
            cin >> s.pf;
            s.gradepf = calculateGrade(s.pf);

            cout <<"\t\t\t\tEnter new ICT Marks: ";
            cin >> s.ict;
            s.gradeict = calculateGrade(s.ict);

            cout <<"\t\t\t\tEnter new English Marks: ";
            cin >> s.eng;
            s.gradeEng = calculateGrade(s.eng);

            cout <<"\t\t\t\tEnter new Physics Marks: ";
            cin >> s.phy;
            s.gradephy = calculateGrade(s.phy);

            cout <<"\t\t\t\tEnter new Calculus Marks: ";
            cin >> s.cal;
            s.gradecal = calculateGrade(s.cal);
        }
        tempFile << s.firstname << "\t" << s.secondname << "\t" << s.id << "\t"
                 << s.pf << "\t" << s.gradepf << "\t"
                 << s.ict << "\t" << s.gradeict << "\t"
                 << s.eng << "\t" << s.gradeEng << "\t"
                 << s.phy << "\t" << s.gradephy << "\t"
                 << s.cal << "\t" << s.gradecal << "\n";
    }

    if (!found) {
        cout << "Record not found for ID: " << id << endl;
    } else {
        cout << "Record modified successfully!\n";
    }

    infile.close();
    tempFile.close();
    remove("Database.txt");
    rename("TempDatabase.txt", "Database.txt");
}
// Delete a student record
void delete_record(string id) {
    ifstream infile("Database.txt");
    ofstream tempFile("TempDatabase.txt");
    if (!infile || !tempFile) {
        cerr << "Error: Could not open file.\n";
        return;
    }

    student s;
    bool found = false;

    while (infile >> s.firstname >> s.secondname >> s.id >> s.pf >> s.gradepf >> s.ict >> s.gradeict >> s.eng >> s.gradeEng >> s.phy >> s.gradephy >> s.cal >> s.gradecal) {
        if (s.id == id) {
            found = true;
            cout <<"\t\t\t\tDeleting data for ID: " << id << endl;
            continue; // Skip writing this record to the temp file
        }
