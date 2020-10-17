#include <Mailbox.h>
#include <mbx/containers.h>

#include <iostream>
using namespace mbox;

Mailbox::Mailbox() {
}

Mailbox::~Mailbox() {
}

void Mailbox::update(){
    cout << "updating mailbox" << endl;
}

bool Mailbox::writeMessage(String msg){
    return (msg.length() < 10);
}

String Mailbox::readMessage(int id) const{
    if (1 == id){
        return String("Hello World!");
    }

    return String();
}