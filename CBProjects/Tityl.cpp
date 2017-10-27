#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
 
int main()
{

cout<<"Write name:";
string name;
cin>>name;
cout<<endl<<"Write second name:";
string Sname;
cin>>Sname;
cout<<endl<<"Group:";
string Group;
cin>>Group;
cout<<endl<<endl<<endl<<"\t\t";
	if ((name.size()+Sname.size()+2)>(Group.size()+19))
		
			for (int i=0;i<(name.size()+Sname.size()+2);i++)
			cout<<"*";
		
			
		
				
	else
	
			for (int i=0;i<(Group.size()+19);i++)
			cout<<"*";
			cout<<endl<<"\t\t*Laboratory work N1";
			if ((name.size()+Sname.size()+2)>(Group.size()+19))
			for (int i=0;i<(name.size()+Sname.size()-16);i++)
			cout<<" ";
			else
			for (int i=0;i<Group.size()-1;i++)
			cout<<" ";
			cout<<"*"<<endl;
			cout<<"\t\t*Complited:st.gr. "<<Group;
			
			if ((name.size()+Sname.size()+2)>(Group.size()+19))
			{
			
			for (int i=0;i<(name.size()+Sname.size()-17-Group.size());i++)
			cout<<" ";
			cout<<"*"<<endl;
		}
			else
			cout<<"*"<<endl;
			cout<<"\t\t*"<<name<<" "<<Sname;
			if ((name.size()+Sname.size()+2)>(Group.size()+19))
			cout<<"*"<<endl;
			else
			{
			for (int i=0;i<(Group.size()+16-name.size()-Sname.size());i++)
			cout<<" ";
				cout<<"*"<<endl<<"\t\t";
						
		}
		if ((name.size()+Sname.size()+2)>(Group.size()+19))
		
			for (int i=0;i<(name.size()+Sname.size()+2);i++)
			cout<<"*";
		
			
		
				
	else
	
			for (int i=0;i<(Group.size()+19);i++)
			cout<<"*";
cin.get();
cin.get();
cin.get();
cin.get();
		
}
