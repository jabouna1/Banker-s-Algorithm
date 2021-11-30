//Banker's Algorithim 

#include <fstream>
#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include<ctype.h>

std::vector< std::vector<int> > allocation;
std::vector< std::vector<int> > max; 
std::vector< std::vector<int> > need;
std::vector<int> processNumbers;
std::vector<int> safeSqnce;

int available[3];


//Reads entire csv file and places values into vectors and arrays
void parseFile(std::string filename) {
	//open file into stream
	std::fstream in;
	in.open(filename);
	
	//Skip two lines
	for(int i = 0; i < 2; i++) {
		std::string temp;
		in >> temp;
	}
		

	while(!in.eof()) {
		std::string line, nextChar;
		//reads whole row into string
		in >> line;
		std::stringstream s(line);
		
		//pushes first character since that is process number
		getline(s, nextChar, ',');
		if(isdigit(nextChar[0])){
			processNumbers.push_back(std::stoi(nextChar));
		}		

		
		//temp variables
		int index = 0;
		std::vector<int> allocTuple, maxTuple;
		//reads each column
		while (getline(s, nextChar, ',')) {
  			index++;
			
			if(index >= 1 && index <= 3) {
				//checks if character read is a digit
				if(isdigit(nextChar[0])){
					//pushes into tuple of 3
					allocTuple.push_back(std::stoi(nextChar));
				}

			}else if(index >= 4 && index <= 6) {
				
				if(isdigit(nextChar[0])){
					maxTuple.push_back(std::stoi(nextChar));
				}
				

			}else if(index >= 7) {

				if(isdigit(nextChar[0])){
					available[index - 7] = std::stoi(nextChar);
				}
			}

        	}
		
		//pushes into allocations list 
		if(!allocTuple.empty()) {
			allocation.push_back(allocTuple);
		}
		

		if(!maxTuple.empty()) {
			max.push_back(maxTuple);
		}
		
	}

	std::cout<<"File has been successfully read."<<std::endl;
	in.close();
	return;
}

int main(int argc, char *argv[]) {

	if(argc < 2) {
		std::cout<<"File name was not entered. Exiting."<<std::endl;
		return 1;
	}
	
	parseFile(argv[1]);
	
	//calculates need 
	for(int i = 0; i < allocation.size(); i++) {
		std::vector<int> temp = {0,0,0};
		
		for(int x = 0; x < 3; x++) {
			temp[x] = max[i][x] - allocation[i][x];
		}
		
		need.push_back(temp);
	}
	
	//banker's alogrithim
	while(processNumbers.size() > 0) {
		

		int needSize = need.size();
		bool atleastOnePush = false;

		for(int z = 0; z < needSize; z++) {

			bool needLessThanAvail = true;

			for(int y = 0; y < 3; y++) {
				
				if(need[z][y] > available[y]) {
					needLessThanAvail = false;
				}
			}
			
			//if need is <= available, add onto safe sequence 
			if(needLessThanAvail) {

				atleastOnePush = true;				
				
				//add to safe sequence and pop off process from list
				safeSqnce.push_back(processNumbers[z]);
				processNumbers.erase(processNumbers.begin() + z);
				
				for(int v = 0; v < 3; v++) {
					available[v] += allocation[z][v];
				}
				
				allocation.erase(allocation.begin() + z);
				need.erase(need.begin() + z);

				z--;
				needSize--;
			}								

		}
		
		//if there is no a single need <= available that is true in iteration than system is unsafe
		if(!atleastOnePush) {
			std::cout<<"The system is not in safe state."<<std::endl;
			return 1;	
		}		

		
	}

	std::cout<<"The system is in a safe state.\nThe safe sequence is: "<<std::endl;
	for(int b = 0; b < safeSqnce.size(); b++) {
		std::cout<<"P"<<safeSqnce[b]<<" "<<std::endl;
	}

	return 0;
}
