import sys
import os
root_path = os.path.dirname(os.path.abspath(__file__))
build_path = os.path.join(root_path, 'build')
sys.path.insert(0, build_path)

import preprocessor

planet = preprocessor.world(5.0, 6.0)
planet2 = preprocessor.world("hello world")

print planet.sum_s()
print planet2.greet()