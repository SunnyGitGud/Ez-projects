#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <conio.h>
#include <functional> 
#include <iomanip>
using namespace std;


string hashPassword(const string& password) {
    hash<string> hasher;
    size_t hashed = hasher(password);
    return to_string(hashed);
}


class BankAccount {
private:
    string username;
    double balance;
    string password;
public:
    BankAccount() : username(""), password(""), balance(0.0) {}


    BankAccount(const string& user, const string& pass, double initialBalance)
        : username(user), balance(initialBalance), password(pass) {}

    void deposite(double amount){
        if (amount > 0){
            balance += amount;
        }
    }    
    
    void withdraw(double amount){
        if (amount <= balance){
            balance -= amount;
        } else {
            cout << "There is not enough balance" << endl;
        }
    }

    void display(){
        cout << "Username: " << username << "\nBalance: $" <<
        fixed << setprecision(2) << balance << endl;
    }

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    double getBalance() const { return balance; }
};

int main() {
     map<string, BankAccount> users;
    
    ifstream inFile("accounts.txt");
        if (inFile.is_open()) {
            string user, pass;
            double bal;
            while (inFile >> user >> pass >> bal) {
                BankAccount acc(user, pass, bal);
                users[user] = acc;
            }
            inFile.close();
            cout << "Accounts loaded from file.\n";
        } else {
            cout << "No saved accounts found.\n";
        }


    int choice;

    do{
        cout << "\n1. Register\n2. Log In\n3. Exit\nChoose option: ";
        cin>> choice;
        cin.ignore();

        if(choice == 1){
            //registration
            string user, pass;
            double deposit;

            cout << "Enter username: ";
            getline(cin, user);

            if (users.find(user) != users.end() ) {
                cout << "Username already exists!\n";
                continue;
            }

            cout << "enter password: ";
            getline(cin, pass);

            string hashedPass = hashPassword(pass);

            cout << "Enter initial deposit: ";
            cin >> deposit;
            cin.ignore();

            users[user] = BankAccount(user, hashedPass, deposit);
            cout << "account created successfuly. \n";
        }
    else if (choice == 2){
        string user, pass;
        cout << "Enter username: ";
        getline(cin,user);

        auto it = users.find(user);
        if (it == users.end()) {
            cout << "User not found. \n";
            continue;
        }

        cout << "Enter password: ";
        getline(cin, pass);

        string hashedPass = hashPassword(pass);

        if (it->second.getPassword() != hashedPass){
            cout << "Incorrect password. \n";
            continue;
        }



        cout << "login successful!\n";

       int action;
            double amount;
            do {
                cout << "\n1. Deposit\n2. Withdraw\n3. Display\n4. Logout\nChoose option: ";
                cin >> action;

                switch (action) {
                    case 1:
                        cout << "Amount to deposit: ";
                        cin >> amount;
                        it->second.deposite(amount);
                        break;
                    case 2:
                        cout << "Amount to withdraw: ";
                        cin >> amount;
                        it->second.withdraw(amount);
                        break;
                    case 3:
                        it->second.display();
                        break;
                    case 4:
                        cout << "Logging out...\n";
                        break;
                    default:
                        cout << "Invalid choice.\n";
                }
            } while (action != 4); 
        }   
    } while (choice != 3);
    

    ofstream outFile("accounts.txt");
    for (const auto& pair : users) {
        outFile << pair.second.getUsername() << " "
                << pair.second.getPassword() << " "
                << pair.second.getBalance() << endl;
    }
    outFile.close();

    cout << "Account saved to file.\n";


    return 0;
}