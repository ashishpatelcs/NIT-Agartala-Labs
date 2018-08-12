/*
    Name: Ashish Patel
    Date: 10/08/18
    Compiler Design Lab
    Program: Design a lexical analyzer for given language and the lexical analyzer should ignore redundant spaces, tabs and new lines. It should also ignore comments. Although the syntax specification states that identifiers can be arbitrarily long, you may restrict the length to some reasonable value. Simulate the same in C language.
    ** WORK IN PROGRESS**
*/

#include <stdio.h>
#include <stdlib.h>


// main program
int main(int argc, char* argv[]) {

    // open c program file for lexical analysis
    FILE* fp = fopen(argv[1], "r");
    FILE* op = fopen("lexi.txt", "w");
    if(!fp) {
        perror("File opening failed!");
        return EXIT_FAILURE;
    }

    // lexical analysis is here :=)
    int ch, _counter = 0, mline=0, mlclose=0;
    while ((ch = fgetc(fp)) != EOF) {
        
        if (ch == '/') {
            //_counter++;
            ch = fgetc(fp);
            if (ch == '*') {
                while((ch = fgetc(fp))!='*') {
                }
                if ((ch = fgetc(fp)) == '/') continue;
            }
            if (ch == '/') {
                //_counter++;
                while((ch = fgetc(fp)) != '\n') {}
            }
        }
        if (ch=='\n') {
            if (_counter == 2) {
                _counter = 0;
                continue;
            }
            continue;
        }

        if (ch==' ') {
            continue;
        }
        putc(ch, op);
    }

    // error handling
    if(ferror(fp))
        puts("I/O error when reading");
    else if(feof(fp))
        puts("\nLexical analysis is completed! Please check lexi.txt file\n");

    // close file after successful operation
    fclose(fp);
}
