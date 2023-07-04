class Solution {
public:
    string decode(string s){
        int count = 0; string temp = "", n = "", res = ""; vector<string> ans; 


        for(int i=0; i<s.length(); i++){
            if(s[i]>=48 && s[i]<58 && count == 0) {n+= s[i]; if(temp!= ""){ans.push_back("1");  ans.push_back(temp); temp = ""; } }
            else if(s[i] == '[' && count == 0) count++; 
            else if(s[i] == ']' && count == 1) { ans.push_back(n); ans.push_back(temp); n = ""; temp = ""; count = 0; }
            else if(s[i] == '[') {count++; temp += s[i]; }
            else if(s[i] == ']'){ count--; temp += s[i]; }
            else {temp += s[i]; } 
        } 
        
        if(temp != ""){ans.push_back("1");  ans.push_back(temp); }
        for(int i=0; i<ans.size(); i+=2){
            int c = stoi(ans[i]);  string temp = ans[i+1]; 
            while(c--) res += temp; 
        }

        return res; 
    }

    bool check(string s){
        for(int i=0; i<s.length(); i++) if(s[i]>=48 && s[i]<58) return true; 
        return false; 
    }

    string decodeString(string s) {
     
    while(check(s)) s = decode(s); 

    return s; 

    }
};