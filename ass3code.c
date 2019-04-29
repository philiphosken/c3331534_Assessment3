#include <stdio.h>

int main(){
int selectionnumber = 0;

printf("Would you like use:\n\nRotation Encrytion with key: 1\nRotation Decryption with key: 2\nSubstitution Encryption with key: 3\nSubstitution Decryption with key: 4\nRotation Decryption NO KEY: 5\nSubstitution Decryption NO KEY: 6\n\n\n\n");
scanf("%d", &selectionnumber);

//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      1..........Rotation encrytion with key
//*****************************************************************************************************************************
//*****************************************************************************************************************************
if(selectionnumber == 1){

int k = 0; //KEY = the number of charcters shifted in the rotation cypher to generate coded message 
printf("(Key is the number of characters youd like the encryption to shift)\n\nKey: ");
scanf("%d", &k);

FILE *in; //protocall for opening a pointer to a file
FILE *out; //protocall for opening a pointer to a file
    
in = fopen("in.txt", "a+"); /*Opens a file called 'in.txt' for reading and appending (writing at end of file).  The file is created if it does not exist.  The initial
              file position for reading is at the beginning of the file, but output is always appended to the end of the file. */
out = fopen("out.txt", "w+"); /*Opens a file called 'out.txt' for writing and reading*/
    
    while (feof(in) == 0){ //while there is still infomation in the file continue reading 
    char phi;
    fscanf(in, "%c", &phi); //scan each character into the varaiable 'phi'

        if (phi == 32){ //if phi == 32 this means it is a space which we want the complier to print unchanged
        fprintf(out, "%c", phi); //Just prints the space to out.txt
        printf("%c", phi); //prints space to std out
     
        } else if((phi + k) > 90){ // If it exceeds 'Z' after k is added, then simply take 26 away then add k to create looping effect 
        fprintf(out, "%c", phi - 26 + k); //prints this charater to out.txt
        printf("%c", phi - 26 + k); //prints this character to std out 
        
        } else if ( (phi + k) < 65 ){ //If it exceeds 'Z' after k is added, then simply add 26 away then add k
        fprintf(out, "%c", phi + 26 + k); //prints this character to out.txt
        printf("%c", phi + 26 + k); //prints this character to std out
        
        } else { // if within the bounds of ASCII 'A' and 'Z' just add k
        fprintf(out, "%c", phi + k); //prints to file out.txt
        printf("%c", phi + k); // prints to std out
        }
    }
}
//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      2..........Rotation Decryption with key
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 2){
    
int k = 0; //KEY = the number of charcters shifted in the rotation cypher to generate coded message 
printf("(Key is the number of characters that have been shifted from original)\n\nKey: "); //prompt to enter a value that will be the Key
scanf("%d", &k); // stores the key into varible 'k' that can then be used to alter ascii numbers and hence alter letters 

FILE *in; //protocall for opening a pointer to a file
FILE *out; //protocall for opening a pointer to a file

in = fopen("in.txt", "a+"); // The a+ allows for reading and writing to the end of a file 
out = fopen("out.txt", "w+"); /*Opens a file called 'out.txt' for writing and reading*/
    
    while (feof(in) == 0){ //while there is still infomation in the file continue reading 
    char phi;
    fscanf(in, "%c", &phi);
      
        if (phi == 32){
        fprintf(out, "%c", phi); //Just prints the space
        printf("%c", phi);
    
        } else if((phi + k) > 90){ // If it exceeds 'Z' after k is added, then simply take 26 away then add k
        fprintf(out, "%c", phi - 26 + k); 
        printf("%c", phi - 26 + k);
        
        } else if ( (phi + k) < 65 ){ //If it exceeds 'Z' after k is added, then simply add 26 away then add k
        fprintf(out, "%c", phi + 26 + k);
        printf("%c", phi + 26 + k);
            
        } else {fprintf(out, "%c", phi + k);// if within the bounds of ASCII 'A' and 'Z' just add k
            printf("%c", phi + k);
        }

    } 
}
//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      3..........Substitution Encryption with key
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 3){
    
char alphatxt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
char subtxt[27] ; //Keeps 27 'boxes' of space someone in memory that the user input will sub for the alphabet PLUS SPACE 
char N = 27;
char m;
char i;
char a;
char b;

printf("What would you like to substitute the letters of the alphatbet too?\n\nABCDEFGHIJKLMNOPQRSTUVWXYZ<SPACE>\n\n");
scanf("%s", subtxt);

FILE *in;
FILE *out;

in = fopen("in.txt", "a+");
out = fopen("out.txt", "w+");
    
    while (feof(in) == 0){
    fscanf(in, "%c", &m);
        
        for (i = 0; i < N; ++i){
        a = alphatxt[i];
        b = subtxt[i];
        
        if (m == a){
        fprintf(out, "%c", b);
        printf("%c", b);
        }

    }
}
}
//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      4..........Substitution Decryption with key
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 4){

char alphatxt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
char subtxt[27] ; //Keeps 27 'boxes' of space someone in memory that the user input will sub for the alphabet
char N = 27;
char m;
char i;
char b;
char a;

printf("What have the letters of the alphabet been substituted for?\n\nABCDEFGHIJKLMNOPQRSTUVWXYZ <space> \n\n");
scanf("%s", subtxt);

FILE *in;
FILE *out;

in = fopen("in.txt", "a+");
out = fopen("out.txt", "w+");
    
    while (feof(in) == 0){
    fscanf(in, "%c", &m);
        
        for (i = 0; i < N; ++i){
        a = alphatxt[i];
        b = subtxt[i];
            
            if (m == b){
            fprintf(out, "%c", b);
            printf("%c", b);
    } 
       
}
}    
}
//*********************************************************************************************************************************
//*****************************************************************************************************************************
//      5..........Rotation Decryption NO KEY
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 5){
int k = 0; //KEY = the number of charcters shifted in the rotation cypher to generate coded message 
int option = 0;




FILE *in;
FILE *out;

in = fopen("in.txt", "a+"); /// Tha a+ allows for reading and writing to the end of a file (so i dont get two of the last character scan ABC print ABCC)
out = fopen("out.txt", "w+");
    
    while (feof(in) == 0){
    char phi;
    fscanf(in, "%c", &phi);
      
        if (phi == 32){
        fprintf(out, "%c", phi); //Just prints the space
        printf("%c", phi);
    
        } else if((phi + k) > 90){ // If it exceeds 'Z' after k is added, then simply take 26 away then add k
        fprintf(out, "%c", phi - 26 + k); 
        printf("%c", phi - 26 + k);
        
        } else if ( (phi + k) < 65 ){ //If it exceeds 'Z' after k is added, then simply add 26 away then add k
        fprintf(out, "%c", phi + 26 + k);
        printf("%c", phi + 26 + k);
            
        } else {fprintf(out, "%c", phi + k);// if within the bounds of ASCII 'A' and 'Z' just add k
            printf("%c", phi + k);
        }

    }
    fclose(in);
    fclose(out);
    

    for (k = 1 ; k < 26 ; k++){
    
    printf("\n\nis this the correct decryption? (KEY = %d) y/n\n\n", k);
    scanf("%d", &option);
    
    if(option == 121){
        break;
    } else {

FILE *in;
FILE *out;

in = fopen("in.txt", "a+"); /// Tha a+ allows for reading and writing to the end of a file (so i dont get two of the last character scan ABC print ABCC)
out = fopen("out.txt", "w+");
    
    while (feof(in) == 0){
    char phi;
    fscanf(in, "%c", &phi);
      
        if (phi == 32){
        fprintf(out, "%c", phi); //Just prints the space
        printf("%c", phi);
    
        } else if((phi + k) > 90){ // If it exceeds 'Z' after k is added, then simply take 26 away then add k
        fprintf(out, "%c", phi - 26 + k); 
        printf("%c", phi - 26 + k);
        
        } else if ( (phi + k) < 65 ){ //If it exceeds 'Z' after k is added, then simply add 26 away then add k
        fprintf(out, "%c", phi + 26 + k);
        printf("%c", phi + 26 + k);
            
        } else {fprintf(out, "%c", phi + k);// if within the bounds of ASCII 'A' and 'Z' just add k
            printf("%c", phi + k);
        }

    }

}
fclose(in);
fclose(out);
}
   
}       
//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      6..........Substitution Decryption NO KEY
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 6){

printf("ran out of time yet I have a basic understanding on how this concept could work");
    
}
} //final closing brace...end of program yaya