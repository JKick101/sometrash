#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <cstring>
//using namespace std;
struct Student
{
    //private:
    //char *Name=new char[17];
    std::string Name;
    size_t year;
    int ball;
    int pol;
    int CurNum;
    Student* starosta;
   // public:
    Student()=default;
    Student(std::string N,size_t y,int b, bool p,int C,Student* s):
        Name(N),year(y),ball(b),pol(p),CurNum(C),starosta(s){}

   /* ~Student()
    {
        delete starosta;
        //delete [] Name;
    }*/
};
std::ostream& operator<<(std::ostream& output, const Student& outStud);
std::istream& operator>>(std::istream& input,Student& inStud);
void workFile(const char*);
void findText(char*,int,char*,int);
char **delText(char *buffer,int SIZEb);
void bubbleSort ( char **pp,unsigned int SIZE );

#endif // STUDENT_H_INCLUDED
