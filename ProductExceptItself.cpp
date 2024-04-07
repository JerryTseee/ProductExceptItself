#include <iostream>
using namespace std;

/*
Given an integer array nums,
return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
*/

int * productExceptItself(int* nums, int length){
    int* output = new int[length];
    int* left = new int[length];
    int* right = new int[length];
    
    left[0] = 1;
    right[length - 1] = 1;

    //calculate the product of left side
    for (int i = 1; i < length; i++){
        left[i] = left[i-1]*nums[i-1];
    }
    //calculate the product of right side
    for (int i = length - 2; i >= 0; i--){
        right[i] = right[i+1]*nums[i+1];
    }
    //multiply left and right together
    for (int i = 0; i < length; i++){
        output[i] = left[i] * right[i];
    }

    delete[] left;
    delete[] right;

    return output;
}

int main(){
    int nums[] = {1,2,3,4};
    int length = sizeof(nums) / sizeof(nums[0]);

    int * result = productExceptItself(nums, length);

    //print the output
    for (int i = 0; i < length; i++){
        cout << result[i] << " ";
    }
    cout<<endl;

    delete[] result;
    return 0;
}