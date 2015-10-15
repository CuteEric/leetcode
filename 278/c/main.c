#include <stdio.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int low = 1, high = n, mid;
    while(low < high) {  
	// ����low+high�п����������˲���дmid = (low + high) / 2;
        mid = low + (high - low) / 2; 
        if(isBadVersion(mid)) 
            high = mid;  
        else  
            low = mid + 1;  
    }  
    return low;  
}
