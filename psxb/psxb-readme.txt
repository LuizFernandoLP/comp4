/**********************************************************************
 *  ps4b                                                
 *  
 **********************************************************************/

Name:Luiz Fernando Leite Pereira

Hours to complete assignment : 8h

/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I did not complete the whole assignment, the implementation
of the StringSound class I did completely and I think it is working
fine because it does not throw exceptions and compiles fine. However,
I did not get pulseAudio to work so I dont know if my program isn't working
because I failed to successfully code the classes or if it is because
pulseAudio isnt working. because of that, I didnt get to code all 37 keys


/**********************************************************************
 *  Did you attempt the extra credit parts? Which one(s)?
 *  Successfully or not?  
 **********************************************************************/
didnt do extra credit

/**********************************************************************
 *  Did you implement exceptions to check your StringSound 
 *	implementation?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
yes, for example in the constructor of the stringSound I initialized my buffer
with zeroes just to get it working and make sure it actually enqueues correctly/
then I used an exception to see if after the while loop my buffer was full or not.
because it did not throw an exception I assumed that the buffer was enqueueing correctly.
Also I used a exception to see if I was generating a valid number in the pluck function.


/**********************************************************************
 *  Did you implement lambda expression?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
yes, I used a lambda expression to throw an exception to see if the buffer
was full after I initialized it in the constructor. it goes like:

auto f1 = [](int x){
        if (x == 0)
            throw std::runtime_error("buffer isn't full");
    };
    f1(static_cast<int>(buffer->isFull()));

the reason why i used static_cast is because the function isFull actually
returns a bool (which would work regardless but it's better for readability)


/**********************************************************************
 *  Did your code pass cpplint?
 *  Indicate yes or no, and explain how you did it.
 **********************************************************************/
yes it does pass the cpplint, I did this by adjusting the spaces, making
the lines less than 80 characters long and organizing my directives (should be
C then c++ then others)

/**********************************************************************
 *  List whatever help (if any) you received from TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I received help from my classmates throw discord to implement my classes


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I just cant get pulseAudio to work on my computer like its impossible

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
none