Bhai, tere Banking System ke example se teeno cheezein samajhte hain: class ke andar record delete karna, login karne wale ko Admin/User ke roop mein pehchanna, aur `map` / `unordered_map` se unique account entries rakhna.

Sabse pehle ek important difference:

- Class account ka data aur operations manage karegi.
- Role batayega ki logged-in person Admin hai ya normal User.
- Data structure accounts ko store aur search karne mein help karega.

## 1. Class mein normal record delete kaise karein?

Tere pehle code mein `Bank ba[100]` array aur `cnt` variable tha. Agar array use kar raha hai, toh kisi record ko delete karne ke baad baaki records ko ek position left shift kar sakta hai.

Example: account index `1` delete karna hai.

```
void deleteAccount(int index) {
    if (index < 0 || index >= cnt) {
        cout << "Invalid account\n";
        return;
    }

    for (int i = index; i < cnt - 1; i++) {
        ba[i] = ba[i + 1];
    }

    cnt--;
    cout << "Account deleted\n";
}
```

Ye function tab kaam karega jab `ba` aur `cnt` uske scope mein available hon, jaise `Bank` class ke member variables.

Lekin `ba[100]` array ke saath ek limitation hai: deleted record ke baad ke records shift karne padte hain. Isi kaam ke liye `vector` aur `map` jaise alternatives useful hain.

## 2. `vector`, `map`, `unordered_map` — kaunsa use karein?

## Data structures comparison

`vector`

Index-based

Records list mein store hote hain. Search usually linear hoti hai. Delete karne par elements shift ho sakte hain.

```
vector<int> accounts = {1001, 1002, 1003};
accounts.push_back(1004);
accounts.erase(accounts.begin() + 1);
```

`map`

Sorted keys

Har key unique hoti hai aur keys sorted order mein rehti hain. Search, insertion aur deletion O(log n) hote hain.

```
map<int, string> accounts;
accounts[1001] = "Rahul";
accounts[1002] = "Aman";
accounts.erase(1001);
```

`unordered_map`

Fast lookup

Keys unique hoti hain, lekin sorted nahi hoti. Search, insertion aur deletion average O(1) hote hain.

```
unordered_map<int, string> accounts;
accounts[1001] = "Rahul";
accounts[1002] = "Aman";
accounts.erase(1001);
```

Tere banking project ke liye: account number ko key bana kar `unordered_map` use karna ek achha option hai.

## 3. Unique account entry kaise rakhein?

Maan le account number `1001` pehle se exist karta hai. Tu nahi chahta ki same account number dobara add ho.

```
#include <iostream>
#include <unordered_map>
using namespace std;

class BankAccount {
public:
    string name;
    double balance;

    BankAccount(string n, double b) {
        name = n;
        balance = b;
    }
};

int main() {
    unordered_map<int, BankAccount> accounts;

    auto result = accounts.emplace(
        1001, BankAccount("Rahul", 5000)
    );

    if (result.second) {
        cout << "Account created\n";
    } else {
        cout << "Account already exists\n";
    }

    auto result2 = accounts.emplace(
        1001, BankAccount("Aman", 2000)
    );

    if (!result2.second) {
        cout << "Duplicate account rejected\n";
    }
}
```

`emplace()` ka result check karne ka matlab:

- `result.second == true`: nayi entry insert hui.
- `result.second == false`: woh key pehle se exist karti thi.

Isliye duplicate key se existing account overwrite nahi hoga.

### Search aur delete

```
// Search
auto it = accounts.find(1001);

if (it != accounts.end()) {
    cout << it->second.name << '\n';
    cout << it->second.balance << '\n';
} else {
    cout << "Account not found\n";
}

// Delete
size_t deleted = accounts.erase(1001);

if (deleted == 1) {
    cout << "Account deleted\n";
} else {
    cout << "Account not found\n";
}
```

Yaad rakh: `it->first` key hai, aur `it->second` us key se associated value hai.

## 4. Admin aur normal user ko kaise pehchanein?

Iske liye `enum class Role` use kar sakta hai. Har login user ke saath uska role store hoga.

```
enum class Role {
    ADMIN,
    USER
};

class LoginUser {
public:
    string username;
    string password;
    Role role;

    LoginUser(string u, string p, Role r)
        : username(u), password(p), role(r) {}
};
```

Ab users ko username se store kar:

```
unordered_map<string, LoginUser> users;

users.emplace(
    "admin", LoginUser("admin", "admin123", Role::ADMIN)
);

users.emplace(
    "rahul", LoginUser("rahul", "rahul123", Role::USER)
);
```

Login ke waqt:

```
string username, password;

cout << "Username: ";
cin >> username;

cout << "Password: ";
cin >> password;

auto it = users.find(username);

if (it != users.end() &&
    it->second.password == password) {

    Role currentRole = it->second.role;

    if (currentRole == Role::ADMIN) {
        cout << "Admin Dashboard\n";
    } else {
        cout << "User Dashboard\n";
    }

} else {
    cout << "Invalid username or password\n";
}
```

Is example mein:

- `admin` login karega toh Admin Dashboard milega.
- `rahul` login karega toh User Dashboard milega.
- Galat username/password par login reject hoga.

Important: Ye sirf learning demo hai. Real application mein passwords ko plain text mein store mat karna; password hashing aur secure authentication use karna. Admin role bhi trusted, protected account data se aana chahiye.

## 5. Admin-only delete ko kaise enforce karein?

Sirf dashboard se delete option hide karna sufficient nahi hai. Delete function ke andar permission check hona chahiye.

```
void deleteAccount(
    int accountNumber,
    Role currentRole,
    unordered_map<int, BankAccount>& accounts
) {
    if (currentRole != Role::ADMIN) {
        cout << "Access denied\n";
        return;
    }

    if (accounts.erase(accountNumber) == 1) {
        cout << "Account deleted\n";
    } else {
        cout << "Account not found\n";
    }
}
```

Isse normal user delete function call karne ki koshish kare, tab bhi operation reject ho jayega.

## 6. Quick revision

| Requirement                     | Best starting option               |
| ------------------------------- | ---------------------------------- |
| Duplicate account numbers rokna | `map` / `unordered_map`            |
| Account number se fast lookup   | `unordered_map`                    |
| Keys sorted chahiye             | `map`                              |
| Simple list of records          | `vector`                           |
| Login user ko identify karna    | `unordered_map<string, LoginUser>` |
| Admin/User permissions          | `enum class Role`                  |
| Record delete karna             | `erase()`                          |

Bhai, ek concept aur yaad rakh: `unordered_map` key ko unique rakhta hai, lekin customer ka naam unique nahi banata. Do customers ka naam Rahul ho sakta hai; account number unique hona chahiye.

Tere project ke liye meri recommendation: `unordered_map<int, BankAccount>` mein accounts store kar aur `unordered_map<string, LoginUser>` mein login users. Isse search, duplicate checking aur deletion ka code kaafi simple ho jayega.