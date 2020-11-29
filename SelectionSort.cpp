// Example program
#include <iostream>
#include <string>
#define SIZE 10

int main()
{
    int arr[SIZE];
    for(int i = 0  ; i < SIZE ; ++i){
        std::cin >> arr[i] ; 
        
    }
    int min_index ;
    int temp ; 

    for(int i = 0 ; i < SIZE-1 ; ++i){
        min_index = i;
        for(int j =i+1 ; j < SIZE ; ++j){
         if(arr[j] < arr[min_index]) min_index = j ; 
        }
        temp = arr[i] ;
         arr[i] = arr[min_index];
         arr[min_index] = temp ;
    }
    for(int i: arr) std::cout << i << '\n' ; 
    
    
}
