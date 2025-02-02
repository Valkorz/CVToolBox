# CVToolBox

Computer Vision ToolBox: a repository containing every implementation relative to Artificial Inteligence, in the C programming language. The finished state of the project should include: 
- Different data structures (trees, nodes, lists, hashmaps, queues);
- Mathematical functions targeted towards data conversion and AI statistics;
- Different AI algorithms (node networks, probability, supervised learning, non-supervised learning, reinforcement learning, semi-supervised);

*Please note that this is a work in progress: not all features have been promptly added.

## Why C?

Being aware of **Python**'s high applicability in the Artificial Intelligence field certainly nourishes some skepticism of C being the programming language of choice for this endeavor, given its old age and more confusing syntax. 
The choice was made due to the author's wish to create something entirely (or most, at least) original, this includes the avoidance of most libraries, requiring deep knowledge of the machine to create resource-efficient AI implementations. Moreover, this allowed the author to further understand how an AI model is trained and executed throughout every step... including the **memory aspect**. This, therefore, does not mean the author's opinion on Python has a negative connotation, quite the opposite: It is prefered that an AI project uses Python instead, with more fleshed-out libraries such as OpenCV, PyTorch and TensorFlow.

## Why this project?

This project is predominantly for research and education, providing detailed documentation that helps the user understand the 'whys' or 'hows' of Artificial Intelligence technology, even in the low level aspect.

---

## Building the project

### Using CMAKE and Visual Studio Code on Windows

1. **Generate Visual Studio Project Files**:
    - Open a Command Prompt or PowerShell window.
    - Navigate to the project's root directory and create Visual Studio project files:
        ```sh
            cmake .
        ```
2. **Build the project**:
    ```sh
        cmake --build .
    ```

3. **Install the project (Optional)**:
    You can also install the compiled project into a specified directory:
    ```sh
        cmake --install . --prefix /path/to/install
    ```