#include <stdio.h>

typedef struct {
    char name[50];
    char address[100];
    char phone[15];

} Person;

void main(){
    Person array[5];
    char aux[50];
    
    for(int i=0; i<5; i++){
        setbuf(stdin, 0);
        printf("\n%dth Person Name: ", (i+1));
        fgets(array[i].name, 50, stdin);
        setbuf(stdin, 0);

        printf("\n%dth Person Address: ", (i+1));
        fgets(array[i].address, 50, stdin);
        setbuf(stdin, 0);

        printf("\n%dth Person Phone [ Ex: (xx) xxxxx-xxxx ]: ", (i+1));
        fgets(array[i].phone, 15, stdin);
        setbuf(stdin, 0);
    }

    for(i=0;i<5;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(str[i],str[j])>0){
                strcpy(s,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],s);
            }
        }
    }


}