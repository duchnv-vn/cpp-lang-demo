#include <iostream>
using namespace std;

// Write classes code here
// make base class functions virtual
class Account
{
protected:
    float balance;

public:
    virtual void Withdraw(float amount) {};
    virtual void Deposit(float amount) {};
    virtual void printBalance() {};
};

class Savings : public Account
{
    float interest_rate = 0.8;

public:
    Savings(float b)
    {
        balance = b;
    };

    void Withdraw(float amount)
    {
        balance -= amount * (1 + interest_rate);
    };

    void Deposit(float amount)
    {
        balance += amount * (1 + interest_rate);
    };

    void printBalance()
    {
        cout << "Balance in your current account: " << balance << endl;
    };
};

class Current : public Account
{
public:
    Current(float b)
    {
        balance = b;
    };

    void Withdraw(float amount)
    {
        balance -= amount;
    };

    void Deposit(float amount)
    {
        balance += amount;
    };

    void printBalance()
    {
        cout << "Balance in your current account: " << balance << endl;
    };
};

int main()
{
    // make instances of classes here
    // call their traits functions here
    Savings s1(50000);
    Account *acc = &s1;
    acc->Deposit(1000);
    acc->printBalance();

    acc->Withdraw(3000);
    acc->printBalance();

    Current c1(50000);
    acc = &c1;
    acc->Deposit(1000);
    acc->printBalance();

    acc->Withdraw(3000);
    acc->printBalance();

    return 0;
}