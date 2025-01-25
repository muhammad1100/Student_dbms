// Student Database Management System
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include<vector>
#include<sstream>
using namespace std;

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

