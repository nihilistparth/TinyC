/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/

int printInt(int num);
int printStr(char * c);
int readInt(int *eP);

int test(int *a)
{
    return a;
}

int main()
{
    int a,b;
    int *e;
    
    printStr("        ############################ Testing Read Functions ############################# \n");
    b = 3;
    e = &b;
    printStr("\nEnter an Integer : ");
    b = readInt(e);
    printStr("The integer that was read is : ");
    printInt(b);
    printStr("\n");
    

    return 0;
}