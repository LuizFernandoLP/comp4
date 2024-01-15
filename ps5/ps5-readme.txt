/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name:Luiz Fernando Leite Pereira

Hours to complete assignment (optional): 10h

/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
I used the Needleman-Wunsch algorithm to find the alignment of the seqeunce.
I did that using a vector of columns (because I was having problems with conversions
using 2d arrays, + the notation is pretty much the same so its easier). the way I did was
I filled the matrix from the upper left corner to the lower right corner using a scoring scheme,
then I traceback starting from the lower-right and follow the "arrow" (which in a diagram would indicate from where
the value of a given cell is coming) until I reach the top-left. then based on that I can just organize the sequence based
on the values of each cell.


/**********************************************************************
 * You are required to create one additional test case by hand. 
 * It should be constructed in such a way that you know the correct 
 * output before running your program on it, and it should be a 
 * "corner case" that helps check if your program handles all special 
 * situations correctly. Please list:
 * - a copy of the test case input
 * - the expected test case output
 * - whether your program ran correctly on it or not
 * - optionally, any other remarks
 **********************************************************************/
Input: AGTGTGA ATGTGA

Expected output: AGTGTGA A-TGTGA

What happened: I got the right result (wanted to see if I wasnt gonna get something like AGTGTGA ATGTG-A)

/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2GB and 4GB. If your machine has 512MB or less, use a cluster
 *  machine for this readme (see the checklist for instructions).
 **********************************************************************/
I use a laptop with 32gb RAM,
inte core i7-9750H generation,
base speed of 2.60GHz (actually 3.96GHz due to overclocking)
running program on "ubuntu on windows"



/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 1GB (billion bytes) of memory?
 **********************************************************************/
a = 4 
b = 2
largest N ====> 4N^2 = 1000000000 ===> N = 15811.38830

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *  For help on how to do timing, see the checklist (e.g. -Xprof).
 *  If you get an OutOfMemoryError, see the checklist about -Xmx.
 *  If you get "Could not reserve enough space for object heap" or the timing
 *  of these tests takes too long for the last few test cases (N=20000 or higher), 
 *   note this, and skip filling out those rows of the table.
 **********************************************************************/

data file           distance       time (seconds)   memory(byte)
-----------------------------------------------------------------
ecoli2500.txt	      118           0.166005	     25175574
ecoli5000.txt         160           0.659175         100423155
ecoli10000.txt        223           2.68617          400767225
ecoli20000.txt        3135          11.1444          1601454591 (1.6 gb)
ecoli50000.txt        19485         70.2909          10003638163(10gb)
ecoli100000.txt       killed


/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds) 
--------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 2
b = 4
largest N = 640000

every time sequence size doubles, time increases by 4.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs, preceptors,
 *  classmates, past COS 126 students, or anyone else.
 **********************************************************************/
for this assignment I received help from the professor and my classmates through discord.
Also, I received help from youtube videos, and a bunch of documentations that would teach me
about the theory and the application of the Needleman-Wunsch algorithm and about some syntax in
C++ (like how to make a multidimensional array using vectors, etc.)

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had countless problems with conversions while working with matrices and characters.
for example, in this assignment I found out that the syntar "string myString = AnotherString[0];" is not 
acceptable because there is "no viable conversion from 'value_type' (aka 'char') to 'string'". Also, while working
with arrays I had a lot of problems like that too which is why I decided to change it to vectors of columns.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
none
