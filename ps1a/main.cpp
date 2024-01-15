//main.cpp
/************************************************************
 *Name: <Luiz Fernando Leite Pereira>
 *Course name: <COMP.2040>
 *Assignment: <Ps1a>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/1/2022>
 *Sources Of Help: <professor through Discord and youtube for makefile>
************************************************************/
#include"FibLFSR.h"

using namespace std;

int main(){
	FibLFSR l("1111");
	for (int i=0; i<10; i++){
	    int k = l.step();
	    cout << l << " " << k << endl;
	}
	FibLFSR l2("1110");
	cout << l2.generate(5)<<endl;
}
