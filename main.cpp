#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Define Student structure
struct Student {
    string name;
    int idNum;
    int* tests;
    double average;
    char grade;
};

// Function to calculate the average score
double calculateAverage(int* scores, int numTests) {
    int sum = 0;
    for (int i = 0; i < numTests; i++) {
        sum += scores[i];
    }
    return static_cast<double>(sum) / numTests;
}

// Function to assign grade based on average score
char getGrade(double avg) {
    if (avg >= 91) return 'A';
    else if (avg >= 81) return 'B';
    else if (avg >= 71) return 'C';
    else if (avg >= 61) return 'D';
    else return 'F';
}

int main() {
    ifstream inputFile("students.txt");
    int numStudents, numTests;

    if (inputFile) { 
        // File exists, read data from file
        inputFile >> numStudents >> numTests;
    } else {
        // File not found, ask user for input
        cout << "File not found! Enter number of students: ";
        cin >> numStudents;
        cout << "Enter number of test scores per student: ";
        cin >> numTests;
    }

    // Dynamically allocate an array of structures
    Student* students = new Student[numStudents];

    if (inputFile) {  
        // Read student data from file
        for (int i = 0; i < numStudents; i++) {
            inputFile >> students[i].name >> students[i].idNum;
            students[i].tests = new int[numTests];

            for (int j = 0; j < numTests; j++) {
                inputFile >> students[i].tests[j];
            }

            // Calculate average and grade
            students[i].average = calculateAverage(students[i].tests, numTests);
            students[i].grade = getGrade(students[i].average);
        }
        inputFile.close();  // Close file
    } else {
        // Read student data from user input
        for (int i = 0; i < numStudents; i++) {
            cout << "\nEnter student " << i + 1 << " name: ";
            cin >> students[i].name;
            cout << "Enter student ID: ";
            cin >> students[i].idNum;

            students[i].tests = new int[numTests];  // Allocate memory for test scores

            for (int j = 0; j < numTests; j++) {
                cout << "Enter test score " << j + 1 << ": ";
                cin >> students[i].tests[j];
            }

            // Calculate average and grade
            students[i].average = calculateAverage(students[i].tests, numTests);
            students[i].grade = getGrade(students[i].average);
        }
    }

    // Display student data in a table format
    cout << "\nStudent Records:\n";
    cout << left << setw(10) << "Name" << setw(10) << "ID" 
         << setw(10) << "Average" << setw(10) << "Grade" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < numStudents; i++) {
        cout << left << setw(10) << students[i].name
             << setw(10) << students[i].idNum
             << setw(10) << fixed << setprecision(2) << students[i].average
             << setw(10) << students[i].grade << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < numStudents; i++) {
        delete[] students[i].tests;
    }
    delete[] students;

    return 0;
}
