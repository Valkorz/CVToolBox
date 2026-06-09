#include <stdio.h>
#include <stdlib.h>
#include "cllist.h"
#include "calclib.h"
#include "perceptron.h"

static void demo_data_structures(void) {
    printf("=== Data Structures ===\n");
    CLList list;
    createCLL(&list, 4);
    addEntry(list, (void*)(size_t)10);
    addEntry(list, (void*)(size_t)20);
    addEntry(list, (void*)(size_t)30);
    printCLL(list);
    printf("\n");
}

static void demo_math(void) {
    printf("=== Math Utilities ===\n");
    printf("relu(-2.0)   = %.4f\n", relu(-2.0));
    printf("relu( 3.5)   = %.4f\n", relu(3.5));
    printf("sigmoid(-2)  = %.4f\n", logCurve(-2.0));
    printf("sigmoid( 0)  = %.4f\n", logCurve(0.0));
    printf("sigmoid( 2)  = %.4f\n", logCurve(2.0));
    printf("\n");
}

static void demo_perceptron(void) {
    printf("=== Single-layer Perceptron (AND gate) ===\n");

    double r0[] = {0.0, 0.0};
    double r1[] = {0.0, 1.0};
    double r2[] = {1.0, 0.0};
    double r3[] = {1.0, 1.0};
    double *inputs[] = {r0, r1, r2, r3};
    int labels[] = {0, 0, 0, 1};

    Perceptron *p = percep_init(2, 0.1);
    percep_train(p, inputs, labels, 4, 200);

    printf("0 AND 0 = %d  (expected 0)\n", percep_predict(p, r0));
    printf("0 AND 1 = %d  (expected 0)\n", percep_predict(p, r1));
    printf("1 AND 0 = %d  (expected 0)\n", percep_predict(p, r2));
    printf("1 AND 1 = %d  (expected 1)\n", percep_predict(p, r3));

    percep_free(p);
    printf("\n");
}

int main(void) {
    demo_data_structures();
    demo_math();
    demo_perceptron();
    return 0;
}
