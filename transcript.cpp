#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	int i;
	srand(time(NULL));
       for(int j = 0 ; j < 6; j ++){
	
	    i   = (rand()%6)+1;
	    std::cout << i << "\n";
       }

}

