#include <iostream>

int main() {
    int scores[10] = {52, 78, 75, 68, 88, 63, 75, 90, 78};  
   
    int item = 10;                                        
    int k = 3;                                           
    int len = 9;                                          
    int j = len - 1;                                      

    
    while (j >= k) {
        scores[j + 1] = scores[j]; 
        j = j - 1;                  
    }

    scores[k] = item;  

   
    for (int index = 0; index < len + 1; index++) { 
        std::cout << scores[index] << " ";          
    }

    std::cout << std::endl;  

    return 0;
}

