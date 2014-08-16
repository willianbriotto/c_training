/*
 * This samples has taken "Pratical C"
 * *Have some modifications*
 * Usage:						*
 *	print [options] file(s)				*
 *							*
 * Options:						*
 *	-v		Produce versbose messages	*
 *	-o<file>	Send output to a file 		*
 *			(default=filename.out)		*
 *	-l<lines>	Set the number of lines/page.	*
 *			(default=66).			*
 *  -h<help> Show usage()
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verbose = 0; //verbose  mode(default = false);
char *filename = "filename"; //output filename
char *file_extension = ".out"; //Accept file extension
char *program_name; //"Save" the of program to future use
int line_max = 66 //number of lines
char *token;

void do_file(char *name);
void usage(void);

int main(int argc, char *argv[])
{
	program_name = argv[0];
	
	while((argc > 1) && (argv[1][0] == '-')) {
		switch(argv[1][1]) {
			//verbose
			case 'v':
				verbose = 1;
			break;
			/*
             * -o<name>  output file
             *    [0] is the dash
             *    [1] is the "o"
             *    [2] starts the name
             */
			case 'o':
				filename = &argc[1][2];
				token = strtok(filename, '.');
				if(!token)
				   filename = strcat(filename, file_extension); 
			break;
			/*
             * -l<number> set max number of lines
             */
            case 'l':
                line_max = atoi(&argv[1][2]);
            break;
			// -h<help>
			case 'h':
				usage();
			break;	
            default:
                fprintf(stderr,"Bad option %s\n", argv[1]);
                usage();
		}
		++argv;
        --argc;
	}
	
	if(argc == 1)
		do_file("print.in");
	else {
		while(argc > 1) {
			do_file(argv[1]);
			++argv;
			--argc;
		}
	}
	return 0;
}

void do_file(char *name)
{
	printf("Verbose %d Lines %d Input %s Output %s\n",
        verbose, line_max, name, strcat(filename, file_extension));
}

void usage(void)
{
    fprintf(stderr,"Usage is %s [options] [file-list]\n", program_name);
    fprintf(stderr,"Options\n");
    fprintf(stderr,"  -v          verbose\n");
    fprintf(stderr,"  -l<number>  Number of lines\n");
    fprintf(stderr,"  -o<name>    Set output filename\n");
	fprintf(stderr,"  -h<help>    Show help\n");
    exit (8);
}