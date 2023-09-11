/*
Разработайте программу для управления банковскими счетами.
 Создайте класс "Банковский счет" и производные классы для разных типов счетов (например, сберегательный, чековый).
 Используйте полиморфизм для реализации различных операций,
 таких как депозиты, снятия и переводы.
 Особенностью может быть использование виртуальных методов для обработки начисления процентов на сберегательном счете.
 */
#include <iostream>
#include <string>

 // Базовый класс BankAccount для представления банковского счета
class BankAccount {
protected:
    std::string accountNumber; // Номер счета
    double balance; // Баланс

public:
    // Конструктор класса BankAccount
    BankAccount(const std::string& accNumber, double initialBalance)
        : accountNumber(accNumber), balance(initialBalance) {}

    // Виртуальная функция для внесения денег на счет
    virtual void deposit(double amount) {
        balance += amount;
        std::cout << "Deposited: $" << amount << std::endl;
    }

    // Виртуальная функция для снятия денег со счета
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount << std::endl;
        }
        else {
            std::cout << "Insufficient funds" << std::endl;
        }
    }

    // Виртуальная функция для отображения информации о счете
    virtual void display() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Виртуальный деструктор
    virtual ~BankAccount() {}
};

// Подкласс SavingsAccount, наследующийся от BankAccount
class SavingsAccount : public BankAccount {
    double interestRate; // Процентная ставка

public:
    // Конструктор класса SavingsAccount
    SavingsAccount(const std::string& accNumber, double initialBalance, double rate)
        : BankAccount(accNumber, initialBalance), interestRate(rate) {}

    // Переопределенная функция deposit для сберегательного счета
    void deposit(double amount) override {
        BankAccount::deposit(amount); // Вызываем deposit из базового класса
        calculateInterest(); // Вычисляем и начисляем проценты
    }

    // Функция для вычисления и начисления процентов
    void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        std::cout << "Interest added: $" << interest << std::endl;
    }
};

// Подкласс CheckingAccount, наследующийся от BankAccount
class CheckingAccount : public BankAccount {
public:
    // Конструктор класса CheckingAccount
    CheckingAccount(const std::string& accNumber, double initialBalance)
        : BankAccount(accNumber, initialBalance) {}

    // Переопределенная функция withdraw для счета CheckingAccount
    void withdraw(double amount) override {
        BankAccount::withdraw(amount); // Вызываем withdraw из базового класса
        if (balance < 1000) {
            double fee = balance / 100;
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