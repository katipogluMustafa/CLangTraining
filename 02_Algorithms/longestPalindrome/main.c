int longestPalindrome(char* s) {
    int arr[126] = { 0 };
    while(*s){
        arr[*s++]++;
    }
  0  int i;
    int count = 0;
    int x = 0;
    for(i = 0; i < 126; i++){
        if( arr[i] && (arr[i] / 2) ){
            count += arr[i] / 2;
        }
        
        if(arr[i] % 2){
            x++;
        }
    }
    
    if(x > 0){
        return 2 * count + 1;
    }
    
    return 2 * count;
    
}
