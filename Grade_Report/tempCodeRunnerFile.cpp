#include<iostream>
#include<string>

using namespace std;

struct student
{
    int ID,age,year;
    char fname[15];
    char lname[15];
    char gender[8];
    char semister[10];
    float CGPA;
    struct Main
    {
        float prog1;
        float Int_cs;
        float prog2;
        float comEng;
    }course;

    struct 
    {
        float prog1g;
        float Intg;
        float prog2g;
        float comeg;
    }grade;
};
struct student s[100];

int n;
int main()
{
    cout<<"====================================================\n";

        cout<<"    Student Grade Report System Using C++\n";
		cout<<"          Made By Lohit & Alok\n\n";
		cout<<"    Welcome To Student Grade Report:\n";
		
	cout<<"====================================================\n";

}


