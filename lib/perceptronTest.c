#include <stdio.h>
#include <stdlib.h>
#include "perceptron.h"

// Function to extract features from an email
void extract_features(const char *email, double *features) {
    features[0] = strstr(email, "free") != NULL ? 1.0 : 0.0;
    features[1] = strstr(email, "win") != NULL ? 1.0 : 0.0;
    features[2] = strlen(email);
    features[3] = 0; // Assume 0 links for simplicity
}

int main() {
    int num_samples = 4; // Number of training samples
    int num_inputs = 4;  // Number of features
    double learning_rate = 0.2;
    int epochs = 1000;

    // Training data (emails)
    const char *emails[] = {
        "You have won a free lottery!",
        "Hello, how are you?",
        "Win a free trip to Paris!",
        "Meeting tomorrow at 10 AM."
    };

    // Labels (1 for spam, 0 for not spam)
    int labels[] = {1, 0, 1, 0};

    // Allocate memory for training inputs
    double **training_inputs = (double **)malloc(num_samples * sizeof(double *));
    for (int i = 0; i < num_samples; i++) {
        training_inputs[i] = (double *)malloc(num_inputs * sizeof(double));
        extract_features(emails[i], training_inputs[i]);
    }

    // Initialize perceptron
    Perceptron *p = percep_init(num_inputs, learning_rate);

    // Train perceptron
    train(p, training_inputs, labels, num_samples, epochs);

    // Test perceptron with a new email
    const char *test_email = "You gonna shit my pants";
    double test_features[4];
    extract_features(test_email, test_features);
    int prediction = predict(p, test_features);
    printf("Prediction for test email: %d\n", prediction);

    // Free perceptron and training data
    percep_free(p);
    for (int i = 0; i < num_samples; i++) {
        free(training_inputs[i]);
    }
    free(training_inputs);

    system("pause");

    return 0;
}
