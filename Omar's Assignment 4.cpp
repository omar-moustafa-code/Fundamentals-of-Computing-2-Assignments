#include <iostream>
using namespace std;

class Account {
protected:
    string CustomerID;
    string CustomerName;
    double balance;
    double saving_min_amount;
    double current_min_amount;
    double CD_min_amount;
public:
    Account() {
        CustomerID = "";
        CustomerName = "";
        balance = 0.0;
        saving_min_amount = 0.0;
        current_min_amount = 0.0;
        CD_min_amount = 0.0;
    }
    ~Account () {

    }
    void set_Customer_ID(string id) {
        CustomerID = id;
    }
    void set_Customer_Name(string n) {
        CustomerName = n;
    }
    void set_balance (double b) {
        balance = b;
    }
    void set_saving_min_amount(double sma) {
        saving_min_amount = sma;
    }
    void set_current_min_amount(double cma) {
        current_min_amount = cma;
    }
    void set_CD_min_amount(double cdma) {
        CD_min_amount = cdma;
    }
    void print_balance() {
        cout << "Balance: " << balance << endl;
    }
    double get_balance() {
        return balance;
    }
    double get_saving_minimum_amount() {
        return saving_min_amount;
    }
    double get_current_minimum_amount() {
        return current_min_amount;
    }
    double get_CD_min_amount() {
        return CD_min_amount;
    }
    bool open_account(double initial_balance, double minimum_amount) {
        if (initial_balance >= minimum_amount) {
            balance = initial_balance;
            saving_min_amount = minimum_amount;
            current_min_amount = minimum_amount;
            CD_min_amount = minimum_amount;
            return true;
    } else {
            return false;
        }
    }
    void DisplayAccount() {
        cout << "Information of Newly Opened Account: " << endl;
        cout << "Name: " << CustomerName << endl;
        cout << "ID: " << CustomerID << endl;
        cout << "Balance: " << balance << endl;
        cout << "Minimum Saving Amount: " << saving_min_amount << endl;
        cout << "Minimum Current Amount: " << current_min_amount << endl;
        cout << "Minimum CD Amount: " << CD_min_amount << endl;
    }
};

class Saving_Account : public Account {
private:
    double minimum_amount;
    double deposit_amount;
    double withdrawal_amount;
    double interest_rate;
    double interest;
    double saving_balance;
    string Account_Number;
    string Account_Name;
public:
    Saving_Account() {
        minimum_amount = 0.0;
        deposit_amount = 0.0;
        withdrawal_amount = 0.0;
        interest_rate = 0.0;
        interest = 0.0;
        saving_balance = 0.0;
        Account_Number = "";
        Account_Name = "";
    }
    ~Saving_Account() {

    }
    void set_interest(double i) {
        interest = i;
    }
    void set_minimum_amount(double deposit) {
        minimum_amount = deposit;
    }
    void set_deposit_amount(double d) {
        deposit_amount = d;
    }
    bool check_withdrawal(double w) {
        // not allowed to exceed the balance
        if (w <= balance) {
            cout << "Balance Sufficient. You have withdrawn $" << w << endl;
            balance = balance - w;
            return true;
        } else {
            cout << "Error. Withdrawal Exceeds Balance." << endl;
            return false;
        }
    }
    void set_withdrawal_amount(double withdrawal) {
        withdrawal_amount = withdrawal;
    }
    void set_interest_rate(double ir) {
        interest_rate = ir;
    }
    void set_saving_balance(double sb) {
        saving_balance = sb;
    }
    void set_account_number(string an) {
        Account_Number = an;
    }
    bool open_account(double amount) {
        if (amount >= saving_min_amount) {
            balance = amount;
            cout << "Success! Your New Account Has $" << balance << endl;
            return true;
        } else {
            cout << "Error. Unable to Open Account." << endl;
            return false;
        }
    }
    double get_interest() {
        return interest;
    }
    double get_interest_rate() {
        return interest_rate;
    }
    double get_minimum_amount() {
        return minimum_amount;
    }
    double get_deposit_amount() {
        return deposit_amount;
    }
    double get_withdrawal_amount() {
        return withdrawal_amount;
    }
    double get_saving_balance() {
        return saving_balance;
    }
    void compute_interest() {
        interest = balance * interest_rate / 100;
        cout << "Your Interest Is: " << interest << endl;
    }
    void update_balance() {
        balance += deposit_amount;
        cout << "Success! You Updated Balance Is: " << balance << endl;
    }
};

typedef struct {
    int day;
    int month;
    int year;
} date;
typedef enum {monthly, quarterly, yearly} frequency;

class Certificate_Deposit : public Saving_Account {
private:
    string Account_Number;
    string Account_Name;
    double amount;
    double interest_rate;
    double interest;
    int duration_in_months;
    int interest_payment;
    date dat;
public:
    Certificate_Deposit() {
        Account_Number = "";
        Account_Name = "";
        amount = 0.0;
        interest_rate = 0.0;
        interest = 0;
        duration_in_months = 0;
        interest_payment = 0;
    }
    ~Certificate_Deposit() {

    }
    void set_amount(double amo) {
        amount = amo;
    }
    void set_interest_payment(int ip) {
        interest_payment = ip;
    }
    void set_duration_in_months(int d) {
        duration_in_months = d;
    }
    void set_interest(double i) {
        interest = i;
    }
    void set_interest_rate(double ir) {
        interest_rate = ir;
    }
    double compute_interest() {
        interest = amount * interest_rate / 100;
    }
    double get_amount() {
        return amount;
    }
    double get_interest_rate() {
        return interest_rate;
    }
    int get_duration_in_months() {
        return duration_in_months;
    }
    int get_interest_payment() {
        return interest_payment;
    }
    date get_dat() {
        return dat;
    }
    double get_interest() {
        return interest;
    }
};

class Current_Account : public Account {
protected:
    string Account_Number;
    string Account_Name;
    double minimum_amount;
    double current_balance;
public:
    Current_Account() {
        Account_Number = "";
        Account_Name = "";
        minimum_amount = 0.0;
        current_balance = 0.0;
    }
    ~Current_Account() {

    }
    void update_balance(double amount) {
        current_balance += amount;
    }
    void set_current_balance(double cb) {
        current_balance = cb;
    }
    double get_current_balance() {
        return current_balance;
    }
    bool open_account(double amount) {
        if (amount >= minimum_amount) {
            balance = amount;
            current_balance = amount;
            cout << "Success! Your New Account Has $" << balance << endl;
            return true;
        } else {
            cout << "Error. Unable to Open Account." << endl;
            return false;
        }
    }
    void set_amount(double a) {
        minimum_amount = a;
    }
    bool withdraw_from_current(double w) {
        // not allowed to exceed the balance
        if (w <= balance) {
            cout << "Balance Sufficient. You have withdrawn $" << w << endl;
            balance = balance - w;
            return true;
        } else {
            cout << "Error. Withdrawal Exceeds Balance." << endl;
            return false;
        }
    }
};


int main() {

    Account a;
    string my_name;
    string my_ID;
    double min_amount;
    double balance;
    double saving_min_amount;
    double cd_min_amount;
    int view_account;

    Saving_Account s;
    double deposit;
    double withdraw;
    double saving_interest;
    double saving_interest_rate;
    double saving_deposit_to_update;

    Current_Account c;
    float current_withdraw;

    Certificate_Deposit cd;
    double update;
    double cd_interest;
    double cd_interest_rate;
    double cd_amount;
    string certificate_name;
    string certificate_ID;
    double certificate_amount;
    int months;
    double add_to_saving;

    int choice = -1;

    while (choice != 0) {
        cout << "--------- User Interface ---------\n"
             << "Please choose an option:\n"
             << "1: Open a New Account\n"
             << "2: Deposit an amount in the Saving Account\n"
             << "3: Deposit an amount in the Current Account\n"
             << "4: Purchase a Certificate Account\n"
             << "5: Withdraw from the Saving Account\n"
             << "6: Withdraw from the Current Account\n"
             << "7: Compute Interest at the end of a month and Update Balance\n"
             << "8: Compute Interest of a CD and add the Interest to Saving/Current Account\n"
             << "0: Exit\n";

        cout << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                // Open an account
                cout << "Enter Your Name: " << endl;
                cin >> my_name;
                a.set_Customer_Name(my_name);
                cout << "Enter ID: " << endl;
                cin >> my_ID;
                a.set_Customer_ID(my_ID);
                cout << "Enter Balance: " << endl;
                cin >> balance;
                a.set_balance(balance);
                cout << "Enter Current Minimum Amount: " << endl;
                cin >> min_amount;
                a.set_current_min_amount(min_amount);
                a.open_account(balance, min_amount);
                cout << "Enter Saving Minimum Amount: " << endl;
                cin >> saving_min_amount;
                a.set_saving_min_amount(saving_min_amount);
                cout << "Enter CD Minimum Amount: " << endl;
                cin >> cd_min_amount;
                a.set_CD_min_amount(cd_min_amount);
                cout << "Account Successfully Opened!" << endl;
                cout << endl;

                cout << "Would You Like To View The Information You Just Inserted? " << endl;
                cin >> view_account;

                if (view_account == 1) {
                    a.DisplayAccount();
                } else {
                    cout << "Very Well." << endl;
                }

                cout << endl;

                break;
            case 2:
                // Deposit in the saving account
                cout << "How Much Would You Like To Deposit Into Your Savings Account? " << endl;
                cin >> deposit;
                s.set_deposit_amount(deposit);
                cout << endl;
                break;
            case 3:
                // Deposit in the current account
                cout << "How Much Would You Like To Deposit Into Your Current Account? " << endl;
                cin >> update;
                c.update_balance(update);
                cout << "Success! Your Updated Balance Is: " << c.get_current_balance() << endl;
                cout << endl;
                break;
            case 4:
                // Purchase a certificate account
                cout << "How Much Would You Like To Add To Your New Certificate Account? " << endl;
                cin >> certificate_amount;
                cd.set_amount(certificate_amount);
                cout << "This Will Be Paid Over How Many Months? " << endl;
                cin >> months;
                cd.set_duration_in_months(months);
                cout << "Certificate Account Successfully Purchased!" << endl;
                cout << endl;
                break;
            case 5:
                // Withdraw from the saving account
                cout << "How Much Would You Like To Withdraw From Your Savings Account? " << endl;
                cin >> withdraw;
                s.check_withdrawal(withdraw);
                cout << endl;
                break;
            case 6:
                // Withdraw from the current account
                cout << "How Much Would You Like To Withdraw From Your Current Account? " << endl;
                cin >> current_withdraw;
                c.withdraw_from_current(current_withdraw);
                cout << endl;
                break;
            case 7:
                // Compute interest at the end of a month and update balance
                cout << "Enter Your Interest: " << endl;
                cin >> saving_interest;
                s.set_interest(saving_interest);
                cout << "Enter Interest Rate: " << endl;
                cin >> saving_interest_rate;
                s.set_interest_rate(saving_interest_rate);
                cout << "Computed Interest: " << endl;
                s.compute_interest();
                cout << "Enter Deposit To Update Balance: " << endl;
                cin >> saving_deposit_to_update;
                s.set_deposit_amount(saving_deposit_to_update);
                s.update_balance();
                cout << endl;
                break;
            case 8:
                // Compute interest of a CD and add the interest to saving account
                cout << "Enter Amount Added To CD Account: " << endl;
                cin >> cd_amount;
                cd.set_amount(cd_amount);
                cout << "Enter Your Interest: " << endl;
                cin >> cd_interest;
                cd.set_interest(cd_interest);
                cout << "Enter Your Interest Rate: " << endl;
                cin >> cd_interest_rate;
                cd.set_interest_rate(cd_interest_rate);
                cout << "You Interest Is: " << cd.compute_interest();
                add_to_saving = cd.compute_interest();
                // Adding It To Saving Account
                cd.set_interest(add_to_saving); // Computed interest is set as the interest in the savings account
                cout << endl;
                break;
            case 0:
                // Exit the while loop
                cout << "Interface Closed. Thank You For Trusting Us!" << endl;
                cout << endl;
                break;
            default:
                cout << "Invalid Choice. Please Choose Again." << endl;
                cout << endl;
                break;
        }
    }

    return 0;

}

