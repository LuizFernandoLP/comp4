/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name:Luiz Fernando Leite Pereira
Hours to complete assignment: 12h

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
the assignment itself was painful, especially because in my opinion the 
pdf was very confusing and not self-explanatory at all. Also, I still don't
know what on the pdf should be "reproduced" exactly the same and what is up to us
to decide. for example, the grading part says that we must have an SFML while loop
that uses window.draw(obj) but I don't know if we must use this exact syntax or if name
variables or data types are up to us to decide (like I saw many people doing differently on discord).
aside from the PDF problems, I personally feel like I managed to learn a bit more about pointers and 
memory allocation (which im not good at). However, the PDF confusion made me write my program in a way that
I personally think is not effective and will make my part B much harder later on.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
one of the key algorithms I used was definitely the Vector of pointers to CelestialBody.
it was exceptionally hard to develop them, first because im not good at working with dynamic memory
(even though the hard part c++ already does for me) and because of the limitations of the PDF that I had to get around.
In order to maintain the exact syntax that was asked in the pdf I had to write a copy assignment operator overload to copy celestial bodies
then I had to use my universe to create the vector of pointers to celestial bodies initialize as many CelestialBodies as the txt file asked me to and then send the
vector back to my main function through a getVecBodies() function. then I created a CelestialBody obj (called obj) and used a for loop to assign every celestialBody object in the vector
of pointers to it and then used the window.draw(obj) (the exact syntax in the pdf) to draw each celestialBody to the window.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
i did not use smart pointers but for the working features there is a copy assignment operator overload
so we are allowed to do things like "CelestialBody obj = *myVec[i];" that will assign the celestialBody object that the vector of pointers
in the i position is pointing to to the CelestialBody obj and then I can display the obj without having to use the *myVec[i] syntax (makes it easier to just write window.draw(obj)).
Also, there is an overload of the >> operator that reads input from cin and sets every private variables of the CelestialBody class at once (even the texture and the sprite which made me find out that I can
write syntax like this obj.sprite.setTexture(obj.texture); which I thought that would generate an error or at least a warning but didnt). moreover, there is a function to set position of the celestial body
by using the formula (theRadius+xPos)*(winx/(theRadius*2)); for the x position and (theRadius-yPos)*(winy/(theRadius*2)); for the y position. lastly, there is a function called getVecBodies(); in the universe.h
file that returns the Vector of pointers to celestial body so we can access that from the main function.



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
help from professor and classmates through discord + youtube videos about overloading operators and vectors of pointers +
the SFML official documentation.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
the worst problemas I faced was to know when to dereference the objects of the vector of pointers to celestial bodies, they caused me way too many bugs and I still
dont know how I managed to make it work.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
the PDF is extremely disorganized and ambiguous. like, it actually makes things harder rather than easier how it should be.