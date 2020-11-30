#include <iostream>
#include <string>
#define SIZE 10

int main()
{
    int arr[SIZE];
    int temp ; 
    for(int i = 0 ; i < SIZE ; ++i)std::cin >> arr[i];
    
    for(int i = 0 ; i < SIZE ; ++i){
        
        for(int j = i+1 ; j < SIZE ; ++j){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j] ; 
                arr[j] = temp;
            }
        }
        
    }
    
    for(auto i : arr) std::cout << i << '\n';
}
