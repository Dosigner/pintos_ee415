/* thread/fixed_point.h */

#define F (1<<14) //fixed point 1
#define INT_MAX ((1<<31)-1)
#define INT_MIN (-(1 << 31))
// x and y denote fixed_point numbers in 17.14 format
// n is an integer

int int_to_fp(int n);       /* integer -> fixed point */
int fp_to_int_round(int x); /* FP -> int (round) */
int fp_to_int(int x);       /* FP -> int (throw away) */
int add_fp(int x, int y);   /* FP + FP */
int add_mixed(int x, int n); /* FP + integer */
int sub_fp(int x, int y);   /* FP - FP */
int sub_mixed(int x, int n);/* FP - integer */

int mult_fp(int x, int y);    /* FP * FP */
int mult_mixed(int x, int n); /* FP * integer */
int div_fp(int x, int y);     /* FP/FP */
int div_mixed(int x, int n);  /* FP / int (x/n) */


int int_to_fp (int n) {
  return n * F; // Convert n to fixed point
}

int fp_to_int (int x) {
  return x / F; // Convert x to integer (rounding toward zero)
}

int fp_to_int_round (int x) {
  // Convert x to integer (rounding to nearest)
  return (x >= 0)? (x+F/2)/F:(x-F/2)/F;
}

int add_fp (int x, int y) {
  return x+y; // add x and y
}

int sub_fp (int x, int y) {
  return x-y; // subtract y from x
}

int add_mixed (int x, int n) {
  return x + n*F; // add x and n
}

int sub_mixed (int x, int n) {
  return x - n*F; // subtract n from x
}

int mult_fp (int x, int y) {
  return ((int64_t)x)*y /F; // multiply x by y
}

int mult_mixed (int x, int n) {
  return x*n; // multiply x by n
}

int div_fp (int x, int y) {
  return ((int64_t)x)*F /y; // divide x by y
}

int div_mixed (int x, int n) {
  return x/n; // divide x by n
}
