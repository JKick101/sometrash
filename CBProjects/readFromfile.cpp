#include <iostream>

#include <vector>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	vector<string> words;
	ifstream in("Get.txt");
	string word,MyWord;
	int count;
	cout<<"Enter a word";
	cin>>MyWord;
	while(in >> word)
	if (word==MyWord)
	count++;
	cout<<count;
	cin.get();
	
}
