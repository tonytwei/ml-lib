# PREPROCESSING
import os
import sys
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(script_dir, 'build'))
# END PREPROCESSING

import ml_lib as ml
#help(ml)

print(ml.add(1, 1))
print(ml.add())