#!/usr/bin/python3

import pytest
# sudo apt install python-pytest

from testhelpers import lib, ffi

@pytest.fixture(scope='function')
def context(request):
    mbx = lib.mbx_mailbox_new()
    
    def cleanup():
        lib.mbx_mailbox_free(mbx)

    request.addfinalizer(cleanup)
    return mbx