#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("Get.txt");
	string vivod,word;
	while(in>>word)
	vivod=vivod+word;
	cout<<vivod;
	
	
}
