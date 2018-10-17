//============================================================================
// Name        : Intervals.cpp
// Author      : sc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

void interval_calculator();

int main() {
	interval_calculator();
	return 0;
}

void interval_calculator(){
	float input_a;
	float input_b;
	float immediate_a = -1;
	float immediate_b = -2;
	float stored_a = 0;
	float stored_b = -1;
	std::string command;
	while(true){
		std::cout<<"input :> ";
		std::cin>>command;
		if(command == "exit"){
			std::cout<<"Bye bye: Terminating interval calculator program.";
			return ;
		}else if(command == "enter"){
				std::cin>>input_a>>input_b ;
				if(input_a > input_b){
						std::cout<<"Error: invalid interval as "<<input_a<<" > "<<input_b<<std::endl;
					}else{
						immediate_a = input_a;
						immediate_b = input_b;
					}
				if(immediate_a!= -1 && immediate_b != -2){
						std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
					}else{
						std::cout<<"--"<<std::endl;
					}
			}else if(command == "negate"){
				if(immediate_a!= -1 && immediate_b != -2){
					std::cout<<"["<<-immediate_b<<","<<-immediate_a<<"]"<<std::endl;
				}else{
					std::cout<<"--"<<std::endl;
				}
			}else if(command == "invert"){
					if(immediate_a * immediate_b <= 0){
					    std::cout<<"Error: division by zero "<<std::endl;
						immediate_a = -1;
						immediate_b = -2;
			           }
					if(immediate_a!= -1 && immediate_b != -2){
						std::cout<<"["<<1/immediate_b<<","<<1/immediate_a<<"]"<<std::endl;
									}else{
										std::cout<<"--"<<std::endl;
									}
				}
		}
}



