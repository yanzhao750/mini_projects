/*
Gets ints from the user and returns a merge sorted array.
*/

#include <stdio.h>
#include <string.h>

// prototype of function to implement merge sort
void merge_sort(int array[], int start, int end, int auxArray[]);

int main(void)
{
    // declare array[] to be sorted and auxArray[]
    int array[100], auxArray[100];

    // get size of array from user
    int n;
    printf("Enter size of array: ");
    scanf("%i", &n);

    // get integers in array from user
    printf("Enter %i integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%i", &array[i]);

    // merge sort array
    merge_sort(array, 0, n - 1, auxArray);

    // print sorted array
    printf("[");
    for (int i = 0; i < n; i++)
        printf(" %i ", array[i]);
    printf("]\n");

    return 0;
}

void merge_sort(int array[], int start, int end, int auxArray[])
{
    // base case: if (sub)array is of size 1 or is empty, consider the array sorted and return
    if (end <= start)
        return;

    // find the middle of the array
    int mid = (start + end) / 2; // note only integer is returned, not decimals

    // recursively sort...
    // ... left sub-array, which is from array[start ... mid]
    merge_sort(array, start, mid, auxArray);
    // ... right sub-array, which is from array[mid + 1, ... end]
    merge_sort(array, mid + 1, end, auxArray);

    // declare pointers for the beginnings of the left and right sub-arrays
    int pointerLeft = start;
    int pointerRight = mid + 1;

    // loop from start to end to fill each element of auxArray[]
    for (int i = start; i < end + 1; i++)
    {
        // if pointerLeft points to the beginning of the right sub-array
        if (pointerLeft == mid + 1)
        {
            auxArray[i] = array[pointerRight];
            pointerRight++;
        }
        // if pointerRight points one past the end of the right sub-array
        else if (pointerRight == end + 1)
        {
            auxArray[i] = array[pointerLeft];
            pointerLeft++;
        }
        // if pointerLeft points to the smaller element
        else if (array[pointerLeft] < array[pointerRight])
        {
            auxArray[i] = array[pointerLeft];
            pointerLeft++;
        }
        // if pointerRight points to the smaller element
        else if (array[pointerLeft] > array[pointerRight])
        {
            auxArray[i] = array[pointerRight];
            pointerRight++;
        }
        // if pointerRight and pointerLeft point to values of the same value
        else
        {
            auxArray[i] = array[pointerLeft];
            pointerLeft++;
        }
    }

    // copy elements from auxArray[] to array[]
    for (int i = 0; i < end + 1; i++)
    {
        array[i] = auxArray[i];
    }
}
