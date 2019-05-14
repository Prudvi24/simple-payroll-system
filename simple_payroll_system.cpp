#include<fstream>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
string name;
string	user="",pass="password";
int nolines();
void view(int n);
void registration(int roll);
void record();
void bonus();
void logout();
void login();
int auth=0;
int main()
{
	cout<<"||---------------------------------------------------------------------------------------------||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                   Simple Payroll System                                     ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
    cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||                                                                                             ||\n\t\t\t";
	cout<<"||---------------------------------------------------------------------------------------------||\n\t\t\t";
	cout<<"\n\n\n\n\n\n";
	menu:
	cout<<"Press Enter to continue...";
	getchar();
	cout<<"\033[2J";
	int a,b,c;
	cout<<"\n\t\t\t\t-------------------------------MAIN MENU-----------------------------------\n\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
	cout<<"|                     1. Register an employee                             |\n\t\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
    cout<<"|                     2. View employee's  payment	                  |\n\t\t\t\t";
   	cout<<"|                                                                         |\n\t\t\t\t";
   	cout<<"|                        			                          |\n\t\t\t\t";
   	cout<<"|                     3. Employee record                                  |\n\t\t\t\t";
   	cout<<"|                                                                         |\n\t\t\t\t";
   	cout<<"|                                                                         |\n\t\t\t\t";
   	cout<<"|                     4. Bonus calculator                                 |\n\t\t\t\t";
   	cout<<"|                                                                         |\n\t\t\t\t";
	if(auth==0)
	cout<<"|                     5. Login                                            |\n\t\t\t\t";
	else
	cout<<"|                     5. Logout                                           |\n\t\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
	cout<<"|                     6. Exit                                             |\n\t\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
	cout<<"|                                                                         |\n\t\t\t\t";
	cout<<"|            Note: Exiting program casues logout automatically            |\n\t\t\t\t";			
    cout<<"|                                                                         |\n\t\t\t\t";
   	cout<<"|                                                                         |\n\t\t\t\t";
   	cout<<"---------------------------------------------------------------------------\n\n\n\t\t";
	cout<<"\n\n\n\n\n\n";
	redo:
	cout<<"Enter your option:";
	cin>>a;
	char x;
	switch(a)
{
	      	case 1:     	if(auth==0)
				{
					cout<<"Please Login to continue..";
					getchar();
					goto menu;
				}
				else
				{
				cout<<"\033[2J";
				cout<<"\n\t\t\t\t----------------------------Registering employee--------------------------------\n";
			        c=nolines();
				registration(c);
				cout<<"\033[2J";
				goto menu;
			    	break;
				}
        	case 2:     	cout<<"\033[2J";
			    	cout<<"\n\t\t\t\t----------------------------Search Employee Payment---------------------------------\n";
				cout<<"Enter id no:";
			        cin>>c;
			    	view(c);
		            	getchar();
		            	goto menu;
			        break;
		case 3:     	cout<<"\033[2J";
			    	cout<<"\n\t\t\t\t----------------------------Employee Record--------------------------------\n";
				record();
				getchar();
				goto menu;
				break;
                case 4:         cout<<"\033[2J";
			    	cout<<"\n\t\t\t\t----------------------------Bonus calculator--------------------------------\n";
				bonus();
				getchar();
				goto menu;
				break;
		case 5:		cout<<"\033[2J";
				cout<<"\n\t\t\t\t----------------------------Login Portal--------------------------------\n";
				if(auth==0)
				login();
				else
				logout();
				getchar();
				goto menu;
   		case 6:         cout<<"\033[2J";
				exit(0);
				break;
}
	return 0;
}
void registration(int id)
{
	string name;
	int hours,grosspay,bonus=0;
	fstream a;
	a.open("employee.txt",ios::out | ios::app);
	a<<id<<"\t";
	cout<<"Enter name:";
	cin>>name;
	a<<name<<"\t\t\t\t";
	cout<<"Enter no of hours worked:";
	cin>>hours;
	a<<hours<<"\t\t";
        grosspay=hours*50;//pay rate for each hour is 50 rupees
	if(hours>8)
	bonus=(hours-8)*30;
        a<<bonus<<"\t\t"<<grosspay+bonus<<"\n";
	a.close();
}
void view(int n)
{
	int i;
	string line;
	fstream a;
	a.open("employee.txt",ios::in);
	for(i=0;i<n;i++)
	{
		getline(a,line);
	}
	if(!getline(a,line))
	cout<<"Employee not registered.";
	else
	cout<<"id no:\tEmployee name\t\t\t\thours worked\t\t\tbonus\t\t\tgrosspay\n";
	cout<<line<<endl;
	a.close();
} 
void record()
{
	string line;
	fstream a;
	a.open("employee.txt",ios::in);
	while(getline(a,line))
	cout<<line<<endl;
	a.close();
}
void bonus()
{
	int i,bonus,hours;
	string line;
	fstream a;
	a.open("employee.txt",ios::in);
	cout<<"Enter the number of hours worked : ";
	cin>>hours;
	if(hours>8)
	{
	bonus=(hours-8)*30;
	}
	else
	bonus=0;
	cout<<"The bonus earned by the employee is : Rs."<<bonus<<endl;
	a.close();
}      
void login()
{
	string uentered,pentered;
	cout<<"Enter username:";
	cin>>uentered;
	cout<<"Enter password:";
	cin>>pentered;
	if(uentered==user&&pentered==pass)
	{
	auth=1;	
	cout<<"Logged in successfully...";
	}
	else
	cout<<"Something went wrong.....";
}

void logout()
{
	auth=0;
	cout<<"Logged out successfully...";
}
int nolines()
{
	int nlines;
	string line;
	fstream a;
	a.open("employee.txt",ios::in);
	while(getline(a,line))
	nlines++;
	return nlines;
}

