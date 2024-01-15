/**********************************************************************
 *  readme.txt template                                                   
 *  Random Writer 
 **********************************************************************/

Name: Luiz Fernando Leite Pereira

Hours to complete assignment: 10h
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
the assignment was very interesting because I got to learn more about
coding things with different probabilities which was something that I
never noticed I didn't know how to do until now, so it was interesting to
see how formulas like P(A or B) = P(A) + P(B) work in actual codes. I feel
like it was a bit frustrating to work with maps specially because they are
not as straightforward as vectors but in the end I managed to make things
work.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
one key data structure that was central to the assignment was the map format that I used
" std::map<std::string, std::map<char, int>> " where I could use the first key to store
the kgrams and the second part I could store every character that followed a given kgram
along with its frequency, so this gives easy access to the probability of a given character
to be generated after a given kgram. Also, another key algorithm was the one I used to calculate
the probabilities where based on the formula P(A or B) = P(A) + P(B) I can do somehting like:

if (randNumber <= PA)
   return A;
   if (randNumber <= (PA+PB))
   return B;

(just an example to make things clearer. I actually did everything in one if statement inside a for statement) like this

if (variables.size() == totalSize) {
        for (i = 0; i < variables.size(); i++) {
            probCount = probCount + probabilities[i];
            if (num <= probCount)
                break;
        }
    }
    return variables[i];

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
for the generate function i used this excerpt to generate the string:

while (buildString.length() < static_cast<size_t>(L)) {
        buildString = buildString + kRand(nextKgram);
        nextKgram = buildString.substr(
          buildString.length()-kgram.length(), kgram.length());
    }

this works because i'm repetitively calling kRand() to generate the next character
by actually using the kgram+1 that I was supposed to use according to the pdf. the way
it works is I get the last K characters of my current string and set it as the new kgram,
since the first k characters of the string are actually the kgram I started with. For example,
if I started with str = ag then I generated kRand("ag") and i got a c for example, my string would
become str = agc and since k = 2 the last 2 characters are "gc" which would be the next kgram to be used
to generate the next character.

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I did complete the assignment successfully, it works as proven by the screenshots.
for example, when generating the sequence everytime I run I get a different sequence that is
somehow related to the first sequence (as it should be).

--> important <--

however, because of my implementation, my program is not well optimized (I think) specially because
of how many for loops and nested for loops I used. because of that, I am not able to generate a string
using the full tomsawyer text. not because it wont work, but because it just takes too much time. for comparison,
if I only use the first 6529 characters of the text, it takes about 150 seconds to generate the random text (and the time
grows exponentially I think) while the full text contains exactly 384403 characters, which is 377874 more than what I used when
it took me about 150 seconds. Thus, because my implementation isnt optimized, it could take hours to generate the random function
(it technically works though)



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
yes they do, I know that because I used the BOOST_REQUIRE_THROW function to test
if the functions would throw an expection on bad input and the BOOST_REQUIRE_NO_THROW
to see if they wouldnt when they shouldnt, and as expected they all worked fine. Also,
I used the BOOST_CHECK to see if the frequencies were as expected and to see if the letter
generated was at least part of the alphabet being used in the original text.



 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
I used exceptions in the functions that required a kgram as an input like the generate,
kRand, freq, etc. (they are all in the RandWriter.cpp file at lines 25,39,87,102,136).
The exceptions were used to check if the input kgram was valid to begin with, because for example
there is no point in generating a character from a given kgram if the kgram isn't in the text, because it 
will not appear in the map and will not work at all.




 /**********************************************************************
 *  Describe where you used lambda expression if any
 *  Provide files and lines of the code.
 ***********************************************************************/
I used a lambda expression in the RandWriter.cpp file (around line 114) to
get the number of elements in a vector using the accumulate function. I did
this just to get the size in a different way to make sure that in the end the size
of the given vector would be the same as the same of the other vector I used (in this part
I made two vectors, one would store the letter and the other one the probability, and the index
of the two should match the character with its given probability, so I needed both vectors to be of
same size)

/**********************************************************************
 *  Did you implemented program for extra poits? If yes, describe your 
 *  If yes, describe your implementation.
 ***********************************************************************/
I didn't do the extra credit part


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I received a lot of help from my classmates and my professor through discord
and I also learned a lot from some documentations that I read about different
libraries and how to use some data types and functions.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I encountered some serious problems with memory management (I think)
because at some point every time I added a new private variable in my class 
I would either get segmentation fault or it would display the message 
" *** stack smashing detected ***: terminated Aborted " which until now
I have no idea what it means. but then I managed to work around the problem
(couldn't fix so I had to make things work in another way)


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
none