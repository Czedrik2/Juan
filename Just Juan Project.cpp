#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector> // Use vectors for dynamic memory management

using namespace std;

// Function Prototypes
void inputNames(vector<string>& names);
void inputGrades(vector<float>& grades);
float getValidatedGrade(int studentNumber);
void displayStudentData(const vector<string>& names, const vector<float>& grades);
float calculateAverage(const vector<float>& grades);
string generateUniqueFilename();
void saveToFile(const vector<string>& names, const vector<float>& grades, const string& filename);
void displayFromFile(const string& filename);
void deleteFile(const string& filename);

int main() {
    int choice;
    string lastFilename = ""; // Initialize lastFilename to an empty string

    do {
        system("cls"); // Clear Screen

        cout << "===== Student Info Menu =====\n";
        cout << "[1] Input and Save Student Data\n";
        cout << "[2] View Last Saved File\n";
        cout << "[3] Delete Last Saved File\n";
        cout << "[4] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // clear newline

        if (choice == 1) {
            int count;
            while (!(cin >> count) || count <= 0) {
                cout << "Invalid input. Please enter a positive integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            vector<string> names(count); "juan"
            vector<float> grades(count); "90"

            inputNames(names);"juan"
            inputGrades(grades);"90"

            displayStudentData(names, grades);

            float avg = calculateAverage(grades);"juan","90"
            cout << fixed << setprecision(2);
            cout << "Average grade: " << avg << endl;

            lastFilename = generateUniqueFilename();
            saveToFile(names, grades, lastFilename);

            system("pause"); //Added pause to see the output
        }
        else if (choice == 2) {
            if (lastFilename.empty()) {
                cout << "No file has been saved yet.\n";
            }
            else {
                displayFromFile(lastFilename);
            }
            system("pause");
        }
        else if (choice == 3) {
            if (lastFilename.empty()) {
                cout << "No file to delete.\n";
            }
            else {
                deleteFile(lastFilename);
                lastFilename = ""; //Reset lastfilename after deletion
            }
            system("pause");
        }
        else if (choice == 4) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
            system("pause");
        }

    } while (choice != 4);

    return 0;
}

void inputNames(vector<string>& names) {
    for (size_t i = 0; i < names.size(); ++i) {
        cout << "Enter name for student " << (i + 1) << ": ";
        getline(cin, names[i]);
    }
}

void inputGrades(vector<float>& grades) {
    for (size_t i = 0; i < grades.size(); ++i) {
        grades[i] = getValidatedGrade(i + 1);
    }
}

float getValidatedGrade(int studentNumber) {
    float grade;
    while (true) {
        cout << "Enter grade for student " << studentNumber << " (0-100): ";
        cin >> grade;

        if (!cin.fail() && grade >= 0 && grade <= 100) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number between 0 and 100.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return grade;
}

void displayStudentData(const vector<string>& names, const vector<float>& grades) {
    cout << left << setw(20) << "Name" << setw(10) << "Grade" << endl;
    for (int i = 0; i < 30; i++) cout << "-";
    cout << endl;

    for (size_t i = 0; i < names.size(); ++i) {
        cout << left << setw(20) << names[i] << setw(10) << grades[i] << endl;
    }
}

float calculateAverage(const vector<float>& grades) {
    float sum = 0;
    for (float grade : grades) {
        sum += grade;
    }
    return grades.empty() ? 0 : sum / grades.size(); //Handle empty vector case
}


string generateUniqueFilename() {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    stringstream ss;
    ss << "student_data_";
    ss << (1900 + localTime->tm_year);
    ss << (1 + localTime->tm_mon);
    ss << localTime->tm_mday;
    ss << "_";
    ss << localTime->tm_hour << localTime->tm_min << localTime->tm_sec;


    return ss.str();
}

void saveToFile(const vector<string>& names, const vector<float>& grades, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    for (size_t i = 0; i < names.size(); ++i) {
        outFile << names[i] << "," << grades[i] << endl;
    }

    outFile.close();
    cout << "Student data saved to " << filename << endl;
}

void displayFromFile(const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    cout << "Data from file " << filename << ":" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void deleteFile(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        cout << "File '" << filename << "' deleted successfully.\n";
    }
    else {
        cerr << "Error deleting file: " << filename << endl;
    }
}