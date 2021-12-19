/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/
int printStr(char *c);
int printInt(int i);
int readInt(int *eP);

int main () {
    int eP;
    printStr("\n ############################ Printing matrix of dimension n*n ################################# \n");    
    printStr(" Enter the the value of n \n");

    int b,n,i,j;
    n = readInt(&eP);

    for (i = 0; i < n; i++)
    {
        printStr("\n");
        for (j = 0; j < n; j++)
        {
            printStr("*");
        }
        
    }
    printStr("\n");
    return 0;
}