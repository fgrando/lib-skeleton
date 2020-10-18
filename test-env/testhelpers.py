#!/usr/bin/python3

import os
import subprocess
from cffi import FFI

# install CFFI with: pip3 install cffi

ffi = FFI()
here = os.path.abspath(os.path.dirname(__file__))
header = os.path.join(here, '..','mailbox', 'api', 'mbxlib.h')


if os.name == 'nt':
    print('not supported')
    shared_lib = ''
    api = ''
else:
    shared_lib = os.path.join(here, '..','mailbox', 'bin', 'libmbxlib.so')
    # generate a new header file excluding other includes
    raw = subprocess.Popen(['cc', '-E', '-DMBX_API=', '-DMBX_NOINCLUDE', header], stdout=subprocess.PIPE).communicate()[0]
    api = str(raw, 'utf-8')

ffi.cdef(api)
lib = ffi.dlopen(shared_lib)

