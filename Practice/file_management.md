Bhai, ab tu Banking System ko next level par le ja raha hai. 🔥 Tujhe 2 cheezein seekhni hain:

1. File Management in C++ — data ko file mein save, open, read, add, update aur delete karna.
2. Admin & User Dashboard — admin ko special permissions dena, normal user ko sirf allowed operations dena.

Dono ko tere Banking Management System ke example se samajhte hain.

# 1. C++ mein file kaise open aur manage karte hain?

C++ mein `<fstream>` library use hoti hai.

| Class      | Kaam                      |
| ---------- | ------------------------- |
| `ofstream` | File mein data likhna     |
| `ifstream` | File se data read karna   |
| `fstream`  | Read aur write dono karna |

## Example: File create karna aur data add karna

```
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("accounts.txt", ios::app);

    if (!file) {
        cout << "File open failed\n";
        return 1;
    }

    file << "1001 Rahul 5000\n";
    file.close();

    cout << "Data saved successfully\n";
    return 0;
}
```

Samajh:

- `accounts.txt` file open hogi.
- `ios::app` ka matlab existing data ko delete kiye bina end mein naya data add karna.
- `file << ...` data file mein likhta hai.
- `close()` file close karta hai.

Agar file exist nahi karti, toh `ofstream` use karne par aam taur par file create ho jaati hai.

## File se data read kaise karein?

```
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("accounts.txt");

    if (!file) {
        cout << "File not found\n";
        return 1;
    }

    string line;

    while (getline(file, line)) {
        cout << line << '\n';
    }

    file.close();
    return 0;
}
```

`getline(file, line)` file ki har line read karta hai.

## File update kaise karein?

Maan le file mein ye data hai:

```
1001 Rahul 5000
1002 Aman 3000
1003 Priya 8000
```

Tu Rahul ka balance ₹5,000 se ₹7,000 karna chahta hai.

Simple text file mein beech ka data update karne ka beginner-friendly tareeka:

1. Original file read kar.
2. Har record ko temporary storage mein load kar.
3. Jis account ko update karna hai, uska balance modify kar.
4. Temporary file mein saara updated data likh.
5. File successfully write hone ke baad original file ko replace kar.

Example concept:

```
accounts.txt  → read all records
              → update account 1001
              → write updated records
temp.txt      → updated data
              → replace accounts.txt
```

Important: `ios::app` se existing record update nahi hota; woh sirf end mein data add karta hai. Production application mein crash-safe replacement aur data integrity ka dhyan rakhna chahiye.

# 2. Banking system mein data kaise store karein?

Har account ka record file mein rakh sakta hai.

```
AccountNumber Name Age Balance
1001 Rahul 20 5000
1002 Aman 21 3000
1003 Priya 20 8000
```

Tere program ke functions kuch aise honge:

| Function            | Kaam                                    |
| ------------------- | --------------------------------------- |
| `createAccount()`   | Naya record add kare                    |
| `searchAccount()`   | Account number se record find kare      |
| `displayAccounts()` | Saare records dikhaye                   |
| `updateAccount()`   | Name, age ya doosri details modify kare |
| `deposit()`         | Balance badhaye                         |
| `withdraw()`        | Balance ghataaye                        |
| `deleteAccount()`   | Record remove kare                      |

Ek real banking system mein PIN ko plain text mein file par save nahi karna chahiye. Academic demo ke liye bhi PIN ko balance aur customer details se alag rakhna better design hai.

# 3. Admin aur normal user dashboard kaise banayein?

Isko role-based access control kehte hain.

Login System

Username + Password verification

Admin Dashboard

Create account

Search any account

Update / delete account

View all accounts

Manage users

User Dashboard

View own account

Deposit money

Withdraw money

Change own PIN

View own history

## 4. C++ mein roles ka basic implementation

Ek `enum` bana sakte hain:

```
enum class Role {
    ADMIN,
    USER
};
```

Login successful hone ke baad user ka role determine karo:

```
void dashboard(Role role) {
    if (role == Role::ADMIN) {
        cout << "\n=== ADMIN DASHBOARD ===\n";
        cout << "1. Create Account\n";
        cout << "2. Search Any Account\n";
        cout << "3. Update Account\n";
        cout << "4. Delete Account\n";
        cout << "5. Display All Accounts\n";
    }
    else {
        cout << "\n=== USER DASHBOARD ===\n";
        cout << "1. View My Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Change PIN\n";
        cout << "5. Transaction History\n";
    }
}
```

Isse menu alag ho jayega. Lekin sirf menu hide karna security nahi hai. Agar normal user kisi tarah `deleteAccount()` call kar de, toh operation phir bhi block hona chahiye.

Isliye actual operation ke andar bhi permission check karo:

```
bool canDeleteAccount(Role role) {
    return role == Role::ADMIN;
}
```

Use:

```
if (canDeleteAccount(currentRole)) {
    // Delete account
}
else {
    cout << "Access denied\n";
}
```

Yeh sirf concept demonstration hai. Real application mein authorization har sensitive operation par enforce karni chahiye; role ko user ke arbitrary input se trust nahi karna chahiye.

# 5. File management + dashboard ko combine kaise karna hai?

Recommended structure:

```
BankingSystem/
│
├── main.cpp
├── accounts.txt
├── users.txt
└── transactions.txt
```

- `accounts.txt` — account number, customer details, balance.
- `users.txt` — login identity aur role information; passwords plain text mein nahi.
- `transactions.txt` — deposits, withdrawals aur transaction records.

Program start hone par files se data load hoga. User login karega, role verify hoga, dashboard open hoga, operation execute hoga, aur successful changes ko persistent storage mein save kiya jayega.

Agar multiple users ek hi waqt par system use karenge, toh simple text files ki jagah SQLite ya kisi database ka use karna zyada reliable rahega.

## Ab teri practice

Bhai, pehle ek chhota program bana:

1. `accounts.txt` mein 3 accounts save kar.
2. Program start par unhe read karke display kar.
3. Admin ko naya account add karne de.
4. Normal user ko sirf apna account search karke dekhne de.
5. Normal user se delete operation attempt karwa aur `Access denied` dikha.

Isse file handling aur role-based access control dono practical ho jayenge.