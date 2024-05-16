/* Section 1.9: Character Arrays */

#include <stdio.h>

/* a program that reads a set of text
   lines and prints the longest
*/

// #define MAXLINE    10     /* maximum input line length */

// function declarations
/* int get_line(char line[], int maxline);
void copy(char to[], char from[]);
*/
/* print the longest input line */
// int main() {
//    int len;               /* current line length */
//    int max;               /* maximum length seen so far */
//   char line[MAXLINE];    /* current input line */
//    char longest[MAXLINE]; /* longest line saved here */

/*    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
           max = len;
           copy(longest, line);
        } */
//    if (max > 0)            /* there was a line */
//        printf("The length of the longest line is %d characters.\n", max); /* EX 1-16 */
/*        printf("%s", longest);
    return 0;
}
*/
/* get_line: read a line into s, return length */
//int get_line(char s[], int lim) {
//    int c, i;
//    int j; /* EX 1-16 */
//    j = 0; /* EX 1-16 */

    // for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    // Begin EX 1-16
/*    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[j++] = c;
        }
    }
    
    if (c == '\n' && i < lim - 1) {
        s[j++] = c;
        ++i;
    } */
    // End EX 1-16
        /* s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    } */
//    s[i] = '\0';
//    return i;
//}

/* copy: copy 'from' into 'to'; assume to is big enough */
/* void copy(char to[], char from[]) {
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
} */

/* Exercise 1-17: Write a program to print all input lines that are longer than 80 characters. */
// I'm going to change it to 10 characters for easier testing
/* #define MINCHARS 10
#define MAXCHARS 1000
int get_line(char line[], int lim);

int main() {
    int len;
    char line[MAXCHARS];
    
    while ((len = get_line(line, MAXCHARS)) > 0)
        if (len >= MINCHARS)
            printf("%s\n", line);

    return 0;
}
*/
/* read a line into s, return length */
/* int get_line(char s[], int lim) {
    int c, i;

    // Read characters until the limit is reached, EOF is encountered, or a newline is encountered
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c; // Store the character in the array s

    // Check if the last character read was a newline
    if (c == '\n') {
        s[i] = c; // Store the newline character in the array s
        ++i;
    }

    s[i] = '\0'; // Null-terminate the string

    return i; // Return the length of the line
}
*/

/* Exercise 1-18: Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */
#define MAX     1000
// Without help
/* int get_line(char s[], int charlimit);

int main() {
    int len;
    char line[MAX];

    while ((len = get_line(line, MAX)) > 0) {
        for (int i = 0; i < len; ++i) {
            // Check if there is a space in the string. Example: Hello world
            if (line[i] == ' ' || line[i] == '\t') {
                line[i] = '_';
            }
            // Check if the last character is a space or a tab
            if (line[len - 2 - i] == ' ' || line[len - 2 - i] == '\t') {
               line[len - 2 - i] = '\0'; 
            }
        }
        for (int i = 0; i < len; ++i) {
            if (line[i] == '_') {
                line[i] = ' ';
            }
        }
        
        printf("%s", line);
    }
    
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
} */

// With help
/* int get_line(char line[], int maxline);
int remove_trailing_blanks(char line[]);

int main() {
    char line[MAX];

    while (get_line(line, MAX) > 0) {
        if (remove_trailing_blanks(line) > 0) {
            printf("%s", line);
        }
    }

    return 0;
}

int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int remove_trailing_blanks(char s[]) {
    int i = 0;
    
    while (s[i] != '\0') {
        i++;
    }

    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')) {
        i--;
    }

    if (i >= 0) {
        s[++i] = '\n';
        s[++i] = '\0';
    } else {
        s[0] = '\0';
    }

    return i;
}
*/

/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */
// Without help
/* int get_line(char s[], int charlimit);
void reverse(char s[]);

int main() {
    char line[MAX];

    while(get_line(line, MAX) > 0)
        reverse(line);

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

    s[i++] = '\0';
    
    return i;
}

void reverse(char s[]) {
    int i, j, len;
    char line[MAX];
    
    i = 0;
    j = 0;
    
    while (s[i] != '\0')
        ++i;
    
    len = i;
    for (j = 0; j <= len; ++j) {
        line[j] = s[i];
        printf("%c", line[j]);
        --i;
    }

    return;
} */

// With help
int get_line(char line[], int charlimit);
void reverse(char s[]);

int main() {
    char line[MAX];

    while (get_line(line, MAX) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverse(char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        ++len;
    }

    int i, j;
    char temp;
    for (i = 0, j = len - 1; i < j; ++i, --j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
































