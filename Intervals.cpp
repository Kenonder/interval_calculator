//============================================================================
// Name        : Intervals.cpp
// Author      : sc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <cmath>
void interval_calculator();

int main() {
	interval_calculator();
	return 0;
}

void interval_calculator(){
	double immediate_a = -1;
	double immediate_b = -2;
	double stored_a = -1;
	double stored_b = -2;
	std::string command;
	while(true){
		std::cout<<"input :> ";
		std::cin>>command;
		if(command == "exit"){
			std::cout<<"Bye bye: Terminating interval calculator program.";
			return ;
		}else if(command == "enter"){
			double input_a = 0;
			double input_b = 0;
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
	       			double c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				immediate_a =immediate_a + c;
	       				immediate_b =immediate_b + c;
	       			 std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			    }
	       		}else if(command == "scalar_subtract"){
	       			double c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				immediate_a =immediate_a - c;
	       				immediate_b =immediate_b - c;
	       			 std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			    }
	       		}else if(command == "scalar_multiply"){
	       			double c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				if(c > 0){
	       					immediate_a =immediate_a * c;
	       					immediate_b =immediate_b * c;
	       					std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				}else{
	       					double tem_a = immediate_a;
	       					immediate_a =immediate_b * c;
	       				    immediate_b =tem_a * c;
	       			        std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				}
	       			}else{
	       				std::cout<<"--"<<std::endl;
	       			}
	       		}else if(command == "scalar_divide"){
	       			double c = 0;
	       			std::cin>>c;
	       			if(immediate_a!= -1 || immediate_b != -2){
	       				if(c > 0){
	       					immediate_a =immediate_a / c;
	       					immediate_b =immediate_b / c;
	       					std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				}else if(c < 0){
	       					double tem_a = immediate_a;
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
	       			double c = 0;
	       			std::cin>>c;
	       			if(immediate_a != -1 || immediate_b != -2){
	       				if(immediate_a * immediate_b > 0){
	       			      if(c <= 0){
	       					immediate_a = c / immediate_a;
	       					immediate_b = c / immediate_b;
	       				    std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       					}else if(c > 0){
	       						double tem_a = immediate_a;
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
	       			double c = 0;
	       			double d = 0;
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
	       			double c = 0;
	       			double d = 0;
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
	       		}else if(command == "interval_multiply"){
	       			double c = 0;
	       			double d = 0;
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
	       		    		double max = 0;
	       		    		double min = 0;
	       		    		if ( immediate_a * c > immediate_a * d)
	       		    		{
	       		    		max = immediate_a * c;
	       		    		min = immediate_a * d;
	       		    		}
	       		    		else
	       		    		{
	       		    		max = immediate_a * d;
	       		    		min = immediate_a * c;
	       		    		}
	       		    		if (max < immediate_b * c)
	       		    		max = immediate_b * c;
	       		    		else if (min > immediate_b * c)
	       		    		min = immediate_b * c;
	       		    		if (max < immediate_b * d)
	       		    		max = immediate_b * d;
	       		    		else if (min > immediate_b * d)
	       		    		min = immediate_b * d;
	       		    		immediate_a = min;
	       		    	    immediate_b = max;
	       		    	    std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       		    	}else{
	       		    		std::cout<<"--"<<std::endl;
	       		    	}
	       		    }
	       		}else if(command == "interval_divide"){
	       			double c = 0;
	       			double d = 0;
	       			std::cin>>c>>d;
	       		    if(c > d){
	       			   std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
	       	    	      if(immediate_a!= -1 || immediate_b != -2){
	       				    std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       				    }else{
	       				          std::cout<<"--"<<std::endl;
	       				       	 }
	       		   }else{
	       			     if(c * d <= 0){
	       				       		    std::cout<<"Error: division by zero"<<std::endl;
	       				       			immediate_a = -1;
	       				       		    immediate_b = -2;
	       			     }
	       			   if(immediate_a!= -1 || immediate_b != -2){
	       				double max = 0;
	       				double min = 0;
	       			    if ( immediate_a / c > immediate_a / d)
	       			    {
	       			     max = immediate_a / c;
	       			     min = immediate_a / d;
	       			    }
	       	     		else
	       		        {
	       				 max = immediate_a / d;
	       		   		 min = immediate_a / c;
	       			    }
	       			    if (max < immediate_b / c)
	       				max = immediate_b / c;
	       			    else if (min > immediate_b / c)
	       			    min = immediate_b / c;
	       			    if (max < immediate_b / d)
	       			    max = immediate_b / d;
	       			    else if (min > immediate_b / d)
	       			    min = immediate_b / d;
	       			    immediate_a = min;
	       				immediate_b = max;
	       			    std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	       			    }else{
	       		    		std::cout<<"--"<<std::endl;
	       		    	}
	       		       }
	               }else if(command == "intersect"){
	            	   double c = 0;
	            	   double d = 0;
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
	            			if(c < immediate_b && d > immediate_a){
	            				if(c > immediate_a){
	            					immediate_a = c;
	            				}
	            				if(d < immediate_b){
	            					immediate_b = d;
	            				}
	            				std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	            			}else{
	            				 immediate_a = -1;
	            			     immediate_b = -2;
	            			     std::cout<<"--"<<std::endl;
	            			}
	            		   }else{
	       				          std::cout<<"--"<<std::endl;
	       				       	 }
	            	   }
	               }else if(command == "integers"){
	            	     if(immediate_a!= -1 || immediate_b != -2){
	            	 	   int integer = 0;
	            		   if(immediate_a != (int)immediate_a){
	            			   if(immediate_a > 0){
	            			   integer = immediate_a / 1 + 1;
	            			   }else{
	            				integer = immediate_a / 1;
	            			   }
	            		   }else{
	            			   integer = immediate_a;
	            		   }

	            		   while(integer <= immediate_b - 1){
	            			   std::cout<<integer<<",";
	            			   integer++;
	            		      }
	            		      std::cout<<integer;
                              std::cout<<std::endl;
	            		  std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;

	            	   }else{
	            		   std::cout<<"--"<<std::endl;
	            	   }
	               }else if(command == "cartesian_integers"){
	            	   double c = 0;
	            	   double d = 0;
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
	            		  int integer1 = 0;
                           if(immediate_a != (int)immediate_a){
                              if(immediate_a > 0){
                           	    integer1 = immediate_a / 1 + 1;
                           	  }else{
                           	        integer1 = immediate_a / 1;
                           	       }
                           }else{
                           	     integer1 = immediate_a;
                           	     }
                           int integer2 = 0;
                           if(c != (int)c){
                              if(c > 0){
                                 integer2 = c / 1 + 1;
                              }else{
                                   integer2 = c / 1;
                                    }
                            }else{
                                  integer2 = c;
                                  }
                           for(int i = integer1 ;i <= immediate_b; ++i){
                        	   for(int k = integer2;k <= d;++k){
                        		   if(i != integer1 || k != integer2){
                        		   std::cout<<","<<"("<<i<<","<<k<<")";
                        		   }else{
                        			   std::cout<<"("<<i<<","<<k<<")";
                        		   }
                        	   }
                           }
                           std::cout<<std::endl;
                           std::cout<<"["<<immediate_a<<","<<immediate_b<<"]"<<std::endl;
	            	   }else{
	            		     std::cout<<"--"<<std::endl;
	            	        }
	            	  }
	               }else{
                        std::cout<<"Error: illegal command"<<std::endl;
	               }
	           }
		}





