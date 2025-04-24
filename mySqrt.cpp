class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int izq = 0;
        int der = x;
        int med;
        while(izq <= der ){
            med = (izq + der) / 2;
            if(med < x/med){
                izq = med+1;
            }else if(med > x/med){
                der = med-1;
            }else{
                return med;
            }
        }
        return der;
    }
};
