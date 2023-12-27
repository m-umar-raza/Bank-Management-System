#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>
using namespace std;

// Function prototypes
void displayMenu();
void accountInquiry(string* ptr_name, string* ptr_password, int* ptr_balance, int number);
void deposit(string* ptr_name, string* ptr_password, int* ptr_balance, int number);
void withdraw(string* ptr_name, string* ptr_password, int* ptr_balance, int number);
void deletion(string* ptr_name, string* ptr_password, int* ptr_balance, int number);
void admin(string* ptr_name, string* ptr_password, int* ptr_balance, int number);
void change_password(string* ptr_name, string* ptr_password, int number);

int main()
{
	// Initialize variables
	int number = 0;	// Number of accounts
	int opt;	// User's menu option
	int x = 0;	// Counter for account creation
	string* ptr_name = nullptr;	// Pointer to array storing account names
	int* ptr_balance = nullptr;	// Pointer to array storing account balances
	string* ptr_password = nullptr;	// Pointer to array storing account passwords

	// Welcome message
	cout << "\n\t\t\t\t   WELCOME TO \"FINANCIAL HARMONY BANKING MANAGEMENT SYSTEM\"" << endl;
	cout << "\t\t\t\t\t   A Symbol of Excellence and Pride\n\n\n\n\n";
	Sleep(1550);

	// Main program loop
	while (1)
	{
	back:
		// Display menu and get user input
		displayMenu();
		if (!(cin >> opt) || (opt < 1 || opt > 8))
		{
			cout << "Invalid Input!" << endl;
			cin.clear();	// Clear the error flag
			cin.ignore(80, '\n');	// Discard input buffer
			system("pause");
			goto back;
		}

		cin.ignore(80, '\n');
		string username;	//the name of the new user
		string userpassword;	//the password
		int userbalance;	//the balance the user want to deposit
		int age;
		// Menu options
		if (opt == 1)
		{
			// Account creation
		valid: cout << "\n\tPlease Enter Your Name\n ";
			getline(cin, username);
			if (username == "deleted")
			{
				cout << "\n\nInvalid name!" << endl;
				cin.clear();	// Clear the error flag
				cin.ignore(80, '\n');	// Discard input buffer
				system("pause");
				goto valid;
			}

			cout << "\n\tPlease Enter Your Age in Years: \n";

			if (!(cin >> age) || (age < 16 || age > 100))
			{
				cout << "\n\tInvalid Input!" << endl;
				cout << "The age must be an integer between 16 - 100" << endl;
				cin.clear();	// Clear the error flag
				cin.ignore(80, '\n');	// Discard input buffer
				system("pause");
				goto back;
			}

			cout << "\n\tSet Your Password\n";
			cin >> userpassword;
			cin.clear();	// Clear the error flag
			cin.ignore(80, '\n');	// Discard input buffer
		newback: cout << "\n\tEnter The Amount Of Money You Want To Deposit(Rs)\n";
			if (!(cin >> userbalance))
			{
				cout << "Invalid Input!" << endl;
				cin.clear();	// Clear the error flag
				cin.ignore(80, '\n');	// Discard input buffer
				system("pause");
				goto newback;
			}
			else
			{
				// Validate minimum balance requirement
				if (userbalance < 100)
				{
					cout << "\n\n\tERROR! Minimum deposit is 100 rupees.\n";
					goto newback;
				}
				else
				{
					// Increment counters
					x = x + 1;
					number = number + 1;

					// Create new dynamic arrays with increased size
					string* new_ptr_name = new string[x];
					string* new_ptr_password = new string[x];
					int* new_ptr_balance = new int[x];

					// Copy data from old arrays to new arrays
					for (int i = 0; i < x - 1; ++i)
					{
						new_ptr_name[i] = ptr_name[i];
						new_ptr_password[i] = ptr_password[i];
						new_ptr_balance[i] = ptr_balance[i];
					}

					// Add new account data to new arrays
					new_ptr_name[x - 1] = username;
					new_ptr_password[x - 1] = userpassword;
					new_ptr_balance[x - 1] = userbalance;

					// Delete old arrays
					delete[] ptr_name;
					delete[] ptr_password;
					delete[] ptr_balance;

					// Assign pointers to new arrays
					ptr_name = new_ptr_name;
					ptr_password = new_ptr_password;
					ptr_balance = new_ptr_balance;

					system("cls");
					// Display account creation success message
					cout << "\n*********CONGRATULATIONS!*******\n";
					cout << "\n*******ACCOUNT SUCCESSFULLY CREATED!*****\n" << endl;
					cout << "\n\t\tACCOUNT TITLE: " << "\"" << new_ptr_name[x - 1] << "\"" << endl;
					cout << "\n\t\tACCOUNT NUMBER: " << "\'" << number << "\'" << endl;
					cout << "\n\t\tBALANCE: " << "\'" << new_ptr_balance[x - 1] << "\'" << endl;
					cout << "\n*************************" << endl;
				}

				system("pause");
			}
		}
		else if (opt == 2)
		{
			// Account inquiry
			accountInquiry(ptr_name, ptr_password, ptr_balance, number);
			system("pause");
		}
		else if (opt == 3)
		{
			// Deposit money
			deposit(ptr_name, ptr_password, ptr_balance, number);
			system("pause");
		}
		else if (opt == 4)
		{
			// Withdraw money
			withdraw(ptr_name, ptr_password, ptr_balance, number);
			system("pause");
		}
		else if (opt == 5)
		{
			// Delete account
			deletion(ptr_name, ptr_password, ptr_balance, number);
			system("pause");
		}
		else if (opt == 6)
		{
			// Exit program
			cout << "\n\n\n_THANK YOU FOR TRUSTING OUR BANK_\n";
			cout << "\nFor any queries please contact\nBANK MANAGER: Asif Khan(03269799169)\t\t\t\t\tBANK SUPERVISOR: Muhammad Umar(03345818524)\n\n\n\n";
			fstream file;
			file.open("data.txt", ios::out | ios::app);
			file << "\n+------------------------------------------------------------------------------------------+\n";
			file << "|          ACCOUNTS            |         ACCOUNT_NOs        |            BALANCE           |\n";
			file << "|                              |                            |                              |\n";

			// Loop through the accounts and write details to the file
			for (int i = 0; i < number; i++) {
				if (ptr_name[i] == "deleted") {
					continue;
				}

				// Display account details in a tabular format
				file << "| " << setw(20) << ptr_name[i] << "         |   " << setw(16) << i + 1 << "         |     " << setw(16) << ptr_balance[i] << "         |\n";
			}

			file << "+------------------------------------------------------------------------------------------+\n";

			file.close(); // Close the file
			system("pause");
			break;
		}
		else if (opt == 7)
		{
			// password change
			change_password(ptr_name, ptr_password, number);
			system("pause");
		}
		else if (opt == 8)
		{
			// Admin access
			admin(ptr_name, ptr_password, ptr_balance, number);
			system("pause");
		}
		else
		{
			// Invalid input
			cout << "\n\tINVALID INPUT!!";
			system("pause");
		}
	}

	// Clean up dynamic memory
	delete[] ptr_name;
	delete[] ptr_password;
	delete[] ptr_balance;
	return 0;
}

// Function to display menu
void displayMenu()
{
	system("cls");

	cout << "\n\n\t\t+-------------------------------------------------------------------------+\n";
	cout << "\t\t|                 CHOOSE WHICH OPERATION TO PERFORM                       |\n";
	cout << "\t\t+-------------------------------------------------------------------------+\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t| 1. Make a new Account              2. Balance Inquiry and Account Info  |\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t|-------------------------------------------------------------------------|\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t| 3. Add money to account            4. Withdraw money from your account  |\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t|-------------------------------------------------------------------------|\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t| 5. Delete your account             6. EXIT                              |\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t|-------------------------------------------------------------------------|\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t| 7. Change Password                 8. Accounts Info (only admin)        |\n";
	cout << "\t\t|                                                                         |\n";
	cout << "\t\t+-------------------------------------------------------------------------+\n";
	cout << "\n\t\t\t\t\tENTER YOUR OPTION: ";
}

// Function for account inquiry
void accountInquiry(string* ptr_name, string* ptr_password, int* ptr_balance, int number)
{
	int an;
	string pw;
newback_2:
	cout << "\n\n\tEnter your account number: " << endl;

	if (!(cin >> an))
	{
		cout << "Invalid Input!" << endl;
		cin.clear();	// Clear the error flag
		cin.ignore(80, '\n');	// Discard input buffer
		system("pause");
		goto newback_2;
	}

	if (ptr_name[an - 1] == "deleted")
	{
		cout << "\n\n\tThis account no longer exists!!\n\n" << endl;
	}
	else
	{
		if (an > number || an < 1)
		{
			cout << "\n\n\tNO SUCH ACCOUNT EXISTS!\n";
		}
		else
		{
			cout << "\n\n\tEnter your password:" << endl;
			cin >> pw;
			if (pw != ptr_password[an - 1])
			{
				cout << "\n\t\tWRONG PASSWORD!\n" << endl;
			}
			else
			{
				system("cls");
				// Display account information
				cout << "\n\t\tACCOUNT TITLE\t\t" << endl;
				cout << "\t\t" << ptr_name[an - 1] << endl;
				cout << "\n\t\tTOTAL BALANCE\t\t" << endl;
				cout << "\t\t" << ptr_balance[an - 1] << endl;
				cout << "\n*************************" << endl;
			}
		}
	}
}

// Function for depositing money
void deposit(string* ptr_name, string* ptr_password, int* ptr_balance, int number)
{
	int an2;
	string pw2;
	int money;
newback_3:
	cout << "\n\n\tEnter your account number: " << endl;

	if (!(cin >> an2))
	{
		cout << "Invalid Input!" << endl;
		cin.clear();	// Clear the error flag
		cin.ignore(80, '\n');	// Discard input buffer
		system("pause");
		goto newback_3;
	}

	if (ptr_name[an2 - 1] == "deleted")
	{
		cout << "\n\nThis account no longer exists!!\n\n" << endl;
	}
	else
	{
		if (an2 > number || an2 < 1)
		{
			cout << "\n\n\tNO SUCH ACCOUNT EXISTS!\n";
		}
		else
		{
			cout << "\n\nEnter your password:" << endl;
			cin >> pw2;
			if (pw2 != ptr_password[an2 - 1])
			{
				cout << "\n\t\tWRONG PASSWORD!\n" << endl;
			}
			else
			{
			newback_4: cout << "\n\nHow much money do you want to add?\n";

				if (!(cin >> money))
				{
					cout << "Invalid Input!" << endl;
					cin.clear();	// Clear the error flag
					cin.ignore(80, '\n');	// Discard input buffer
					system("pause");
					goto newback_4;
				}

				if (money < 100)
				{
					cout << "\n\n\tYou need to add at least 100 rupees\n";
					goto newback_4;
				}
				else
				{
					// Update account balance
					ptr_balance[an2 - 1] = ptr_balance[an2 - 1] + money;
					system("cls");
					// Display success message
					cout << "\n\nAmount Successfully Added!\n";
					cout << "\t\tACCOUNT TITLE\t" << endl;
					cout << "\t\t" << ptr_name[an2 - 1] << "\t\t" << endl;
					cout << "\nYour new balance is: " << ptr_balance[an2 - 1] << " Rupees" << endl;
					cout << "\n*************************" << endl;
				}
			}
		}
	}
}

// Function for withdrawing money
void withdraw(string* ptr_name, string* ptr_password, int* ptr_balance, int number)
{
	int an2;
	string pw2;
	int money;
newback_5:
	cout << "\n\n\tEnter your account number: " << endl;
	if (!(cin >> an2))
	{
		cout << "Invalid Input!" << endl;
		cin.clear();	// Clear the error flag
		cin.ignore(80, '\n');	// Discard input buffer
		system("pause");
		goto newback_5;
	}

	if (an2 > number || an2 < 1)
	{
		cout << "\n\n\tNO SUCH ACCOUNT EXISTS!\n";
	}
	else if (ptr_name[an2 - 1] == "deleted")
	{
		cout << "\n\nThis account no longer exists!!\n\n" << endl;
		goto newback_5;
	}
	else
	{
		cout << "\n\n\tEnter your password" << endl;
		cin >> pw2;

		if (pw2 != ptr_password[an2 - 1])
		{
			cout << "\n\t\tWRONG PASSWORD!\n" << endl;
		}
		else
		{
		newback_6: cout << "\n\n\tHow much money do you want to withdraw?\n";
			if (!(cin >> money))
			{
				cout << "Invalid Input!" << endl;
				cin.clear();	// Clear the error flag
				cin.ignore(80, '\n');	// Discard input buffer
				system("pause");
				goto newback_6;
			}

			if (money <= ptr_balance[an2 - 1] - 25 && money > 0)
			{
				// Update account balance
				ptr_balance[an2 - 1] = ptr_balance[an2 - 1] - money - 25;
				system("cls");
				// Display success message
				cout << "\t\tACCOUNT TITLE\t" << endl;
				cout << "\t\t" << ptr_name[an2 - 1] << "\t\t" << endl;
				cout << "\n\n\t___Amount successfully withdrawn!___\n";
				cout << "\n\n\tYour new balance is: " << ptr_balance[an2 - 1] << " Rupees" << " after deducting 25 Rs as service charges!" << endl;
			}
			else
			{
				cout << "\n\tTHIS TRANSACTION IS NOT POSSIBLE!" << endl;
			}
		}
	}
}

// Function for deleting account
void deletion(string* ptr_name, string* ptr_password, int* ptr_balance, int number)
{
	int an2;
	string pw2;
newback_7:
	cout << "ACCOUNT DELETION" << endl;
	cout << "\nEnter your account number" << endl;
	if (!(cin >> an2))
	{
		cout << "Invalid Input!" << endl;
		cin.clear();	// Clear the error flag
		cin.ignore(80, '\n');	// Discard input buffer
		system("pause");
		goto newback_7;
	}

	if (ptr_name[an2 - 1] == "deleted")
	{
		cout << "\nThis account no longer exists!!\n" << endl;
		goto newback_7;
	}
	else
	{
		if (an2 > number || an2 < 1)
		{
			cout << "\n\n\tNo such account exists!\n";
			goto newback_7;
		}
		else
		{
			cout << "\n\nEnter your password:" << endl;
			cin >> pw2;
			if (pw2 != ptr_password[an2 - 1])
			{
				cout << "\n\tWRONG PASSWORD!\n" << endl;
				cout << "\n*******************\n";
			}
			else
			{
				char ans;
				cout << "\n\nAre you sure you want to delete your account? (y/n)" << endl;
				cin >> ans;
				if (ans == 'n')
				{
					cout << "OK!" << endl;
				}
				else if (ans == 'y')
				{
					// Mark account as deleted
					ptr_name[an2 - 1] = "deleted";
					// Display balance before deleting
					system("cls");
					cout << "\nPlease receive your deposited money: " << ptr_balance[an2 - 1] << " Rupees";
					cout << "\n____ACCOUNT SUCCESSFULLY DELETED!____\n" << endl;
				}
				else
				{
					cout << "\n_____INVALID INPUT!_____\n";
				}
			}
		}
	}
}

// Function for admin access
void admin(string* ptr_name, string* ptr_password, int* ptr_balance, int number)
{
	string pw;
	cout << "\n\n\tTHIS CAN ONLY BE ACCESSED BY THE ADMIN\n";
	cout << "\n\n\tEnter the ADMIN Password to proceed \n";
	cin >> pw;
	if (pw != "whitepanther3715")
	{
		cout << "WRONG PASSWORD\nYOU CANNOT BE GIVEN ACCESS";
	}
	else
	{
		system("cls");
		// Display all account information
		cout << setw(15) << "ACCOUNTS" << setw(20) << "ACCOUNT_NOs" << setw(15) << "BALANCE" << endl;
		cout << endl;
		for (int i = 0; i < number; i++)
		{
			if (ptr_name[i] == "deleted")
			{
				continue;
			}

			// Display account details
			cout << setw(15) << ptr_name[i] << setw(20) << i + 1 << setw(15) << ptr_balance[i] << endl;
		}
	}
}

// Function to change password
void change_password(string* ptr_name, string* ptr_password, int number)
{
	int an2;
	string pw2;
	string new_pass;
	char ans;
newback_8:
	cout << "\n\n\tEnter your account number: " << endl;
	if (!(cin >> an2))
	{
		cout << "Invalid Input!" << endl;
		cin.clear();	// Clear the error flag
		cin.ignore(80, '\n');	// Discard input buffer
		system("pause");
		goto newback_8;
	}

	if (an2 > number || an2 < 1)
	{
		cout << "\n\n\tNO SUCH ACCOUNT EXISTS!\n";
	}
	else if (ptr_name[an2 - 1] == "deleted")
	{
		cout << "\n\nThis account no longer exists!!\n\n" << endl;
	}
	else
	{
		cout << "\n\n\tEnter your old password" << endl;
		cin >> pw2;

		if (pw2 != ptr_password[an2 - 1])
		{
			cout << "\n\t\tWRONG PASSWORD!\n" << endl;
		}
		else
		{
			cout << "\n\n\tEnter your new password " << endl;
			cin >> new_pass;
			cin.clear();	// Clear the error flag
			cin.ignore(80, '\n');	// Discard input buffer
			cout << "\n\n\tAre you sure you want to change?(y/n)" << endl;
			cin >> ans;
			if (ans == 'y')
			{
				ptr_password[an2 - 1] = new_pass;	//assigning the new password 
				system("cls");
				cout << "\n\n\tPASSWORD SUCCESSFULLY CHANGED!" << endl;
			}
			else if (ans == 'n')
			{
				cout << "\n\n\tOK! Password not changed!";
			}	//in case the yser enters no
			else
			{
				cout << "INVALID INPUT";
			}
		}
	}
}