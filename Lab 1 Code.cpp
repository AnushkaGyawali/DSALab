#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

int i;

struct Subject{
	char name[30];
	int marks;
};

struct Student{
	int crn;
	char name[30];
	Subject subject[3];
};

Student * initialize(){
	static Student student[5]; 
	student[0].crn=301; /*first student data initialization */
	strcpy(student[0].name,"Hari Kunwar");
	strcpy(student[0].subject[0].name, "Programming");
	student[0].subject[0].marks=45;
	strcpy(student[0].subject[1].name, "Maths");
	student[0].subject[1].marks=60;
	strcpy(student[0].subject[2].name, "Physics");
	student[0].subject[2].marks=36;
	student[1].crn=302; /*second student data initialization */
	strcpy(student[1].name,"Manita Thapa");
	strcpy(student[1].subject[0].name, "Programming");
	student[1].subject[0].marks=52;
	strcpy(student[1].subject[1].name, "Maths");
	student[1].subject[1].marks=15;
	strcpy(student[1].subject[2].name, "Physics");
	student[1].subject[2].marks=65;
	student[2].crn=303; /*third student data initialization */
	strcpy(student[2].name,"Puskar Shah");
	strcpy(student[2].subject[0].name, "Programming");
	student[2].subject[0].marks=78;
	strcpy(student[2].subject[1].name, "Maths");
	student[2].subject[1].marks=85;
	strcpy(student[2].subject[2].name, "Physics");
	student[2].subject[2].marks=79;
	student[3].crn=304; /*fourth student data initialization */
	strcpy(student[3].name,"Usha Karki");
	strcpy(student[3].subject[0].name, "Programming");
	student[3].subject[0].marks=48;
	strcpy(student[3].subject[1].name, "Maths");
	student[3].subject[1].marks=45;
	strcpy(student[3].subject[2].name, "Physics");
	student[3].subject[2].marks=45;
	student[4].crn=305; /*fifth student data initialization */
	strcpy(student[4].name,"Bikash Rajat");
	strcpy(student[4].subject[0].name, "Programming");
	student[4].subject[0].marks=92;
	strcpy(student[4].subject[1].name, "Maths");
	student[4].subject[1].marks=95;
	strcpy(student[4].subject[2].name, "Physics");
	student[4].subject[2].marks=88;
	
	return student;
}
float calculatePercentage(Student *individual){/*%calculation */
	int total;
	total=individual->subject[0].marks+individual->subject[1].marks+individual->subject[2].marks;
	return total/3;
	
}

void PassStudentCount(Student * student){
	int count=0;
	for (i=0; i<5; i++){
		if (calculatePercentage(student+i)>=45){
			count++;
		}
	}
	cout<<"Pass student= "<<count<<endl;
}

string calculateDivision(Student * student){
	
	if(calculatePercentage(student)>=90){
		return "Distinction";
	}else if(calculatePercentage(student)>=75){
		return "First Division";
	}else if(calculatePercentage(student)>=50){
		return "Second Division";
	}else if(calculatePercentage(student)>=45){
		return "Pass";
	}else{
		return "Fail";
	}
}

void IndividualResult(Student *student){
	int input;
	
	cout<<"CRN number: ";
	cin>>input;
	for(i=0; i<5;i++){
		if((student+i)->crn==input){
			cout<<"Division is: "<<calculateDivision(student+i)<<endl;
		}
	}
}

void displayReport(Student *student){
	cout<<"CRN	"<<"  Name	"<<"	Division	"<<endl;
	for(i=0;i<5;i++){
		cout<<(student+i)->crn<<"	"<<(student+i)->name<<"	"<<calculateDivision(student+i)<<endl;
	}
}

int main(){
	Student *allStudents;
	allStudents=initialize();
	PassStudentCount(allStudents);
	IndividualResult(allStudents);
	displayReport(allStudents);
	return 0;
}
