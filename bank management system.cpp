#include<iostream>
#include<string>
#include<windows.h>
#include<conio.h>
using namespace std;
class Bank
{
	private:
	// Variables For sign up in bank 
	
	string username;
	string password;
 
	struct customer
	{
	string CNIC; 
	string name;
	int  ID;
	string Email;
	string contract_num;
	double cash;	
	}person[50];	

	int total;//store the  accounts are created
	  // store the maximum accounts;
 
	public:
		Bank()
		{
			total=0;
			 
			
		}
		
	void Sign_UP();
	void Sign_IN();
	void choices();
	void Data();
	void Data_show();
	void Update_Data();
	void Transaction();
	void del_Account();
	
	
		 
		
	
};
void Bank::Sign_UP()
{
	cout<<" WELCOME  TO HBL BANK MANAGEMENT SYSTEM \n";
	cout<<"  Sign UP "<<endl;
	cout<<" Enter the Username "<<endl;
	getline(cin,username);
	cout<<" Enter the Password "<<endl;
	getline(cin,password);
	cout<<" Your New ID is created please Wait ";
	for(int i=0;i<3;i++)
	{
		cout<<" . ";
		Sleep(1000);
	}
}
//sign in function defination
void Bank::Sign_IN()
{
	system("CLS");
	cout<<"  Log IN "<<endl;
	string username1,password1;
	signin: cout<<" Username "<<endl;
	getline(cin,username1);
	cout<<" password "<<endl;
	getline(cin,password1);
	if((username1==username)&&(password1==password))
	{
		for(int i=0;i<3;i++)
		{
			cout<<" Wait"<<endl;
		    cout<<" . ";
			Sleep(1000);
		}
		system("CLS");
		Bank::choices();
		
	}
	else if((username1!=username)||(password1!=password))
	{
		cout<<" inavalid Username! Try again !"<<endl;
	     goto signin;
	}

	
}
// choice function
void Bank::choices()
{
	char ch;
	cout<<"      Main   Menu        "<<endl;
	cout<<"1. Creating  new account  "<<endl;
	cout<<"2. View the customer details "<<endl;
	cout<<"3. Update the information of customer Details "<<endl;
	cout<<"4. For Transaction                            "<<endl;
	cout<<"5. Delete the account                         "<<endl;
	cout<<"6. Exit the program                          "<<endl;
	cout<<" Press!!!! "<<endl;
	cin>>ch;
	system("CLS");
	switch(ch)
{
	case '1':
		
       Bank::Data();
       system("CLS");
       Bank::choices();
       break;
       
    case'2':
    	
    	Bank::Data_show();
    	cout<<" . ";
    	Sleep(6000);
    	system("CLS");
    	Bank::choices();
    
    	break;
    	
    case'3':
    	
    	Bank::Update_Data();
    	cout<<" . ";
    	Sleep(4000);
    	system("CLS");
    	Bank::choices();
    	break;
		
    case'4':
    	
    	Bank::Transaction();
    	system("CLS");
    	Bank::choices();
    	break;
    	
    case'5':
    	
    	Bank::del_Account();
    	system("CLS");
    	Bank::choices();
    	break;
    	
    case'6':
    	
    	exit(0);
    	break;
    	
    default:
    	cout<<" Invalid input "<<endl;
    	break;
    	
}
	
}
// Data function 
void Bank::Data()
{
	 	
	cout<<" Enter The Data of custumer   1       "<<endl;
	cout<<" Enter The CNIC(without dashes)       "<<endl;
	cin.ignore(1, '\n');
	getline(cin,person[total].CNIC);
	cout<<" Enter the ID (only 4   digit form)   "<<endl;
	  cin>>person[total].ID;
	while(person[total].ID<0||person[total].ID>32767)
	{
		cout<<" ID can be 4 digit between 0 to 32767"<<endl;
		cin>>person[total].ID;
	}
	cout<<" Enter The Name                        "<<endl;
	cin.ignore(1,'\n');
	getline(cin,person[total].name);
	cout<<" Enter THe Contract Number             "<<endl;
	cin.ignore(1,'\n');
	getline(cin,person[total].contract_num);
	cout<<" Enter the Email                       "<<endl;
	cin.ignore(1,'\n');
	getline(cin,person[total].Email);
	cout<<" Enter the cash(in positive digit form) "<<endl;
	cin>>person[total].cash;
	while(person[total].cash<0)
	{
		cout<<" enter the positive amount! please renter the cash "<<endl;
		cin>>person[total].cash;
	}
cout<<" Customer Data Details Successfullly Saved "<<endl;
total++;
cout<<" . ";
Sleep(300);
}

void Bank::Data_show()
{
	int id;
	cout<<" Enter the ID for showing details (only 4   digit form)   "<<endl;
	cin>>id;
	while(id<0||id>32767)
	{
		cout<<" ID can be 4 digit between 0 to 32767"<<endl;
		cin>>id;
	}
	for(int i=0;i<total;i++)
 {
	if(id==person[i].ID)
	{
		cout<<"--->Data of Customer--->"<<i+1<<endl;
		cout<<"  CNIC   --->      "<<person[i].CNIC<<endl;
		cout<<"  ID     --->      "<<person[i].ID<<endl;
		cout<<"  Name   --->      "<<person[i].name<<endl;
		cout<<"  Contract NUmber->"<<person[i].contract_num<<endl;
		cout<<"  Email  --->      "<<person[i].Email<<endl;
		cout<<"  Cash   --->      "<<person[i].cash<<endl;
	}
	
 } 
	
}
void Bank::Update_Data()
{
	int id;
	cout<<" Enter the ID for update Data (only 4   digit form)   "<<endl;
	cin>>id;
	while(id<0||id>32767)
	{
		cout<<" ID can be 4 digit between 0 to 32767"<<endl;
		cin>>id;
	}
	for(int i=0;i<total;i++)
 {
	if(id==person[i].ID)
	{
		cout<<" Previous Data of customer "<<i+1<<endl;
		cout<<"  CNIC              "<<person[i].CNIC<<endl;
		cout<<"  ID               "<<person[i].ID<<endl;
		cout<<"  Name             "<<person[i].name<<endl;
		cout<<"  Contract NUmber  "<<person[i].contract_num<<endl;
		cout<<"  Email            "<<person[i].Email<<endl;
		cout<<"  Cash             "<<person[i].cash<<endl<<endl;
	
	cout<<" Enter New Data "<<endl<<endl;
	cout<<" Enter The CNIC(without dashes)       "<<endl;
	cin.ignore(1,'\n');
	getline(cin,person[i].CNIC);
	cout<<" Enter the ID (only 4   digit form)   "<<endl;
	cin>>person[i].ID;
	while(person[i].ID<0||person[i].ID>32767)
	{
		cout<<" ID can be 4 digit between 0 to 32767"<<endl;
		cin>>person[i].ID;
	}
	cout<<" Enter The Name                        "<<endl;
	cin.ignore(1,'\n');
	getline(cin,person[i].name);
	cout<<" Enter THe Contract Number             "<<endl;
	cin.ignore(1,'\n');
	getline(cin,person[i].contract_num);
	cout<<" Enter the Email                       "<<endl;
	cin.ignore(1,'\n');
	getline(cin,person[i].Email);
	cout<<" Enter the cash(in positive digit form) "<<endl;
	cin>>person[i].cash;
	while(person[i].cash<0)
	{
		cout<<" enter the positive amount! please renter the cash "<<endl;
		cin>>person[i].cash;
	}
	 
cout<<" Your  required  Data  is  updated               "<<endl;
cout<<" you can check using ID by function 2 (show data)"<<endl;
	cout<<" . ";
	Sleep(3000);
    }
  }
}
void Bank::Transaction()
{
	int id;
	double Cash;
	char choice;
	cout<<" Enter the ID for transaction cash (only 4   digit form)   "<<endl;
	cin>>id;
	while(id<0||id>32767)
	{
		cout<<" ID can be 4 digit between 0 to 32767"<<endl;
		cin>>id;
	}
	for(int i=0;i<total;i++)
 {
	if(id==person[i].ID)
	{
		cout<<" ---> Data of customer---> "<<i+1<<endl;
		cout<<"  CNIC     ---->   "<<person[i].CNIC<<endl;
		cout<<"  ID       ---->   "<<person[i].ID<<endl;
		cout<<"  Name     ---->   "<<person[i].name<<endl;
		cout<<"  Contract NUmber-->"<<person[i].contract_num<<endl;
		cout<<"  Email    ---->   "<<person[i].Email<<endl;
		cout<<"  Cash     ---->   "<<person[i].cash<<endl<<endl;
    }
    cout<<" 1. For withdraw  "<<endl;
    cout<<" 2. For Deposit   "<<endl;
    above : cout<<" Enter the choice for transaction "<<endl;
    cin>>choice;
    switch(choice)
    {
case'1':
    		 withdraw:  cout<<" How Many Amount you want to withdraw "<<endl;
    		   cin>>Cash;
    		   
   if(Cash<=person[i].cash)
    {
    		   	person[i].cash-=Cash;
    		   	cout<<" you Withdraw the amount from account is---> "<<Cash<<endl;
    		   	cout<<" Your New amount in your account--->"<<person[i].cash<<endl;
    		   	cout<<" . ";
    	        Sleep(3000);
    }
		else
		
		{
		cout<<" In your Account,present Amount is--->"<<person[i].cash<<endl;	
		cout<<" Please withdraw the amount less than or equal to present amount "<<endl;
		goto withdraw;
		cout<<" . ";
		Sleep(5000);
	    } 
	    cout<<" . ";
	    Sleep(5000);
	            break;
	    
case'2':
	     cout<<" Your present Amount is--->"<<person[i].cash<<endl;
         cout<<" How many Amount you want to Deposit "<<endl;
		 cin>>Cash;
		 person[i].cash+=Cash;
		 cout<<" After Deposit New Cash "<<endl;
		 cout<<"Your New Amount in your account is--->"<<person[i].cash<<endl;
		 cout<<" . ";
		 Sleep(3000);
		 break;
		 
		default:
		cout<<" Invalid Input! Enter 1 or 2 "<<endl;
		cout<<" . ";
		Sleep(3000);
		goto above;
		break;		   
	}
 }
}
void Bank::del_Account()
{
	char choice;
	int id;
	if(total!=0)
	{
	 cout<<" Press 1. For removing the Record "<<endl;
	 cin>>choice;
	 if(choice=='1')
	 {
	cout<<" Enter the ID for removing  Data (only 4   digit form)   "<<endl;
	cin>>id;
	while(id<0||id>32767)
	{
		cout<<" ID can be 4 digit between 0 to 32767"<<endl;
		cin>>id;
	}
	for(int i=0;i<total;i++)
	{
		if(id==person[i].ID)
		{
			for(int j=i;j<total;j++)
			{
				person[j].name=person[j+1].name;
				person[j].ID  =person[j].ID;
				person[j].CNIC=person[j+1].CNIC;
				person[j].cash=person[j+1].cash;
				person[j].contract_num=person[j+1].contract_num;
				person[j].Email=person[j+1].Email;
				total--;
				cout<<" Your Required ID Data id Deleted "<<endl;
				Sleep(5000);
				
			}
		}
     }
   }
 }
}
int main()
{
	Bank obj;
	obj.Sign_UP();
	obj.Sign_IN();
	 
}
