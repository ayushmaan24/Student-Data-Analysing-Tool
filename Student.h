#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<sstream>
class Student
{
	public:
		Student(std::string input);
		std::string getfirstname();
		std::string getlastname();
		std::string getname();
		double getsid();
		float getgpa();
	protected:
		std::string firstname;
		std::string lastname;
		double sid;
		float gpa;
};

#endif
