import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from numpy.linalg import norm

def read(file):
    # Read integers from the file
    with open(file, 'r') as file:
        integers = [int(line.strip()) for line in file]
        array = np.array(integers).reshape(1, -1)
        return array.flatten()

def cos_sim(A,B):
    cosine = np.dot(A, B) / (norm(A) * norm(B))
    return cosine

# Reshape the list into a 128-dimensional array

k0 = read('out_data1_k0.txt')
k1 = read('out_data1_k1.txt')
# k2 = read('out_data1_k2.txt')

# g0 = read('out_data1_g0.txt')
# g1 = read('out_data1_g1.txt')
# g1 = read('data_g_1.log')

import ipdb; ipdb.set_trace()

# cosine_sim = cosine_similarity(array, other_array)

print(cosine_sim)