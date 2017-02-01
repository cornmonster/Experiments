/*
 * I wrote bubble sort because I need to implement a
 * multi-process bubble sort program. This program 
 * sorts numbers in descending way.
 */
#include <iostream>
#include <vector>
using namespace std;
int bubbleSort(std::vector<long long> &nums,int begin, int end)
{
    bool change = true;
    long long swap;
    for(int j=0; j < nums.size(); j++)
    {
        change = false;
        for(int i=0; i < end-1-j; i++)
        {
            if(nums[i] < nums[i+1])
            {
                swap = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = swap;
                change = true;
            }
        }
        if(!change)
        {
            break;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    std::vector<long long> nums;
    long long temp;
    FILE *file;

    file = fopen(argv[1], "r");
    if(file == NULL)
    {
        fprintf(stderr, "Can't open this file.\n");
    }

    while((fscanf(file, "%lld\n", &temp)) != EOF)
    {
        nums.push_back(temp);
    }

    bubbleSort(nums, 0, nums.size());

    for(int i=0; i < nums.size(); i++)
    {
        printf("%lld\n", nums[i]);
    }
    return 0;
}

