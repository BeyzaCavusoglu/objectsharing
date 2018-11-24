#ifndef CHILD_H
#define CHILD_H

using namespace std;

class Child // Creating a Child class for having child objects
{
public:
	Child() ; //default constructor	
	Child(const string name, Parent & parent); //parametrized constructor
	void displayAccountInfo();
	void spendMoney(double childmoneyspent);

private:
	string childname;
	Parent & childparent;	//parent object passed by reference (we will reach the account of parent-object sharing)
};


//*********************************************
//OUTSIDE OF CLASS CHILD

Child::Child(const string name, Parent & parent)
	:childname(name), childparent(parent)
{};


void Child:: displayAccountInfo() //displays the balance, limit and available limit info of linked parent's account
{
	cout<<endl << "******************************"<<endl;
	cout<<"The account balance is: "<< childparent.parentaccount.balance<<"TL." <<endl;
	if(childparent.parentaccount.limit>childparent.parentaccount.debt)
	{
		cout<<"The available account limit is: "<<childparent.parentaccount.availablelimit<<"TL." <<endl;
	}
	else
	{
	cout<<"No available account limit, debts are more than limit of account!"<< endl;
	}
	cout<<"******************************"<<endl;
};

void Child:: spendMoney(double childmoneyspent) //Spends money by given childspentmoney value
{
	if(childmoneyspent>200) //child cannot spend more than 200 TL.
	{
		cout<<childname << " can not spend " << childmoneyspent  << "TL. Children can spend up to 200TL." << endl;	
	}
	else
	{
		cout<<childname << " has successfully spent "<< childmoneyspent << "TL." << endl;	
		childparent.parentaccount.availablelimit=childparent.parentaccount.limit-childparent.parentaccount.debt-childmoneyspent;
		if(childparent.parentaccount.balance>0) //if there is money in balance
		{
			childparent.parentaccount.balance=childparent.parentaccount.balance-childmoneyspent; //update balance
		}
		else if(childparent.parentaccount.debt>0){ //add to debt
			childparent.parentaccount.debt=childparent.parentaccount.debt + childmoneyspent;
		}
	}
};


#endif