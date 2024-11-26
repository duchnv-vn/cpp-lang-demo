#include <iostream>
using namespace std;

// Write classes code here
// make base class functions virtual
class Account
{
protected:
    float balance;

public:
    virtual void Withdraw(float amount) = 0;
    virtual void Deposit(float amount) = 0;
    virtual void printBalance() = 0;
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
    Account *acc[2];
    acc[0] = new Savings(50000);
    acc[0]->Deposit(1000);
    acc[0]->printBalance();

    acc[0]->Withdraw(3000);
    acc[0]->printBalance();

    acc[1] = new Current(50000);
    acc[1]->Deposit(1000);
    acc[1]->printBalance();

    acc[1]->Withdraw(3000);
    acc[1]->printBalance();

    return 0;
}