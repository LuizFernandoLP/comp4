/**********************************************************************
 * PS1b: LFSR - PhotoMagic ps1b-readme.txt template:
 **********************************************************************/

Name: Luiz Fernando Leite Pereira
Hours to complete assignment: 2h
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
this assignment was actually much easier to do compared to the previous one
because most of the hard work was already done and the code for this project
was given in the pixels.cpp file, so pretty much what I had to do was to adapt
the code to meet the current requirements. I think it was very interesting to see
how the encryption was working and I think I got a better understanding at how encryption works
because of this project.


/**********************************************************************
 *  Explain the implementation:
 **********************************************************************/
in my project I adapted the code from the pixels.cpp to encrypt the picture by calling
a function called transform that would take a pointer to a FibLFSR and the address of an image.
In this function I used the seed from the FibLFSR object to generate an 8-bit number that would get
XOR'd with the current color of each RGB like this : p.r = p.r ^ l->generate(8); (this would be for the red part of the RGB).
Then in main I loaded the same image twice and then passed the address of one of them to the function transform so it could be encrypted
and then finally I displayed both the orinal image and the encrypted image in two different windows and saved the encrypted image to a new file


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
only got help through discord to understand about the signature of the transform function
(in the project pdf the parameters have no name only the data type and the professor and my classmates
explained to me that I was allowed to give name to paramaters but I needed to keep the data types)

/**********************************************************************
 *  state of the program:                  
 **********************************************************************/
The program fully works, it encodes and decodes perfectly. However, it is not going to work
if the seed has less than 4 bits (because when I created mt FibLFSR I decided that the seed could not be less than 4 bits
and made the program throw an exception and exit if that ever occurred).


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
the only problem I had really was to understand how the windows functions work
(I still dont get what an event,pollEvent, etc. are but because we were provided with this part
of the code I knew how to use it)

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

nothing to add this time