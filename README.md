# Financial Harmony Banking Management System

This C++ program is a simple banking management system that allows users to perform various operations such as creating accounts, checking balances, depositing money, withdrawing money, deleting accounts, changing passwords, and allows admin access to view all account details.

## Instructions:

### Compiling and Running the Program:

1. Ensure you have a C++ compiler installed.
2. Compile the program using your C++ compiler.
3. Run the compiled executable file.

### Functionalities:

1. **Creating a New Account:**
   - Allows users to create a new account by providing a name, age, password, and initial deposit amount (minimum deposit: 100 rupees).

2. **Balance Inquiry and Account Info:**
   - Enables users to check their account balance and account details by entering their account number and password.

3. **Deposit Money:**
   - Users can deposit money into their accounts by specifying the account number and password, then entering the amount to deposit.

4. **Withdraw Money:**
   - Allows users to withdraw money from their accounts after providing the account number, password, and withdrawal amount (with a service charge of 25 rupees).

5. **Delete Account:**
   - Provides an option for users to delete their accounts. It prompts for the account number and password for confirmation.

6. **Change Password:**
   - Allows users to change their account password. Users need to enter their current password, specify a new password, and confirm the change.

7. **Admin Access:**
   - Accessible only through the admin password "whitepanther3715." It enables the admin to view all account details, including account names, numbers, and balances.

### Usage Notes:

- The program utilizes dynamic memory allocation for managing account details.
- Minimum deposit and withdrawal limits are set to maintain account integrity (100 rupees minimum deposit, withdrawal with a service charge).
- For admin access, the password is required and hardcoded in the program.

### Important Points:

- The program handles various user inputs and provides appropriate error messages for invalid inputs.
- File "data.txt" is used to store account details (appending details on program exit).

### Disclaimer:

- This code is a simplified banking management system for learning purposes and may not be suitable for real-world banking applications.
- Always use such systems in controlled environments and consider security implications before deployment.
