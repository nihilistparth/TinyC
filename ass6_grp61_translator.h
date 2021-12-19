/*
Group 61
Parth Tusham 19CS30034
Shashwat Shukla 19CS10056
*/
#ifndef TRANSLATE
#define TRANSLATE
#include <bits/stdc++.h>

#define CHAR_SIZE          1
#define INT_SIZE           4
#define DOUBLE_SIZE        8
#define POINTER_SIZE       4

using namespace std;

extern char *yytext;
extern int yyparse();

  // class for storing Entry in a symbol table
class sym;	
   // class for storing Entry in quad Array                                                                   
class quad;         
 // class for storing Type of a symbol in symbol table                                                          
class symtype;  
 // class for storing Symbol Table                                                                
class symtable;     
 // class for storing QuadArray                                                            
class quadArray;	                                                            

 // Array of Quads
extern quadArray q;    
 // Current Symbbol Table                                                          
extern symtable * table;           
// Pointer to just encountered symbol                                              
extern sym * currentSymbol;    
 // Global Symbbol Table                                                   
extern symtable * globalTable;                                                   




class symtype
{    // Type of symbols in symbol table                                                                             
	public:
	
	symtype(string type, symtype *ptr = NULL, int width = 1);
	string type;
	 // Size of Array (in case of Arrays)
	int width;
	 // for 2d Arrays and pointers                                                                   
	symtype * ptr;                                                               
};



class quad
{                                                                                  
	public:
		
	string op;                                                                    
	string result;                                                                
	string arg1;                                                                   
	string arg2;                                                                   

	void print();                                                                  
	quad(string result, string arg1, string op = "EQUAL", string arg2 = "");       
	quad(string result, int arg1, string op = "EQUAL", string arg2 = "");          
	quad(string result, float arg1, string op = "EQUAL", string arg2 = "");        
};



class quadArray
{                                                                                  
	public:
	
	vector<quad> Array;                                                            
	void print();                                                                  
};

class sym
{   // Symbols class                                                                           
	public:
	// Name of the symbol
	string name;                                                                 
	symtype * type;          
	// Type of the Symbol                                                      
	string initial_value;    
	// Symbol initial valus (if any)                                                     
	string category;                                                               
	int size;                                                                      
	int offset;     
	// Pointer to nested symbol table                                                               
	symtable * nested;                                                             

	sym(string name, string t = "INTEGER", symtype *ptr = NULL, int width = 0);    
	sym* update(symtype *t);                                                       
	sym* link_to_symbolTable(symtable *t);
};


class symtable
{   
	// Symbol Table class                                                                          
	public:
	// Name of Table
	string name;                                                                  
	int count; 
	// Count of temporary variables                                                                    
	list<sym> table;                                                              
	symtable * parent;                                                            
	map<string, int> ar; 
	// activation record
	symtable(string name = "NULL");
	// Lookup for a symbol in symbol table
	sym* lookup(string name);                                                      
	void print();                                                                 
	void update();                                                                 
};

struct statement
{
	list<int> nextlist;	                                                          
};

struct Array
{
	string cat;
	sym * loc;                                                                    
	sym * Array;                                                                  
	symtype * type;                                                                
};


struct expr
{
	string type;	                                                               

	
	sym * loc;                                                                     


	list<int> truelist;                                                           
	list<int> falselist;                                                           


	list<int> nextlist;
};


// GENTEMP A static method to generate a new temporary, insert
 // it to the Symbol Table, and return a pointer to the entry.

 // Parameter => takes pointer to the class of symbol type and 
 // returns the pointer to the newly created symbol table entry
sym* gentemp(symtype *t, string init = "");


void emit(string op, string result, string arg1 = "", string arg2 = "");	       
void emit(string op, string result, int arg1, string arg2 = "");                   
void emit(string op, string result, float arg1, string arg2 = "");                 


//Backpatching and related functions


void backpatch(list<int> lst, int i);
// Make a new list contaninig an integer
list<int> makelist(int i);       
// Merge two lists into a single list                                                  
list<int> merge(list<int> &lst1, list<int> &lst2);                                 


//Other helper functions required for TAC generation


sym* conv(sym *, string);                                                          
bool typecheck(sym* &s1, sym* &s2);                                               
bool typecheck(symtype *t1, symtype *t2);                                          

expr* convertInt2Bool(expr*);                                                     
expr* convertBool2Int(expr*);                                                     

void changeTable(symtable *newtable);                                              
int nextinstr();                                                                   


//Other helper function for debugging and printing


int size_type(symtype*);                                                          
string print_type(symtype*);                                                       

#endif