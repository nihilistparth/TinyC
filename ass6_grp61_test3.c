/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/
int printStr(char *c);
int printInt(int i);
int readInt(int *eP);
int a;
int b = 1;
char c;
char d = 'a';

int mul (int a, int b) {
  int ans = a*b;
  return ans;
}
int main () {
  int c = 2, d, arr[10];
  int*p;
  int x, y, z;
  int eP;
  printStr("\n    ######################### multiplying two numbers in by passing to a function ###########################\n");
  printStr("\n    Enter first numbers  : ");
  x = readInt(&eP);
  printStr("    Enter second numbers : ");
  y = readInt(&eP);
  z = mul(x,y);
  printStr("\n    multiplication is equal to : ");
  printInt(z);
  printStr("\n");
  return c;
}
