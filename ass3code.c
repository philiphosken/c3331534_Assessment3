#include <stdio.h>

int main(){
int selectionnumber = 0;

printf("Would you like use:\n\nRotation Encrytion with key: 1\nRotation Decryption with key: 2\nSubstitution Encryption with key: 3\nSubstitution Decryption with key: 4\nRotation Decryption NO KEY: 5\nSubstitution Decryption NO KEY: 6\n\n\n\n");
scanf("%d", &selectionnumber);

//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      1..........Rotation encrytion with key
//
//    This process will read a plain english message held within a file named in.txt. After this a rotation key can be entered which will 
//    then rotate the letters that many times resulting a encrypted output. My code will only process capital letters and spaces
//
//*****************************************************************************************************************************
//*****************************************************************************************************************************
if(selectionnumber == 1){

int k = 0; //KEY = the number of charcters shifted in the rotation cypher to generate coded message 
printf("(Key is the number of characters youd like the encryption to shift)\n\nKey: "); // Prompt user to input a key
scanf("%d", &k); //stores key value or character shift within variable k

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
//
//    The principle of this task is similar to that of task 1. This process will read a plain english message held within a file 
//    named in.txt. After this a rotation key can be entered which will then rotate the letters that many times resulting a encrypted 
//    output. My code will only process capital letters and spaces.
//
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 2){
    
int k = 0; //KEY = the number of charcters shifted in the rotation cypher to generate coded message 
printf("(Key is the number of characters that have been shifted from original)\n\nKey: "); //prompt to enter a value that will be the Key
scanf("%d", &k); // stores the key into varible 'k' that can then be used to alter ascii numbers and hence alter letters 

FILE *in; //protocall for opening a pointer to a file
FILE *out; //protocall for opening a pointer to a file

in = fopen("in.txt", "a+"); // The a+ allows for reading and writing to the end of a file 
out = fopen("out.txt", "w+"); //Opens a file called 'out.txt' for writing and reading
    
    while (feof(in) == 0){ //while there is still infomation in the file continue reading 
    char phi;
    fscanf(in, "%c", &phi);//Scans each individual character within in.txt and tests it within the flow control below
      
        if (phi == 32){
        fprintf(out, "%c", phi); //Just prints the space character with ascii 32 to out.txt
        printf("%c", phi); // prints the space character to std output
    
        } else if((phi + k) > 90){ // If it exceeds 'Z' after k is added, then simply take 26 away then add k
        fprintf(out, "%c", phi - 26 + k); // Prints the single corresponding charater to out.txt which is altered by the key based off the letter variable phi
        printf("%c", phi - 26 + k); // prints the same charater to std output
        
        } else if ( (phi + k) < 65 ){ //If it exceeds 'Z' after k is added, then simply add 26 away then add k
        fprintf(out, "%c", phi + 26 + k); //Prints the single corresponding charater to out.txt which is altered by the key based off the letter variable phi
        printf("%c", phi + 26 + k); //prints the same character to std output
            
        } else {
        fprintf(out, "%c", phi + k);// if within the bounds of ASCII 'A' and 'Z' just add k
        printf("%c", phi + k); // prints the corresponding letter alteration to the std output 
        }

    } 
}
//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      3..........Substitution Encryption with key
//
//      The substitution will prompt the user to input an alphabet that is made up followed by a space. The text in input.txt 
//      will then be read and compared with the english alphatbet that is so many places into an array. When the two equal, 
//      the value of the substitud alphabet so many places into the array will be printed to std output and the out.txt
//      as an encrypted message.
//
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 3){
    
char alphatxt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "; ///stores the letters of the alphabet AND A SPACE as a basis to compare letters too
char subtxt[27] ; //Keeps 27 'boxes' of space someone in memory that the user input will sub for the alphabet PLUS SPACE 
char N = 27; //N is a count limit so the 'i' counter doesnt exceed the space allocation of the array
char m; // short for message...This temporarily serves to hold the charater read from in.txt
char i; // counting index to access parts of an array
char a; // varible that holds the temporary value of alphatxt[i]
char b; // variable that temporaroily holds the value of subtxt[i]

printf("What would you like to substitute the letters of the alphatbet too?\n\nABCDEFGHIJKLMNOPQRSTUVWXYZ<SPACE>\n\n");
scanf("%s", subtxt); //takes the 27 entered characters

FILE *in; //protocall for opening a pointer to a file called in.txt
FILE *out; //protocall for opening a pointer to a file called out.txt

in = fopen("in.txt", "a+"); // The a+ allows for reading and writing to the end of a file 
out = fopen("out.txt", "w+"); //Opens a file called 'out.txt' for writing and reading
    
    while (feof(in) == 0){ //while there is still infomation in in.txt, the while loop will continue
    fscanf(in, "%c", &m); // scans charater from in.txt and stores it in 'm' temporarily
        
        for (i = 0; i < N; ++i){ //a counter for 0 to 26 in order to test all characters and the space
        a = alphatxt[i]; // variable holding temporarily alphatxt[i]
        b = subtxt[i]; // variable holding temporarily subtext[i]
        
        if (m == a){// if the letter stored in 'm' from the in.txt file is the same as a letter in the alphabet it proceeds to print the substitution
        fprintf(out, "%c", b);//prints sub to the out.txt file
        printf("%c", b); //prints to std out
        }

    }
}
}
//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      4..........Substitution Decryption with key
//
//      This task is similar to that of task 3. The substitution will prompt the user to input an alphabet that is the key 
//      required to decode the cipher up followed by a space. The text in input.txt will then be read and compared with 
//      the cipher alphatbet that is so many places into an array. When the two equal, the value of the real alphabet 
//      so many places into the array will be printed to std output and the out.txt as a message.
//
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 4){

char alphatxt[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "; ///stores the letters of the alphabet AND A SPACE as a basis to compare letters too
char subtxt[27] ; //Keeps 27 'boxes' of space someone in memory that the user input will sub for the alphabet
char N = 27; //N is a count limit so the 'i' counter doesnt exceed the space allocation of the array
char m; // short for message...This temporarily serves to hold the charater read from in.txt
char i; // counting index to access parts of an array
char a; // varible that holds the temporary value of alphatxt[i]
char b; // variable that temporaroily holds the value of subtxt[i]

printf("What have the letters of the alphabet been substituted for?\n\nABCDEFGHIJKLMNOPQRSTUVWXYZ <space> \n\n");
scanf("%s", subtxt); // scans an input from the prompt that serves as a key or replacement alphabet into an array called subtxt

FILE *in; //protocall for opening a pointer to a file called in.txt
FILE *out; //protocall for opening a pointer to a file called out.txt

in = fopen("in.txt", "a+"); // The a+ allows for reading and writing to the end of a file 
out = fopen("out.txt", "w+"); //Opens a file called 'out.txt' for writing and reading
    
    while (feof(in) == 0){ //while there is still infomation in in.txt, the while loop will continue
    fscanf(in, "%c", &m); // scans charater from in.txt and stores it in 'm' temporarily
        
        for (i = 0; i < N; ++i){ //a counter for 0 to 26 in order to test all characters and the space
        a = alphatxt[i]; // variable holding temporarily alphatxt[i]
        b = subtxt[i]; // variable holding temporarily subtext[i]
            
            if (m == b){ // if the letter stored in 'm' from the in.txt file is the same as a letter in the alphabet it proceeds to print the substitution
            fprintf(out, "%c", a); //prints sub to the out.txt file
            printf("%c", a); // prints to std out
    } 
       
}
}    
}
//*********************************************************************************************************************************
//*****************************************************************************************************************************
//      5..........Rotation Decryption NO KEY
//
//      This task has been hard coded to print the 25 variations involved in the rotation of the alphabet.
//      It is then up to the used to observe which message reads as plain english. This is similar to task 2,
//      just with extra prompts and all 25 rotations
//        
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 5){
int k = 0; //KEY = the number of charcters shifted in the rotation cypher to generate coded message 
int option = 0;

FILE *in; //protocall for opening a pointer to a file called in.txt
FILE *out; //protocall for opening a pointer to a file called out.txt

in = fopen("in.txt", "a+"); // opens a file in a+ allows for reading and writing to the end of a file (so i dont get two of the last character scan ABC print ABCC)
out = fopen("out.txt", "w+"); //Opens a file called 'out.txt' for writing and reading
    
    while (feof(in) == 0){ //continues to read from the file as long as there is still infomation ie. = 0
    char phi;
    fscanf(in, "%c", &phi); //stores the character temporarily in 'phi'
      
        if (phi == 32){
        fprintf(out, "%c", phi); //Just prints the space character with ascii 32 to out.txt
        printf("%c", phi); // prints the space character to std output
    
        } else if((phi + k) > 90){ // If it exceeds 'Z' after k is added, then simply take 26 away then add k
        fprintf(out, "%c", phi - 26 + k); // Prints the single corresponding charater to out.txt which is altered by the key based off the letter variable phi
        printf("%c", phi - 26 + k); // prints the same charater to std output
        
        } else if ( (phi + k) < 65 ){ //If it exceeds 'Z' after k is added, then simply add 26 away then add k
        fprintf(out, "%c", phi + 26 + k); //Prints the single corresponding charater to out.txt which is altered by the key based off the letter variable phi
        printf("%c", phi + 26 + k); //prints the same character to std output
            
        } else {
        fprintf(out, "%c", phi + k);// if within the bounds of ASCII 'A' and 'Z' just add k
        printf("%c", phi + k); // prints the corresponding letter alteration to the std output 
        }

    }
    fclose(in); // this will close the in.txt file so when it is opened again and the key is altered, it will start reading the file again from the begining 
    fclose(out); // this will close the in.txt file so when it is opened again and the key is altered, it will start reading the file again from the begining 
    

    for (k = 1 ; k < 26; k++){ // a counter for the key which will make for all 25 rotatioins of the alphabet
    
    printf("\n\nis this the correct decryption? (KEY = %d) y/n\n\n", k); // prompt for user input y (yes) or n (no)
    scanf("%d", &option); //scans input and stores the ascii value of y or n in the variable 'option'
    
    if(option == 121){
        break; //if the input was y for yes this means the message has been decoded hence the code can jump out of the loop and discontinue
    } else { //n for no would have been entered so the loop would continue to the next key value

FILE *in; //reopens the files using the protocall
FILE *out;

in = fopen("in.txt", "a+"); // Tha a+ allows for reading and writing to the end of a file (so i dont get two of the last character scan ABC print ABCC)
out = fopen("out.txt", "w+"); //Opens a file called 'out.txt' for writing and reading
    
    while (feof(in) == 0){ //continues to read from the file as long as there is still infomation ie. = 0
    char phi;
    fscanf(in, "%c", &phi); //stores the character temporarily in 'phi'
      
        if (phi == 32){
        fprintf(out, "%c", phi); //Just prints the space character with ascii 32 to out.txt
        printf("%c", phi); // prints the space character to std output
    
        } else if((phi + k) > 90){ // If it exceeds 'Z' after k is added, then simply take 26 away then add k
        fprintf(out, "%c", phi - 26 + k); // Prints the single corresponding charater to out.txt which is altered by the key based off the letter variable phi
        printf("%c", phi - 26 + k); // prints the same charater to std output
        
        } else if ( (phi + k) < 65 ){ //If it exceeds 'Z' after k is added, then simply add 26 away then add k
        fprintf(out, "%c", phi + 26 + k); //Prints the single corresponding charater to out.txt which is altered by the key based off the letter variable phi
        printf("%c", phi + 26 + k); //prints the same character to std output
            
        } else {
        fprintf(out, "%c", phi + k);// if within the bounds of ASCII 'A' and 'Z' just add k
        printf("%c", phi + k); // prints the corresponding letter alteration to the std output 
        }

    }

}
fclose(in); // this will close the in.txt file so when it is opened again and the key is altered, it will start reading the file again from the begining 
fclose(out); // this will close the in.txt file so when it is opened again and the key is altered, it will start reading the file again from the begining 
    
}
   
}       
//*****************************************************************************************************************************
//*****************************************************************************************************************************
//      6..........Substitution Decryption NO KEY
//*****************************************************************************************************************************
//*****************************************************************************************************************************
else if (selectionnumber == 6){

printf("ran out of time yet I have a basic understanding on how this concept could work"); // an emotional message
    
}
} //final closing brace...end of program yaya