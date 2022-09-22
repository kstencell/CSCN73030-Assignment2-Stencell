
#include <iostream>
#include "Student.h"

// simple output of student details
#ifdef _DEBUG
void PrintStudent(STUDENT_DATA student) {

#ifdef PRERELEASE
	cout << student.lastName << ", " << student.firstName << ", " << student.email << endl;
#else
	cout << student.lastName << ", " << student.firstName << endl;
#endif
}
#endif