#include "Studentlist.h"
#define failing_gpa 4
#define honor_grade 9
using namespace std;
bool compare(Student& s1, Student& s2){
	return s1.getgpa()>s2.getgpa();
}
Studentlist::Studentlist(string filepath){
	ifstream studentfile(filepath.c_str());
	string linecontents;
	while(!studentfile.eof()){
		getline(studentfile, linecontents);
		Student s(linecontents);
		students.push_back(s);
	}
	studentfile.close();
	sort(students.begin(), students.end(), compare);
	
}

Student Studentlist::gettopper(){
	if(students.size()==0 || students.at(0).getgpa()<=failing_gpa){
		throw myexception();
	}
	return students.at(0);
}
vector<Student> Studentlist::gethonorstudents(){
	if(students.size()==0 || students.at(0).getgpa()<=failing_gpa){
		throw myexception();
	}
	vector<Student> ans;
	for(int i=0; i<students.size(); i++){
		if(students[i].getgpa()<honor_grade) break;
		else if(students[i].getgpa()>=honor_grade) ans.push_back(students[i]);
	}
	return ans;
}
vector<Student> Studentlist::getfailingstudents(){
	vector<Student> ans;
	if(students.size()==0 || students[students.size()-1].getgpa()>4){
		throw myexception();
	} 
	for(int i=students.size()-1; i>=0; i--){
		if(students[i].getgpa()<=4) ans.push_back(students[i]);
	}
	return ans;
}
vector<Student> Studentlist::getallstudents(){
	vector<Student> ans;
	if(students.size()==0){
		throw myexception();
	}	
	for(int i=0; i<students.size(); i++){
		ans.push_back(students[i]);
	}
	return ans;
}

