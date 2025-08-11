#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;
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
        chatName = "";
    }

    Chat(vector<string> users, string name) {
        // TODO: Implement parameterized constructor
        participants = users;
        chatName = name;
    }

    void addMessage(const Message &msg) {
        // TODO: Implement message addition
        messages.push_back(msg);
    }
    string getChatName() const {
        return chatName;
    }

    bool deleteMessage(int index, const string &username) {
        // TODO: Implement message deletion
        if (index >= 0 && index < messages.size() && messages[index].getSender() == username) {
            messages.erase(messages.begin() + index);
            return true;
        }
        return false;
    }
    virtual bool isParticipant(const string &username) const {
        return find(participants.begin(), participants.end(), username) != participants.end();
    }

    virtual void displayChat() const {
        // TODO: Implement chat display
        cout << "========== Chat: " << chatName << " ==========" << endl;
        if(messages.empty()){
            cout << "No messages yet." << endl;
            return;
        }
        for(const Message &msg: messages) {
            msg.display();
        }
    }

    vector<Message> searchMessages(string keyword) const {
        // TODO: Implement message search
        vector<Message> results;
        for (const Message &msg: messages) {
            if (msg.getContent().find(keyword) != string::npos) {
                results.push_back(msg);
            }
        }
        return results;
    }

    void exportToFile(const string &filename) const {
        // TODO: Implement export to file
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
            cout << "[" << msg.getTimestamp() << "] " << msg.getSender() << ": " << msg.getContent() << endl;
        }
        cout << "---------------------------------" << endl;
    }}

    void sendJoinRequest(const string &username) {
        if (isParticipant(username)) {
            cout << username << " is already in the group." << endl;
        } else {
            cout << username << "has requested to join the group chat." << endl;
        }
    }
};
int main(){
    vector<Chat *> chats;
    string groupName = "Friends";
    vector<string> members = {"Alice", "Bob"};
    chats.emplace_back(new GroupChat(members, groupName, "Y"));
    cout << typeid(chats[0]).name() << endl;
    return 0;
}