
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Student.h"

using namespace std;

int main(void) {

	// open file and double check
	ifstream studentData("StudentData.txt");
	if (!studentData) {
		cout << "Error reading file" << endl;
		exit(1);
	}

	vector<STUDENT_DATA> students;
	string line;

	// read one line at a time from the .txt file
	while (getline(studentData, line)) {
		STUDENT_DATA newStudent;
		stringstream ss(line);
		
		// parse the lines by comma and assign struct variables accordingly
		string substr;
		getline(ss, substr, ',');
		newStudent.lastName = substr;
		getline(ss, substr); // stringstream is pushed forward by last getline() so no need to specify comma here, it goes to end of line by default
		newStudent.firstName = substr;

		// add to vector of students
		students.push_back(newStudent);

#ifdef _DEBUG
		cout << newStudent.firstName << ", " << newStudent.lastName << endl;
#endif
	}

	return 0;
}