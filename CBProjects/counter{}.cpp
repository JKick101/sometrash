#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
 int main()
 {

 	ifstream fileOut;
 	fileOut.open("Get.txt");
 	char simbol;
 	int counter=0;
 	while(fileOut>>simbol)
 	{
 	if (simbol=='{')
 	counter++;
 	if (simbol=='}')
 	counter--;
 	}
 	if (!counter)
 	cout<<"OK";
 	else
 	cout<<"Ne ok";
 	fileOut.close();
 }
