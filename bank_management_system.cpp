#include <iostream>
#include <cstring>

using namespace std;

struct Customer
 {
    int accountNumber;
    string name;
    double balance;

    Customer* prev;
    Customer* next;
};

class BankManagementSystem 
{

private:
    Customer* head;

public:
    BankManagementSystem() { head = nullptr;}

    bool isAccountNumberUnique(int accountNumber) 
    {
       
        Customer* temp = head;

        while (temp != nullptr) {
            if (temp->accountNumber == accountNumber)
            {
                return false;
            }
            temp = temp->next;
        }

        return true;
    }

    void createAccount() 
    {
        Customer* newCustomer = new Customer;

        cout << "Enter account number: ";
        cin >> newCustomer->accountNumber;

        if (!isAccountNumberUnique(newCustomer->accountNumber)) 
        {
            cout << "Account number already exists. Please choose a unique account number.\n";
            delete newCustomer;
            return;
        }

        cout << "Enter name: ";
        cin >> newCustomer->name;
        cout << "Enter initial balance: ";
        cin >> newCustomer->balance;

        newCustomer->prev = nullptr;
        newCustomer->next = nullptr;

        if (head == nullptr) 
        {
            head = newCustomer;
        } 
        else
        {
            Customer* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newCustomer;
            newCustomer->prev = temp;
        }

        cout << "Account created successfully!\n";
    }

    void displayAccounts()
    {
        Customer* temp = head;

        if (temp == nullptr)
        {
            cout << "No accounts available!\n";
            return;
        }

        cout << "----------------------------------------------\n";
        cout << "Account Number | Name          | Balance\n";
        cout << "----------------------------------------------\n";

        while (temp != nullptr) 
        {
            cout << temp->accountNumber << "\t\t| " << temp->name << "\t\t| " << temp->balance << "\n";
            temp = temp->next;
        }

        cout << "----------------------------------------------\n";
    }

    void depositMoney()
     {
        int accountNumber;
        double amount;

        cout << "Enter account number to deposit money: ";
        cin >> accountNumber;

        Customer* customer = findCustomer(accountNumber);

        if (customer != nullptr) 
        {
            cout << "Enter amount to deposit: ";
            cin >> amount;

            if (amount > 0) 
            {
                customer->balance += amount;
                cout << "Deposit successful! New balance: " << customer->balance << "\n";
            } 
            else 
            {
                cout << "Invalid amount for deposit!\n";
            }
        } 
        else 
        {
            cout << "Account not found!\n";
        }
    }

    void withdrawMoney() 
    {
        int accountNumber;
        double amount;

        cout << "Enter account number to withdraw money: ";
        cin >> accountNumber;

        Customer* customer = findCustomer(accountNumber);

        if (customer != nullptr) 
        {
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (amount > 0 && amount <= customer->balance) 
            {
                customer->balance -= amount;
                cout << "Withdrawal successful! New balance: " << customer->balance << "\n";
            } 
            else 
            {
                cout << "Invalid amount for withdrawal or insufficient balance!\n";
            }
        } 
        else 
        {
            cout << "Account not found!\n";
        }
    }

    void checkBalance()
     {
        int accountNumber;

        cout << "Enter account number to check balance: ";
        cin >> accountNumber;

        Customer* customer = findCustomer(accountNumber);

        if (customer != nullptr) 
        {
            cout << "Current balance for account " << accountNumber << ": " << customer->balance << "\n";
        } 
        else
        {
            cout << "Account not found!\n";
        }
    }

private:

    Customer* findCustomer(int accountNumber) 
    {
        Customer* temp = head;

        while (temp != nullptr)
         {
            if (temp->accountNumber == accountNumber) {
                return temp;
            }
            temp = temp->next;
        }

        return nullptr;
    }
};

int main() 
{

    BankManagementSystem bank;

    int choice;

    cout <<"\n\t\t\t\t *****CREATIVE COMPUTERS*****\n\n";
    
    cout << "\t\t\t\t\t WELCOME TO \n \t\t\t\t\t    BANK \n  \t\t\t\t\t MANAGEMENT  \n  \t\t\t\t\t   SYSTEM \n\n";
    
    cout << endl;

    do {
        cout << "\n\n\n\t MAIN MENU";
        cout << "\n\n\n\t1 Create Account";
        cout << "\n\n\n\t2 Display Accounts";
        cout << "\n\n\n\t3 Deposit Money";
        cout << "\n\n\n\t4 Withdraw Money";
        cout << "\n\n\n\t5 Check Balance";
        cout << "\n\n\n\t0 Exit";
        cout << "\n\n\n\t Please select your option (0-5): ";

        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.displayAccounts();
                break;
            case 3:
                bank.depositMoney();
                break;
            case 4:
                bank.withdrawMoney();
                break;
            case 5:
                bank.checkBalance();
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "INVALID CHOICE";
        }
    } while (choice != 0);

    return 0;
}
