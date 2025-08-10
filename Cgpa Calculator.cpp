#include<iostream>
#include<iomanip> // for setw and formatting
using namespace std;

// Function to convert marks to GPA
float convertToGPA(float marks) {
    if (marks >= 85) return 4.0;
    else if (marks >= 80) return 3.7;
    else if (marks >= 75) return 3.3;
    else if (marks >= 70) return 3.0;
    else if (marks >= 65) return 2.7;
    else if (marks >= 60) return 2.3;
    else if (marks >= 55) return 2.0;
    else if (marks >= 50) return 1.7;
    else if (marks >= 45) return 1.3;
    else if (marks >= 40) return 1.0;
    else return 0.0;
}

int main() {
    int numCourses;
    float marks, creditHours;
    float totalGradePoints = 0, totalCredits = 0;

    cout << "Enter number of courses: ";
    cin >> numCourses;

    string courseNames[numCourses];
    float marksArray[numCourses], credits[numCourses], gpaArray[numCourses];

    cin.ignore(); // Clear buffer

    for (int i = 0; i < numCourses; i++) {
        cout << "\nEnter name of course " << i + 1 << ": ";
        getline(cin, courseNames[i]);

        cout << "Enter marks for " << courseNames[i] << " (out of 100): ";
        cin >> marks;

        cout << "Enter credit hours for " << courseNames[i] << ": ";
        cin >> creditHours;

        float gpa = convertToGPA(marks);

        marksArray[i] = marks;
        credits[i] = creditHours;
        gpaArray[i] = gpa;

        totalGradePoints += gpa * creditHours;
        totalCredits += creditHours;

        cin.ignore(); // prepare for next getline
    }

    float cgpa = totalGradePoints / totalCredits;

    // Display course details in table format
    cout << "\n---------------------------------------------\n";
    cout << left << setw(20) << "Course Name" 
         << setw(10) << "Marks" 
         << setw(10) << "GPA" 
         << setw(15) << "Credit Hours" << endl;
    cout << "---------------------------------------------\n";

    for (int i = 0; i < numCourses; i++) {
        cout << left << setw(20) << courseNames[i]
             << setw(10) << marksArray[i]
             << setw(10) << fixed << setprecision(1) << gpaArray[i]
             << setw(15) << credits[i] << endl;
    }

    cout << "---------------------------------------------\n";
    cout << "Total Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Your CGPA is: " << fixed << setprecision(2) << cgpa << " (on a 4.0 scale)" << endl;

    return 0;
}

