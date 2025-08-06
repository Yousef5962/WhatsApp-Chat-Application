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
    string sender;
    string content;
    string timestamp;
    string status;
    Message* replyTo;
    
public:
    Message() {
        // TODO: Implement default constructor
    }
    
    Message(string sndr, string cntnt) {
        // TODO: Implement parameterized constructor
    }
    
    string getContent() const {
        // TODO: Implement getter
        return "";
    }
    
    string getSender() const {
        // TODO: Implement getter
        return "";
    }
    
    string getTimestamp() const {
        // TODO: Implement getter
        return "";
    }
    
    string getStatus() const {
        // TODO: Implement getter
        return "";
    }
    
    Message* getReplyTo() const {
        // TODO: Implement getter
        return nullptr;
    }
    
    void setStatus(string newStatus) {
        // TODO: Implement setter
    }
    
    void setReplyTo(Message* msg) {
        // TODO: Implement setter
    }
    
    void updateTimestamp() {
        // TODO: Implement timestamp update
    }
    
    void display() const {
        // TODO: Implement message display
    }
    
    void addEmoji(string emojiCode) {
        // TODO: Implement emoji support
    }
};

int main() {
    // Example usage of Message class
    Message msg("john_doe", "Hello, World!");
    return 0;
}