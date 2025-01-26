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

