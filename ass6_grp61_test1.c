
/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/
int printInt(int num);
int printStr(char * c);
int readInt(int *eP);

int main()
{
    int a,b;
    int *e;
    
    printStr("\n        ########################## Testing Print FUNCTION ############################\n");
    
    b = 1;
    e = &b;

    printStr(" printing first 10 non negative integers \n");
    for(a=0;a<10;a++){
        printInt(b);
        printStr(" ");
        b = b+1;
    }
     printStr("\n");
    return 0;
}