int somar_diferente(int x,int y){
    if(x==0){
        return y;
    }
    else{
        return 1+somar_diferente(x-1,y);
    }
}

int main(){
    printf(" %d ",somar_diferente(3,3));
    return 0;
}