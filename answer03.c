// do not change this part, if you do, your code may not compile
//
/* test for structure defined by student */
#ifndef NTEST_STRUCT 
#include "answer03.h"
#else 
#include "answer03_key.h"
#endif /* NTEST_STRUCT */
//
// do not change above this line, if you do, your code may not compile
// This is the only file you have to include 

// Given intg_arg, this function performs numerical integration of 
// the function intg_arg.func_to_be_integrated over the range
// intg_arg.lower_lilmit to intg_arg.upper_limit
// 
// The range is divided into intg_arg.n_intervals uniform intervals, where the
// left-most interval has a left boundary of intg_arg.lower_limit and the 
// right-most interval has a right boundary of intg_arg.upper_limit (assuming 
// intg_arg.lower_limit <= intg_arg.upper_limit).  
// If intg_arg.lower_limit >= intg_arg.upper_limit, the right-most interval 
// has a right boundary of intg_arg.lower_limit and the left-most interval has 
// a left boundary of intg_arg.upper_limit.
// 
// The Simpson's rule is used to perform the integration for each interval
// In the Simpson's rule, three points are used to approximate the 
// intg_arg.func_to_be_integrated.  The three points are:
// (left boundary, intg_arg.func_to_be_integrated(left boundary)), 
// (right boundary, intg_arg.func_to_be_integrated(right boundary)),
// (mid-point, intg_arg.function_to_be_integrated(mid-point)).  
// mid-point is the middle of the left and right boundary.
// A quadratic equation that passes through these three points is used
// to approximate the intg_arg.func_to_be_integrated
// The integration of the quadratic equation yields
// (width of interval)/6 * (f(left) + 4*f(mid-point) + f(right))
// Here, f is short for intg_arg.func_to_be_integrated
// The width of the interval is (interval boundary closer to 
// intg_arg.upper_limit - interval boundary closer to intg_arg.lower_limit).  
// Note that width could be negative if intg_arg.upper_limit < 
// intg_arg.lower_limit
//
// The integral is the sum of the integration over all intervals
//
// The caller function has to make sure that intg_arg.n_intervals >= 1
// Therefore, this function may assume that intg_arg.n_intervals >= 1
//
double simpson_numerical_integration(integrand intg_arg)
{
  double integral = 0.0;
  double dx = 0; //small increment
  int negative_integral = 1; //this will be converted to -1 if we switch the boundaries
  int step = 0; //this will be the counter for the for loop when calculating the integral
  double lower_limit = intg_arg.lower_limit;
  double upper_limit = intg_arg.upper_limit;
  double n_intervals = intg_arg.n_intervals;
  void *func = intg_arg.func_to_be_integrated;
  double current_hight = 0;

  //check if the limits are correct
  if(lower_limit > upper_limit){
    int help = 0;//help variable for swaping variables
    
    //swaping variables
    
    help = lower_limit;
    lower_limit = upper_limit;
    upper_limit = help;

    //makes sure the integral is turned negative if we switch the boungaries
    negative_integral = -1; 
  }
  
  //initializes the current hight
  
  current_hight = lower_limit;
  
  //caculates the stap according to the intervals
  
  dx = (upper_limit - lower_limit) / n_intervals; 
  
  for(step = 0; step < n_intervals; step++){
    integral += (dx/6) * (func(current_hight)+4*(func(a+dx/2)+func(current_hight+dx)));
    //updates the current hight
    current_hight = current_hight + dx;
  } 

  return ((double)negative_integral*integral);
}
