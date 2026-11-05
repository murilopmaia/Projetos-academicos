int padovan(int n){
    if(n == 1||n == 2|| n == 3){
        return 1;
    }
    else{
        return padovan(n-2) + padovan(n-3);
    }
}

int main(){
    printf("%d",padovan(8));
    return 0;
}