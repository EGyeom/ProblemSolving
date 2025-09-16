// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    long long l = 1;
    long long r = n;
    int answer = 2e31-1;
    while(l <= r)
    {
        int mid = (l + r) /2;
        if(isBadVersion(mid))
        {
            answer = mid < answer ? mid : answer;
            r = mid - 1;
        }
        else l = mid + 1;
    }


    return answer;
}
