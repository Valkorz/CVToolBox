# PERCEPTRON
#### A Guide on using the perceptron model in CVToolBox.
Author: Vittorio Pivarci (Valkorz)

---

## What is a Perceptron? 

A Perceptron is the simplest form of a neural network. It uses binary classification to determine whether it should return `True` or `False` as a response for a specified test. A perceptron is usually trained to separate a **specific** theme into two possible outputs. 

## How does it work?

#### The principles

A Perceptron, like any other neural network, contains a few parameters that allow it to achieve its final answer:

- **Weights:** represent the strength of connection of a neuron towards a specified input, that is, how likely it is for that input to be positive (represented as a random value that is then tweaked to further match the most appropriate answer).

- **Inputs/features:** an 'Input' or 'feature' is essentially the variable that identifies the presence of a certain trait in the item to be classified by the Perceptron. An input is always multiplied by a weight as they work together. The inputs represent a certain characteristic that will be searched for in a piece of data.

- **Bias:** represents the likelihood for the model to prefer certain inputs over others, favoring positively or negatively certain groups or individuals.

- **Learning rate:** represents how quickly the model will adjust itself to the more appropriate output (mathematically).

- **Learning rule:** represents the mathematical formula that results in the true or false output for a given problem. Said mathematical formula has its coefficients adjusted during the training process to enhance the precision of the model.

The points above represent the properties present in a Perceptron, and we use these to define a `struct` in our Perceptron code:

```c
//perceptron.h
typedef struct Perceptron{
    double *weights;
    double bias;
    int num_inputs;
    double learning_rate;
}Perceptron;
```

#### The learning rule

The learning rule, as aforemenetioned, represents a mathematical equation that determines whether a piece of data is true or false. For example, consider the following message:

`Hello! You've won a prize! Enter this URL to claim...`

The above represents a scam message. We know this because it is sudden, unexplained, mentions an undisclosed `prize` and attempts to get the user to access an `URL`. We've reached this conclusion due to common sense and past experiences with scam messages, but how would you teach a machine to identify potential scam messages?
Consider the following code snippet:

```c
void train(Perceptron *p, double **training_inputs, int *labels, int num_samples, int epochs) {
    int epoch, i;
    for(epoch = 0; epoch < epochs; epoch++){
        for(i = 0; i < num_samples; i++){
            int prediction = predict(p, *(training_inputs + i));
            int error = *(labels + i) - prediction;

            //Update weights and bias
            for(int j = 0; j < p->num_inputs; j++){
                //Adjust the weights based on the calculated error.
                *(p->weights + j) += p->learning_rate * error * (*(*(training_inputs + i)) + j);
            }
            p->bias += p->learning_rate * error;

            //The model will correct itself based on how far it 'missed' from the real answer
            //the correction rate is measured by the 'learning_rate' constant.
        }
    }
}
```

The code above is used to train the perceptron. As arguments, we supply the perceptron with `training inputs` which represent the features for each input to be used as an example for training the perceptron, along with `labels` that represent the true/false state for each input. The `num_samples` argument represents the size of the training data, while `epochs` is for how many training loops the model will go through before it reaches a satisfactory state.
To sum things up, basically we give the algorithm the 'answer' to a problem, and it will attempt to guess the right solution. The more it guesses, the more it calculates the error margin (how far away it was from the real answer) and adjusts itself based on the `learning_rate`.
This also means that the number of samples results in a more precise model, because it has "seen" more possibilities and can adjust itself accordingly.

#### Separating the data into features

The "features" represent existing elements in data. Each piece of data is analyzed for the same features (to ensure consistency). They will either represent a true/false state for each input or a real value, as shown in the following function:

```c
    // Function to extract features from an email
void extract_features(const char *email, double *features) {
    features[0] = strstr(email, "free") != NULL ? 1.0 : 0.0;
    features[1] = strstr(email, "win") != NULL ? 1.0 : 0.0;
    features[2] = strlen(email);
    features[3] = 0; // Assume 0 links for simplicity
}
```

So, basically, the function is checking the following properties and conditions:

- Does the string contain the word "free"?
- Does the string contain the word "win"?
- What is the string size?
- Are there any URLs attached to the string?

All of these values contribute to the equation that will determine whether an email/message is a scam or not.

#### Calculating the output

All the properties of a perceptron (weights, bias, inputs, etc...) contribute to the final decision of whether an input is `true` or `false`, following the general formula (that can be tweaked for different results):

$ y = g(w_0 + \sum_{i=1}^{m} x_i * w_i)$

$y$ = output;
$g(x)$ = non-linear activation function;
$w_0$ = bias;
$x_i$ = linear combination of inputs;
$w_i$ = weights (that combine with inputs);

The mathematical expression above describes the general behavior of a perceptron. It will look through each one of its inputs (features) and multiply the value for its corresponding weight and add up the value to the previous iteration. After the sum is finished, the final value is also incremented by $w_0$ (bias), and then transferred to the **activation function**, which then determines the output between `true` or `false`

#### The Activation Function

The activation function represents the logic that will read the input(argument) and determine whether it should return `true` or `false`. For a simple perceptron, the activation function simply checks if the provided value is above or equal zero, in which case it returns `true` (1), otherwise `false` (0).

```c
    int activate(double sum){
    return sum >= 0? 1 : 0;
}
```

#### Creating a perceptron

To train a perceptron, first we need to create one. This is done by the following function:

```c
Perceptron* percep_init(int num_inputs, double learning_rate){
    Perceptron *p = (Perceptron*)malloc(sizeof(Perceptron));
    p->num_inputs = num_inputs;
    p->learning_rate = learning_rate;
    p->weights = (double*)malloc(num_inputs * sizeof(double)); //each feature has a specified weight
    p->bias = 0.0; //No initial bias

    int i;
    for(i = 0; i < num_inputs; i++){
        //Assign random values to each feature weight
        *(p->weights + i) = ((double)rand() / RAND_MAX) - 0.5;
    }

    return p;
}
```

The perceptron is created with the **number of inputs** and **learning rate** as parameters. The perceptron then is allocated in the memory and all of its values are initialized. Random values are assigned for each weight.

#### Using the perceptron

The code below presents the perceptron being used to analyze messages/emails and determine whether they're scam or not.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "perceptron.h"
#define MAX_LENGTH 5
#define EPOCHS 200
#define FEATURES 4
#define LEARNING_RATE 0.5

// Function to extract features from an email
void extract_features(const char *email, double *features) {
    features[0] = strstr(email, "free") != NULL ? 1.0 : 0.0;
    features[1] = strstr(email, "win") != NULL ? 1.0 : 0.0;
    features[2] = strlen(email);
    features[3] = 0; // Assume 0 links for simplicity
}

int main()
{
    printf("\n Creating training data...");

    srand(time(NULL));
    // Create some example data to train the perceptron with
    char** emails = (char**)malloc(sizeof(char*) * MAX_LENGTH);
    emails[0] = "Hello! you win a prize!";
    emails[1] = "Do you want a free chance to win a cellphone?";
    emails[2] = "Hello, how have you been?";
    emails[3] = "Your verification code is XXXXX";
    emails[4] = "Enter this link to win free robux!";

    // 1 = is a scam message
    // 0 = is not a scam message
    int* labels = (int*)malloc(sizeof(int) * MAX_LENGTH);
    labels[0] = 1;
    labels[1] = 1;
    labels[2] = 0;
    labels[3] = 0;
    labels[4] = 1;

    //Extract features for each email
    double** features = (double**)malloc(sizeof(double*) * MAX_LENGTH);
    for(int i = 0; i < MAX_LENGTH; i++)
    {
        features[i] = (double*)malloc(sizeof(double) * FEATURES);
        extract_features(emails[i], features[i]);
    }
    
    // Create a new perceptron
    Perceptron *p = percep_init(FEATURES, LEARNING_RATE);

    // Train the perceptron
    printf("\n Training the perceptron...");
    train(p, features, labels, MAX_LENGTH, EPOCHS);

    //Test the perceptron on a new message
    char* msg_normal = "Good Morning, I hope you have a nice day!"; //Not a scam message
    double* normal_features = (double*)malloc(sizeof(double) * MAX_LENGTH);
    extract_features(msg_normal, normal_features);
    char* msg_scam = "This link contains a free prize. Claim it."; //Scam message
    double* scam_features = (double*)malloc(sizeof(double) * MAX_LENGTH);
    extract_features(msg_scam, scam_features);

    printf("\n Testing the perceptron...");
    printf("\n Message 1: %s. Is Scam: %s", msg_normal, predict(p, normal_features) == 1? "TRUE" : "FALSE");
    printf("\n Message 2: %s. Is Scam: %s", msg_scam, predict(p, scam_features) == 1? "TRUE" : "FALSE");
    
    
    system("pause");
    printf("\n Cleaning up...");

    free(emails);
    free(labels);

    for(int i = 0; i < MAX_LENGTH; free(features[i]), i++);

    free(features);
    free(normal_features);
    free(scam_features);

    return EXIT_SUCCESS;
}
``` 

This code organizes some sample emails and categorizes them between 'scam' and 'not scam'. The data is fed into the perceptron training algorithm. After the training process is finished, the perceptron is tested for the following results on the terminal:

```
 Message 1: Good Morning, I hope you have a nice day!. Is Scam: FALSE
 Message 2: This link contains a free prize. Claim it.. Is Scam: TRUE
```

This means that the perceptron has worked, and it is able to detect scam messages using the features checked using the `extract_features` function! 
It is worth noting, however, that in some executions of the program, the perceptron might *not* detect the scam message, this because the random weight being applied might result in the sum being negative. Increasing the `epochs` does increase accuracy significantly during the training process.