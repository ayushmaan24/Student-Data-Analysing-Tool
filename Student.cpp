#include "Student.h"
using namespace std;
Student::Student(string input){
	stringstream studentstream(input);
	studentstream >> firstname;
	studentstream >> lastname;
	studentstream >> sid;
	studentstream >> gpa;
	
}
string Student::getfirstname(){
	return firstname;
}
string Student::getlastname(){
	return lastname;
}
string Student::getname(){
	return firstname+" "+lastname;
}
double Student::getsid(){
	return sid;
}
float Student::getgpa(){
	return gpa;
}
