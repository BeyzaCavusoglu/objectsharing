// The aim of this code is to practice object sharing concept in C++.I implemented three classes: account, parent, child. The parents and the child will share a single account and perform operations on it. The operations are explained below.

*************
Program Flow

There will be three classes to implement. 
1-	Account:
This class will implement a basic account object. There will be three member variables and they will be double values. The members are: balance, limit, debt. 


2-	Parent: This class will implement a basic parent object. There will be two member variables: name and account. The parent can perform the following functions:
•	printAccountInfo() : This function will display the current information about the account. For the exact output, please check Sample Runs. 
Note: The available account limit is calculated as limit – debt.
•	depositMoney(double) : This function will deposit the given amount to the account. After the deposit, the balance will be increased by the given amount.
•	spendMoney(double) : This function will try to spend the given amount of money. If the balance is more than the amount to spent, only balance will decrease. If there are not enough money in balance, the remaining money will be added to debt. If the debt exceeds the limit, an error message will be prompted and no money will be spent.
•	payDebt(double) : This function will try to pay the given amount of debt. If the given amount is more than the current debt, an error message will be prompted. Otherwise, the debt will be paid.

3- Child: This class will implement a basic child object. The child can only display the account info (the balance and the available limit) and spend money. While spending money, a child can only spend up to 200TL. Otherwise, an error message will be displayed. 

*************************************************
Sample Runs
The given source file produces the following output.

Lily has deposited 50TL.
Lily has successfully spent 250TL.
James has successfully spent 2000TL.

******************************
The account balance is: 0TL.
The account debt is: 1700TL.
The account limit is: 2000TL.
The available account limit is: 300TL.
******************************
Harry can not spend 500TL. Children can spend up to 200TL.
Harry has successfully spent 50TL.

******************************
The account balance is: 0TL.
The available account limit is: 250TL.
******************************
James attempts to pay more than debt. No payment is done.
James payed 1000TL of debt.

******************************
The account balance is: 0TL.
The account debt is: 750TL.
The account limit is: 2000TL.
The available account limit is: 1250TL.
******************************
Lily payed 750TL of debt.
James has deposited 500TL.
Harry can not spend 250TL. Children can spend up to 200TL.
Harry has successfully spent 150TL.

******************************
The account balance is: 350TL.
The account debt is: 0TL.
The account limit is: 2000TL.
The available account limit is: 2000TL.
******************************
Press any key to continue . . .

