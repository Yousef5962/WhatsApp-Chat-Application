#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// ========================
//       USER CLASS
// ========================
class User
{
private:
    string username;
    string password;
    string phoneNumber;
    string status;
    string lastSeen;

public:
    User()
    {
        // TODO: Implement default constructor
        username = "";
        password = "";
        phoneNumber = "";
        status = "";
        lastSeen = "";
    }

    User(string uname, string pwd, string phone)
    {
        // TODO: Implement parameterized constructor  (Done)
        username = uname;
        password = pwd;
        phoneNumber = phone;
    }

    string getUsername() const
    {
        // TODO: Implement getter   (Done)
        return username;
    }

    string getPhoneNumber() const
    {
        // TODO: Implement getter  (Done)
        return phoneNumber;
    }

    string getStatus() const
    {
        // TODO: Implement getter (Done)
        return status;
    }

    string getLastSeen() const
    {
        // TODO: Implement getter  (Done)
        return lastSeen;
    }

    void setStatus(string newStatus)
    {
        // TODO: Implement setter  (Done)
        status = newStatus;
    }

    void setPhoneNumber(string phone)
    {
        // TODO: Implement setter  (Done)
        phoneNumber = phone;
    }

    /*
    ✅ Simplest Use Case: Get Current Time as Readable String
     Steps:

        1- time(0) → get current time.
            time_t now = time(0);

        2- ctime() → convert it to readable format like:
            char* dt = ctime(&now);
            cout << "Current time: " << dt;
        "Thu Aug 7 01:45:23 2025"
    */
    void updateLastSeen()
    {
        // TODO: Implement last seen update  (Done)
        time_t now = time(0);         // Get current time
        char *datetime = ctime(&now); // Convert to string
        lastSeen = datetime;          // save in the lastSeen
        cout << "User: " << username << " last seen in: " << lastSeen << endl;
    }

    bool checkPassword(string pwd) const
    {
        // TODO: Implement password check  (Done)
        if (password == pwd)
            return true;
        return false;
    }

    void changePassword(string newPwd)
    {
        // TODO: Implement password change  (Done)
        password = newPwd;
    }
};

int main() {
    // Example usage of User class
    User user("john_doe", "password123", "1234567890");
    return 0;
}