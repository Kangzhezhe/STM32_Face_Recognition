import numpy as np
from sklearn.metrics.pairwise import cosine_similarity

def read(file):
    # Read integers from the file
    with open(file, 'r') as file:
        integers = [int(line.strip()) for line in file]
        array = np.array(integers).reshape(1, -1)
        return array

# Reshape the list into a 128-dimensional array

k0 = read('data_k_0.log')
k1 = read('data_k_1.log')
k2 = read('data_k_2.log')
k3 = read('data_k_3.log')

g0 = read('data_g_0.log')
g1 = read('data_g_1.log')


import ipdb; ipdb.set_trace()

cosine_sim = cosine_similarity(array, other_array)

print(cosine_sim)