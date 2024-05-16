/*  
    Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
    of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
    Should n be a variable or a symbolic parameter?
    
    Steps to approach the task:
        Understand the requirements
            Determine the fixed tab stop interval
            Replace each tab char in the input with the appropriate number of spaces to reach the next tab stop
            Ensure the output visually aligns the text as if tabs were still present
        Define constants and variables
        Read input
        Process each line
            Initialize a position counter to keep track of the current column positions
            Iterate through each character in the line
                If the character is \t
                    Calculate the number of spaces needed to reach the next tab stop
                    Append the calculated number of spaces to the output
                    Update the position counter accordingly
                If the character is not \t
                    Append the character to the output
                    Increment the position counter by 1
            Output the processed lines
*/

#include <stdio.h>
#define MAXLINE 1000
#define TABWIDTH 4
int tabcol1 = 8;
int tabcol2 = 16;
int get_line(char s[], int charlimit);
void detab(char s[]);

int main() {
    char line[MAXLINE];
    extern int tabstops;
    
    while (get_line(line, MAXLINE) > 0)
        detab(line);

    return 0;
}

int get_line(char s[], int charlimit) {
    int c, i;

    for (i = 0; i < charlimit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
        
    s[i] = '\0';

    return i;
}

void detab(char s[]) {
    int c, i, currpos;
    extern int tabcol1;
    extern int tabcol2;

    i = currpos = 0;

    while ((c = s[i]) != '\0') {
        if (c == '\t') {
            int spaces;
            if (currpos < tabcol1)
                spaces = tabcol1 - currpos;
            else if (currpos < tabcol2)
                spaces = tabcol2 - currpos;
            else
                spaces = TABWIDTH - (currpos % TABWIDTH);
            for (int j = 0; j < spaces; ++j) {
                putchar('_');
                currpos++;
            }
        } else {
            putchar(c);
            currpos++;
            if (c == '\n')
                currpos = 0;
        }
        i++;
    }
}

/*
                             |                       |
                             v                       v
    00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20
     h  e  l  l  o              w  o  r  l  d
     h  e  l  l  o           w  o  r  l  d
     a  b  c              d  e  f              g  h  i
     a  b  c                 d  e  f                 g  h  i
*/
























