#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
public:
    string name;
    int accountNumber;
    double balance;

    void createAccount() {
        cout << "Enter account holder's name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter account number: ";
        cin >> accountNumber;

        cout << "Enter initial deposit amount: ";
        cin >> balance;

        cout << "\n Account created successfully!\n";
    }

    void displayAccount() const {
        cout << "\nAccount Details:\n";
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << " $" << amount << " deposited.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << " Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << " $" << amount << " withdrawn.\n";
        }
    }
};

// Save all accounts to file
void saveAccounts(const vector<BankAccount>& accounts) {
    ofstream file("accounts.dat", ios::binary);
    for (const auto& acc : accounts) {
        file.write(reinterpret_cast<const char*>(&acc), sizeof(acc));
    }
    file.close();
}

// Load all accounts from file
vector<BankAccount> loadAccounts() {
    vector<BankAccount> accounts;
    ifstream file("accounts.dat", ios::binary);
    BankAccount acc;
    while (file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        accounts.push_back(acc);
    }
    file.close();
    return accounts;
}

//  Find account by number
int findAccount(const vector<BankAccount>& accounts, int number) {
    for (int i = 0; i < accounts.size(); ++i) {
        if (accounts[i].accountNumber == number)
            return i;
    }
    return -1;
}

// 🔧 Main Menu
int main() {
    vector<BankAccount> accounts = loadAccounts();
    int choice;

    do {
        cout << "\n Bank Management System";
        cout << "\n1. Create Account";
        cout << "\n2. Display Account";
        cout << "\n3. Deposit Money";
        cout << "\n4. Withdraw Money";
        cout << "\n5. Save and Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            BankAccount acc;
            acc.createAccount();
            accounts.push_back(acc);
        } else if (choice == 2 || choice == 3 || choice == 4) {
            int number;
            cout << "Enter account number: ";
            cin >> number;
            int index = findAccount(accounts, number);
            if (index == -1) {
                cout << " Account not found.\n";
            } else {
                if (choice == 2)
                    accounts[index].displayAccount();
                else if (choice == 3) {
                    double amt;
                    cout << "Enter amount to deposit: $";
                    cin >> amt;
                    accounts[index].deposit(amt);
                } else if (choice == 4) {
                    double amt;
                    cout << "Enter amount to withdraw: $";
                    cin >> amt;
                    accounts[index].withdraw(amt);
                }
            }
        } else if (choice == 5) {
            saveAccounts(accounts);
            cout << "All accounts saved. Exiting...\n";
        } else {
            cout << " Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}
