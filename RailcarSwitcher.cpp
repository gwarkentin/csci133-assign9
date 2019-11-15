#include <iostream>
#include <string>

class RailcarSwitcher {
	int maxCars;
	int stack[10];
	int stackLen;
	std::string inSequence;
	int iSeq[10];//stores the input string as an array
	int iPos;
	int iLen;
	std::string outSequence;
	int oSeq[10];//stores the output string as an array
	int oPos;
	int oLen;
	int actOut[10];//store what is actually output

	int strToArr(std::string textSeq, int *seq) {
		if (textSeq.empty()) {
			return 0;
		}
		else {
			//I didn't know that C++ cin already does this space separation
			//I had been testing using a pre-generated string initially.
			//Basically this separates the string at each space and loads
			//the numbers into the array
			int len = 0;
			int wasSpace = true;
			for (int i = 0; i < textSeq.length(); i++) {
				//less over max length
				if (len > 10) {
					return -1;
				}
				else {
					if (textSeq[i] == ' ') {
						wasSpace = true;
					}
					else {
						if (wasSpace == true) {
							seq[len] = std::stoi(textSeq.substr(i,textSeq.find(' ',i)));
							len++;
						}
						wasSpace = false;
					}
				}
			}
			return len;
		}
	}

	//returns item at current position in Queue
	//and moves to next position
	//if no items left, returns -1
	int getCar() {
		if (iPos < iLen) {
			int item = iSeq[iPos];
			iPos++;
			return item;
		}
		else {
			return -1;
		}
	}
	//add car to stack if there's room.
	//returns true if success, false if full
	bool push() {
		//std::cout << "push " << std::endl;
		if (stackLen + 1 < maxCars) {
			stack[stackLen] = getCar();
			stackLen++;
			return true;
		}
		else {
			return false;
		}
	}
	//takes car from top of stack if there is one and returns it.
	//otherwise returns -1
	int pop() {
		//std::cout << "pop " << std::endl;
		if (stackLen > 0) {
			return stack[--stackLen];
		}
		else {
			return -1;
		}
	}
	//check what next item is on top of stack
	int peek() {
		//std::cout << "peek " << std::endl;
		if (stackLen > 0) {
			
			return stack[(stackLen - 1)];
		}
		else {
			return -1;
		}
	}

	//loops throught testing if top item on stack needs to be popped
	bool popLoop() {
		while (oPos < oLen && stackLen > 0) {
			if (peek() == oSeq[oPos]) {
				std::cout << "pop ";
				//store the output of the pops in a new array
				actOut[oPos] = pop();
				oPos++;
			}
			else {
				return false;
			}
		}
		return true;
	}

public:
	RailcarSwitcher () {
		maxCars = 10;
		stackLen = 0;

		std::cout << "Please enter car in sequence: ";
		std::getline(std::cin, inSequence);
		iLen = strToArr(inSequence, iSeq);
		iPos = 0;

		std::cout << "Please enter desired out sequence: ";
		std::getline(std::cin, outSequence);
		oLen = strToArr(outSequence, oSeq);
		oPos = 0;

		bool success;
		//run though input Queue adding items to stack
		//check if items in stack need to be popped
		if (iLen == -1 || oLen == -1) {
			std::cout << "Tracks overloaded." << std::endl;
			success = false;
		}
		else {
			if (oLen > iLen) {
				std::cout << "More inputs than outputs.";
				success = false;
			}
			else {
				for (int i = 0; i < iLen; i++) {
					push();		
					std::cout << "push ";
					success = popLoop();//this should be true on last try if it works
				}
			}
			std::cout << std::endl;
		}
			
		//added this so we can see if it actually came out right
		std::cout << "Actual output: ";
		for (int i = 0; i < oPos; i++) {
			std::cout << actOut[i] << " ";
		}
		std::cout << std::endl;

		if (success) {
			std::cout << "Success" << std::endl;
		}
		else {
			std::cout << "Failure" << std::endl;
		}
	}
};

int main() {
	RailcarSwitcher rcs;
	return 0;
}
