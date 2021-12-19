/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/
#include "myl.h"
#define BUFF 32
int printStr(char *s) 
{
    int i;
    int len = 0;
    while (s[len] != '\0') //iterate till the end of the string
    {
        len++;
    }
    for (i = 0; i < len; i++)
        ;
    __asm__ __volatile__(
        "movl $1, %%eax \n\t"        //what to write
        "movq $1, %%rdi \n\t"        //where to write, which is primary output in our case   
                                    // system call
        "syscall \n\t"
        :
        : "S"(s), "d"(i));
    
    if(i){                         
        return OK;
    }
    return ERR;                    
}
int printInt(int n)                 
{
    char buff[BUFF];                        //buffer memo to store the integer as string or char array
    char zero = '0';                        
    int i = 0, j = 0, k = 0, bytes; 
    if (n == 0)                            
    {
        buff[i++] = zero;
    }
    else
    {
        if (n < 0)                          //if n is negative put a minus sign in front 
        {
            buff[i++] = '-';
            n = -n;                         // and change the number n to postive    
        }
        while (n)                           // In this loop we are extracting out the digits of n                            
        {
            int d = n % 10;
            buff[i++] = (char)(zero + d);
            n /= 10;
        }
        if (buff[0] == '-')                //if minus present then start from 1st index else 0th index                 
        {
            j = 1;
        }
        else
        {
            j = 0;
        }
        k = i - 1;
        while (j < k)                      //reverse the extracted digits             
        {
            char temp = buff[j];
            buff[j++] = buff[k];
            buff[k--] = temp;
        }
    }
    buff[i] = ' ';                        //place a new line (optional)                         
    bytes = i + 1;

    __asm__ __volatile__(
        "movl $1, %%eax \n\t"               //what to write
        "movq $1, %%rdi \n\t"               //where to write, which is primary output in our case   
                                            // system call
        "syscall \n\t"
        :
        : "S"(buff), "d"(bytes));
    return bytes;                       
}
int readInt(int *ep) {
	char buff[1];
	char n[20];
	int num=0,len=0,i;
	while (1) {
	 __asm__ __volatile__ ("syscall"::"a"(0), "D"(0), "S"(buff), "d"(1));/*readIntng inputs one by one from STDIN to buff*/
		if(buff[0]=='\t'||buff[0]=='\n'||buff[0]==' ') break;/*breaks at the first encounter of whitespace*/
		else if (((int)buff[0]-'0'>9||(int)buff[0]-'0'<0)&& buff[0]!='-') *ep=1;/*only '-' or digits are allowed, else error*/
		else{
			n[len++]=buff[0]; 
		}
	}
	if(len>9||len==0){/*less than 9 bits allowed, keeping in mind the range of int in C*/
		*ep=1;
		return 0;
	}
	if (n[0]=='-') {
		if(len==1) {
			*ep=1;
			return 0;
		}
		for (i=1;i<len;i++) {
			if(n[i]=='-') *ep=1;/*a number can contain '-' only at the starting of the number*/
			num*=10;
			num+=(int)n[i]-'0';
		}
		num=-num;
	}
	else{
		for (i=0;i<len;i++) {
			if (n[i]=='-') *ep=1;/*a number can contain '-' only at the starting of the number*/
			num*=10;
			num+=(int)n[i]-'0';
		}
	}
	return num;/*number is returned*/
}

int readFlt (float * f)
{
    int sz;                                     //size of input number 
    char buff2[BUFF];                           // input buffer memory

    __asm__ __volatile__ (
        "movl $0, %%eax \n\t"
        "movq $0, %%rdi \n\t"   // stdin
        "syscall \n\t"
        : "=a"(sz)
        :"S"(buff2), "d"(BUFF)
    );

    if (sz < 0) { 
        // printf("error return 1");
        return ERR;
    }   

    char buff[sz];//main
    char buff3[sz];//e
    int k;
    for (k = 0; k < sz; k++){
    
        buff[k] = buff2[k];                         //dulplicating memo to perform checks such that its scientific notation or not
        buff3[k] = buff2[k];
    }
    buff[sz - 1] = '\0';                            //placing null character at the end of the array    
    int is_E_present =0;
    int is_minus = 0;
    int pos = sz;
    for(int i = 0;i<sz;i++){
        if(buff3[i]=='E' || buff3[i]=='e'){         // checking if it contains E (or e) or not
            is_E_present =1;
            pos = i+1;                              //storing lenght of number before E
            if(buff3[pos]=='-'){                    //checking if its negative power or positive    
                is_minus = 1;
            }
            break;
        }
    }
    float mul  =1;                      
    if(is_E_present){                               //if E is present then accumulate power or strore the coefficient
        // char  buff4[sz]; 
        int ten_pow = 0;
        for(int i=pos+is_minus;i<sz-1;i++){
           if(buff3[i]>='0' && buff3[i]<='9'){          //checking if it contains digits only 
                ten_pow = ten_pow*10 + (buff3[i]-'0');  //calculating coefficient to be multiplied    
           }    
           else{
                // printf("error return 2");

               return ERR;
           }
        }
        for(int i = 0;i<ten_pow;i++){
            mul*=10.0;                                  // storing coeff   
        }
    }
    // printf("mul is %d \n",mul);
   
    int count = 0;                                      // number of dots
    float val = 0;                                      // final value
    float shift = 1;                                    // shift if minus present
    char num;
    if (buff[0] == '-')                                 // keep minus at front if negative number
    {
        int idx =1;                                     
        float sign = -1;                                //change sign
        int j;
        j=0;
        for ( j = idx; j < pos - 1; j++)
        {
            num = buff[j];
            if (num == '.' && count == 0)              // check where the integer and fractional part are separated
            {
                count = 1;
                continue;
            }
            else if (num == '.' && count > 0)           // check where the integer and fractional part are separated
            {   
            //    printf("error return 3");

                return ERR;
            }

            if ((num - '0') >= 0 && (num - '0') <= 9)   // check where the integer and fractional part are separated
            {
                num = num - '0';
                if (count == 1)
                    shift = shift / ((float) 10.0);
                val = val * 10.0 + (float)num;
            }
            else{
            //    printf("error return 4");
                return ERR;
            }
        }
        
        if(is_minus){                               // if the coeff negative then divide
             *f = (sign * val * shift);
             *f/=mul;
        }
        else{                                       //else multiply
            *f = (sign * val * shift*mul);
        }
        // printf("f is %f \n",*f);

    }
    else {                                          // if the number is positive
        float sign =1;
        int idx = 0;
        int j;
        for ( j = idx; j < pos - 1; j++)
        {
            num = buff[j];
            if (num == '.' && count == 0)           
            {
                count = 1;
                continue;
            }
            else if (num == '.' && count > 0)
            {
                return ERR;
            }

            if ((num - '0') >= 0 && (num - '0') <= 9) //check if the number only contains digits
            {
                num = num - '0';
                if (count == 1)
                    shift = shift / ((float) 10.0);
                val = val * 10.0 + (float)num;
            }
            else
                return ERR;
        }
        if(is_minus){                                   //if minus coeff divide with power of 10
             *f = (sign * val * shift);
             *f/=mul;
        }
        else{                                             //else multiply with poer of ten  
            *f = (sign * val * shift*mul);
        }
       
        // printf("f is %f \n",*f);

      
    }
    return OK;

}
int printFlt (float f)
{
    char INTEGER_L[40]; // storing the intefetr part on the left of decimal point
    char FRACTION_R[7]; //stroing the fraction on the right of decimal point
    int len =0;         // max len of precision 6 (as per standard)
    for(len=0;len<7;len++){
        FRACTION_R[len] = '0';
    }
    long long int integer_part = (long long int)f;
    int part_left = (int)((f - integer_part) * 1000000); //converting fraction to integer to extract digits

    if(part_left<0){
        part_left*=-1;                                      
    }

    int index = 5;
    while (index >= 0 && part_left > 0)
    {
        FRACTION_R[index--] = '0' + part_left % 10;         //extracting digits from fractional part
        part_left /= 10;
    }
    FRACTION_R[6] = '\0';                                   //placing terminal null character at the end of the array

    int i = 0;
    if(integer_part == 0)                                   // if integer part is zero then just place 0 at the start
    {
        INTEGER_L[0] = '0';                                  
        i = 1;
    }

    else if(integer_part>0){                                // if integer part is positve extract digits normally         
         while(integer_part > 0)
        {
            INTEGER_L[i++] = '0' + integer_part % 10;
            integer_part /= 10;
        }
    }
    else if(integer_part<0){                                // if integer part is negative then place minus sign at front and take absolute value of the negatove number
        integer_part*=-1;
        while(integer_part > 0)
        {
            INTEGER_L[i++] = '0' + integer_part % 10; //extracting digits
            integer_part /= 10;
        }
        INTEGER_L[i++] = '-';
    }

    char buffer[i+1];
    for(int j = i - 1; j >= 0; j--)
        buffer[j] = INTEGER_L[i - j - 1];               //reversing to get the correct representation
    buffer[i] = '\0';

    char buff[i+9];            
    for(int j = 0; j < i; j++)
        buff[j] = buffer[j];

    buff[i] = '.';                                      //placing decimal point after placing integer part of the floating point number

    for(int j = i+1; j < i + 7; j++){
      if(FRACTION_R[j-i-1]!='\0')  buff[j] = FRACTION_R[j - i - 1]; //place digits until termnial null caharachter is encountered
      else{                                                         //else place a zero before the terminal charcter to handle case where 0 is printed as 0. only
          buff[j++] = '0';
          buff[j] = '\0';
          break;
      }

    }

    int sz = i + 7;
    
    buff[i + 8] = '\0';                                         

    __asm__ __volatile__ (
            "movl $1, %%eax \n\t" 
            "movq $1, %%rdi \n\t"
            "syscall \n\t"
            :
            :"S"(buff), "d"(sz)
        );
    if(sz){         
        return OK;
    }
    else{
        return ERR;
    }
}