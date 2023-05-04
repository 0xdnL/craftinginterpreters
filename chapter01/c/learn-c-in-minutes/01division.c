#include <stdio.h>

/*
  https://en.wikipedia.org/wiki/Division_algorithm

  input:
    N = numerator   (divided)
    D = denominator (divisor)
  ouput:
    Q = quotient
    R = remainder

  R := N
  Q := 0
  while R ≥ D do
    R := R − D
    Q := Q + 1
  end
  return (Q,R)
*/
void divide(int N, int D, int *q, int *r) {

    int R = N;
    int Q = 0;

    while (R >= D) {
      R = R - D;
      Q = Q + 1;
    }

    *q = Q;
    *r = R;
}

int main (){

  int q, r;
  divide(10, 4, &q, &r);
  printf("divide(10,4)=[Q=%i, R= %i] \n", q, r);

  printf("div(10,4)=%i\n", 10/4);
  printf("mod(10,4)=%i\n", 10%4);

}
