class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26]={0};
        for(int i=0;i<str.size();i++){
            if(str[i]>='a'&&str[i]<='z'){
                arr[str[i]-'a']++;
            }
            if(str[i]>='A'&&str[i]<='Z'){
                arr[str[i]-'A']++;
            }
        }
        int pos=-1, maxi=-1;
        for(int i=0;i<26;i++){
            if(maxi<arr[i]){
                maxi=arr[i];
                pos=i;
            }
        }
        return 'a'+ pos;
    }

};