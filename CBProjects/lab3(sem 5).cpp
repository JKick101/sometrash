#include <iostream>
#include <stdexcept>
using namespace std;

//double convert(double, char, char); //объявление простой функции
//enum Error{Fine=0, From=1,To=2, Minus=3};
//int convert(double,char,char,double&); //функция для обработки ошибок по коду возврата
void convert(double,char,char,double&);  //обработка ошибок через исключения
int main()
{
	double temp;
	char A,B;
	cin>>temp>>A>>B;
	double result;
	try{
			convert(temp,A,B,result);
		}catch (invalid_argument err)
				{	cout<<err.what();
				
					
		
				}	

	cout<<result;
	
//Обработка ошибок по кодам возврата
	/*switch(convert(temp,A,B,result)) 
		{
				case From:cerr<<"\nCheck your 'from' parameter\n";
						break;
				case To:cerr<<"\nCheck your 'to' parameter\n";
						break;
				case Fine:cout<<result;
						break;
				case Minus:cerr<<"\Kelvin < 0!";
						break;
				default:cerr<<"Don't know what the fuck is happening...";
					
		}*/
		
		
		
		
}

/*int convert(double temperature, char from, char to,double& result)
{
	switch(from)
	{
	
		case 'K':
			{
				
				if (to=='F')
					{
						result=(temperature-273)*1.8+32;
						return 0;
					}
				else if (to=='C')
						{
							result=(temperature-273);
							return 0;
						}
					else if(to=='K')
						{
							result=temperature;
							return 0;
						}
						else
							return 2;
								
							
			};
			break;
		case 'F':
			{
				if (to=='K')
					{
						result=(temperature-32)/1.8+273;
						return 0;
					}
				else if (to=='C')
					{
						result=(temperature-32)/1.8;
						return 0;
					}
					else if(to=='F')
							{
								result=temperature;
								return 2;
							}
						else
							return 2;
			};
			break;
		case 'C':
			{
				if (to=='F')
					{
						result=temperature*1.8+32;
						return 0;
					}
				else if (to=='K')
					{
						result=temperature+273;
						return 0;
					}
					else if(to=='C')
						{
							result=temperature;
							return 0;
						}
						else
							return 2;	
			}
			break;
		default:
			return 1;
	}
}*/

/*double convert(double temperature, char from, char to)
{
	switch(from)
	{
	
		case 'K':
			{
				if (to=='F')
					return (temperature-273)*1.8+32;
				else if (to=='C')
						return (temperature-273);
					else if(to=='K')
							return temperature;
						else
							cout<<"Check your 'to' parameter";
							
			};
			break;
		case 'F':
			{
				if (to=='K')
					return (temperature-32)/1.8+273;
				else if (to=='C')
						return (temperature-32)/1.8;
					else if(to=='F')
							return temperature;	
						else
							cout<<"Check your 'to' parameter";
			};
			break;
		case 'C':
			{
				if (to=='F')
					return temperature*1.8+32;
				else if (to=='K')
						return temperature+273;
					else if(to=='C')
							return temperature;
						else
							cout<<"Check your 'to' parameter";	
			}
			break;
		default:
			cout<<"Check your 'from' parameter";
	}
	
	
}*/




void convert(double temperature, char from, char to,double& result)
{
	switch(from)
	{
	
		case 'K':
			{
				if (to=='F')
					result=(temperature-273)*1.8+32;
				else if (to=='C')
					result=(temperature-273);
					else if(to=='K')
							result=temperature;
						else
							throw invalid_argument("Check your to");
							
			};
			break;
		case 'F':
			{
				if (to=='K')
						result=(temperature-32)/1.8+273;
				else if (to=='C')
						result=(temperature-32)/1.8;
					else if(to=='F')
							result=temperature;	
						else
							throw invalid_argument("Check your to");
			};
			break;
		case 'C':
			{
				if (to=='F')
					result=temperature*1.8+32;
				else if (to=='K')
						result=temperature+273;
					else if(to=='C')
							result=temperature;
						else
							throw invalid_argument("Check your to");
			}
			break;
		default:
			throw invalid_argument("Check your from");
	}
	
	
}
