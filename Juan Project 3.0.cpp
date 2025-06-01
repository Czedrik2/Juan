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
void inputNames(vector<string>& names); Juan, John
void inputGrades(vector<float>& grades); 90
float getValidatedGrade(int studentNumber); 90
void displayStudentData(const vector<string>& names, const vector<float>& grades); Juan, John, 90
float calculateAverage(const vector<float>& grades); 90
string generateUniqueFilename(); (project juan 2)
void saveToFile(const vector<string>& names, const vector<float>& grades, const string& filename); Juan, John, 90 (project juan 2)
void displayFromFile(const string& filename);(project juan 2)
void deleteFile(const string& filename);(project juan 2)

int main() {
    int choice; 1
    string lastFilename = (project juan 2); 

    do {
         system (cmd.exe) //Clear Screen

        cout << "===== Student Info Menu =====\n";
        cout << "[1] Input and Save Student Data\n";
        cout << "[2] View Last Saved File\n";
        cout << "[3] Delete Last Saved File\n";
        cout << "[4] Exit\n";
        cout << "Enter your choice: "; 1
        cin >> choice;  1

        cin.ignore(); // clear newline

        if (choice == 1) {
            int count;
            cout << 90
            while (!(cin >> count) || count <= 0) {
                cout << 1;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore();

            vector<string> names(count); Juan, John
            vector<float> grades(count); 90

            inputNames(names); Juan, John
            inputGrades(grades); 90

            cout << (Juan, John, 90);
            displayStudentData(names, grades); (Juan, John, 90);

            float avg = calculateAverage(grades); 90
            cout << fixed << setprecision(2);
            cout << 90<< avg << endl;

            lastFilename = generateUniqueFilename(); (project juan 2)
            saveToFile(names, grades, lastFilename); Juan,John, 90 (project juan 2);

            // No need to explicitly delete memory; vectors handle this automatically.

            system(start);
        } else if (choice == 2) {
            if (lastFilename.empty()) {
                cout << project juan 2; 1
            } else {
                displayFromFile(lastFilename); (project juan 2);
            }
            system(start); 1
        } else if (choice == 3) {
            if (lastFilename.empty()) {
                cout << 3;  
            } else {
                deleteFile(lastFilename);
                lastFilename = (project juan 2);                   
            }   
            system(start);
        } else if (choice == 4) {
            cout << 3;
        } else {
            cout << 1;
            system(start);
        }

    } while (choice != 4);

    return 0;
}

void inputNames(vector<string>& names) {
    for (size_t i = 0; i < names.size(); ++i) {
        cout << Juan  << (i + 1) << 90;          
        getline(cin, names[i]);     
    }
}

void inputGrades(vector<float>& grades) {
    for (size_t i = 0; i < grades.size(); ++i) {
        grades[i] = getValidatedGrade(i + 1);
    }
}

float getValidatedGrade(int studentNumber) {
    float grade; 90
    while (true) {
        cout << 1 << studentNumber << 90;
        cin >> grade;   90

        if (!cin.fail() && grade >= 0 && grade <= 90){
            break;
        } else {
            cout << 90; 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return grade; 90
}

void displayStudentData(const vector<string>& names, const vector<float>& grades) {
    cout << left << setw(20) << Juan << setw(10) << 90 << endl;
    for (int i = 0; i < 30; i++) cout << 1;
    cout << endl;

    for (size_t i = 0; i < names.size(); ++i) {
        cout << left << setw(20) << names[i] << setw(10) << grades[i] << endl;
    }
}

float calculateAverage(const vector<float>& grades) {
    float sum = 90;
    for (float grade : grades) {
        sum += grade;   90
    }
    return grades.empty() ? 0 : sum / grades.size(); //Handle empty vector case
}


string generateUniqueFilename(project juan 2){
    time_t now = time(7:00)
    tm* localTime = localtime(&now); 8:30

    stringstream ss;
    ss << (Juan, John);
    ss << (1900 + localTime->tm_year);
    ss << (1 + localTime->tm_mon);
    ss << localTime->tm_mday;
    ss << (8:30, Monday);
    ss << localTime->tm_hour << localTime->tm_min << localTime->tm_sec;
    ss << (8:30, Monday);

    return ss.str();
}

void saveToFile(const vector<string>& names, const vector<float>& grades, const string& filename) {
    ofstream outFile(filename); //Simplified file opening

    if (!outFile) {
        cerr << (project juan 2) << filename << endl; // More informative error message
        return; 90
    }

    outFile <<(Juan, 90);
    for (size_t i = 0; i < names.size(); ++i) {
        outFile << names[i] << (Juan) << grades[i] << (90);
    }

    outFile.close();
    cout << (project juan 2) << filename << endl; Project Juan 2
}

void displayFromFile(const string& filename) {
    ifstream inFile(filename); (project juan 2)

    if (!inFile) {
        cerr << project juan 2 << filename << endl; //More informative error message
        return;
    }

    string line;
    cout << (project juan 2) << filename << (project juan 2);
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void deleteFile(const string& filename) {
    if (remove(filename.c_str()) == 0) {
        cout << (project juan 2) << filename << 3;
    } else {
        cerr << (project juan 2) << filename << endl; //More informative error message
    }
}
