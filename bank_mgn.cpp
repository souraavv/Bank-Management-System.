#include<bits/stdc++.h>
using namespace std;

bool isdigit(char a){
	if(a=='0'||a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')
	   return true;
	   else return false;
}

class account
{  
    char name[50];
    double deposit;
	long long int acno;
	char type;
public:
	void create_account();
	void show_account() const;	
	void modify();	
	void dep(double);	
	void draw(double);	
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;	
};         


void account::show_account() const
{
	cout<<"\n\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;

}

void account::dep(double x)
{
	deposit+=x;
}
	
void account::draw(double x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<"  "<<type<<setw(6)<<" "<<deposit<<endl;

}
	
int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}

void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	char dec;
	cout<<"\nDo you want to modify the name: (y/n) ";
	cin>>dec;
	if(dec=='y')
	{
	cout<<"\nModify Account Holder Name : ";
	  int t=0;
	  char name[50];
   while(t==0){
	cin.ignore();
	cin.getline(name,50);
	int i=0;
	
	
	if(name[0]=='\0'){
			 cout<<"You are trying to modify the name..but still you left it blank.. PLEASE DO AGAIN\n"<<endl;
	          t=0;
	          
		}
    while(name[i]!='\0'){
    	char a=name[i];
    	if(isdigit(a))
    	{
    		
    			cout<<"A name cannot have a numeric with in it:  please type again: \n";
    	      // cout<<"\n\nPlease enter a valid name again ";
    	       break;
			   t=0;
		}
		else{
			++i;
		}
	}
	
	if(name[i]=='\0'&&name[0]!='\0'){
		t=1;
		
	}
	else{
		t=0;
	}

}
    }
    cout<<"\nDo you want to modify account type: It will charge you: Rs 100 (y/n) ";
    cin>>dec;
    if(dec=='y'){
	
	cout<<"\nModify Type of Account : ";
	cin>>type;

	if(type=='c'){
		if(deposit<=1000){
			cout<<"As you are moving to Current account..you must have at least Rs 1100 in your account";
			cout<<"\n\n you have to deposit atleast Rs"<<1100-deposit<<" in your account";
			int p=0;
			while(p==0){
			
			int k;
			cout<<"\nPlease deposit the given upper amount: ";
			cin>>k;
			if(k<1100-deposit){
				cout<<"\n\nNo you have entered wrong amount..Please do it correctly again\n\n";
		       p=0;		
			}
			else{
				deposit+=k;
				p=1;
			}
		}
		}
		
	}
	cout<<"\n Your account is changed to "<<type<<"::: \nINR. 100.00 has been deducted from your account";
	deposit-=100;

	
	//type=toupper(type);
    }
}

	


void write_account();	
void display_sp(int);	
void modify_account(int);
void delete_account(int);	
void display_all();		
void deposit_withdraw(int, int);

int main()
{   
	int ch;
	int num;
	cout<<"\n\n\n\n";
	do
	{     cout<<"\n\n\n";
	   
		system("cls");
		cout<<"\n\n\n";
		cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  WELCOME TO BANK OF INDIA   <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
		cout<<"\n\n\t\t\t\t\t\t1. WANT TO CREATE A NEW ACCOUNT";
		cout<<"\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t\t\t\t\t\t2. WANT TO DEPOSIT AMOUNT IN YOUR ACCOUNT";
		cout<<"\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t\t\t\t\t\t3. WANT TO WITHDRAW MONEY";
		cout<<"\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t\t\t\t\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t\t\t\t\t\t5. [ONLY FOR BANK EMPLOYEE] ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t\t\t\t\t\t6. WANT TO CLOSE AN ACCOUNT PERMANENTLY";
		cout<<"\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t\t\t\t\t\t7. WANT SOME MODIFICATION IN ACCOUNT";
		cout<<"\n\t\t\t\t\t\t-----------------------------------------------------------------------------------------------------";
		cout<<"\n\n\t\t\t\t\t\t8. EXIT";
		cout<<"\n\t\t\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
		
		
		cout<<"\n\n\t\t\t\t\t\tPlease...Select a Option from(1-8) ";
	
		
		cin>>ch;
		
		system("cls");
		switch(ch)
		{
		case 1:
			write_account();
			break;
		case 2:
			cout<<"\n\n\tPlease Enter your account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case 3:
			cout<<"\n\n\tPlease Enter your account No. :: "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case 4: 
			cout<<"\n\n\tPlease Enter your account No. : "; cin>>num;
			display_sp(num);
			break;
		case 5:
			display_all();
			break;
		case 6:
			cout<<"\n\n\tPlease Enter your account No. : "; cin>>num;
			delete_account(num);
			break;
		 case 7:
			cout<<"\n\n\tPlease Enter your account No. :"; cin>>num;
			modify_account(num);
			break;
		 case 8:
			cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\tThanks for using our service...\n";
			cout<<"\n\t\t\t\t\t\tHOPE WE SEE YOU SOON....\n";
			break;
		 default :cout<<"INVALID CHOICE ENTER AGAIN(1-8) ";
		       cout<<"\nPress any key to return to HOME page"<<endl;
		       
		}
		cin.ignore();
		cin.get();
	}
	
	while(ch!=8);
	return 0;
}
void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void account::create_account()
{  
    bool flag=false;
    while(flag==false){
    	int c=0;
    cout<<"\nENTER THE ACCOUNT NUMBER GENERATED BY THE SYSTEM: :";
	cin>>acno;
    account temp;
    flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);

    	while(inFile.read(reinterpret_cast<char *> (&temp), sizeof(account)))
	{
		if(temp.retacno()==acno)
		{
		
			flag=false;
			c=1;
			cout<<"\nsame account exist:  DUE TO SOME PROBLEM SYSTEM MIGHT HAVE GENERATE A WRONG NUMBER ..please generate another number:: "<<endl;
		}
		else{
			flag=true;
		}
	
	}
	if(c==1)flag=false;
	else flag=true;
	inFile.close();
	
		
		
   }
		
   int t=0;
   while(t==0){
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	int i=0;
	
	
	if(name[0]=='\0'){
			 cout<<"please enter  the name first ...you can't skip this!"<<endl;
	          t=0;
	          
		}
    while(name[i]!='\0'){
    	char a=name[i];
    	if(isdigit(a))
    	{
    		
    			cout<<"A name cannot have a numeric with in it:  please type again: \n";
    	       cout<<"\n\nPlease enter a valid name again ";
    	       break;
			   t=0;
		}
		else{
			++i;
		}
	}
	
	if(name[i]=='\0'&&name[0]!='\0'){
		t=1;
		
	}
	else{
		t=0;
	}

}
    t=0;
	while(!t){

	cout<<"\nEnter Type of The account (c/s) : ";
	cin>>type;
	if(type=='c'||type=='s'){
		t=1;
		
	}
	else{
		cout<<"OOPS! You have Enter invalid character...please enter again\n";
		t=0;
	}
	
	
   }
	t=0;
	while(!t){
    
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	  if(type=='c'){
	  	if(deposit<1000)t=0,cout<<"\n PLEASE PROVIDE VALID AMOUNT AGAIN !.....YOU HAVE CREATED A CURRENT ACCOUNT SO ADD ATLEAST Rs.1000"<<endl;
	  	else t=1;
	  }
	  else{
	  	if(deposit<500)t=0,cout<<"\n PLEASE PROVIDE VALID AMOUNT AGAIN !......YOU HAVE CREATED A SAVING ACCOUNT SO ADD ATLEAST Rs.500"<<endl;
	  	else t=1;
	  }
	
    }
   
    cout<<"-------------------------------------------------------------------"<<endl;
	cout<<"\nCongratualation !"<<name<<" your  Account have been Created  ....."<<endl;
	 cout<<"Please collect your ACCOUNT NUMBER ----"<<acno<<"\n"<<endl;
	 
	 cout<<"\n\n PRESS ENTER IF YOU WANT TO GO ON HOME PAGE\n";
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
		
		
    cout<<"\n\n PRESS ENTER IF YOU WANT TO GO ON HOME PAGE\n";		
}

void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
		
		
		
    cout<<"\n\n PRESS ENTER IF YOU WANT TO GO ON HOME PAGE\n";
}

void delete_account(int n)
{    cout<<"\nWe BANK OF INDIA thanking you for being with us so long\n";
     cout<<"\nHope you like our services: \n";
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);

	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	
	
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
	
		cout<<"\n\n PLEASE COLLECT YOUR MONEY ON THE COUNTER: ";
	
	
	
	
	
	 cout<<"\n\n PRESS ENTER IF YOU WANT TO GO ON HOME PAGE\n";
}

void display_all()
{   cout<<"\n\n\n\t\t\tONLY FOR BANK EMPLOYEE \n\n";
    string s;
    	int g=4;
    while(g>0){
	
	cout<<"\t\t\t\tEnter the password: ";
	cin>>s;
	string k="sourav";

	if(s==k){
	
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"============================================================\n";
	cout<<"A/c no.          |NAME    	  |Type | Balance   |\n";
	cout<<"============================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
		cout<<"\t\t ";
	}
	
    g=-4;
	inFile.close();
	
	
	 cout<<"\n\n PRESS ENTER IF YOU WANT TO GO ON HOME PAGE\n";
	 
}

else if(g==0){
	cout<<"\n\nNO TRY REMAIN...system is going to auto-locked \n";
	return;
}
else{
	cout<<"_______________WRONG PASSWORD_______________:: \n";
	--g;
	cout<<"\t\t PLEASE TRY AGAIN\n";
	cout<<"\n You have " <<g<<"chances more\n";

	
}
}
}
void deposit_withdraw(int n, int option)
{
	double amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				
				int j=0;
				while(j==0)
				{
					
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				if(amt<0){
					cout<<"\tSeriously Do you think you can deposit a negative amount :) \n ";
					cout<<"\n\tPlease enter again";
					j=0;
				}
				else{
				ac.dep(amt);
			     j=1;
			 }
			
			}
		}
			
			int bal;
			if(option==2)
			{
			   cout<<"\n\n\tTO WITHDRAW AMOUNT ";
			//	int c=0;
			//	while(c==0){
				
					int j=0;
				while(j==0){
				
				cout<<"\n\nEnter The amount to be withdraw";
				
				cin>>amt;
				if(amt<0){
					cout<<"You can't withdraw a negative quantity :)\n\t Please enter a valid amount\n";
					j=0;
				}
				else if(amt>ac.retdeposit()){
					cout<<"Sorry you can't withdraw more than in your account: \n";
					  j=0;
				}
				else{
			       bal=ac.retdeposit()-amt;
			       	if((bal<500 && ac.rettype()=='s') || (bal<1000 && ac.rettype()=='c'))
				
					j=0,cout<<"Insufficience balance will remain in your account as you account is --: "<<ac.rettype()<<"\n\nSo you account must hold the minimum amount\n\n Please enter a valid amount\n ";
	               else
				   j=1;
			         }
		         }

					ac.draw(amt);
	
		}
			
			
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t We have Update your account detail";
			found=true;
			
		}
		}
	       

	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
		
		
		 cout<<"\n\n PRESS ENTER IF YOU WANT TO GO ON HOME PAGE\n";
}



