#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <fstream>
using namespace std; 

int coordinate[1 << 20][2]; 


int LeastTime(int start, bool flag, int arr[], int& n) 
{ 

    
    if (!start) 
        return 0; 

    int& output = coordinate[start][flag]; 

     
    if (~output) 
        return output; 

    
    int endpoint = ((1 << n) - 1) ^ start; 

    
    if (flag == 1) { 
        int least_step = INT_MAX, person; 
        for (int i = 0; i < n; ++i) { 

            
            if (endpoint & (1 << i)) { 
                if (least_step > arr[i]) { 
                    person = i; 
                    least_step = arr[i]; 
                } 
            } 
        } 

         
        output = arr[person] + LeastTime(start | (1 << person), 
                                        flag ^ 1, arr, n); 
    } 
    else { 

        
        if (__builtin_popcount(start) == 1) { 
            for (int i = 0; i < n; ++i) { 

                
                if (start & (1 << i)) { 
                    output = arr[i]; 
                    break; 
                } 
            } 
        } 
        else { 

             
            output = INT_MAX; 
            for (int i = 0; i < n; ++i) { 

                
                if (!(start & (1 << i))) 
                    continue; 

                for (int j = i + 1; j < n; ++j) { 
                    if (start & (1 << j)) { 

                        
                        int calculate = max(arr[i], arr[j]); 

                        
                        calculate += LeastTime(start ^ (1 << i) ^ (1 << j), 
                                                    flag ^ 1, arr, n); 
                        
                        output = min(output, calculate); 
                    } 
                } 
            } 
        } 
    } 
    return output; 
} 


int findTime(int arr[], int n) 
{ 
    
    int masking = (1 << n) - 1; 

    
    memset(coordinate, -1, sizeof(coordinate)); 

    return LeastTime(masking, 0, arr, n); 
} 


int main() 
{ 
   
    ifstream file("input.yaml");
    if (file.is_open())
    {
        int n = 0;
        int arr[10000]; 
 
        while ( true)
        {
            int x;
            file >> x;
            if (file.eof())
                break;
            arr[n++] = x;
        }
        cout << " Number of people : " << n <<std::endl ;
        cout << " Their respective speed : ";
        for (int i = 0; i < n; ++i)
            cout << arr[i] <<" ";
        cout << std::endl;
        
        cout << " Fastest time to cross the bridge : " << findTime(arr, n) << " minutes " <<std::endl;
    }
    else
    {
        cout << "Unable to open file";
    }
     
    return 0; 
}