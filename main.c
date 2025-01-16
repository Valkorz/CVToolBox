#include <stdio.h>
#include <stdlib.h>
#include "include/csv.h"
#include "include/typematch.h"
#include "include/hashMap.h"

/*
    This file presents an example on how to use the csv.h header to convert data to and from .csv files.
    Similar to Python's pandas library, it uses dataFrames, which are basically an array of HashMaps.
*/

int main(){

    /*
    DataFrame* df = df_load("lib\\data\\generated\\random\\random_temps.csv");
    printf("\n Rain on index 2 = %s", get(df->dataFrame[2], "Rain"));
    system("pause");

    dfClear(&df);
    printf("Cleared dataframe."); */

    DataFrame* df = df_new();
    HashMap* data = createHashMap();
    add(data, "test", "0");
    add(data, "test2", "1");
    add(data, "test3", "2");
    add(data, "test4", "3");
    df_append(df, data);
    df_append(df, data);
    char** keys = get_keys(data);
    printf("\n keys return: %s, %s", keys[0],keys[1]);
    printf("\n saving... ");
    df_save(df, "data.csv");
    system("pause");

    return EXIT_SUCCESS;
}