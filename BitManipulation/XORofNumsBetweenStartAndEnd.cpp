class Solution {
  public:
  int findXORofNnums(int n){
      /*
        If 𝑛 % 4 = = 0 : The XOR of the first n natural numbers is n.
        If 𝑛 % 4 = = 1 : The XOR of the first n natural numbers is 1.
        If 𝑛 % 4 = = 2 : The XOR of the first n natural numbers is n + 1.
        If 𝑛 % 4 = = 3 : The XOR of the first n natural numbers is 0.
        */
      if(n%4 == 0)return n;
      else if(n%4 == 1)return 1;
      else if(n%4 == 2)return n+1;
      else return 0;
      
  }
    int findXOR(int l, int r) {
        
        int left = findXORofNnums(l-1);
        int right = findXORofNnums(r);
        
        return right ^ left;
    }
};