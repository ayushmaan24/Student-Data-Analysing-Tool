#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include<string>
#include<vector>
#include "Student.h"
#include<fstream>
#include<algorithm>
#include<exception>
#include<iostream>
class Studentlist
{
	public:
		Studentlist(std::string filepath);
		Student gettopper();
		std::vector<Student> gethonorstudents();
		std::vector<Student> getfailingstudents();
		std::vector<Student> getallstudents();
	protected:
		std::vector<Student> students;
};

class myexception : public std::exception{
	public:
		const char *what() const throw(){
			return "Studentlist: No such students found";
		}
};

#endif
