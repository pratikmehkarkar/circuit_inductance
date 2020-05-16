/*Inductance of an Electrical Circuit*/
#include <stdio.h>
#include <math.h>
#include <ctype.h>
/*function declaration*/ 
/*V - Volts, R - ohms, L- henrys, C - farads*/
double q(double V, double R, double L, double C, double t);
void sim(double V, double R, double L, double C, double d,double t_step); 
void timer(double* duration, double* time);
void circuit(double* voltage, double* resistance, double* inductance, double* capacitance);
 
int main(void)
{
  /*variable declaration*/
  char Selection;
  double voltage,resistance,t_time=0;
  double duration,time,inductance,capacitance;
  do
  {
    printf("Simulate the Inductance of an Electrical Circuit\n");
    printf("\nPlease enter simulation parameters.\n");
    /*timer() function call*/
    timer(&duration, &time);
    printf("\n\nPlease enter circuit parameters.\n");
    
    /*circuit() function call*/
    circuit (&voltage, &resistance, &inductance, &capacitance);
    printf("Decay of the charge, q, as a function of time");
    printf("\n\t\tTime t\tCharge q\n");
    printf("\n\t\t-----------------\n");
    
    /*sim() function call*/
    sim(voltage,resistance,inductance, capacitance,duration, time);
    printf("\nMore (y/n): ");
    scanf(" %c",&Selection);
    if(Selection=='n')
    {
      break;
    }
  }
  while(Selection=='y');
  return 0;
}
/*function timer() takes the user input of length of time to simulate the circuit*/ 
void timer(double* duration, double* time)
{
  printf("\n\t\tDuration of simulation (seconds): ");
  scanf("%lg",duration);
  while(*duration<=0)
  {
    printf("\n\t\t\tError: duration must be > 0.");
    printf("\n\t\tDuration of simulation (seconds): ");
    scanf("%lg",duration);
  }
  printf("\n\t\tTime step for simulation (seconds): ");
  scanf("%lg",time);
  while(*time<=0.0)
  {
    printf("\n\t\t\tError: time step must be > 0.");
    printf("\n\t\tTime step for simulation (seconds): ");
    scanf("%lg",time);
  }
}
/*function circuit() read & validate the circuit properties V,R,L,C*/
void circuit (double* voltage, double* resistance, double* inductance, double* capacitance)
{
  /*variable declaration*/
  double V,R;
  double L,C;
  printf("\n\t\tVoltage: ");
  scanf("%lg",voltage);
  while(*voltage<5 || *voltage>15)
  {
    printf("\n\t\t\tError: voltage range is 5 to 15");
    printf("\n\t\tVoltage: ");
    scanf("%lg",voltage);
  }
  printf("\n\t\tResistance (ohms): ");
  scanf("%lg",resistance);
  while(*resistance<50 || *resistance>500)
  {
    printf("\n\t\t\tError: resistance range is 50 to 500");
    printf("\n\t\tResistance (ohms): ");
    scanf("%lg",resistance);
  }
  printf("\n\t\tInductance (henrys): ");
  scanf("%le",inductance);
  while(*inductance<0.001 || *inductance>0.1)
  {
    printf("\n\t\t\tError: inductance range is 0.001 to 0.1");
    printf("\n\t\tInductance (henrys): ");
    scanf("%le",inductance);
  }
  printf("\n\t\tCapacitance (farads): ");
  scanf("%le",capacitance);
  while(*capacitance<1e-05 || *capacitance>0.0001)
  {
    printf("\n\t\t\tError: capacitance range is 1e-05 to 0.0001");
    printf("\n\t\tCapacitance (farads): ");
    scanf("%le",capacitance);
  }
}

/*function q() evaluate the value of q*/
double q(double V, double R, double L, double C, double t)
{
  /*variable declaration*/
  double r2l= (R/(2*L));
  double part1=(V*C)*(-r2l*t);
  double part2=sin((pow(((1/(L*C))-(r2l*r2l)),0.5))*t);
  printf("\n\t\t%lg\n",ceil(pow(((1/(L*C))-(r2l*r2l)),0.5)));
  return part1*part2;
}
/*function sim() calculates the lenght of time to simulate the circuit and size of time step to use*/
void sim(double V, double R, double L, double C, double duration,double t)
{ 
  double i,N;
  for(i=0;i<duration;i+=t)
    {   
     N=q(V,R,L,C,i);
     printf("\n\t%g\t\t%g",i,N);
   }
}
