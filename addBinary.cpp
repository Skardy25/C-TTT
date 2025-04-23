class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        char acarreo = '0';
        string max, min;
        if(a.length() > b.length()){
            max = a;
            min = b;
        }else{
            max = b;
            min = a;
        }
        int j = min.length() -1;
        for(int i = max.length() -1; i >= 0; --i){
            switch(max[i]){
                case '0':
                    if(j >= 0){
                        if(min[j] == '0'){
                            if(acarreo == '0'){
                                result = '0' + result;
                            }else {
                                result = '1' + result;
                                acarreo= '0';
                            }
                        }else {
                            if(acarreo == '0'){
                                result = '1' + result;
                            }else {
                                result = '0' + result;
                                acarreo= '1';
                            }
                        }
                        --j;
                    }else{
                        if(acarreo == '1'){
                            result = '1' + result;
                            acarreo = '0';
                        }else{
                            result = '0' + result;
                        }
                    }
                    break;
                default:
                    if(j >= 0) {
                        if(min[j] == '0'){
                            if(acarreo == '0'){
                                result = '1' + result;
                            }else{
                                result = '0' + result;
                                acarreo = '1';
                            }
                        }else {
                            if(acarreo == '0'){
                                result = '0' + result;
                                acarreo = '1';
                            }else{
                                result = '1' + result;
                                acarreo = '1';
                            }
                        }
                        --j;
                    }else{
                        if(acarreo == '1'){
                            result = '0' + result;
                            acarreo = '1';
                        }else{
                            result = '1' + result;
                        }
                    }
                    break;
            }
        }
        if(acarreo == '1'){
            result = '1' + result;
        }
        return result;
    }
};

// efficient memory solution
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(),b.end());
        string res = "";
        int x = 0;
        int l = 0;
        while(l<a.length() || l<b.length() || x>0)
        {
            if(l<a.length())
            {
                x += (a[l]-'0');
            }
            if(l<b.length())
            {
                x += (b[l]-'0');
            }
            if(x==3)
            {
                x = 1;
                res += "1";
            }
            else if(x==2)
            {
                x = 1;
                res += "0";
            }
            else if(x==1)
            {
                x = 0;
                res += "1";
            }
            else
            {
                x = 0;
                res += "0";
            }
            l++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
