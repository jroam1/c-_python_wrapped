import sys
sys.path.append("../src_dummy/build")
import ada_dummy

_frame = ada_dummy.create_random_buffer(1024)
print(_frame)



