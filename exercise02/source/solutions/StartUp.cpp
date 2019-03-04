#include "Bank.h"
#include <iostream>

using namespace std;

int main()
{
	Bank bank;
	bank.AddAccount(BankAccount({ "Zdravko", "Hvarlingov", 21, 300, false }));
	bank.AddAccount(BankAccount({ "Kiril", "Ivanov", 23, 3000, true }));
	bank.AddAccount(BankAccount({ "Iveta", "Raleva", 21, 1000, true }));

	cout << bank.GetSize() << endl;
	cout << bank.RemoveAccount(BankAccount({ "Zdravko", "Hvarlingov", 21, 300, false })) << endl;
	cout << bank.GetSize() << endl;

	bank.Deposit(100);
	cout << bank.GetAverageBalance() << endl;

    return 0;
}