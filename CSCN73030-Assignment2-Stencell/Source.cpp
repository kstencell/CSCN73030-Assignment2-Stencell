#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Config.h"
#include "Student.h"

using namespace std;

// PROTOTYPES
void GetStudentData(vector<STUDENT_DATA>&);


int main(void) {

#ifdef PRERELEASE
	cout << "Running PreRelease Version" << endl;
#else
	cout << "Running Standard Version" << endl;
#endif

	vector<STUDENT_DATA> students;
	GetStudentData(students);

	return 0;
}

void GetStudentData(vector<STUDENT_DATA>& students) {

	// open file and double check (same for both standard and pre-release versions)
#ifdef PRERELEASE
	ifstream studentData("StudentData_Emails.txt");
#else
	ifstream studentData("StudentData.txt");
#endif

	if (!studentData) {
		cout << "Error reading file" << endl;
		exit(1);
	}

	string line;

	// read one line at a time from the .txt file
	while (getline(studentData, line)) {
		STUDENT_DATA newStudent;
		stringstream ss(line);

		// parse the lines by comma and assign struct variables accordingly
		string substr;
		getline(ss, substr, ',');
		newStudent.lastName = substr;
		getline(ss, substr, ',');
		newStudent.firstName = substr;

		// reading student emails is a new feature in pre-release
#ifdef PRERELEASE
		getline(ss, substr, ',');
		newStudent.email = substr;
#endif

		// add to vector of students
		students.push_back(newStudent);

#ifdef _DEBUG
		PrintStudent(newStudent);
#endif
	}

	return;
}