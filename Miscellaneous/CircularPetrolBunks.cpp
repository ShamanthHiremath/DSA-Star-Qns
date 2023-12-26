/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

N = 4
Petrol = 4 6 7 4
Distance = 6 5 3 5
Output: 1
Explanation: There are 4 petrol pumps with
amount of petrol and distance to next
petrol pump value pairs as {4, 6}, {6, 5},
{7, 3} and {4, 5}.

struct petrolPump
{
    int petrol;
    int distance;
};*/
class Solution{
  public:
  //4 3 10 4
  //6 5 3  5
  //fuel stock accomadation
  //-2 -2 7 -1
  //ans is 3rd petrol bunk
  int tour(petrolPump p[],int n)
    {
       int start=0;
       int fuel=0;
       int fuelrunoutindefcietstations=0;
       for(int  i=0; i<n; i++){
           fuel+=p[i].petrol - p[i].distance ;
           if(fuel<0){
               fuelrunoutindefcietstations+=fuel;
               start=i+1;
               fuel=0;
           }
       }
       if(fuel+fuelrunoutindefcietstations>0){
           return start;
       }
       else{
           return -1;
       }
    }
};