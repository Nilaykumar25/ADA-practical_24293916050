#include <stdio.h>
#include<stdlib.h>

int sortByFinishTime(int start[], int finish[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (finish[i] > finish[j]){
                int temp = finish[i];  // finish time
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];    // start time
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
}

int main(){
    int start[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finish[]   = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int n = 11;

    printf("Activities with their start and completion time:\n");
    for (int i = 0; i < n; i++){
        printf("Activity %d -> Start: %d End: %d\n", i+1, start[i], finish[i]);
    }

    sortByFinishTime(start, finish, n);

    printf("Selected Activities are:\n");
    int i = 0, count = 1;
    printf("Activity %d -> Start: %d End: %d\n", i+1, start[i], finish[i]);

    for (int j = 0; j < n; j++){
        if (start[j] >= finish[i]){
            printf("Activity %d -> Start: %d End: %d\n", j+1, start[j], finish[j]);
            i = j;
            count++;
        }
    }
    printf("Total Selected Activities: %d\n", count);
    return 0;
}
