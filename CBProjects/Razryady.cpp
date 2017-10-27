#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 
 int  main()
 {
 	cout<<"Enter a value";
 	/*string value;
 	cin>>value;
 	unsigned int SIZE=value.size();
 	for (unsigned int i=0; i<SIZE;  i++ )
 	cout<<i+1<<"	namber is	"<<value[i]<<endl;*/
	unsigned int value,i=0,c,step;
 	cin>>value;	
 
 	do 
 	{	
 	c=value % 10 ;
 	value=(value-c)/10;
 	cout<<c;
 	i++;
 	}
 	while(value);
 }
