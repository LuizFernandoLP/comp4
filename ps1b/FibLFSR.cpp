//FibLFSR.cpp
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps1b>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/7/2022>
 *Sources Of Help: <professor and classmates through Discord >
************************************************************/
#include"FibLFSR.h"

using namespace std;

FibLFSR::FibLFSR(std::string seed){
    int i=0;
    while(seed[i] != '\0'){						//loop to convert bit to integer and save in the array
        sBit = seed[i];
        iBit = stoi(sBit);
        mySeed.push_back(iBit);
        i++;
    }
    seedLength = mySeed.size();
    setTab();
}

std::vector<int> FibLFSR::getVec(){				//function to return my seed as a vector of ints
    return mySeed;
    
}

void FibLFSR::setTab(){
    if(seedLength >=16){						//here things will seem a little messy but they are actually very organized.
        int i = seedLength - 1;					//because I remembered that vectors kinda like arrays and I know that the project
        tab13 = mySeed[i-13];					//file is counting the bits from right to left (like when counting in binary)
        tab12 = mySeed[i-12];					//instead of counting items from left to right (like arrays). I used
        tab10 = mySeed[i-10];					//seedLength-1 to represent the last bit on the right while mySeed[0] will always
        tabMSB = mySeed[0];						//return the Most Significant bit. The others are just an offset based on the bit on the right
    }
	else if(seedLength < 16 && seedLength >=4){
		int i = seedLength - 1;					//here I just changed what bits would be XOR'ed (i decided to use the 3 on the right
        tab13 = mySeed[i-3];					//and the MSB
        tab12 = mySeed[i-2];
        tab10 = mySeed[i-1];
        tabMSB = mySeed[0];
	}
	else{
		try{
			if(seedLength<4){
				throw 1;						//I made an exception to exit the program if the seed doesnt have at least 4 bits.
			}
		}
		catch(int x){
			cout << "seed is too short" << endl;
			exit(1);
		}
	}
}

int FibLFSR::step(){
    for(int i=0; i<seedLength; i++){
        mySeed[i] = mySeed[i+1];			//shift one bit to the left
    }
    
    int i = seedLength-1;
    mySeed[i] = tab13 ^ tab12 ^ tab10 ^ tabMSB;	//changing the last bit
    setTab();
    return mySeed[i];
}


int FibLFSR::generate(int k){
    if(k<0){
        k = -k;
    }
    int i=0;
    int j=0;
    int temp;
    seedLength = mySeed.size();
    int stepReturn;
    for (j=0; j<k; j++){
        stepReturn = step();		//call return k times and calculate the k-bit value (which was very confusing to understand
        temp = stepReturn;			//on the project file)
        i = 2*i+temp;
    }
    return i;
}



std::ostream& operator<<(std::ostream& output, FibLFSR obj){
    std::vector<int> myVec = obj.getVec();			//just a basic operator overload to diplay the bit sequence nothing too ingenious
    vector<int>::iterator i;
    for (i = myVec.begin(); i < myVec.end(); i++){
        cout << *i;
    }
    
    return output;
}