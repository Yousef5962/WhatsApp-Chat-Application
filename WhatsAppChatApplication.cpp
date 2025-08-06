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

// ========================
//      MESSAGE CLASS
// ========================
class Message
{
private:
    string sender;
    string content;
    string timestamp;
    string status;
    Message *replyTo;

public:
    Message()
    {
        // TODO: Implement default constructor
    }

    Message(string sndr, string cntnt)
    {
        // TODO: Implement parameterized constructor
    }

    string getContent() const
    {
        // TODO: Implement getter
        return "";
    }

    string getSender() const
    {
        // TODO: Implement getter
        return "";
    }

    string getTimestamp() const
    {
        // TODO: Implement getter
        return "";
    }

    string getStatus() const
    {
        // TODO: Implement getter
        return "";
    }

    Message *getReplyTo() const
    {
        // TODO: Implement getter
        return nullptr;
    }

    void setStatus(string newStatus)
    {
        // TODO: Implement setter
    }

    void setReplyTo(Message *msg)
    {
        // TODO: Implement setter
    }

    void updateTimestamp()
    {
        // TODO: Implement timestamp update
    }

    void display() const
    {
        // TODO: Implement message display
    }

    void addEmoji(string emojiCode)
    {
        // TODO: Implement emoji support
    }
};

// ========================
//       CHAT CLASS (BASE)
// ========================
class Chat
{
protected:
    vector<string> participants;
    vector<Message> messages;
    string chatName;

public:
    Chat()
    {
        // TODO: Implement default constructor
    }

    Chat(vector<string> users, string name)
    {
        // TODO: Implement parameterized constructor
    }

    void addMessage(const Message &msg)
    {
        // TODO: Implement message addition
    }

    bool deleteMessage(int index, const string &username)
    {
        // TODO: Implement message deletion
        return false;
    }

    virtual void displayChat() const
    {
        // TODO: Implement chat display
    }

    vector<Message> searchMessages(string keyword) const
    {
        // TODO: Implement message search
        return {};
    }

    void exportToFile(const string &filename) const
    {
        // TODO: Implement export to file
    }
};

// ========================
//     PRIVATE CHAT CLASS
// ========================
class PrivateChat : public Chat
{
private:
    string user1;
    string user2;

public:
    PrivateChat(string u1, string u2)
    {
        // TODO: Implement constructor
    }

    void displayChat() const override
    {
        // TODO: Implement private chat display
    }

    void showTypingIndicator(const string &username) const
    {
        // TODO: Implement typing indicator
    }
};

// ========================
//      GROUP CHAT CLASS
// ========================
class GroupChat : public Chat
{
private:
    vector<string> admins;
    string description;

public:
    GroupChat(vector<string> users, string name, string creator)
    {
        // TODO: Implement constructor
    }

    void addAdmin(string newAdmin)
    {
        // TODO: Implement add admin
    }

    bool removeParticipant(const string &admin, const string &userToRemove)
    {
        // TODO: Implement remove participant
        return false;
    }

    bool isAdmin(string username) const
    {
        // TODO: Implement admin check
        return false;
    }

    bool isParticipant(string username) const
    {
        // TODO: Implement participant check
        return false;
    }

    void setDescription(string desc)
    {
        // TODO: Implement set description
    }

    void displayChat() const override
    {
        // TODO: Implement group chat display
    }

    void sendJoinRequest(const string &username)
    {
        // TODO: Implement join request
    }
};

// ========================
//    WHATSAPP APP CLASS
// ========================
class WhatsApp
{
private:
    vector<User> users;
    vector<Chat *> chats;
    int currentUserIndex;

    int findUserIndex(string username) const
    {
        // TODO: Implement user search
        return -1;
    }

    bool isLoggedIn() const
    {
        // TODO: Implement login check
        return false;
    }

    string getCurrentUsername() const
    {
        // TODO: Implement get current user
        return "";
    }

public:
    WhatsApp() : currentUserIndex(-1) {}

    void signUp()
    {
        // TODO: Implement user registration
    }

    void login()
    {
        // TODO: Implement user login
    }

    void startPrivateChat()
    {
        // TODO: Implement private chat creation
    }

    void createGroup()
    {
        // TODO: Implement group creation
    }

    void viewChats() const
    {
        // TODO: Implement chat viewing
    }

    void logout()
    {
        // TODO: Implement logout
    }

    void run()
    {
        while (true)
        {
            if (!isLoggedIn())
            {
                cout << "\n1. Login\n2. Sign Up\n3. Exit\nChoice: ";
                int choice;
                cin >> choice;

                if (choice == 1)
                    login();
                else if (choice == 2)
                    signUp();
                else if (choice == 3)
                    break;
            }
            else
            {
                cout << "\n1. Start Private Chat\n2. Create Group\n3. View Chats\n4. Logout\nChoice: ";
                int choice;
                cin >> choice;

                if (choice == 1)
                    startPrivateChat();
                else if (choice == 2)
                    createGroup();
                else if (choice == 3)
                    viewChats();
                else if (choice == 4)
                    logout();
            }
        }
    }
};

// ========================
//          MAIN
// ========================
int main()
{
    WhatsApp whatsapp;
    whatsapp.run();
    return 0;
}