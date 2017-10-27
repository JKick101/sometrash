#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using std::vector;
using std::cout;
using std::cin;
using std::string;

int main()
{

    cout<<"Enter a word:";
    string myWord;
    cin>>myWord;

    std::ifstream fromFile("Get.txt");


    string line;
    string word;
    int num=0;
    while(getline(fromFile,line))
    {
        num++;
        std::istringstream record(line);

        while(record>>word)
        {

            if(isalpha(word[word.size()-1]))
                 if(word == myWord)
                 {
                    cout<<"find in line number:"<<num<<std::endl<<line<<std::endl;
                    break;
                 }
                 else
                    cout<<"";
            else
                if( (word.size()-1) == myWord.size())
                    {
                        int counter = 0;
                        for(int i=0;i<myWord.size();i++)
                            if(word[i] == myWord[i])
                                counter++;
                        if(counter == myWord.size())
                            {
                                cout<<"Find in line number:"<<num<<std::endl<<line<<std::endl;
                                break;
                            }
                    }

        }
    }





}
