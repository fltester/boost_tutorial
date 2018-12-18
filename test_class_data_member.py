import sys
import os
root_path = os.path.dirname(os.path.abspath(__file__))
build_path = os.path.join(root_path, 'build')
sys.path.insert(0, build_path)

import preprocessor

var = preprocessor.var("hello_var")
var.value = 3.14

print var.name