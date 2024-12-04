// Grade_Book.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_STUDENT = 5;
const int NUM_TESTS = 4;

//Function prototypes
void getStudentData(string[], double[][NUM_TESTS]);

char determineLetterGrade(double);

void printResults(const string[], const double[][NUM_TESTS], const char[]);

double averageAfterDropLowest(const double[], int);

int main()
{
    string studentNames[NUM_STUDENT]; 
    char letterGrades[NUM_STUDENT]; 
    double testScores[NUM_STUDENT][NUM_TESTS]; 

    // Input student data
    getStudentData(studentNames, testScores); 

    // Calculate average scores (dropping the lowest score) and assign letter grades 
    for (int i = 0; i < NUM_STUDENT; ++i) { 
        double average = averageAfterDropLowest(testScores[i], NUM_TESTS); 
        letterGrades[i] = determineLetterGrade(average); 
    } 

    // Display the results 
    printResults(studentNames, testScores, letterGrades); 

    return 0; 
}


// Function to input student names and test scores 
void getStudentData(string studentNames[], double testScores[][NUM_TESTS]) {
    for (int i = 0; i < NUM_STUDENT; ++i) { 
        cout << "Enter the name of student " << (i + 1) << ": "; 
        cin >> studentNames[i]; 
        for (int j = 0; j < NUM_TESTS; ++j) { 
            do { 
                cout << "Enter test score " << (j + 1) << " for " << studentNames[i] << ": "; 
                cin >> testScores[i][j]; 
                if (testScores[i][j] < 0 || testScores[i][j] > 100) { 
                    cout << "Invalid score. Please enter a score between 0 and 100.\n"; 
                } 
            } while (testScores[i][j] < 0 || testScores[i][j] > 100); 
        } 
    } 
}


// Function to determine the letter grade based on the average score
char determineLetterGrade(double average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else return 'F';
}

// Function to display the results 
void printResults(const string studentNames[], const double testScores[][NUM_TESTS], const char letterGrades[]) { 
    for (int i = 0; i < NUM_STUDENT; ++i) {
        double average = averageAfterDropLowest(testScores[i], NUM_TESTS);
        cout << "\nStudent: " << studentNames[i] 
             << "\nAverage Score (excluding lowest): " << fixed << std::setprecision(2) << average 
             << "\nLetter Grade: " << letterGrades[i] << "\n"; 
    } 
}


// Function to calculate the average of test scores, dropping the lowest score 
double averageAfterDropLowest(const double scores[], int size) {
    double total = 0.0; 
    double minScore = scores[0];
    for (int i = 0; i < size; ++i) {
        total += scores[i];
        if (scores[i] < minScore) {
            minScore = scores[i];
        }
    }
    total -= minScore; // Subtract the lowest score from the total 
    return total / (size - 1); // Calculate the average, excluding the lowest score 
}

