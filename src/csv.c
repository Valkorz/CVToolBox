#include "csv.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Converts a .csv file to a HashMap** (which is a Data Frame) inside a DataFrame struct 
//(for size tracking)
DataFrame* df_load(const char* fname){
    FILE* fptr = fopen(fname,"r");
    char ch, buffer[MAX_LENGTH], **headers = NULL;
    int row = 0, buffer_index = 0, hash_index = 0, hash_size = 1, elements = 1, offset = 0, i;
    unsigned long hcount = 0, len = 0;
    DataFrame* _df = (DataFrame*)malloc(sizeof(DataFrame));
    HashMap** df = (HashMap**)malloc(sizeof(HashMap*) * hash_size);

    //Quit function if file opening fails
    if(fptr == NULL){
        printf("\n ERROR: %s not found.", fname);
        return NULL;
    }

    clearBuffer(MAX_LENGTH, buffer); //Initialize buffer with line endings ('\0').

    do{
        ch = fgetc(fptr);
        *(buffer + buffer_index) = ch;

        //Add every character found to the buffer until line ends
        if(ch == '\n'){

            //Count number of columns and allocate headers buffer
            if(row == 0){
                headers = strsplit(buffer, ',', &elements);
                hcount = elements;
            }
            else {
                //Add an entry into the HashMap entry with the collected arrays from the first line of the .csv file.
                // printf("\n Adding entry of number %d into the hashmap array... \n", hash_index);
                HashMap* current = *(df + hash_index) = createHashMap();

                // printf("\n Created hashmap (%p)... adding elements...", current);
                
                offset = 0;
                char** values = strsplit(buffer, ',', NULL);

                for(i = 0; i < elements; i++){
                    // printf("\n Adding element: [%s] = %s into hashmap: %p", *(headers + i), *(values + i), current);
                    add(current, *(headers + i), *(values + i));
                }

                // printf("\n Testing %d for Date: %s", hash_index, get(current, "Date"));
                hash_size++;
                hash_index++;
                len++;
                df = (HashMap**)realloc(df, sizeof(HashMap*) * hash_size);

                if(df == NULL) printf("\n dataframe allocation failed.");
            }

            row++;
            buffer_index = 0;
            clearBuffer(MAX_LENGTH, buffer); //Clear buffer and reset counter
        } else{
            buffer_index++;       
        } 


    }while(ch != EOF);

    fclose(fptr);
    
    _df->dataFrame = df;
    _df->headCount = hcount;
    _df->length = len;

    printf("\n Created dataframe with headCount %lu and length %lu", _df->headCount, _df->length);
    return _df;
}

//Converts dataframe to .csv file
void df_save(DataFrame* df, const char* fname){
    FILE* fptr = fopen(fname, "w");
    int i, e;
    printf("\n headcount: %d", df->headCount);
    //Write all the headers in the first line of the file
    for(i = 0; i < df->headCount; i++){
        char* hdr = strdup(((*(df->dataFrame ))->map + i)->key);
        if(hdr == NULL) break;

        fprintf(fptr, hdr);
        if(i < df->headCount - 1)
            fprintf(fptr,",");
    }
    fprintf(fptr, "\n");

    //Write the rest of the data
    for(i = 0; i < df->length; i++){
        for(e = 0; e < df->headCount; e++){
            char* vle = strdup(((*(df->dataFrame + i))->map + e)->value);
            if(vle == NULL) break;

            fprintf(fptr, vle);
            if(e < df->headCount - 1)
                fprintf(fptr,",");
        }
        fprintf(fptr, "\n");  
    }

    fclose(fptr);
    //finish this
}

void clearBuffer(const int len, char* buffer){
    int i;
    for(i = 0; i < len; i++){
        if(*(buffer + i) != '\0'){
            *(buffer + i) = '\0';
        } else return;
    }
}

//Creates a new empty dataFrame
DataFrame* df_new(){
    DataFrame* df = (DataFrame*)malloc(sizeof(DataFrame));
    df->dataFrame = NULL;
    df->headCount = 0;
    df->length = 0;

    return df;
}

//Appends data to the DataFrame, allocates a new hashmap array if NULL
void df_append(DataFrame* df, HashMap* data){
    if(df->dataFrame == NULL){
        df->dataFrame = (HashMap**)malloc(sizeof(HashMap*));
        df->length = 1;
        df->headCount = (unsigned long)data->count;
        *(df->dataFrame) = data;

        printf("\n HashMap is NULL. Allocated new array %p with length %lu and headCount %lu", df->dataFrame, df->length, df->headCount);
        printf("\n Added: ");
        printAll(data);
    }
    else{
        df->length++;
        df->dataFrame = (HashMap**)realloc(df->dataFrame, sizeof(HashMap*) * df->length);
        *(df->dataFrame + df->length - 1) = data;

        printf("\n Added: ");
        printAll(*(df->dataFrame + df->length - 1));
    }
}

//Calculates the mean of values of a header (assumes the value is an int/float/double)
void df_mean(DataFrame* df, const char* header){
    //TODO
}

void df_clear(DataFrame* df){
    int i;
    unsigned long size = df->length;
    HashMap** _df = df->dataFrame;
    for(i = 0; i < size; i++){
        clearMap(*(_df + i));
    }

    free(_df);
    free(df);
}