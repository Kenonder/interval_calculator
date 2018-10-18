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
	float immediate_a = -1;
	float immediate_b = -2;
	float stored_a = -1;
	float stored_b = -2;
	std::string command;
	while(true){
		std::cout<<"input :> ";
		std::cin>>command;
		if(command == "exit"){
			std::cout<<"Bye bye: Terminating interval calculator program.";
			return ;
		}else if(command == "enter"){
			    float input_a = 0;
				float input_b = 0;
				std::cin>>input_a>>input_b ;
				if(input_a < input_b){
					immediate_a = input_a;
					immediate_b = input_b;
			        std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
					}else{
						std::cout<<"Error: invalid interval as "<<input_a<<" > "<<input_b<<std::endl;
						if(immediate_a!= -1 || immediate_b != -2){
							std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
							}else{
								  std::cout<<"--"<<std::endl;
								}
					}

			}else if(command == "negate"){
				if(immediate_a!= -1 || immediate_b != -2){
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
					if(immediate_a!= -1 || immediate_b != -2){
						std::cout<<"["<<1/immediate_b<<","<<1/immediate_a<<"]"<<std::endl;
									}else{
										std::cout<<"--"<<std::endl;
									}
				}else if(command == "ms"){
					if(immediate_a!= -1 || immediate_b != -2){
						std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
						stored_a =  immediate_a;
						stored_b =  immediate_b;
					}else{
						std::cout<<"--"<<std::endl;
					}
				}else if(command == "mr"){
					if(stored_a!= -1 || stored_b != -2){
						immediate_a = stored_a;
						immediate_b = stored_b;
					}
					if(immediate_a!= -1 || immediate_b != -2){
				    	std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
							}else{
						          std::cout<<"--"<<std::endl;
			  					}
				}else if(command == "mc"){
					stored_a =  -1;
	                stored_b =  -2;
	                if(immediate_a!= -1 || immediate_b != -2){
	                	std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       					}else{
	               		          std::cout<<"--"<<std::endl;
	       					}
	       		}else if(command == "m+"){
	       			if(immediate_a!= -1 || immediate_b != -2 || stored_a!= -1 || stored_b != -2){
	       				stored_a =immediate_a + stored_a;
	       				stored_b =immediate_b + stored_b;
	       			}
	       			if(immediate_a!= -1 && immediate_b != -2){
	       				 std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	        					}else{
	     				              std::cout<<"--"<<std::endl;
	       				   			}
	       		}else if(command == "m-"){
	       			if(immediate_a!= -1 || immediate_b != -2 || stored_a!= -1 || stored_b != -2){
	       				stored_a =-immediate_a + stored_a;
	       				stored_b =-immediate_b + stored_b;
	       			}
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				 std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	        					}else{
	     				              std::cout<<"--"<<std::endl;
	       				   			}
	       		}else if(command == "scalar_add"){
	       			float c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				immediate_a =immediate_a + c;
	       				immediate_b =immediate_b + c;
	       			 std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			    }
	       		}else if(command == "scalar_subtract"){
	       			float c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				immediate_a =immediate_a - c;
	       				immediate_b =immediate_b - c;
	       			 std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			    }
	       		}else if(command == "scalar_multiply"){
	       			float c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				if(c > 0){
	       					immediate_a =immediate_a * c;
	       					immediate_b =immediate_b * c;
	       					std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				}else{
	       					float tem_a = immediate_a;
	       					immediate_a =immediate_b * c;
	       				    immediate_b =tem_a * c;
	       			        std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				}
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			}
	       		}else if(command == "scalar_divide"){
	       			float c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				if(c > 0){
	       					immediate_a =immediate_a / c;
	       					immediate_b =immediate_b / c;
	       					std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				}else if(c < 0){
	       					float tem_a = immediate_a;
	       					immediate_a =immediate_b / c;
	       				    immediate_b =tem_a / c;
	       			        std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				}else{
	       					std::cout<<"Error: division by zero"<<std::endl;
	       					immediate_a = -1;
	       					immediate_b = -2;
	       					std::cout<<"--"<<std::endl;
	       				     }
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			}
	       		}else if(command == "scalar_divided_by"){
	       			float c = 0;
	       			std::cin>>c;
	       			if(immediate_a != -1 || immediate_b != -2){
	       				if(immediate_a * immediate_b > 0){
	       			      if(c <= 0){
	       					immediate_a = c / immediate_a;
	       					immediate_b = c / immediate_b;
	       				    std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       					}else if(c > 0){
	       					       float tem_a = immediate_a;
	       					       immediate_a = c / immediate_b;
	       					       immediate_b = c / tem_a;
	       					       std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       					      }
	       				}else{
	       					  immediate_a = -1;
	       					  immediate_b = -2;
	       					  std::cout<<"Error: division by zero"<<std::endl;
	       					  std::cout<<"--"<<std::endl;
	       					 }
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			}
	       		}else if(command == "interval_add"){
	       			float c = 0;
	       		    float d = 0;
	       		    std::cin>>c>>d;
	       		    if(c > d){
	       		    	std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
	       		    	if(immediate_a!= -1 || immediate_b != -2){
	       		            std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       		    		}else{
	       		    			  std::cout<<"--"<<std::endl;
	       		    	         }
	       		    }else{
	       		    	if(immediate_a!= -1 || immediate_b != -2){
	       		    	immediate_a = immediate_a + c;
	       		    	immediate_b = immediate_b + d;
	       		    	std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       		    	}else{
	       		    		std::cout<<"--"<<std::endl;
	       		    	}
	       		    }
	       		}else if(command == "interval_subtract"){
	       			float c = 0;
	       		    float d = 0;
	       		    std::cin>>c>>d;
	       		    if(c > d){
	       		    	std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
	       		    	if(immediate_a!= -1 || immediate_b != -2){
	       		            std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       		    		}else{
	       		    			  std::cout<<"--"<<std::endl;
	       		    	         }
	       		    }else{
	       		    	if(immediate_a!= -1 || immediate_b != -2){
	       		    	immediate_a = immediate_a - d;
	       		    	immediate_b = immediate_b - c;
	       		    	std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       		    	}else{
	       		    		std::cout<<"--"<<std::endl;
	       		    	}
	       		    }
	       		}
		}
}




