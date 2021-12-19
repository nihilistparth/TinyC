/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/
int printStr(char *c);
int printInt(int i);
int readInt(int *eP);

int main () {
  printStr("\n    ############################ Printing first N fibonacci numbers ###########################\n");


  printStr("Enter value of N : ");
  int i,ep;
  i=readInt(&ep);
  printStr("\nValue of N entered is : ");
  printInt(i);

  printStr("\n\nThe first ");
  printInt(i);
  printStr(" Fibonacci numbers are :\n\n        ");

  int j,a=0,b=1,c;

  if(i>0) printInt(a);
  printStr(" ");
  if(i>1) printInt(b);
  printStr(" ");

  for(j=2;j<i;j++){
    c = a+b;
    printInt(c);
    printStr(" ");
    a = b;
    b = c;

    int r=j/10;
    if(r*10==j){
      printStr("\n        ");
    }
  }

  printStr("\n");
  return;
}