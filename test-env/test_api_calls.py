#
# run this like:
# pytest -q test-api-calls.py 
#
# use -s flag to display the print():
# pytest -q test-api-calls.py -s 

import time
from testhelpers import ffi, lib

def test_api_calls(context):
    version = lib.mbx_get_version()
    print(f"lib version: {version}")
   
    result = lib.mbx_is_compatible_dll()
    print(f'is compatible dll: {result}')

    lib.mbx_refresh(context)
    
    result = lib.mbx_send_message(context, b"test")
    print(f'send msg result: {result}')
    
    result = lib.mbx_get_message(context, 1)
    print(f'get msg result: {ffi.string(result)}')

    