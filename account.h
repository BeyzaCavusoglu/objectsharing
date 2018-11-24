#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;
class Account    //Creating an Account Class
{

public:
	double balance;
	double limit;
	double debt;
	double availablelimit;
	Account ()  //default constructor
	{
	double mybalance;
	double mylimit;
	double mydebt;		
	};  

	Account(double mybalance, double mylimit, double mydebt)  //parametrized constructor
	{
		balance=mybalance;
		limit=mylimit;
		debt=mydebt;
		availablelimit = mylimit- mydebt;
	};  

private:	
};

#endif