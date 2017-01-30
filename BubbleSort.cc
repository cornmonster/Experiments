/*
 * I wrote bubble sort because I need to implement a
 * multi-process bubble sort program. This program 
 * sorts numbers in descending way.
 */
#include <iostream>
#include <vector>
using namespace std;
int bubbleSort(std::vector<int> &nums,int begin, int end)
{
    bool change = true;
    int swap;
    while(change)
    {
        change = false;
        for(int i=begin; i < end-1; i++)
        {
            if(nums[i] < nums[i+1])
            {
                swap = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = swap;
                change = true;
            }
        }
    }
    return 0;

}

int main() {
    std::vector<int> v {65,32,698,678,3254,68,2,35,38,48,38,689,1,2,76,3,38,145,99};
    bubbleSort(v, 3, 7);
    for(int i=0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}

