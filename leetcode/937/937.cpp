class Solution {
public:
    
    static bool compare(const string& a, const string& b)
    {
        int indexA = a.find(" ");
        int indexB = b.find(" ");
        
        string identifierA = a.substr(0,indexA);
        string logA = a.substr(indexA+1);
        string identifierB = b.substr(0,indexB);
        string logB = b.substr(indexB+1);
        
        if( logA < logB ) return true;
        else if( logA > logB ) return false;
        else
        {
            if(identifierA < identifierB) return true;
            else return false;
        }
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> numLog;
        vector<string> letterLog;
        
        for(auto log : logs)
        {
            int index = log.find(" ");
            if(isdigit(log[index+1])) numLog.push_back(log);
            else letterLog.push_back(log);
        }
        
        std::sort(letterLog.begin(), letterLog.end(), Solution::compare) ;
        
        for(auto log : numLog)
        {
            letterLog.push_back(log);
        }
        return letterLog;
    }
};