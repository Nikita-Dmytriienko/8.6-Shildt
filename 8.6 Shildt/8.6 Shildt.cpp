/*
Develop a program for managing bank accounts.
Create a class "Bank Account" and derived classes for different types of accounts (e.g., savings, checking).
Use polymorphism to implement various operations such as deposits, withdrawals, and transfers.
A feature can be the use of virtual methods for handling interest calculations on a savings account.
*/
#include <iostream>
#include <string>

// Base class BankAccount to represent a bank account
class bank_account {
protected:
    std::string account_number_; // Account number
    double balance_; // Balance

public:
    // Constructor of the BankAccount class
    bank_account(std::string acc_number, const double initial_balance)
        : account_number_(std::move(acc_number)), balance_(initial_balance) {}

    // Virtual function for depositing money into the account
    virtual void deposit(const double amount) {
        balance_ += amount;
        std::cout << "Deposited: $" << amount << "\n";
    }

    // Virtual function for withdrawing money from the account
    virtual void withdraw(const double amount) {
        if (balance_ >= amount) {
            balance_ -= amount;
            std::cout << "Withdrawn: $" << amount << "\n";
        }
        else {
            std::cout << "Insufficient funds" << "\n";
        }
    }

    // Virtual function for displaying account information
    virtual void display() {
        std::cout << "Account Number: " << account_number_ << "\n";
        std::cout << "Balance: $" << balance_ << "\n";
    }

    // Virtual destructor
    virtual ~bank_account() = default;
};

// Subclass SavingsAccount, inheriting from BankAccount
class savings_account final : public bank_account {
    double interest_rate_; // Interest rate

public:
    // Constructor of the SavingsAccount class
    savings_account(const std::string& acc_number, const double initialBalance, const double rate)
        : bank_account(acc_number, initialBalance), interest_rate_(rate) {}

    // Overridden deposit function for a savings account
    void deposit(const double amount) override {
        bank_account::deposit(amount); // Call the deposit method from the base class
        calculate_interest(); // Calculate and add interest
    }

    // Function to calculate and add interest
    void calculate_interest() {
	    const double interest = balance_ * interest_rate_ / 100;
        balance_ += interest;
        std::cout << "Interest added: $" << interest << "\n";
    }
};

// Subclass CheckingAccount, inheriting from BankAccount
class checking_account final : public bank_account {
public:
    // Constructor of the CheckingAccount class
    checking_account(const std::string& acc_number, const double initial_balance)
        : bank_account(acc_number, initial_balance) {}

    // Overridden withdraw function for a CheckingAccount
    void withdraw(const double amount) override {
        bank_account::withdraw(amount); // Call the withdrawal method from the base class
        if (balance_ < 1000) {
	        const double fee = balance_ / 100;
            balance_ -= fee;
            std::cout << "Service fee charged: $" << fee << "\n";
        }
    }
};

int main() {
    // Create account objects
    savings_account savings_account("SAV123", 1000, 2.5);
    checking_account checking_account("CHK456", 1500);

    // Deposit and withdraw funds, display account information
    savings_account.deposit(500);
    savings_account.withdraw(200);
    savings_account.display();
    std::cout << "\n";

    checking_account.deposit(7853);
    checking_account.withdraw(4500);
    checking_account.display();
    std::cout << "\n";

    return 0;
}
