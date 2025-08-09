#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
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
    string sender;
    string content;
    string timestamp;
    string status;
    Message *replyTo;

    string getCurrentTimestamp() const {
        time_t now = time(0);
        string ts = ctime(&now);
        ts.pop_back();
        return ts;
    }

public:
    Message() {
        sender = "";
        content = "";
        timestamp = getCurrentTimestamp();
        status = "unsent";
        replyTo = nullptr;
    }

    Message(string sndr, string cntnt) {
        sender = sndr;
        content = cntnt;
        timestamp = getCurrentTimestamp();
        status = "sent";
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
        cout << "sender: " << sender << endl;
        cout << content << endl;
        cout << timestamp << "   " << status << endl;
        if (replyTo != nullptr) {
            cout << "Replying to: " << replyTo->getSender() << " - \"" << replyTo->getContent() << "\"" << endl;
        }
        cout << "-------------------------*-" << endl;
    }

    void addEmoji(string emojiCode) {
        content += "   reactions : " + emojiCode;
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
        participants.push_back(user1);
        participants.push_back(user2);
        chatName = user1 + "and" + user2;
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
        if (isParticipant(newAdmin) && !isAdmin(newAdmin)) {
            admins.push_back(newAdmin);
        }
    }

    bool removeParticipant(const string &admin, const string &userToRemove) {
        if (!isAdmin(admin)) {
            return false;
        }
        bool removed = false;
        for (int i = 0; i < participants.size(); ++i) {
            if (participants[i] == userToRemove) {
                participants.erase(participants.begin() + i);
                removed = true;
                break;
            }
        }
        if (!removed)return false;
        for (int i = 0; i < admins.size(); ++i) {
            if (admins[i] == userToRemove) {
                admins.erase(admins.begin() + i);
                break;
            }
        }
        return true;
    }

    bool isAdmin(string username) const {
        for (int i = 0; i < admins.size(); i++) {
            if (admins[i] == username) {
                return true;
            }
        }
        return false;
    }

    bool isParticipant(string username) const {
        for (int i = 0; i < participants.size(); i++) {
            if (participants[i] == username) return true;
        }
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
        if (isParticipant(username)) {
            cout << username << " is already in the group." << endl;
        } else {
            cout << username << "has requested to join the group chat." << endl;
        }
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
        if (isLoggedIn()) {
            return users[currentUserIndex].getUsername();
        }
        return "";
    }

public:
    WhatsApp() : currentUserIndex(-1) {
    }

    void signUp() {
        // TODO: Implement user registration
        bool is_unique = false;
        string username;
        while (!is_unique) {
            cout << "Enter username to sign up: ";
            cin.ignore();
            getline(cin, username);
            is_unique = true;
            for (auto &user: users) {
                if (user.getUsername() == username) {
                    cout << username << " is already signed please enter another username." << endl;
                    is_unique = false;
                    break;
                }
            }
        }
        string password;
        cout << "Enter password to sign up: ";
        getline(cin, password);
        is_unique = false;
        string phoneNumber;
        while (!is_unique) {
            cout << "Enter number to sign up: ";
            getline(cin, phoneNumber);
            is_unique = true;
            for (const auto &user: users) {
                if (user.getPhoneNumber() == phoneNumber) {
                    cout << phoneNumber << " is already signed please enter another number" << endl;
                    is_unique = false;
                    break;
                }
            }
        }
        users.emplace_back(username, password, phoneNumber);
    }

    void login() {
        // TODO: Implement user login
        bool is_logged_in = false;
        while (!is_logged_in) {
            string username;
            cout << "Enter username to login: ";
            cin.ignore();
            getline(cin, username);
            string password;
            cout << "Enter password to login: ";
            getline(cin, password);
            for (int i = 0; i < users.size(); ++i) {
                if (users[i].getUsername() == username && users[i].checkPassword(password)) {
                    cout << username << " logged in." << endl;
                    currentUserIndex = i;
                    is_logged_in = true;
                    break;
                }
            }
            if (!is_logged_in) {
                cout << username << " is not logged in." << endl;
            }
        }
    }

    void startPrivateChat() {
        // TODO: Implement private chat creation
        bool is_logged_in = false;
        if (!isLoggedIn()) {
            cout << getCurrentUsername() << " is not logged in." << endl;
            is_logged_in = true;
        }
        string username;
        cin.ignore();
        while (!is_logged_in) {
            cout << "Enter username to chat with: ";
            getline(cin, username);
            for (const auto &user: users) {
                if (user.getUsername() == username && user.getUsername() != getCurrentUsername()) {
                    is_logged_in = true;
                }
            }
            if (!is_logged_in) {
                cout << username << " is not logged in." << endl;
            }
        }
        chats.push_back(new PrivateChat(getCurrentUsername(), username));
        chats.back()->displayChat();
    }

    void createGroup() {
        if (!isLoggedIn()) {
            cout << getCurrentUsername() << " is not logged in." << endl;
            return;
        }

        string groupName;
        cout << "Enter name of the group: ";
        cin.ignore();
        getline(cin, groupName);

        vector<string> members;
        members.push_back(getCurrentUsername());

        int number;
        cout << "Enter number of participants of the group: ";
        cin >> number;
        cin.ignore(); // clear newline

        while (number > 0) {
            string groupParticipant;
            cout << "Enter username of participant " << members.size() + 1 << ": ";
            getline(cin, groupParticipant);

            bool found = false;
            for (const auto &user: users) {
                if (user.getUsername() == groupParticipant) {
                    if (find(members.begin(), members.end(), groupParticipant) != members.end()) {
                        cout << groupParticipant << " is already in the group." << endl;
                    } else {
                        members.push_back(user.getUsername());
                        cout << groupParticipant << " is added to " << groupName << " successfully." << endl;
                    }
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << groupParticipant << " is not registered." << endl;
            }
            number--;
        }
        chats.emplace_back(new GroupChat(members, groupName, getCurrentUsername()));
        chats.back()->displayChat();
    }


    void viewChats() const {
        // TODO: Implement chat viewing
        if (chats.empty()) {
            cout << "There are no chats." << endl;
        }
        for (const auto &chat: chats) {
            chat->displayChat();
        }
    }

    void logout() {
        // TODO: Implement logout
        if (isLoggedIn()) {
            cout << getCurrentUsername() << " has been logged out." << endl;
            currentUserIndex = -1;
        } else {
            cout << "You have not logged in." << endl;
        }
        run();
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
