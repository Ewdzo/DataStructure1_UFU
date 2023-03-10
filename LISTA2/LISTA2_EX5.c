#include <stdio.h>

#define MAX 3

typedef struct {
    char name[50];
    char sex;
    int age;
} Person;

int createGroup(){
    Person array[MAX];
    int countMasc = 0;
    int countOverFifteen = 0;

    for(int i=0; i<MAX; i++){
        setbuf(stdin, 0);
        printf("%dth person's Name: ", (i+1));
        fgets(array[i].name, 50, stdin);

        setbuf(stdin, 0);
        printf("%dth person's Sex (M/F): ", (i+1));
        fgets(array[i].sex, 1, stdin);
        if(array[i].sex == 'M' || array[i].sex == 'm') countMasc++;

        setbuf(stdin, 0);
        printf("%dth person's Age: ", (i+1));
        scanf("%d", &array[i].age);
        if(array[i].age > 15) countOverFifteen++;
    }

    printf("There are %d person of the Masculine Gender", countMasc);
    return countOverFifteen;
}

void main(){
    int overFifteen = createGroup();
}