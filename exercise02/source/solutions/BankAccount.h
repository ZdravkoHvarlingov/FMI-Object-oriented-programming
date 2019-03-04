#pragma once

#include <string.h>

struct Person
{
	char name[128];
	char familyName[128];
	unsigned int age;
	double averageIncome;
	bool hasWork;

	bool AreEqual(Person prs)
	{
		return strcmp(name, prs.name) == 0 && strcmp(familyName, prs.familyName) == 0 &&
			age == prs.age && averageIncome == prs.averageIncome && hasWork == prs.hasWork;
	}
};

class BankAccount
{
public:
	BankAccount();
	BankAccount(Person prs);
	BankAccount(Person prs, double initialDeposit, bool isBlocked);

	bool Deposit(double value);
	bool Withdraw(double value);
	void Block();
	void Unblock();
	Person GetOwner();
	double GetBalance();
	double IsBlocked();
	bool PerformOperation(double(*op)(double));
	bool AreEqual(BankAccount acc);

private:
	double currentBalance;
	Person owner;
	bool isBlocked;
};

BankAccount::BankAccount()
{
	this->currentBalance = 0;
	this->isBlocked = false;
}

BankAccount::BankAccount(Person prs)
	: BankAccount()
{
	this->owner = prs;
}

BankAccount::BankAccount(Person prs, double initialDeposit, bool isBlocked = false)
	: BankAccount(prs)
{
	this->currentBalance = initialDeposit >= 0 ? initialDeposit : 0;
	this->isBlocked = isBlocked;
}

bool BankAccount::Deposit(double value)
{
	if (value < 0 || isBlocked)
	{
		return false;
	}

	currentBalance += value;
	return true;
}

bool BankAccount::Withdraw(double value)
{
	if (value < 0 || value > currentBalance || isBlocked)
	{
		return false;
	}

	currentBalance -= value;
	return true;
}

void BankAccount::Block()
{
	isBlocked = true;
}

void BankAccount::Unblock()
{
	isBlocked = false;
}

Person BankAccount::GetOwner()
{
	return owner;
}

double BankAccount::GetBalance()
{
	return currentBalance;
}

double BankAccount::IsBlocked()
{
	return isBlocked;
}

bool BankAccount::PerformOperation(double(*op)(double))
{
	double newBalance = op(currentBalance);

	if (isBlocked || newBalance < 0)
	{
		return false;
	}

	currentBalance = newBalance;
	return true;
}

bool BankAccount::AreEqual(BankAccount acc)
{
	return currentBalance == acc.currentBalance && owner.AreEqual(acc.owner) && isBlocked == acc.isBlocked;
}