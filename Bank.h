#include <bits/stdc++.h>
#include "date1.h"
using namespace std;

int count = 0;
class Customer
{
private:
    string name, address, telephone_number, acc_tp, customer_type;
    int age, customer_number;

public:
    void setName()
    {
        cout << "Enter your name : ";
        cin.ignore();
        getline(cin, name);
    }

    string getName()
    {
        return name;
    }

    void setAddress()
    {
        cout << "Enter Your Address : ";
        getline(cin, address);
    }

    string getAddress()
    {
        return address;
    }

    void setAge()
    {
        cout << "Enter Your Age : ";
        cin >> age;
    }
    int getAge()
    {
        return age;
    }

    void setTelephoneNumber()
    {
        cout << "Enter Your Telephone Number : ";
        cin >> telephone_number;
    }
    string getTelephoneNumber()
    {
        return telephone_number;
    }

    void setCustomerNumber()
    {
        customer_number = ::count;
    }
    int getCustomerNumber()
    {
        return customer_number;
    }

    void setAccountType()
    {
        cout << "Select : " << endl;
        cout << "1: Savings Account" << endl;
        cout << "2: checking Account" << endl;
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            acc_tp = "Savings";
            break;

        case 2:
            acc_tp = "Checking";
            break;

        default:
            break;
        }
    }

    string getAccountType()
    {
        return acc_tp;
    }

    void setCustomerType(string type)
    {
        customer_type = type;
    }

    string getCustomerType()
    {
        return customer_type;
    }
};

class Account : public Customer
{
    Customer customer;

private:
    int account_number = 0;
    double balance, od;

public:
    void set_customer()
    {
        customer.setName();
        customer.setAddress();
        customer.setAge();
        customer.setTelephoneNumber();
        customer.setCustomerNumber();
        cout << "Select: " << endl;
        cout << "0: Senior" << endl;
        cout << "1: Adult" << endl;
        cout << "2: Student" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
            customer.setCustomerType("Senior");
            customer.setAccountType();
            break;
        case 1:
            customer.setCustomerType("Adult");
            customer.setAccountType();
            break;
        case 2:
            customer.setCustomerType("Student");
            customer.setAccountType();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        cout << "-----------------------------------------------------------------" << endl;
        cout << "Account added" << endl;
        cout << "Account Holder Name : " << customer.getName() << endl;
        cout << "Account Number : " << customer.getCustomerNumber() << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }

    void create_Account()
    {
        set_customer();
        account_number = ::count;
    }

    int get_account_number()
    {
        return account_number;
    }

    double get_balance()
    {
        return balance;
    }

    void to_string()
    {
        cout << "Account Number : " << account_number << endl;
        cout << "Name: " << customer.getName() << endl;
        cout << "Address: " << customer.getAddress() << endl;
        cout << "Age: " << customer.getAge() << endl;
        cout << "Phone Number: " << customer.getTelephoneNumber() << endl;
        cout << "Customer Type: " << customer.getCustomerType() << endl;
        cout << "Account Type: " << customer.getAccountType() << endl;
        cout << "Balance : $" << balance << endl;
    }

    void set_balance()
    {
        balance = 0;
    }

    void set_balance(double amount)
    {
        od -= amount;
        balance += amount;
    }

    void set_od(double amount)
    {
        od += amount;
    }
    double get_od()
    {
        return od;
    }
    string getAccType()
    {
        return customer.getAccountType();
    }

    string getCustType()
    {
        return customer.getCustomerType();
    }
};

class Transaction : public Account
{
public:
    string transaction_type[100];
    int d[100], m[100], y[100];
    string date[100];
    double amount[100];
    double balance[100];
    Date dt;
    int tr_cnt = 0;
    void set_transaction(string tr_type, double amt, double bal, int dt, int mn, int yr)
    {
        transaction_type[tr_cnt] = tr_type;
        amount[tr_cnt] = amt;
        balance[tr_cnt] = bal;
        d[tr_cnt] = dt;
        m[tr_cnt] = mn;
        y[tr_cnt] = yr;
        stringstream s;
        s << yr << "-" << mn << "-" << dt;
        date[tr_cnt] = s.str();
        tr_cnt++;
    }

    void to_string()
    {
        for (int i = 0; i < tr_cnt; i++)
        {
            cout << transaction_type[i] << "\t";
            cout << date[i] << "\t";
            cout << "Amount: $" << amount[i] << "\t";
            cout << "Balance: $" << balance[i] << endl;
        }
    }

    long long int difference(int dat, int mn, int yr)
    {
        long long int diff_days;
        if(tr_cnt > 0)
        {
        diff_days = dt.difference_of_days(d[tr_cnt-1],m[tr_cnt-1],y[tr_cnt-1],dat,mn,yr);
        return diff_days;
        }
        else
        {
            return 0;
        }
    }
};

class Student : public Customer
{
public:
    const float SAVINGS_INTEREST = 1.00;
    const float CHECK_INTEREST = 2.00;
    const float CHECK_CHARGE = 3.00;
    const float OVERDRAFT_PENALTY = 0.00;
};

class Adult : public Customer
{
public:
    const float SAVINGS_INTEREST = 2.00;
    const float CHECK_INTEREST = 3.00;
    const float CHECK_CHARGE = 4.00;
    const float OVERDRAFT_PENALTY = 15.00;
};

class Senior : public Customer
{
public:
    const float SAVINGS_INTEREST = 3.00;
    const float CHECK_INTEREST = 4.00;
    const float CHECK_CHARGE = 5.00;
    const float OVERDRAFT_PENALTY = 20.00;
};

class savingsAccount : public Account
{
public:
    int ac_no;
    int amount;
    Student student;
    Adult adult;
    Senior senior;
    float deposit(string cs_type)
    {
        if (cs_type == "Student")
        {
            cout << "Student";
            return student.SAVINGS_INTEREST;
        }
        else if (cs_type == "Adult")
        {
            cout << "Adult";
            return adult.SAVINGS_INTEREST;
        }
        else if (cs_type == "Senior")
        {
            cout << "Senior";
            return senior.SAVINGS_INTEREST;
        }
        else
        {
            return 0;
        }
    }
    float withdraw(string cs_type)
    {
        if (cs_type == "Student")
        {
            return student.SAVINGS_INTEREST;
        }
        else if (cs_type == "Adult")
        {
            return adult.SAVINGS_INTEREST;
        }
        else if (cs_type == "Senior")
        {
            return senior.SAVINGS_INTEREST;
        }
        else
        {
            return 0;
        }
    }
    float add_interest(double amount, string cs_type, long long int diff)
    {
        if (cs_type == "Student")
        {
            return (((amount * student.SAVINGS_INTEREST) / 36500) * diff);
        }
        else if (cs_type == "Adult")
        {
            return (((amount * adult.SAVINGS_INTEREST) / 36500) * diff);
        }
        else if (cs_type == "Senior")
        {
            return (((amount * senior.SAVINGS_INTEREST) / 36500) * diff);
        }
        else
        {
            return 0;
        }
    }
};

class checkingAccount : public Account
{
public:
    int ac_no;
    int amount;
    Student student;
    Adult adult;
    Senior senior;
    float deposit(string cs_type)
    {
        if (cs_type == "Student")
        {
            return student.SAVINGS_INTEREST;
        }
        else if (cs_type == "Adult")
        {
            return adult.SAVINGS_INTEREST;
        }
        else if (cs_type == "Senior")
        {
            return senior.SAVINGS_INTEREST;
        }
        else
        {
            return 0;
        }
    }

    float withdraw(string cs_type)
    {
        if (cs_type == "Student")
        {
            return student.CHECK_CHARGE;
        }
        else if (cs_type == "Adult")
        {
            return adult.CHECK_CHARGE;
        }
        else if (cs_type == "Senior")
        {
            return senior.CHECK_CHARGE;
        }
        else
        {
            return 0;
        }
    }
    float add_interest(double amount, string cs_type, long long int diff)
    {
        if (cs_type == "Student")
        {
            return (((amount * student.CHECK_INTEREST) / 36500) * diff);
        }
        else if (cs_type == "Adult")
        {
            return (((amount * adult.CHECK_INTEREST) / 36500) * diff);
        }
        else if (cs_type == "Senior")
        {
            return (((amount * senior.CHECK_INTEREST) / 36500) * diff);
        }
        else
        {
            return 0;
        }
    }
};

class Bank : public checkingAccount
{
public:
    Account acc[100];
    Customer cus[100];
    savingsAccount sav;
    checkingAccount chk;
    int cnt = 0;
    Transaction transaction[100];
    Adult ad;
    Senior se;
    Student st;
    float interest = 0;
    void add_account()
    {
        acc[cnt].create_Account();
        cnt++;
        ::count++;
    }
    void make_deposit(int ac_no, double amount, int d, int m, int y)
    {

        for (int i = 0; i < cnt; i++)
        {
            if (acc[i].get_account_number() == ac_no)
            {

                if (acc[i].getAccType() == "Savings")
                {
                    if (acc[i].get_balance() > 0)
                    {
                        interest = sav.add_interest(amount, acc[i].getCustType(), transaction[i].difference(d,m,y));
                        acc[i].set_balance(interest);
                        transaction[i].set_transaction("INT CR", interest, acc[i].get_balance(), d, m, y);
                    }
                    acc[i].set_balance(amount);
                    transaction[i].set_transaction("DEP", amount, acc[i].get_balance(), d, m, y);
                }
                if (acc[i].getAccType() == "Checking")
                {
                    if (acc[i].get_balance() > 0)
                    {
                        interest = chk.add_interest(amount, acc[i].getCustType(), transaction[i].difference(d,m,y));
                        acc[i].set_balance(interest);
                        transaction[i].set_transaction("INT CR", interest, acc[i].get_balance(), d, m, y);
                    }
                    acc[i].set_balance(amount);
                    transaction[i].set_transaction("DEP", amount, acc[i].get_balance(), d, m, y);
                }
                if (acc[i].get_balance() < acc[i].get_od()){
                    double x = acc[i].get_balance();
                    acc[i].set_balance();
                    acc[i].set_od(0-x);
                    transaction[i].set_transaction("OD", acc[i].get_od(), acc[i].get_balance(), d, m, y);
                }
                else if(acc[i].get_od() > 0){
                    double x = acc[i].get_balance() - acc[i].get_od();
                    acc[i].set_balance(0-x);
                    acc[i].set_od(0-acc[i].get_od());
                    transaction[i].set_transaction("OD", acc[i].get_od(), acc[i].get_balance(), d, m, y); 
                }
                else{
                    continue;
                }
            }
        }
    }

    void make_withdraw(int ac_no, double amount, int d, int m, int y)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (acc[i].get_account_number() == ac_no)
            {
                if (acc[i].getAccType() == "Savings")
                {
                    if (acc[i].get_balance() < amount && acc[i].getCustType() == "Student")
                    {
                        cout << "Students can't do overdraft" << endl;
                        return;
                    }
                    if (acc[i].get_balance() > 0)
                    {
                        interest = sav.add_interest(amount, acc[i].getCustType(), transaction[i].difference(d,m,y));
                        acc[i].set_balance(interest);
                        transaction[i].set_transaction("INT CR", interest, acc[i].get_balance(), d, m, y);
                    }
                    acc[i].set_balance(0 - amount);
                    transaction[i].set_transaction("WD", amount, acc[i].get_balance(), d, m, y);
                    cout << "Balance : " << acc[i].get_balance() << endl;
                }
                if (acc[i].getAccType() == "Checking")
                {
                    if (acc[i].get_balance() > 0)
                    {
                        interest = chk.add_interest(amount, acc[i].getCustType(), transaction[i].difference(d,m,y));
                        acc[i].set_balance(interest);
                        transaction[i].set_transaction("INT CR", interest, acc[i].get_balance(), d, m, y);
                    }
                    interest = chk.withdraw(acc[i].getCustType());
                    acc[i].set_balance(0 - amount);
                    transaction[i].set_transaction("WD", amount, acc[i].get_balance(), d, m, y);
                    acc[i].set_balance(0 - interest);
                    transaction[i].set_transaction("CHKCHG", interest, acc[i].get_balance(), d, m, y);
                    cout << "Balance : $" << acc[i].get_balance() << endl;
                }
                if (acc[i].get_balance() > 0 && acc[i].get_od() == 0)
                {
                    double x = acc[i].get_balance();
                    acc[i].set_balance();
                    if (acc[i].getCustType() == "Adult")
                    {
                        acc[i].set_od((0-x) + ad.OVERDRAFT_PENALTY);
                        transaction[i].set_transaction("OD", x, acc[i].get_balance(), d, m, y);
                    }
                    else
                    {
                        acc[i].set_od((0-x) + se.OVERDRAFT_PENALTY);
                        transaction[i].set_transaction("OD", x, acc[i].get_balance(), d, m, y);
                    }
                }
                else if( acc[i].get_od() > 0){
                    double x = 0;
                    acc[i].set_balance();
                    if (acc[i].getCustType() == "Adult")
                    {
                        x = amount + ad.OVERDRAFT_PENALTY;
                        acc[i].set_od(0-x);
                        transaction[i].set_transaction("OD", x, acc[i].get_balance(), d, m, y);
                    }
                    else
                    {
                        x = amount + se.OVERDRAFT_PENALTY;
                        acc[i].set_od(0-x);
                        transaction[i].set_transaction("OD", x, acc[i].get_balance(), d, m, y);
                    }
                }
                else{
                    continue;
                }
            }
        }
    }

    void get_account(int ac_no)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (acc[i].get_account_number() == ac_no)
            {
                acc[i].to_string();
                transaction[i].to_string();
            }
        }
    }
};

class Application : public Bank
{
public:
    Bank bk;
    int d, m, y;
    int ac_no, amt;
    void start_app()
    {
        int c;
        cout << "Select: " << endl;
        cout << "0: Add Account" << endl;
        cout << "1: Make Deposit" << endl;
        cout << "2: Make Withdrawal" << endl;
        cout << "3: Check Account" << endl;
        cout << "4: Exit" << endl;
        cin >> c;
        switch (c)
        {
        case 0:
            bk.add_account();
            break;
        case 1:
            cout << "Enter Account Number : ";
            cin >> ac_no;
            cout << "Enter The Amount : ";
            cin >> amt;
            cout << "Enter Date : ";
            cin >> y;
            cin.get();
            cin >> m;
            cin.get();
            cin >> d;
            cin.get();

            bk.make_deposit(ac_no, amt, d, m, y);
            break;
        case 2:
            cout << "Enter Account Number : ";
            cin >> ac_no;
            cout << "Enter The Amount : ";
            cin >> amt;
            cout << "Enter Date : ";
            cin >> y;
            cin.get();
            cin >> m;
            cin.get();
            cin >> d;
            cin.get();
            bk.make_withdraw(ac_no, amt, d, m, y);
            break;
        case 3:
            int ac_no;
            cout << "Enter account number: ";
            cin >> ac_no;
            bk.get_account(ac_no);
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }
};