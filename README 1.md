

# Building a Basic Neural Network for MNIST Digit Classification

## 1. Introduction

In this project, we construct a fundamental **feedforward neural network** from the ground up, utilizing **NumPy** to tackle the task of classifying handwritten digits from the **MNIST dataset**. This implementation draws from **Michael Nielsen’s "Neural Networks and Deep Learning" (Chapter 1)**, purposely avoiding established deep learning frameworks like TensorFlow or PyTorch.

Our primary objective is to build a model that can accurately categorize digits (ranging from 0 to 9). The network's structure includes forward propagation, backpropagation, and optimization via the **Adam optimizer**.

## 2. Neural Network Design

### Architecture Overview

- **Input Layer**: Consists of 784 neurons, corresponding to the 28x28 pixel images from MNIST.
- **Hidden Layer**: Contains 64 neurons with **sigmoid activation** functions.
- **Output Layer**: Features 10 neurons (one per digit class) with **softmax activation**.

### Activation Functions Employed

- **Sigmoid Function**: Applied in the hidden layer to introduce non-linearity.
- **Softmax Function**: Used in the output layer to convert raw scores into probabilities suitable for multi-class classification.

### Loss Measurement

- **Cross-Entropy Loss**: Evaluates the disparity between the predicted probabilities and the true labels (encoded in a one-hot format), making it ideal for multi-class tasks.

### Optimization Strategy

- **Adam Optimizer**: Implements the Adam optimization algorithm for adjusting weights during backpropagation. This approach blends momentum with adaptive learning rates to achieve quicker and more stable convergence compared to traditional gradient descent.

### Weight Initialization Method

- **Xavier Initialization**: Uses the Xavier (Glorot) technique to initialize weights, aiming to maintain stable gradient magnitudes and mitigate issues like vanishing or exploding gradients.

## 3. Training Procedure

The training of the neural network on the MNIST dataset follows these steps:

1. **Forward Propagation**: Pass images through the network layers to obtain predictions.
2. **Loss Computation**: Calculate the cross-entropy loss based on the discrepancy between predictions and true labels.
3. **Backpropagation**: Derive gradients and update weights using the Adam optimizer.
4. **Weight Adjustment**: Iteratively modify weights and biases over several epochs.

## 4. Performance Metrics

Here’s a summary of the network’s performance over 10 epochs:

| Epoch | Training Loss | Training Accuracy | Test Accuracy |
| --- | --- | --- | --- |
| 1 | 0.3105 | 91.68% | 91.89% |
| 2 | 0.2357 | 93.49% | 93.30% |
| 3 | 0.2011 | 94.47% | 94.22% |
| 4 | 0.1722 | 95.30% | 95.06% |
| 5 | 0.1528 | 95.88% | 95.51% |
| 6 | 0.1383 | 96.31% | 95.83% |
| 7 | 0.1296 | 96.54% | 96.06% |
| 8 | 0.1190 | 96.86% | 96.30% |
| 9 | 0.1131 | 97.00% | 96.36% |
| 10 | 0.1074 | 97.26% | 96.52% |
- **Final Test Accuracy**: 96.52%

## 5. Insights Gained

- Achieving a **test accuracy of 96.52%** after 10 epochs demonstrates effective model performance.
- The **Adam optimizer** facilitated rapid and stable convergence.
- **Xavier initialization** played a crucial role in maintaining gradient stability.
- The **cross-entropy loss function** proved effective in enhancing classification accuracy over time.

## 6. Areas for Enhancement

- **Layer Expansion**: Introducing additional hidden layers or increasing the current layer’s size could further enhance model accuracy.
- **Regularization Techniques**: Implementing methods like **L2 regularization** or **Dropout** might mitigate overfitting, especially with more complex models.
- **Learning Rate Adjustments**: Employing learning rate scheduling could refine performance by optimizing weight updates throughout the training process.
