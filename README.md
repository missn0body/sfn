# sfn (Short FileName)

To get back to that good 'ol days of "Abort, Retry, Fail?"
First written by anson in the summer of 2023.

This is a short .c program featuring one main() function
and one converter function, which is designed to convert
passed strings representing hypothetical (or real perhaps)
filenames to 8.3 short DOS filenames using Microsoft's
standards. 

This program will not modify any filenames or any files, and
only prints results to stdout. 'sfn' is mainly a visualization
tool.

Command-line arguments are as follows:
> sfn (string)

where (string) is the aformentioned hypothetical filename.
If the string inputted does not resemble a typical filename,
then the program will format it as such regardless.

### v.1.0.0 (First release)

(October 2, 2023)
The initial public release of 'sfn'. Converts a command-line
argument into an 8.3 filename.
