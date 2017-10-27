#include <iostream>
#include <stack>
using namespace std;

int main()
{

string s;

stack <string> st;

while (cin>>s);

st.push(s);

while (!(st.empty()))

{cout<<st.top();st.pop();}

}
