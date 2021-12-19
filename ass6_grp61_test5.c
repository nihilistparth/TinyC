/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/
int printStr(char *c);
int readInt(int *ep);
int printInt(int i);

int factorial(int b){
  int ans;
  if(b==0)ans = 1;
  else ans = b*factorial(b-1);
  return ans;
}

int main() {
  int i,j=5,c;
  int *b = &c;
  printStr("      ###################### Factorial Function using Recursion  #################### \n");
  
  printStr("      Enter the the number for which the factorial is to be found    : ");
  j = readInt(b);

  c=factorial(j);
  printStr("\n\n       The value of factorial is  ");

  printInt(c);
  printStr("\n");
  return 0;
}