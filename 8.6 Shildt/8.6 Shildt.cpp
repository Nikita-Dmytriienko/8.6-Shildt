#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& accNumber, double initialBalance)
        : accountNumber(accNumber), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: $" << amount << std::endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        }
        else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    virtual void display() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(const std::string& accNumber, double initialBalance, double rate)
        : BankAccount(accNumber, initialBalance), interestRate(rate) {}

    void deposit(double amount) override {
        BankAccount::deposit(amount);
        calculateInterest();
    }

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        std::cout << "Interest added: $" << interest << std::endl;
    }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(const std::string& accNumber, double initialBalance)
        : BankAccount(accNumber, initialBalance) {}

    void withdraw(double amount) override {
        BankAccount::withdraw(amount);
        if (balance < 1000) {
            double fee = balance / 200;
            balance -= fee;
            std::cout << "Service fee charged: $" << fee << std::endl;
        }
    }
};

int main() {
    // Создаем объекты счетов
    SavingsAccount savingsAccount("SAV123", 1000, 2.5);
    CheckingAccount checkingAccount("CHK456", 1500);

    // Вносим и снимаем средства, выводим информацию о счетах
    savingsAccount.deposit(500);
    savingsAccount.withdraw(200);
    savingsAccount.display();
    std::cout << std::endl;

    checkingAccount.deposit(300);
    checkingAccount.withdraw(1000);
    checkingAccount.display();
    std::cout << std::endl;

    return 0;
}