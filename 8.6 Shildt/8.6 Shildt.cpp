/*
Develop a program for managing bank accounts.
Create a class "Bank Account" and derived classes for different types of accounts (e.g., savings, checking).
Use polymorphism to implement various operations such as deposits, withdrawals, and transfers.
A feature can be the use of virtual methods for handling interest calculations on a savings account.
*/
#include <iostream>
#include <string>

// Base class BankAccount to represent a bank account
class BankAccount {
protected:
    std::string accountNumber; // Account number
    double balance; // Balance

public:
    // Constructor of the BankAccount class
    BankAccount(const std::string& accNumber, double initialBalance)
        : accountNumber(accNumber), balance(initialBalance) {}

    // Virtual function for depositing money into the account
    virtual void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: $" << amount << std::endl;
    }

    // Virtual function for withdrawing money from the account
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        }
        else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    // Virtual function for displaying account information
    virtual void display() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Virtual destructor
    virtual ~BankAccount() {}
};

// Subclass SavingsAccount, inheriting from BankAccount
class SavingsAccount : public BankAccount {
    double interestRate; // Interest rate

public:
    // Constructor of the SavingsAccount class
    SavingsAccount(const std::string& accNumber, double initialBalance, double rate)
        : BankAccount(accNumber, initialBalance), interestRate(rate) {}

    // Overridden deposit function for a savings account
    void deposit(double amount) override {
        BankAccount::deposit(amount); // Call the deposit method from the base class
        calculateInterest(); // Calculate and add interest
    }

    // Function to calculate and add interest
    void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        std::cout << "Interest added: $" << interest << std::endl;
    }
};

// Subclass CheckingAccount, inheriting from BankAccount
class CheckingAccount : public BankAccount {
public:
    // Constructor of the CheckingAccount class
    CheckingAccount(const std::string& accNumber, double initialBalance)
        : BankAccount(accNumber, initialBalance) {}

    // Overridden withdraw function for a CheckingAccount
    void withdraw(double amount) override {
        BankAccount::withdraw(amount); // Call the withdraw method from the base class
        if (balance < 1000) {
            double fee = balance / 100;
            balance -= fee;
            std::cout << "Service fee charged: $" << fee << std::endl;
        }
    }
};

int main() {
    // Create account objects
    SavingsAccount savingsAccount("SAV123", 1000, 2.5);
    CheckingAccount checkingAccount("CHK456", 1500);

    // Deposit and withdraw funds, display account information
    savingsAccount.deposit(500);
    savingsAccount.withdraw(200);
    savingsAccount.display();
    std::cout << std::endl;

    checkingAccount.deposit(7853);
    checkingAccount.withdraw(4500);
    checkingAccount.display();
    std::cout << std::endl;

    return 0;
}
