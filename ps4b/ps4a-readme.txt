/**********************************************************************
 *  readme.txt template                                                   
 *  Synthesizing a Plucked String Sound:
 *  CircularBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name:Luiz Fernando Leite Pereira


Hours to complete assignment: 4 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
the assignment itself was very interesting because it helped me to get some of the
information from data structures from computing 2 back into my head (especially queues).
Also, it wasn't a hard assignment the only thing that took a little bit more time than normal
was figuring out how to "convert" the queue from linear to circular, but besides that it was
fairly easy compared to other assignments.

/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
one of the key structures that I used was to make a pointer of
int16_t because I can then use the new keyword to make it point to an
array of int16_t of the size that was passed in the constructor.

like this:

	arr = new int16_t[capacity];

this is important because it allows me to only allocate the memory that I will use
and also allows me to have different sizes of the array for different objects.

also because I'm just using an array, having access to the elements is very easy since I only need
the index which eliminates the necessity of doing things like:

	vector<int>::iterator ptr;
   	for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        	cout << *ptr << " ";

that we use to do when using vectors.
I can just do:

	arr[front]

and I'm able to peek at the element in the front which is much simpler.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
one of the working features that I implemented and I think is the most important one
(which I learned from the yt video) is how I did the conversion from linear queue to circular queue. 
and this was done by using the formula (back+1)%capacity because when back+1 equals the capacity of the
array the fact that using a modulus operator will make it return 0 which will be used as my next index making it "return"
to the beginning. This was very useful because I can use the if-else statement:

if ((back+1)%static_cast<int>(m_capacity) == front)
        return true;
    else
        return false;

to check whether my array is full, because since (back+1)%capacity gives me the formula for the next index, if the next index of the back equals
the current index of the front then I know the array is full. technically it could also indicate the array is empty but since we set front and back
to -1 in the beginning this prevents isFull() from returning true in the case the array is empty.


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Yes, I did complete it successfully, everything is working fine and 
I know that because I used a main.cpp to test if they were working and they
all gave me the expected results (I even used main.cpp to test if it would throw
the excepetions if I tried to do something I shouldn't like peek on the empty buffer).
However, although they all seem to be working fine maybe (probably not) there might be
a bug in the size() function which might happen in some cases that I haven't thought of
because the way I implemented was if it is empty it returns zero as the number of elements,
if it is full it returns the capacity of the array as the number of elements, and otherwise it returns
the back-front+1. I say it might have a bug because technically im returning a constant when it is empty
which in my head seems alright but maybe there might be something that causes isEmpty() to return true when
it shouldn't and I will never know because it always returns 0 if isEmpty is true.


/**********************************************************************
 *  Does your CircularBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes, I know that because I used different boost functions to test not only
the exceptions that are thrown but also the values that the functions returns.
For example, the test:

BOOST_REQUIRE_THROW(CircularBuffer obj(0), std::invalid_argument);

is helpful to see whether my constructor throws an exception in the case I try to pass a capacity
that is less than 1. not only that it also allows me to check whether it is throwing the right 
exception or not. For instance, if I change that std::invalid_argument for something like std::runtime_error
this test will fail because the runtime_error exception is not thrown, so the test is not only helpful to keep
track of whether It fails on bad input but also if it "fails correctly".

another thing I did was to use BOOST_REQUIRE in every test I did so in the case one of them fails there is no chance
the next one will pass because it will not be exececuted which is helpful because maybe there is a chance that even
if a test fails the next one will succeeed (even if it shouldnt), so the fact that im using BOOST_REQUIRE to run my tests
is another way of making sure that im not passing some of tests by luck.




/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
the time and space performance are constant O(1) because I do not need to search
for any element when calling the functions (for example, based on the "first in, first out" scheme,
the dequeue does not need to check other elements before removing the element on the "top").
Also, the algorithms do not use any auxiliary space to be performed. therefore, the space and time complexity are constant.


/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I received help from professor daly and I received help from an youtube video
that taught about ring buffers and how they work, time/space complexity, and how 
they are usually implemented. it helped me a lot because I was planning on using a std
library to do the assignment (maybe vector or queue) but after watching the video I decided to use
an array (I actually did it differently because I used a pointer and made it point to an array instead of just making an array) because it is easier to get
it to work in constant time. Also, the idea of setting the front and back to -1 to indicate that I have 
no elements in the buffer I also got from the video which was very helpful since arrays cant have negative
indexes.


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I had a problem fixing a bug where the function size would return 0 when the
CircularBuffer was full because both the front and back would point to the same index
(just like it does when it is empty) so i had to use the function isEmpty to differentiate
whether it should return 0 or the maximum capacity of the ring.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
nothing to add