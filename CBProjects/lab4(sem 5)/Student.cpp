#include <iostream>
#include "Student.h"
#include <fstream>
#include <vector>
#include <cstdio>
using std::cout;
using std::cin;
using std::endl;
std::ostream &operator<<(std::ostream& output, const Student& outStud)
{
    output<<outStud.Name<<outStud.year<<outStud.ball<<outStud.pol<<outStud.CurNum;
    return output;

}
std::istream& operator>>(std::istream& input,Student& inStud)
{
    input>>inStud.Name>>inStud.year>>inStud.ball>>inStud.pol>>inStud.CurNum;
    return input;
}

void workFile(const char* Name)
{

    if (Name[1]==':' || Name[2]=='\\')
        if (Name[1]==':' && Name[2]=='\\' && isalpha(Name[0]))
            for (int i=3;i<strlen(Name)-4;i++)
                {
                    if(!isalpha(Name[i]))
                        throw "Check your path!";
                    else
                        i++;

                }
        else
            throw "Check your :\\";
    else
        for (int i=0;i<strlen(Name)-4;i++)
                {
                    if(!isalpha(Name[i]))
                        throw "Check your path!";
                    else
                        i++;
                }
    char txt[]=".txt";
    char TXT[]=".TXT";
    for (int i=strlen(Name)-4,j=0;i<strlen(Name),j<strlen(txt);i++,j++)
        if (Name[i]!=txt[j] && Name[i]!=TXT[j])
            throw "Check .txt";



    std::ifstream fOut(Name);
    if (!fOut)
        throw 10;

    fOut.seekg(0,fOut.end); // перемещает указатель в конец файла
    int length = fOut.tellg(); //текущее положение относительно начала файла
    fOut.seekg(0,fOut.beg); // перемещает указатель обратно в начало файла


    char *buf=new char[length];
    fOut.read(buf,length);
    fOut.close();
    cout<<buf;
    cout<<"\nEnter text which want to find:";
    char myText[255];
    cin>>myText;
    findText(myText,strlen(myText),buf,strlen(buf));
    char **pp=delText(buf,strlen(buf));

    bubbleSort (pp,12);
    /*std::vector<char*> strok;
    while (!fOut.eof())
        {
            fOut>>buf;

            strok.push_back(buf);
            std::vector<char*>::iterator it=strok.end();
            std::cout<<*(it-1);
        }
    for(std::vector<char*>::iterator it=strok.begin();it!=strok.end(); ++it)
        std::cout<<" "<<*it;*/

}
void findText(char *text, int SIZEt,char *buffer,int SIZEb)
{

    char *strok=new char[SIZEt];
    for (int pos=0;pos<SIZEb;pos++)
        if(text[0]==buffer[pos])
            for(int i=pos,j=0;j<SIZEt;i++,j++)
                if(text[j]!=buffer[i])
                {
                    pos=i;
                    break;}
                else
                    strok[j]=buffer[i];


    cout<<strok<<std::endl;;
    delete [] strok;
}



char **delText(char *buffer,int SIZEb)
{
    int i=0;
    char **pp=new char*[18];
    char * pch = strtok (buffer," ."); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)

  while (pch != NULL)                         // пока есть лексемы
  {
      pp[i]=pch;
      pch = strtok (NULL, " .");
      i++;

  }
return pp;

}


void bubbleSort ( char **pp,unsigned int SIZE )
{

	int i,j;

	for ( i=SIZE-1; pp[i]; i--)
		for( j=0; j<i; j++)
		if (strlen(pp[j])>strlen(pp[j+1]))
		{

			char *temp;
			temp=pp[j];
              pp[j]=pp[j+1];
			pp[j+1]=temp;
		}

    std::ofstream inFile("InFile.txt");
    for (int i = 0 ;pp[i]; i++)
        inFile<<pp[i]<<" ";
    inFile.close();

}


