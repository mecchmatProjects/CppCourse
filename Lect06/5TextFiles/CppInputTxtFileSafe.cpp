#include <iostream>
#include <cstdlib>
#include <cctype>

#define BUF_LEN 100
#define SPACE 32
#define SPCL_CHAR1F 33
#define SPCL_CHAR1L 47
#define SPCL_CHAR2F 58
#define SPCL_CHAR2L 64
#define SPCL_CHAR3F 91
#define SPCL_CHAR3L 96
#define NUMF 48
#define NUML 57
#define UC_CHARF 65
#define UC_CHARL 90
#define LC_CHARF 97
#define LC_CHARL 122

nt main () {
    int SpcCounter, SpclCounter, NumCounter, LcCounter, UcCounter;
    char line[BUF_LEN], response[4];
    bool repeat = false;

    do {
        SpcCounter = SpclCounter = NumCounter = LcCounter = UcCounter = 0;

        // Get a line until valid.

        int stat = getLine ("\nEnter a line: ", line, BUF_LEN);
        while (stat != OK) {
            // End of file means no more data possible.

            if (stat == NO_INPUT) {
                cout << "\nEnd of file reached.\n";
                return 1;
            }

            // Only other possibility is "Too much data on line", try again.

            stat = getLine ("Input too long.\nEnter a line: ", line, BUF_LEN);
        }

 for (int i = 0; i < strlen (line); i++) {
            char temp=line[i];
            if(temp==SPACE||temp==255)
                SpcCounter++;
            else if((temp >= SPCL_CHAR1F && temp <= SPCL_CHAR1L)||
                (temp >= SPCL_CHAR2F && temp <= SPCL_CHAR2L)||
                (temp >= SPCL_CHAR3F && temp <= SPCL_CHAR3L))
                SpclCounter++;
            else if (temp >=NUMF && temp <= NUML)
                NumCounter++;
            else if (temp >= UC_CHARF && temp <= UC_CHARL)
                UcCounter++;
            else if (temp >= LC_CHARF && temp <= LC_CHARL)
                LcCounter++;
        }

        printf("There were %i space%s, %i special character%s, "
               "%i number%s, and %i letter%s,\n"
               "consisting of %i uppercase letter%s and "
               "%i lowercase.\n",
            SpcCounter,  (SpcCounter==1?"":"s"),
            SpclCounter, (SpclCounter==1?"":"s"),
            NumCounter, (NumCounter==1?"":"s"),
            UcCounter+LcCounter, (UcCounter+LcCounter==1?"":"s"),
            UcCounter, (UcCounter==1?"":"s"),
            LcCounter);

 // Get a line until valid yes/no, force entry initially.

        *line = 'x';
        while ((*line != 'y') && (*line != 'n')) {
            stat = getLine ("Try another line (yes/no): ", line, BUF_LEN);

            // End of file means no more data possible.

            if (stat == NO_INPUT) {
                cout << "\nEnd of file reached, assuming no.\n";
                strcpy (line, "no");
            }

            // "Too much data on line" means try again.

            if (stat == TOO_LONG) {
                cout << "Line too long.\n";
                *line = 'x';
                continue;
            }

            // Must be okay: first char not 'y' or 'n', try again.

            *line = tolower (*line);
            if ((*line != 'y') && (*line != 'n'))
                cout << "Line doesn't start with y/n.\n";
        }
    } while (*line == 'y');
}   
