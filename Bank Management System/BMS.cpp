#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    string name;
    double balance;
public:
    BankAccount(const string& accountName, double& initialBalance)
                    :name(accountName), balance(initialBalance){}

    void deposite(double amount){
        if (amount > 0){
            balance += amount;
        }
    }    
    
    void withdraw(double amount){
        if ( amount <= balance){
            balance -= amount;
        } else {
            cout << "there is not enough balance" << endl;
        }
    }

    void display(){
        cout << "Account: " << 
        name << "\nBalance: $"<<
         balance << endl;
    }
};

int main(){
    string name;
    double initialdeposit;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter initial deposit: ";
    cin >> initialdeposit;

    BankAccount account(name, initialdeposit);
    int choice;
    double amount;

    do
    {
    cout << "\n1. Deposit" << endl;
    cout << "\n2. Withdraw" << endl;
    cout << "\n3. Display Account" << endl;
    cout << "\n4. exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
         switch (choice)
        {
        case 1: 
            cout << "Enter deposit Amount: ";
            cin >> amount;
            account.deposite(amount);
            break;

        case 2: 
            cout << "Enter Withdrawal Amount: ";
            cin >> amount;
            account.withdraw(amount);
            break;

        case 3:
            account.display();
            break;
        
        default:
                cout << "Invalid choice." << endl;       
            break;
        } 
    }while (choice != 4);
    return 1;
}
