int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    
    int l, r, u, d;
    int lu, ld, ru, rd;

    r = n - c_q;
    l = c_q - 1;
    u = n - r_q;
    d = r_q - 1;

    lu = min(l, u);
    ld = min(l, d);
    ru = min(r, u);
    rd = min(r, d);
    
    // int total=0;
    
    for(int i=0; i<k; i++){
        //obs row and col
        int row=obstacles[i][0];
        int col=obstacles[i][1];
        //obs is in the same row as q
        if(row==r_q){
            //left side of q
            if(col<c_q){
                l=min(l, c_q - col - 1);
            }
            //right
            else{
               r=min(r, col - c_q -1); 
            }
        }
        else if(col==c_q){
            //up
            if(row>r_q){
                u=min(u, row - r_q - 1);
            }
            //down
            else{
                d=min(d, r_q - row - 1);
            }
        }
        else if (abs(col-c_q)==abs(row-r_q)) {
            //upper side
            if(row>r_q){
                //towards upper-right
                if(col>c_q){
                    ru=min(ru, row-r_q-1);
                }
                //towards upper-left
                else{
                    lu=min(lu, row-r_q-1);
                }
            }
            //lower side
            else{
                //towards lower right
                if(col>c_q){
                    rd=min(rd, r_q-row-1);
                }
                //towards lower left
                else{
                    ld=min(ld, r_q-row-1);
                }
            }
        }
    }
    
    return r+l+u+d+rd+ld+lu+ru;
    
    // return total;
}