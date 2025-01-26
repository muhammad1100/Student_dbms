Student Database Management System

Overview

The Student Database Management System is a console-based application designed to efficiently manage student records. This system allows users to create, view, modify, delete, export, and import student data. The application leverages file operations to ensure persistence of data and includes functionalities for grading and record management.

Features

1. Add Student Record

Allows the user to add a new student record by entering the following details:

First Name

Second Name

Unique Student ID

Marks in Programming Fundamentals, ICT, English, Physics, and Calculus

2. View All Records

Displays all student records in a tabular format, including their grades for each subject.

3. View Specific Record

Searches for and displays the record of a specific student by entering their unique ID.

4. Modify Student Record

Updates an existing student record by allowing the user to modify details such as name and marks.

5. Delete Student Record

Removes a specific student record based on the provided ID.

6. Export to CSV

Exports all student records to a CSV file for external use or backup.

7. Import from CSV

Imports student data from a CSV file, adding the records to the existing database.

8. Grade Calculation

Grades are automatically calculated based on the marks provided using the following scale:

A+: 90 and above

A: 80 - 89

B: 70 - 79

C: 60 - 69

D: 50 - 59

F: Below 50

File Structure

1. Database.txt

Stores all student records in a tab-separated format.

Automatically updated with each operation (add, modify, delete).

2. Database.csv

Used for exporting and importing student records in a comma-separated format.

How It Works

Main Menu Options

Add Student

Prompts the user to enter student details and appends the record to Database.txt.

View All Data

Reads and displays all records from Database.txt.

View Specific Data

Searches for a student record in Database.txt by the provided ID.

Modify Data

Searches for a student record by ID and allows the user to update its details.

Delete Data

Removes the record associated with the provided ID and updates the file.

Export to CSV

Converts all records from Database.txt into a CSV format.

Import from CSV

Adds records from a CSV file to Database.txt.

Exit

Closes the application.

System Requirements

Operating System: Windows

Compiler: GCC or any C++ compiler supporting C++11 or later

Library Dependencies:

<iostream>: For input and output

<fstream>: For file operations

<string>: For string manipulation

<iomanip>: For formatting output

<windows.h>: For system-specific functionalities like Sleep

<vector> and <sstream>: For parsing CSV files

How to Run

Compile the code using a C++ compiler (e.g., g++ -o StudentDB StudentDB.cpp).

Run the compiled executable (StudentDB.exe).

Navigate through the menu by entering the corresponding option number.

Example Workflow

Start the application.

Select 1 to add a new student.

Enter the required details (name, ID, marks).

View all records by selecting 2.

Modify a specific record by choosing 4 and entering the ID.

Export records to CSV using option 6.

Exit the program by selecting 8.

Authors

This project was collaboratively developed by:

Bilal: Core functionalities and export/import.

Aiman: Record creation and viewing features.

Asna: Record modification and deletion.