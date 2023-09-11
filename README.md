# Bank Account Management System

This C++ project demonstrates a simple bank account management system using object-oriented programming principles. It includes a base class `BankAccount` and two derived classes `SavingsAccount` and `CheckingAccount`. The program allows you to perform basic banking operations such as deposits, withdrawals, and displaying account information.

## Project Structure

- `main.cpp`: The main program file containing the implementation of the `BankAccount`, `SavingsAccount`, and `CheckingAccount` classes.

## Usage

1. **Compile the program**:
    - Ensure you have a C++ compiler installed.
    - Clone the repository:
        ```bash
        git clone https://github.com/Nikita-Dmytriienko/8.6-Shildt.git
        ```
    - Navigate to the project directory:
        ```bash
        cd 8.6-Shildt
        ```
    - Compile the program:
        ```bash
        g++ main.cpp -o 8.6-Shildt
        ```

2. **Run the program**:
    - Execute the program:
        ```bash
        ./8.6-Shildt
        ```

## Classes

### `BankAccount`

- Represents a basic bank account with an account number and balance.
- Provides virtual functions for depositing, withdrawing, and displaying account information.

### `SavingsAccount`

- Inherits from `BankAccount`.
- Includes a virtual function to calculate and add interest to the account balance when making a deposit.

### `CheckingAccount`

- Inherits from `BankAccount`.
- Overrides the `withdraw` function to charge a service fee if the balance falls below $1000.

## Example Usage
```
// Create account objects
SavingsAccount savingsAccount("SAV123", 1000, 2.5);
CheckingAccount checkingAccount("CHK456", 1500);

// Perform operations
savingsAccount.deposit(500);
savingsAccount.withdraw(200);
savingsAccount.display();

checkingAccount.deposit(300);
checkingAccount.withdraw(1000);
checkingAccount.display();
```

## Optimizations

* **Refactoring**
* **Performance improvement**
* **Accessibility**


## 🛠 Skills
* **C++**


## Author 

- [@Nikita Dmytriienko](https://github.com/Nikita-Dmytriienko)


## 🚀 About Me
Good day! My name is Nikita Dmitrienko and I am a C++ developer. My main efforts are focused on system and application programming in this language. I study in-depth the concepts of object-oriented programming, working with pointers and references, as well as other fundamental aspects of C++.

My ambition is to develop professionally in C++ development, and I pride myself on my ability to actively and systematically develop in this area. I have recently started actively posting my projects on GitHub, demonstrating my progress and willingness to collaborate in a team of talented developers.

I look forward to applying my knowledge and skills as a C++ Developer and contributing to the success of a top company. Ready to listen attentively, learn and grow together with a team of professionals.


## 🔗 Links

[![linkedin](https://img.shields.io/badge/linkedin-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mykyta-dmytriienko-20231528b/)
[![telegram](https://img.shields.io/badge/telegram-1DA1F2?style=for-the-badge&logo=telegram&r&logoColor=white)](https://t.me/n3_kitosik)
[![github](https://img.shields.io/badge/github%20%20-black?style=for-the-badge&logo=github&r&logoColor=whie)](https://github.com/Nikita-Dmytriienko)

## Support

For support, email:
```nik.dmitrienko2000@gmail.com```


## Related

there will be new projects here soon =)

**[README](https://github.com/Nikita-Dmytriienko)**
