
int getStudents(vector<int>arr, int pages){
    int student = 1;
    int pagesAll = 0;

    for (int i = 0; i < arr.size(); i++){
        if (arr[i] + pagesAll > pages){
            student++;
            pagesAll = arr[i];
        }
        else{
            pagesAll += arr[i];
        }
    }

    return student;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if (m > arr.size()){
        return -1;
    }
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++){
        sum += arr[i];
        maxi = max(maxi , arr[i]);
    }

    int low = maxi;
    int high = sum;

    while (low <= high){
        int mid = ((low + high) >> 1);
        int numStudents = getStudents(arr, mid);

        
        if (numStudents <= m){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return low;
    
}