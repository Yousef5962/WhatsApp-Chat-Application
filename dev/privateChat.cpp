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
        chatName = user1 + " and " + user2;
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

int main() {
    // Example usage of GroupChat and PrivateChat

    return 0;
}