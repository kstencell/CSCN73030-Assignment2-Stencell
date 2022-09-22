#pragma once

#include <string>
#include "Config.h"

using namespace std;

typedef struct STUDENT_DATA {

	string firstName;
	string lastName;

#ifdef PRERELEASE
	string email;
#endif

}STUDENT_DATA;

#ifdef _DEBUG
void PrintStudent(STUDENT_DATA);
#endif