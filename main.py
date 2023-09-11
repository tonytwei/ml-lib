# PYBIND PREPROCESSING
import os
import sys
script_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(script_dir, 'build'))

import pandas as pd
import numpy as np
import ml_lib as ml
# print(ml.add(1, 1))
# print(ml.add())

data_folder = 'data'
data_file = 'NVDA.csv'
data_path = os.path.join(script_dir, data_folder, data_file)
data = pd.read_csv(data_path)

data['Date'] = pd.to_datetime(data['Date'])
print(data.head(5))
data.set_index('Date', inplace=True)

print(data.head(5))