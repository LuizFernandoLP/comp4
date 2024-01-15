/**********************************************************************
 *  Linear Feedback Shift Register (part A) ps1a-readme.txt template
 **********************************************************************/

Name: Luiz Fernando Leite Pereira
Hours to complete assignment: 8h
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.

 **********************************************************************/
The assignment itself was fairly easy to do (which is kind of ironic given that
I spent 8h on it) because the coding part was very simple. I mean, the program itself
was about 200 lines long (spread across the files) and did not require any crazy ideas
to do what we needed. I think the assignment was very important to me because although I
hate to admit Comp4 has been forcing me to improve by forcing me to deal with my weaknessess.
since Comp1 I have been trying to avoid using different files and terminals to code cuz I personally
think it makes things look more confused but during this project I feel like it wasn't that bad (I even
learned how to write a Makefile which I was awful at). so I think the project has helped me to become a better
coder in general (haven't felt like this in a while).




/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/
so I decided to use int vectors to represent my register bits because I think
it is easier to manipulate them like this. What I did was I created a string variable
that would contain 1 character (which in this case represents 1 bit) of the original seed
converted it to integer and saved in a vector using push_back(). by doing this I don't need
to deal with memory allocation/reallocation and I can use the XOR operator to write the other functions.
in short, I think it was easier to do this way only because we were more focused about specific bits rather than
the string itself (if I had to convert to int to do the math than convert back to string I would probably have tried
to think of something else).


 
/**********************************************************************
 * Discuss what's being tested in your two additional Boost unit tests
  **********************************************************************/
one of my unit tests will test for weird/bad inputs in the generate(int k) function
(like when k <= 0). This was very helpful because I decided that the way I
wanted to deal with bad inputs was that if the input was negative it would
be treated as if it were positive so I tested a bunch of cases where I wanted to see
if generate(k) would be equal to generate(-k) (i.e generate(5) and generate(-5) should be equal) and
it ended up working really well (also when k=0 the sequence of bits remains the same).

the other unit test block would check for some weird seeds like in the case of it being really small (only for greater than or equal to 4bits though, 
because I decided that If there were 3bits or less the program would display a message and exit) and for the case of it being really large. although it seem
quite unnecessary it was actually very important to me because the way that the "tabs" were implemented were different depending on the number of bits of the seed.
for example, if it was 16bit or more then I would use tabs on bit 13, 12 ,10 and the most significant bit. on the other hand if it was between 4 and 15bits long I used
tabs on the most significant bit and on the bits 0,1 and 2. So I ended up using my tests to see if my step() function and generate function would work regardless of how long
the string was.




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
only got help to decide which method I would use (convert to integer was my idea
but then I gave up and I was finally convinced again to used this method by my classmates)

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
nothing bad happened actually, the only thing that I didn't like was the way that the formula for 
getting the k-bit number in the generate function was written. It probably took me a few hours to understand
what it meant, but that is a me problem, other than that nothing bad happened.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

nothing to add.