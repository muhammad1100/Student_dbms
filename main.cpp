// Student Database Management System
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <sstream>
#include <limits>
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
    do{
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

    switch (choice) {
        case 1:
            mainmenu();
            break;
        case 2:
            cout << "\n\t\t\t\tExiting the program. Goodbye!\n";
            break;
        default:
            cout << "\n\t\t\t\tInvalid choice! Please enter a valid option (1 or 2).\n";
            system("pause");
            
    }
}while(choice != 2);
    
}
//main

//introduction
void intro() {
    system("cls");
    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  ****  *     ****  ***  ***  ****\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  *     *     *     *  * * * * *\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  ****  *     *     *  * * * * ****\n";
    Sleep(300);
    cout << "\t\t\t\t\t * * *  *     *     *     *  * * * * *\n";
    Sleep(300);
    cout << "\t\t\t\t\t  ***   ****  ****  ****  *** * * *  ****\n";
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

// Add student record
void create_a_record() {
    system("cls");
    student s;
    cout<<"\t\t\t\t=======CREATE A DATA======\n\n";
    cout <<"\t\t\t\tEnter First Name: ";
    cin >> s.firstname;
    cout <<"\t\t\t\tEnter Second Name: ";
    cin >> s.secondname;

    // Input and validate unique ID
    string tempId;
    cout <<"\t\t\t\tEnter ID: ";
    cin >> tempId;
    s.id = tempId;
    
    cout <<"\t\t\tEnter Programming Fundamentals Marks: ";
    cin >> s.pf;
    s.gradepf = calculateGrade(s.pf);

    cout <<"\t\t\tEnter ICT Marks: ";
    cin >> s.ict;
    s.gradeict = calculateGrade(s.ict);

    cout <<"\t\t\tEnter English Marks: ";
    cin >> s.eng;
    s.gradeEng = calculateGrade(s.eng);

    cout <<"\t\t\tEnter Physics Marks: ";
    cin >> s.phy;
    s.gradephy = calculateGrade(s.phy);

    cout <<"\t\t\tEnter Calculus Marks: ";
    cin >> s.cal;
    s.gradecal = calculateGrade(s.cal);
    
    // Write to file
    ofstream outfile("Database.txt", ios::app);
    if (!outfile) {
        cerr << "Error: Could not open file for writing.\n";
        return;
    }

    outfile << s.firstname << "\t" << s.secondname << "\t" << s.id << "\t"
            << s.pf << "\t" << s.gradepf << "\t"
            << s.ict << "\t" << s.gradeict << "\t"
            << s.eng << "\t" << s.gradeEng << "\t"
            << s.phy << "\t" << s.gradephy << "\t"
            << s.cal << "\t" << s.gradecal << "\n";

    outfile.close();
    cout << "Student Data Added Successfully!\n";
}
//Add s student record
    
// View all student records
void viewAll() {
    ifstream infile("Database.txt");
    if (!infile) {
        cerr << "Error: Could not open file for reading.\n";
        return;
    }

    student s;
    cout<<"\t\t\t\t==========VIEW DATA OF ALL STUDENT===========\n\n"<<endl;
    cout << left << setw(15) << "First Name" << setw(15) << "Second Name" << setw(10) << "ID"
         << setw(10) << "PF" << setw(8) << "Grade" << setw(10) << "ICT" << setw(8) << "Grade"
         <<  setw(10) << "English" << setw(8) << "Grade" << setw(10) << "Physics" << setw(8) << "Grade"
         << setw(10) << "Calculus" << setw(8) << "Grade" << endl;
    cout << string(120, '-') << endl<<endl;

    while (infile >> s.firstname >> s.secondname >> s.id >> s.pf >> s.gradepf >> s.ict >> s.gradeict >> s.eng >> s.gradeEng >> s.phy >> s.gradephy >> s.cal >> s.gradecal) {
        cout << left << setw(15) << s.firstname << setw(15) << s.secondname << setw(10) << s.id
             << setw(10) << s.pf << setw(8) << s.gradepf << setw(10) << s.ict << setw(8) << s.gradeict
             << setw(10) << s.eng << setw(8) << s.gradeEng << setw(10) << s.phy << setw(8) << s.gradephy
             << setw(10) << s.cal << setw(8) << s.gradecal << endl<<endl;
    }
     cout<<"\t\t\t\t============================================="<<endl;

    infile.close();
}
//View all student record

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
//View a specific student record

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
//Modify a student record

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
        cout <<"\t\t\t\tData deleted successfully!\n";
    }

    infile.close();
    tempFile.close();
    remove("Database.txt");
    rename("TempDatabase.txt", "Database.txt");
}
//Delete a student record

// Confirm deletion
void deleted() {
    cout <<"\t\t\t\tData has been deleted successfully.\n";
}
//confirm deletion

//Export CSV
void exportToCSV() {
    ifstream infile("Database.txt");
    ofstream outfile("Database.csv");
    if (!infile || !outfile) {
        cerr << "Error: Could not open file.\n";
        return;
    }
    
    student s;
    while (infile >> s.firstname >> s.secondname >> s.id >> s.pf >> s.gradepf >> s.ict >> s.gradeict >> s.eng >> s.gradeEng >> s.phy >> s.gradephy >> s.cal >> s.gradecal) {
        outfile << s.firstname << "," << s.secondname << "," << s.id << ","
                << s.pf << "," << s.gradepf << ","
                << s.ict << "," << s.gradeict << ","
                << s.eng << "," << s.gradeEng << ","
                << s.phy << "," << s.gradephy << ","
                << s.cal << "," << s.gradecal << "\n";
    }
    
    infile.close();
    outfile.close();
    cout <<"\t\t\t\tData exported to CSV successfully!\n";
}
//Export CSV

//Import CSV
void importFromCSV() {
    ifstream infile("Database.csv");
    if (!infile) {
        cerr << "Error: Could not open file for reading.\n";
        return;
    }

    student s;
    while (infile.good()) {
        string line;
        getline(infile, line);
        if (line.empty()) continue;
        
        stringstream ss(line);
        getline(ss, s.firstname, ',');
        getline(ss, s.secondname, ',');
        getline(ss, s.id, ',');
        ss >> s.pf; ss.ignore();
        getline(ss, s.gradepf, ',');
        ss >> s.ict; ss.ignore();
        getline(ss, s.gradeict, ',');
        ss >> s.eng; ss.ignore();
        getline(ss, s.gradeEng, ',');
        ss >> s.phy; ss.ignore();
        getline(ss, s.gradephy, ',');
        ss >> s.cal; ss.ignore();
        getline(ss, s.gradecal);

        // Write to the database file
        ofstream outfile("Database.txt", ios::app);
        if (!outfile) {
            cerr << "Error: Could not open file for writing.\n";
            return;
        }
        
        outfile << s.firstname << "\t" << s.secondname << "\t" << s.id << "\t"
                << s.pf << "\t" << s.gradepf << "\t"
                << s.ict << "\t" << s.gradeict << "\t"
                << s.eng << "\t" << s.gradeEng << "\t"
                << s.phy << "\t" << s.gradephy << "\t"
                << s.cal << "\t" << s.gradecal << "\n";

        outfile.close();
    }

    infile.close();
    cout <<"\t\t\t\tData imported from CSV successfully!\n";
}
//Import CSV

// Main menu
void mainmenu() {
    int choice;
    do {
        system("cls");
        cout<<"\n\n\n";
		Sleep(100);
		cout<<"\t\t\t\t\t   <=============================>"<<endl<<endl;
		Sleep(100);
		cout<<"\t\t\t\t\t              Main Menu           "<<endl;
		Sleep(100);
		cout<<"\t\t\t\t\t   <=============================>"<<endl<<endl;
		Sleep(100);
        cout<<"\t\t\t\t\t 1. Add Student                             "<<endl<<endl;
        Sleep(100);
        cout <<"\t\t\t\t\t 2. View All Data                          "<<endl<<endl;
        Sleep(100);
        cout <<"\t\t\t\t\t 3. View Specific Data                     "<<endl<<endl;
        Sleep(100);
        cout <<"\t\t\t\t\t 4. Modify Data                            "<<endl<<endl;
        Sleep(100);
        cout <<"\t\t\t\t\t 5. Delete Data                            "<<endl<<endl;
        Sleep(100);
        cout <<"\t\t\t\t\t 6. Export to CSV                          "<<endl<<endl;
        Sleep(100);
        cout <<"\t\t\t\t\t 7. Import from CSV                        "<<endl<<endl;
        Sleep(100);
        cout <<"\t\t\t\t\t 8. Exit                                   "<<endl<<endl;
        Sleep(100);
        cout<<"\t\t\t\t\t  <=============================>"<<endl<<endl;
        
        cout <<"\t\t\t\t\t Enter your choice: ==> ";
        cin >> choice;
        
        string id;
        switch (choice) {
        case 1:
            create_a_record();
            break;
        case 2:
            viewAll();
            break;
        case 3:
            cout << "Enter ID to view: ";
            cin >> id;
            view_Specific(id);
            break;
        case 4:
            cout << "Enter ID to modify: ";
            cin >> id;
            modify(id);
            break;
        case 5:
            cout << "Enter ID to delete: ";
            cin >> id;
            delete_record(id);
            deleted();
        case 6:
            exportToCSV();
            break;
        case 7:
            importFromCSV();
            break;
        case 8:
            return;
        default:
            cout << "Invalid choice, please try again.\n";
        }

        system("pause");
    } while (choice != 8);
}
//Main Menu
