# CVToolBox

A C library implementing data structures, sorting algorithms, and a multi-layer perceptron (MLP) for image recognition — built from scratch, with no external AI/ML libraries.

The goal is low-level understanding: every component is hand-implemented, from linked list traversal to backpropagation. This is a research and education project, not a production framework.

## Goals

1. **Data structures** — linked list, circular linked list, binary tree, hash map, queue
2. **Sorting algorithms** — planned
3. **Neural networks** — single-layer perceptron (complete), multi-layer perceptron for image recognition (in progress)

## Why C?

Python with PyTorch or TensorFlow is the practical choice for AI. This project exists for the opposite reason: to understand how AI works at the machine level. That means manual memory management, no automatic differentiation, and no library that hides what happens during training. If you want to understand how gradient descent actually changes weights in memory — this is that kind of project.

## Implementation Status

| Module | Status |
|--------|--------|
| Linked List | Complete |
| Circular Linked List | Complete |
| Binary Tree | Complete |
| Hash Map | Complete |
| Queue | Complete |
| String utilities | Complete |
| Math utilities (ReLU, sigmoid, Lagrange, dichotomy) | Complete |
| CSV / DataFrame | Complete |
| Encoding utilities | Complete |
| Single-layer Perceptron | Complete |
| Neuron / activation function abstraction | Complete |
| Multi-layer Perceptron | In Progress |
| Image loading pipeline | Planned |
| Sorting algorithms | Planned |
| Huffman encoding | Planned |

## Building

### Prerequisites

- CMake 3.10+
- A C11-compatible compiler (MSVC, GCC, Clang)

### Steps

```sh
cmake .
cmake --build .
```

### Install (optional)

```sh
cmake --install . --prefix /path/to/install
```

## Examples

Working examples are in the [`examples/`](examples/) directory:

- **perceptronExample.c** — email spam classifier trained on hardcoded features
- **csvConversionExample.c** — loading, creating, and saving CSV files as DataFrames

## Documentation

- [Single-layer Perceptron](docs/perceptron.md)
- [Binary Tree](docs/BinaryTree.md)
- [Multi-layer Perceptron](docs/mlp.md) *(in progress)*
