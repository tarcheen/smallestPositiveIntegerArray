/* Developer: Hamed Mirlohi
   Date: Oct 29th 2019
   In this problem we are writing a function that give an array A of N integers, returns the
   smallest positive integer(greater) than zero, that does not occur in A.
   For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5
   Given A = [1,2,3], the function should return 4
   Given A = [-1, -3], the function should return 1
*/

#include <iostream>
#include <map>

typedef unsigned int u_int;

int smallestN(int* arr, int size)
{
    // if empty array, answer is 1
    if(!size)
        return 1;
    
    // create hash-table to store all elements larger than zero
    std::map<u_int, u_int> m;
    //if no element exist return 1
    
    
    for(int i = 0; i < size; i++)
    {

        if(arr[i] < 1)
            continue;
        else
            m[arr[i]] = arr[i];
    }
    
    // if hash table empty, answer is 1
    if(m.size() < 1)
        return 1;
    
    // now lets sort the array
    //std::sort(std::begin(vec),std::end(vec),sortIt);
    
    // 1 doesnt exist, must be the answer
    if(m.find(1) == m.end())
        return 1;
    
    // at this point we know the first element is 1
    for(int i = 0; i < m.size() - 1; ++i)
    {
        // return the first gap between numbers
        if(m[i+1] - m[i] > 1)
            return m[i] + 1;
    }
    
    // no gaps found, return a number after the largest element in the array
    return m.size() + 1;
}


int main()
{
    int arr[] = {3,4,2,-1,8,1,5};
    //int arr[] = {-1,-3};
    int res = smallestN(arr, sizeof(arr) / sizeof(int));
    
    std::cout<< "smallest element is: "<< res << std::endl;
}