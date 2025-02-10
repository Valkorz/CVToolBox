#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "perceptron.h"
#define MAX_LENGTH 12
#define EPOCHS 400
#define FEATURES 5
#define LEARNING_RATE 0.5
#define DEFAULT_FNAME "percepsave.bin"

// Function to extract features from an email
void extract_features(const char *email, double *features) {
    features[0] = strlen(email); //Get email length
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
    emails[5] = "How can I win something like this?";
    emails[6] = "I haven't been this free in forever!";
    emails[7] = "How is this free???";
    emails[8] = "Do you want this for free? message me!";
    emails[9] = "There's no free prize.";
    emails[10] = "There is no free food.";
    emails[11] = "Look what I got for free today!";

    // 1 = is a scam message
    // 0 = is not a scam message
    int* labels = (int*)malloc(sizeof(int) * MAX_LENGTH);
    labels[0] = 1;
    labels[1] = 1;
    labels[2] = 0;
    labels[3] = 0;
    labels[4] = 1;
    labels[5] = 0;
    labels[6] = 0;
    labels[7] = 0;
    labels[8] = 1;
    labels[9] = 1;
    labels[10] = 0;
    labels[11] = 0;

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
    system("cls");
    printf("\n Type a message for the perceptron to test for scam... Type # to quit. \n");
    char msg[200];
    double* msg_feat = (double*)malloc(sizeof(double) * FEATURES);
    while(*msg != '#'){
        printf("\n Write a message... ");
        if(fgets(msg, sizeof(msg), stdin) != NULL){
            // Remove the trailing newline
            size_t len = strlen(msg);
            if(len > 0 && msg[len - 1] == '\n'){
                msg[len - 1] = '\0';
            }

            // Check if the first input is '#' to quit.
            if(msg[0] == '#')
                break;

            extract_features(msg, msg_feat);
            printf("\n Message: %s", msg);
            printf("\n Is Scam: %s \n", percep_predict(p, msg_feat) == 1? "TRUE" : "FALSE");
            system("pause");
            system("cls");
        }
    }

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
    free(msg_feat);
    percep_free(p);

    return EXIT_SUCCESS;
}