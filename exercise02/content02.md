# 27.02.2019

### What are we going to talk about today?
1. Class vs Struct;
2. Function templates and class templates;
3. Function pointers;

### Tasks
1. Define **struct Person** which have the following fields and methods:
    -   name up to 127 symbols;
    -   family name up to 127 symbols;
    -   age;
    -   boolean if the person has work or not;
    -   average montly income;
    -   method which accepts another Persons and returns true if both are equal;

2. Define class BankAccount which have the following **private** fields:
    - current balance;  
    - Person owner;
    - boolean if the account is blocked or not;
    
3. Define **public** methods for the following things:
    - Deposit into the account(if account is not blocked);
    - Withdraw from the account(the balance has to be non negative and account not blocked);
    - Block the account;
    - Unblock the account;
    - Accepts a function pointer **func**, which is function to 1 number which returns a new one. You have to call that function on the current balance. The result is the new bank account balance(if the account is not blocked);
    - Returns the account owner;
    - Returns account current balance;
    - Return if the account is blocked;
    - Accepts another BankAccount and returns true if the accounts are equal;

4. Define proper constructors for the class BankAccount.
    - What are the default values?

5. Define class Bank which will be a collection of BankAccounts(maximum 1000);

6. Define the following methods for the Bank class:
    - Adding a new BankAccount;
    - Removing a specific BankAccount if it is already inside the bank;
    - Withdraw a value from all the accounts;
    - Deposit a value to all the accounts;
    - Gets the average balance of the account;
    - Returns the number of bank account handled;
    - Performing an operation on the balance of all the accounts. Operation is passed as a function pointer;
    - Block/Unblock a specific BankAccount;

7. Consider the private fields of the class Bank;