#include<iostream>
#include<string>
#include "Student.h"
#include "Studentlist.h"
#include<exception>
using namespace std;
void print(Student student){
	cout<<endl;
	//cout<<"First Name: "<<student.getfirstname()<<endl;
	//cout<<"Last Name: "<<student.getlastname()<<endl;
	cout<<"Full Name: "<<student.getname()<<endl;
	cout<<"SID: "<<student.getsid()<<endl;
	cout<<"GPA: "<<student.getgpa()<<endl;
	cout<<endl;
}
int main(int argc, const char *argv[]){
	try{		
		if(argc!=2){
			cout<<"Student Data Analyzing software: PATH_TO_STUDENT_FILE"<<endl;
			return -1;
		}
		string path(argv[1]);
		Studentlist list(path);
		vector<Student> ho=list.getfailingstudents();
		cout<<"Failing Students are: "<<endl;
		for(int i=0; i<ho.size(); i++){
			print(ho[i]);
		}
		vector<Student> to=list.gethonorstudents();
		cout<<"Honor Students are: "<< endl;
		for(int i=0; i<to.size(); i++){
			print(to[i]);
		}
		Student s=list.gettopper();
		cout<<"Topper student is: "<<endl;
		print(s);
		vector<Student> all=list.getallstudents();
		cout<<"List of all students in decreasing GPA order: "<< endl;
		for(int i=0; i<all.size(); i++){
			print(all[i]);
		}
		
	}
	catch(exception &e){
		cout<<"An exception was encountered:"<<endl;
		cout<<"\t"<<e.what()<<endl;
		return -1;
	}
	
	return 0;
}

