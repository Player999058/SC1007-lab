#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//memory
int *r;


int cr_bottom_up_dp_print(int *p, int n)
{
    //write your code here
    int *index;
    int z = n;
    for (int j = 1 ; j <= n ; j++){
        for (int i = 1; i<=j ; i++){
            if(r[j] <= p[i] + r[j-i]) {
                r[j] = p[i] + r[j-i];
                index[j] = i;
            }
        }
    }
    printf("Rope cut by length: ");
    while (z > 0){
        printf("%d ", index[z]);
        z -= index[z];
    }
    return r[n];
}

 
void main ()
{
    int n;      //length of  rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,4,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    

    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    
    //set all memory elements to -1
    for (i=0; i<=n; i++)
        r[i] = 0;
                
    printf("The maximun value is: %d \n", cr_bottom_up_dp_print(p,n));
}
