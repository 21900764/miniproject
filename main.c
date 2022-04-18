#include "product.h"

int main(void){
        Product s[20];
        int index =0;
        int count =0;
        int menu;
        int no;
        while(1){
                menu = selectMenu();
                if(menu ==0) break;
                if(menu == 1){
                        if(count >0){
                                listProduct(s,index);
                        }else{
                                printf("데이터가 없습니다.\n");
                        }
                }
                else if(menu ==2){
                        count ++;
                        addProduct(&s[index++]);
                }
                else if(menu==3){
                        no=selectData(s,index);
                        if(no==0){
                                printf("=>취소됨!\n");
                                continue;
                        }
                        updateProduct(&s[no-1]);
                }
                else if(menu==4){
                        int deleteok;
                        no = selectData(s,index);
                        if(no==0){
                                printf("=>취소됨!\n");
                                continue;
                        }
                        printf("정말로 삭제하시겠습니까? (삭제:1)");
                        scanf("%d",&deleteok);
                        if(deleteok==1){
                                if(deleteProduct(&s[no-1])) count--;
                        }
                }
        }
        printf("종료됨!\n");
        return 0;
}
