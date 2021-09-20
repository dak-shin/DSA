#include<iostream>
using namespace std;


class point
{
  public :
    int x,y;
    int fun();

};
int point::fun()
{
  int add(int a, int b)
  {return a+b}

  return add(1,2);

}


int main()
{
  // int c[3][2][2] = {{{2,5},{7,9}},{{3,4},{6,1}},{{0,8},{11,13}}};

  // printf("%d %d %d %d %d\n",c, *c, c[0],c[0][0], *(*(*(c+1)+1)));

  int a=1;//      2     3
  cout<<++a + a++<<"\n" ;
  a=10;//         3+2           15    16         13 14        11  12
  cout<< a++<<"\t" << (a++)+(++a)<<"\t" << ++a+a++ <<"\t" <<++a-a++ <<"\n";
//                         16     14+16       14 + 13     12 - 11





  point p1;
  p1.fun();
}
