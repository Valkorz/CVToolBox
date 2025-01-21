#include <stdio.h>
#include <stdlib.h>
#include "include/csv.h"
#include "include/tmatch.h"
#include "include/hmap.h"

/*
    This file presents an example on how to use the csv.h header to convert data to and from .csv files.
    Similar to Python's pandas library, it uses dataFrames, which are basically an array of HashMaps.
*/

int main()
{
    // Loading a DataFrame from a .csv file
    DataFrame *df = df_load("..\\examples\\data\\csv\\random_temps.csv");

    //Print loaded data if it has been successful.
    if (df != NULL)
    {
        printf("\n Loaded data: ");
        df_print(df); // print whole DataFrame (formatted as such)
        system("pause");
        system("cls");
        df_clear(df);
    }

    // Create a new DataFrame manually

    df = df_new();
    HashMap *data = createHashMap();

    // Add some placeholder data
    add(data, "test", "0");
    add(data, "test2", "1");
    add(data, "test3", "2");
    add(data, "test4", "3");

    // Append the same data twice for two rows (containing the same values)
    df_append(df, data);
    df_append(df, data);

    // Free the data as it will no longer be used
    //(The data is copied when  appended to the DataFrame)
    clearMap(data);

    // Saves the DataFrame to a separate file (in the same directory as the executable)
    printf("\n saving... ");
    df_print(df);
    df_save(df, "data.csv");
    system("pause");
    system("cls");
    df_clear(df);

    printf("\n Everything cleared! Press ENTER to close application...");
    system("pause");

    return EXIT_SUCCESS;
}