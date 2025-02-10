#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "perceptron.h"
#define MAX_LENGTH 5
#define EPOCHS 200
#define FEATURES 4
#define LEARNING_RATE 0.5
#define DEFAULT_FNAME "percepsave.bin"

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
    int hasData = -1;

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
    // Load perceptron model data if it is found, otherwise initiate new instance.
    Perceptron *p = NULL;
    p = percep_load(DEFAULT_FNAME);
    if(!p){
        p = percep_init(FEATURES, LEARNING_RATE);
    } else hasData = 1;

    // Train the perceptron
    printf("\n Training the perceptron...");
    percep_train(p, features, labels, MAX_LENGTH, EPOCHS);

    //Test the perceptron on a new message
    char* msg_normal = "Good Morning, I hope you have a nice day!"; //Not a scam message
    double* normal_features = (double*)malloc(sizeof(double) * MAX_LENGTH);
    extract_features(msg_normal, normal_features);
    char* msg_scam = "This link contains a free prize. Claim it."; //Scam message
    double* scam_features = (double*)malloc(sizeof(double) * MAX_LENGTH);
    extract_features(msg_scam, scam_features);

    printf("\n Testing the perceptron...");
    printf("\n Message 1: %s. Is Scam: %s", msg_normal, percep_predict(p, normal_features) == 1? "TRUE" : "FALSE");
    printf("\n Message 2: %s. Is Scam: %s", msg_scam, percep_predict(p, scam_features) == 1? "TRUE" : "FALSE");
    
    
    printf("\n Saving to percepsave.bin ...");
    if(hasData < 0){
        // Save the perceptron data if no file has been found
        percep_save(p, DEFAULT_FNAME);
    }

    system("pause");
    printf("\n Cleaning up...");

    free(emails);
    free(labels);

    for(int i = 0; i < MAX_LENGTH; free(features[i]), i++);

    free(features);
    free(normal_features);
    free(scam_features);
    percep_free(p);

    return EXIT_SUCCESS;
}