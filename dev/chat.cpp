#include <iostream>
#include <vector>
#include <string>
#include <ctime>
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

int main() {
    // Example usage of Chat class
    Chat chat({"john_doe", "jane_smith"}, "Chat_1");
    return 0;
}