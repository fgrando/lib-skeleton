#ifndef CMAILBOX_H_INCLUDED
#define CMAILBOX_H_INCLUDED

#include <mbx/mbx.h>

#include <vector>
using namespace std;

namespace mbox {

class Mailbox {
public:
    Mailbox();
    ~Mailbox();

    // check for incomming mail
    void update();

    // send a message
    bool writeMessage(String msg);

    // get a message
    String readMessage(int id) const;

private:
    List<String> inbox, outbox; // example

    MBX_IMPLEMENTS_ALLOCATORS;
};

}

#endif