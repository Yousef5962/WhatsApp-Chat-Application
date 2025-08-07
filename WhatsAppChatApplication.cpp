#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// ========================
//       USER CLASS
// ========================
class User {
private:
    string username;
    string password;
    string phoneNumber;
    string status;
    string lastSeen;

public:
    User() {
        // TODO: Implement default constructor
        username = "";
        password = "";
        phoneNumber = "";
        status = "";
        lastSeen = "";
    }

    User(string uname, string pwd, string phone) {
        // TODO: Implement parameterized constructor  (Done)
        username = uname;
        password = pwd;
        phoneNumber = phone;
    }

    string getUsername() const {
        // TODO: Implement getter   (Done)
        return username;
    }

    string getPhoneNumber() const {
        // TODO: Implement getter  (Done)
        return phoneNumber;
    }

    string getStatus() const {
        // TODO: Implement getter (Done)
        return status;
    }

    string getLastSeen() const {
        // TODO: Implement getter  (Done)
        return lastSeen;
    }

    void setStatus(string newStatus) {
        // TODO: Implement setter  (Done)
        status = newStatus;
    }

    void setPhoneNumber(string phone) {
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
    void updateLastSeen() {
        // TODO: Implement last seen update  (Done)
        time_t now = time(0); // Get current time
        char *datetime = ctime(&now); // Convert to string
        lastSeen = datetime; // save in the lastSeen
        cout << "User: " << username << " last seen in: " << lastSeen << endl;
    }

    bool checkPassword(string pwd) const {
        // TODO: Implement password check  (Done)
        if (password == pwd)
            return true;
        return false;
    }

    void changePassword(string newPwd) {
        // TODO: Implement password change  (Done)
        password = newPwd;
    }
};

// ========================
//      MESSAGE CLASS
// ========================
class Message {
private:
    string sender ;
    string content ;
    string timestamp ;
    string status ;
    Message *replyTo ;

    string getCurrentTimestamp() const {
        time_t now = time(0);
        string ts = ctime(&now);
        ts.pop_back();
        return ts;
    }

public:
    Message() {
        sender = "";
        content = "" ;
        timestamp = getCurrentTimestamp();
        status ="unsent";
        replyTo = nullptr;
    }

    Message(string sndr, string cntnt) {
        sender = sndr;
        content = cntnt;
        timestamp = getCurrentTimestamp();
        status ="sent";
        replyTo = nullptr;
    }

    string getContent() const {
        // TODO: Implement getter
        return content;
    }

    string getSender() const {
        // TODO: Implement getter
        return sender;
    }

    string getTimestamp() const {
        // TODO: Implement getter
        return timestamp;
    }

    string getStatus() const {
        return status;

    }

    Message *getReplyTo() const {
        return replyTo;
    }

    void setStatus(string newStatus) {
        status = newStatus;
    }

    void setReplyTo(Message *msg) {
        replyTo = msg;
    }

    void updateTimestamp() {
        timestamp = getCurrentTimestamp();
    }

    void display() const {
        cout<< "sender: " << sender<<endl;
        cout<< content << endl;
        cout << timestamp << "   "<< status <<endl;
        if (replyTo != nullptr) {
            cout << "Replying to: " << replyTo->getSender() << " - \"" << replyTo->getContent() << "\"" << endl;
        }
        cout << "-------------------------*-" << endl;
    }

    void addEmoji(string emojiCode) {
        content += "   reactions : "+   emojiCode;
    }
};

// ========================
//       CHAT CLASS (BASE)
// ========================
class Chat {
protected:
    vector<string> participants;
    vector<Message> messages;
    string chatName;

public:
    Chat() {
        // TODO: Implement default constructor
    }

    Chat(vector<string> users, string name) {
        // TODO: Implement parameterized constructor
    }

    void addMessage(const Message &msg) {
        // TODO: Implement message addition
    }

    bool deleteMessage(int index, const string &username) {
        // TODO: Implement message deletion
        return false;
    }

    virtual void displayChat() const {
        // TODO: Implement chat display
    }

    vector<Message> searchMessages(string keyword) const {
        // TODO: Implement message search
        return {};
    }

    void exportToFile(const string &filename) const {
        // TODO: Implement export to file
    }
};

// ========================
//     PRIVATE CHAT CLASS
// ========================
class PrivateChat : public Chat {
private:
    string user1;
    string user2;

public:
    PrivateChat(string u1, string u2) {
        // TODO: Implement constructor
        user1 = u1;
        user2 = u2;
    }

    void displayChat() const override {
        // TODO: Implement private chat display
        if (messages.empty()) {
            cout << "No messages yet.\n";
            return;
        }

        for (const Message &msg: messages) {
            cout << "[" << msg.getTimestamp() << "] " << msg.getSender() << ": " << msg.getContent() << endl;
        }
    }

    void showTypingIndicator(const string &username) const {
        // TODO: Implement typing indicator
        if (username == user1 || username == user2) {
            cout << username << " is typing..." << endl;
        } else cout << "" << endl;
    }
};

// ========================
//      GROUP CHAT CLASS
// ========================
class GroupChat : public Chat {
private:
    vector<string> admins;
    string description;

public:
    GroupChat(vector<string> users, string name, string creator) {
        // TODO: Implement constructor
        participants = users;
        chatName = name;
        admins.push_back(creator);
        description = "A new group chat.";
    }

    void addAdmin(string newAdmin) {
        // TODO: Implement add admin
    }

    bool removeParticipant(const string &admin, const string &userToRemove) {
        // TODO: Implement remove participant
        return false;
    }

    bool isAdmin(string username) const {
        // TODO: Implement admin check
        return false;
    }

    bool isParticipant(string username) const {
        // TODO: Implement participant check
        return false;
    }

    void setDescription(string desc) {
        // TODO: Implement set description
        description = desc;
    }

    void displayChat() const override {
        // TODO: Implement group chat display
        cout << "Group Chat: " << chatName << endl;
        cout << "Description: " << description << endl;
        cout << "Admins: ";
        for (const string &admin: admins) {
            cout << admin << " ";
        }
        cout << endl;
        cout << "Participants: ";
        for (const string &participant: participants) {
            cout << participant << " ";
        }
        cout << endl;
        if (messages.empty()) {
            cout << "No messages yet. Be the first to say hi!" << endl;
        } else {
            for (const Message &msg: messages) {
                msg.display();
            }
        }
        cout << "---------------------------------" << endl;
    }

    void sendJoinRequest(const string &username) {
        // TODO: Implement join request
    }
};

// ========================
//    WHATSAPP APP CLASS
// ========================
class WhatsApp {
private:
    vector<User> users;
    vector<Chat *> chats;
    int currentUserIndex;

    int findUserIndex(string username) const {
        // TODO: Implement user search
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username) {
                return i;
            }
        }
        return -1;
    }

    bool isLoggedIn() const {
        // TODO: Implement login check
        if (users.empty()) {
            return false;
        }
        if (currentUserIndex >= 0 && currentUserIndex < users.size()) {
            return true;
        }
        return false;
    }

    string getCurrentUsername() const {
        // TODO: Implement get current user
        if (users.empty()) {
            return "";
        }
        if (!isLoggedIn()) {
            return users[currentUserIndex].getUsername();
        }
        return "";
    }

public:
    WhatsApp() : currentUserIndex(-1) {
    }

    void signUp() {
        // TODO: Implement user registration
    }

    void login() {
        // TODO: Implement user login
    }

    void startPrivateChat() {
        // TODO: Implement private chat creation
    }

    void createGroup() {
        // TODO: Implement group creation
    }

    void viewChats() const {
        // TODO: Implement chat viewing
    }

    void logout() {
        // TODO: Implement logout
    }

    void run() {
        while (true) {
            if (!isLoggedIn()) {
                cout << "\n1. Login\n2. Sign Up\n3. Exit\nChoice: ";
                int choice;
                cin >> choice;

                if (choice == 1)
                    login();
                else if (choice == 2)
                    signUp();
                else if (choice == 3)
                    break;
            } else {
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
int main() {
    WhatsApp whatsapp;
    whatsapp.run();
    return 0;
}
