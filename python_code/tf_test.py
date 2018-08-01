# To open this file in interactive mode:
# https://stackoverflow.com/questions/4624416/is-there-a-possibility-to-execute-a-python-script-while-being-in-interactive-mod

# TensorFlow and tf.keras
import tensorflow as tf
from tensorflow import keras

# Helper libraries
import numpy as np
import matplotlib.pyplot as plt
%matplotlib inline

print("TensorFlow " + tf.__version__)

fashion_mnist = keras.datasets.fashion_mnist
(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

class_names = ['T-shirt/top', 'Trouser', 'Pullover', 'Dress', 'Coat', 
               'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']

print("\nTraining image quantity and dim: ")
print(train_images.shape)
print("\nNumber of training labels: ")
print(len(train_labels))
print("\ntrain_labels: ")
print(train_labels)
print("\nTest image quantity and dim: ")
print(test_images.shape)
print("\nNumber of test labels: ")
print(len(test_labels))
print("\ntest_labels: ")
print(test_labels)

# Show the second image in the training set
plt.figure()
plt.imshow(train_images[1])
plt.colorbar()
plt.gca().grid(False)
plt.show()

# Scale [0,255] pixel values to floats between [0,1]
# Cast to float, then simply divide by 255 

train_images = train_images / 255.0
test_images = test_images / 255.0

