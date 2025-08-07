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

int main() {
    // Example usage of Message class
    Message msg("john_doe", "Hello, World!");
    msg.display();
    return 0;
}