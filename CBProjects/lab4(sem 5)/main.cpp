#include <iostream>
#include "Student.h"
//using namespace std;
#include <cstdlib>
#include <cstring>
#define MAX_PATH 256
using std::cout;
using std::cin;
int main()
{

    Student *MasStud=new Student[3];
    Student Starosta("Starosta",2015,5,0,2,nullptr);
    Student Ilya("ilya",2013,4,1,4,&Starosta);
    Student Nikolai("Nikolai",2014,3,1,3,&Starosta);

    MasStud[0]=Ilya;
    MasStud[1]=Nikolai;
    MasStud[2]=Starosta;
    std::cout<<"Size of massiv:"<<sizeof(MasStud[0])*3<<std::endl;
    std::cout<<"Adress of massiv:"<<MasStud<<std::endl;
    for (int i = 0; i < 3; i++)
        {
            std::cout<<std::endl;
            std::cout<<"Size of "<<MasStud[i].Name<<"="<<sizeof(MasStud[i])<<std::endl;
            std::cout<<"Adress of "<<MasStud[i].Name<<"is "<<(&MasStud[i])<<std::endl;
        }

    std::cout<<"\nHere all abot Nikolai:"<<std::endl;
    std::cout<<"Size of Name "<<MasStud[1].Name<<"= "<<sizeof(MasStud[1].Name)<<std::endl;
    std::cout<<"Adress of Name "<<(&MasStud[1].Name)<<std::endl;
    std::cout<<"Offsetof of Name "<<offsetof(struct Student,Name)<<std::endl;
    std::cout<<"Binary Name"<<std::oct<<" "<<MasStud[1].Name<<" Hex "<<std::hex<<MasStud[1].Name<<std::endl;

    std::cout<<"Size of ball "<<MasStud[1].ball<<"= "<<sizeof(MasStud[1].ball)<<std::endl;
    std::cout<<"Adress of ball "<<(&MasStud[1].ball)<<std::endl;
    std::cout<<"Offsetof of ball "<<offsetof(struct Student,ball)<<std::endl;
    std::cout<<"Binary ball"<<std::oct<<" "<<MasStud[1].ball<<" Hex "<<std::hex<<MasStud[1].ball<<std::endl;


    std::cout<<"\nEnter path of file:";
    char fileName[MAX_PATH];
    std::cin>>fileName;


//while(cin>>fileName)
//{


   try
        {
            workFile(fileName);
        }
    catch(const char *str)
        {
            std::cout<<str<<std::endl;
             std::cout<<"\nEnter path of file:";
        }
    catch(int value)
    {
        if (value=10)
            cout<<"Can't open this file :(";
        if (value=5)
        {
            cout<<"Cant find this";
        }
    }

//}







}
