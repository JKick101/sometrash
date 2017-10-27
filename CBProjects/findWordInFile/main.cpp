#include <iostream>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;
void runQueries(ifstream&);
int main()
{

}

void runQueries(ifstream &infine)
{
    TextQuery tq(infile);
    while (true)
    {
        cout<<"enter word to look for,or q to quit";
        string s;
        if(!(cin >> s) || s=="q") break;
        print(cout,tq.query(s))<<endl;
    }
}
