#include <iostream>

struct Student
{
    //private:
    //char *Name=new char[17];
    std::string Name;
    size_t year;
    int ball:3;
    bool pol;
    int CurNum:3;
    Student* starosta;
    public:
    Student()=default;
    Student(std::string N,size_t y,int b, bool p,int C):
        Name(N),year(y),ball(b),pol(p),CurNum(C){}
    ~Student()
    {
        delete starosta;
        //delete [] Name;
    }
};
std::ostream& operator<<(std::ostream& output, const Student& outStud);
std::istream& operator<<(std::istream& input,Student& inStud);



int main()
{
    //Student Ilya("Ilya",2013,5,1,3);
    Student *MasStud=new Student[3];
    MasStud[0]={"Ilya",2013,5,1,3};

}


std::ostream &operator<<(std::ostream& output, const Student& outStud)
{
    output<<outStud.year<<outStud.ball<<outStud.pol<<outStud.CurNum;
    return output;

}

