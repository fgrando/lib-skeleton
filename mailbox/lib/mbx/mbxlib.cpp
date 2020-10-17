#include <mbxlib.h>
#include <Mailbox.h>

// Glue the lib interface to the main logic

#define AS_TYPE(Type, Obj) reinterpret_cast<Type *>(Obj)
#define AS_CTYPE(Type, Obj) reinterpret_cast<const Type *>(Obj)

using namespace mbox;

mbx_mailbox_t *mbx_mailbox_new()
{
    return AS_TYPE(mbx_mailbox_t, new mbox::Mailbox());
}

void mbx_mailbox_free(mbx_mailbox_t *mbx)
{
    if (!mbx)
        return;
    delete AS_TYPE(mbox::Mailbox, mbx);
}

void mbx_refresh(mbx_mailbox_t *mbx){
    AS_TYPE(mbox::Mailbox, mbx)->update();
}

int32_t mbx_send_message(mbx_mailbox_t *mbx, char* msg){
    return AS_TYPE(mbox::Mailbox, mbx)->writeMessage(String(msg)) ? 1 : 0;
}

const char *mbx_get_message(const mbx_mailbox_t *mbx, int32_t id){
    return AS_CTYPE(mbox::Mailbox, mbx)->readMessage(id).c_str();
}
