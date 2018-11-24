#ifndef PARENT_H
#define PARENT_H
using namespace std; 

class Parent    //Creating a Parent Class
{
public:
	string parentname;
	Account & parentaccount;   //Takes the account as reference- object sharing here
	Parent(const string name, Account & account);	//parametrized constructor

	void printAccountInfo();
	void depositMoney(double addmoney); 
	void spendMoney(double spentm);
	void payDebt(double deptm);

private:	
};


//**************************************************
// OUTSIDE OF CLASS PARENT

Parent::Parent (const string name, Account & account)  //parametrized constructor
	: parentname(name), parentaccount(account)         //used initiling list since reference parametre is exist
{};
	

void Parent::printAccountInfo()   //Prints the balance, debt, limit and available limit
{
	cout<<endl << "******************************"<<endl;
	cout<<"The account balance is: "<< parentaccount.balance<< "TL." << endl;
	cout<<"The account debt is: "<<parentaccount.debt<<"TL." <<endl;
	cout<<"The account limit is: "<<parentaccount.limit<<"TL." <<endl;
	if(parentaccount.limit>parentaccount.debt)
	{
		cout<<"The available account limit is: "<< parentaccount.limit-parentaccount.debt <<"TL." <<endl;
	}
	else
	{
	cout<<"No available account limit, debts are more than limit of account!"<< endl;
	}
	cout<<"******************************"<<endl;
};

void Parent:: depositMoney(double addmoney)	 //For depoziting money to account
{	
	cout << parentname <<" has deposited "<< addmoney << "TL." << endl;
	parentaccount.balance += addmoney;  //adds money to the balance
};


void Parent :: spendMoney(double spentm)  //Spends money by spentm variable much
{
	if(spentm<parentaccount.balance)    //if the spending money is already can be spent from balance money
	{
		parentaccount.balance= parentaccount.balance- spentm;	//spent it and decrease the balance money
		cout<< parentname<< " has successfully spent " << spentm <<"TL."  << endl; 
	}
	else if(spentm>parentaccount.balance && spentm < parentaccount.debt < parentaccount.limit) //if there is not enough money in balance but
		                                                                                       //the debt still didnt passed limit, we can spent
																							   //from the debt part.(spentm will be added to debt)
	{		
		parentaccount.debt=parentaccount.debt + spentm - parentaccount.balance;
		parentaccount.balance=0;
		cout<< parentname<< " has successfully spent " << spentm <<"TL." << endl;
	}
	else  //not enough money to spent in balance, debt limit is already exceeded.
	{
		cout<< parentname << " can not spend " << spentm << "TL." << " .Debt is already bigger than limit!" << endl;
	}
};


void Parent :: payDebt(double deptm)  //pays the debt by given deptm value
{
	if(deptm>parentaccount.debt)  //if tries to pay with a bigger money than the debt, dont let it.
	{
		cout << parentname << " attempts to pay more than debt. No payment is done. "<< endl;
	}

	else
	{
		cout<< parentname <<" payed " << deptm << "TL" <<" of debt."<< endl;
		parentaccount.debt=parentaccount.debt-deptm;  //update the dept by substracting the payed deptm money
		
	}

}; 

#endif