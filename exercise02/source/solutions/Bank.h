#pragma once

#include "BankAccount.h"

class Bank
{
public:
	Bank();
	bool Withdraw(double value);
	bool Deposit(double value);
	bool AddAccount(BankAccount acc);
	bool RemoveAccount(BankAccount acc);
	double GetAverageBalance();
	unsigned int GetSize();
	bool BlockAccount(BankAccount acc);
	bool UnBlockAccount(BankAccount acc);
	bool PerformOperation(double(*op)(double));

private:

	void ShiftLeft(int index);

	BankAccount accounts[1000];
	unsigned int size;
};

Bank::Bank()
{
	this->size = 0;
}

bool Bank::Withdraw(double value)
{
	bool allGood = true;
	for (size_t i = 0; i < size; i++)
	{
		allGood = allGood && accounts[i].Withdraw(value);
	}

	return allGood;
}

bool Bank::Deposit(double value)
{
	bool allGood = true;
	for (size_t i = 0; i < size; i++)
	{
		allGood = allGood && accounts[i].Deposit(value);
	}

	return allGood;
}

bool Bank::AddAccount(BankAccount acc)
{
	if (size == 1000)
	{
		return false;
	}

	accounts[size] = acc;
	++size;

	return true;
}

bool Bank::RemoveAccount(BankAccount acc)
{
	int ind = 0;
	while (ind < size && !accounts[ind].AreEqual(acc))
	{
		++ind;
	}

	if (ind == size)
	{
		return false;
	}

	ShiftLeft(ind);
	--size;
	return true;
}

double Bank::GetAverageBalance()
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += accounts[i].GetBalance();
	}

	return sum / size;
}

unsigned int Bank::GetSize()
{
	return size;
}

bool Bank::BlockAccount(BankAccount acc)
{
	for (size_t i = 0; i < size; i++)
	{
		if (accounts[i].AreEqual(acc))
		{
			accounts[i].Block();
			return true;
		}
	}

	return false;
}

bool Bank::UnBlockAccount(BankAccount acc)
{
	for (size_t i = 0; i < size; i++)
	{
		if (accounts[i].AreEqual(acc))
		{
			accounts[i].Unblock();
			return true;
		}
	}

	return false;
}

bool Bank::PerformOperation(double(*op)(double))
{
	bool allGood = true;
	for (size_t i = 0; i < size; i++)
	{
		allGood = allGood && accounts[i].PerformOperation(op);
	}

	return allGood;
}

void Bank::ShiftLeft(int index)
{
	for (size_t i = index; i < size - 1; i++)
	{
		accounts[i] = accounts[i + 1];
	}
}