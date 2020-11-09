#include "libmx.h"

int mx_quicksort(char **arr, int left, int right) 
{
    int count = 0;

    if(arr == NULL){
        return -1;
    }
        if (left < right) {
            int first = left;
            int last = right;
            int middle = (first + last) / 2;

            while (first <= last) {
                while (mx_strlen(arr[first]) < mx_strlen(arr[middle])) first++;
                while (mx_strlen(arr[last]) > mx_strlen(arr[middle])) last--;
                char *tmp = arr[first];
                arr[first] = arr[last];
                arr[last] = tmp;
                first++;
                last--;
                count++;
            }
            mx_quicksort(arr, left, last);
            mx_quicksort(arr, first, right);
        }
    return count;
}
