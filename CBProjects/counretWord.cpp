#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cstring>

using std::string;

void counter(string &str,string& word);

int main()
{

    string s={"hello my name is Ilya am a student and i prog on c++.so hello goodbye dear hello."};
    string myWord;
    std::cin>>myWord;
    counter(s,myWord);


}
void counter(string &str,string& word)
{
    int wordsFound=0;

    for(string::iterator it=str.begin();it!=str.end();it++)
        if (*it == word[0])
        {
            int i=0;
            while (*it == word[i])
            {

                    i++;
                    it++;


            }

             if (i == word.size())
                wordsFound++;


        }

        if(wordsFound==0)
                std::cout<<"No word is line";
        else std::cout<<wordsFound;
        int y_pos=1;
        std::cout<<(y_pos<<6);

        std::cout<<std::endl;




}
