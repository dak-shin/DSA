#include<stdio.h>

int main()
{
  int a=1;//      2     3
  printf("%d\n", ++a + a++ );
  a=10;
  //                          18           17    14  15      13  12    11
  printf("%d %d %d %d %d\n", a++, (a++)+(++a), ++a+a++ , ++a-a++, ++a);
//                            17     15+17      15+14     13-12   18
printf("%d\n",a );
a=10;//           12   12
printf("%d %d\n",++a,++a);

a=10;//           11  10
printf("%d %d\n",a++,a++);
//             12
printf("%d\n", a);
}
