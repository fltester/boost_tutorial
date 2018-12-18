import sys
import os
root_path = os.path.dirname(os.path.abspath(__file__))
build_path = os.path.join(root_path, 'build')
# print root_path
# print build_path
sys.path.insert(0, build_path)

# print sys.path
import preprocessor

planet = preprocessor.world()
planet.set("howdy")
print planet.greet()