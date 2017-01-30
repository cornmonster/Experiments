
/*
 * I wrote bubble sort because I need to implement a
 * multi-process bubble sort program.
 */
#include <iostream>
using namespace std;
int bubbleSort(int *a, int length)
{
    bool change = true;
    int swap;
    while(change)
    {
        change = false;
        for(int i=0; i < length-1; i++)
        {
            if(a[i] > a[i+1])
            {
                swap = a[i];
                a[i] = a[i+1];
                a[i+1] = swap;
                change = true;
            }
        }
    }
    return 0;

}

int main() {
    int a[] = {6,5,4,3,2,1};
    bubbleSort(a, 6);
    for(int i=0; i < 6; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

