#include "manager.h"

int main(void){
    Product p[20];
    int count = 0, menu, index = 0;
    count = loadData(p);
#ifdef DEBUG
    printf("=> DEBUGMODE");
#endif
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1){
            if(count>0) listProduct(p, index);
            printf("\n총 %d개의 리스트가 있습니다.\n", count);
        }
        else if (menu == 2){
            count+=addProduct(&p[index++]);
        }
        else if (menu == 3){
            int no = selectDataNo(p, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            getchar();
            updateProduct(&p[no-1]);
        }
        else if (menu == 4){
            int no = selectDataNo(p, index);
            if(no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int delok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)" );
            scanf("%d", &delok);
            if(delok == 1){
                if(deleteProduct(&p[no-1])) count--;
                printf("\n=> 삭제됨!\n");
            }
        }
        else if( menu == 5) saveData(p, index);
        else if( menu == 6){
            int num = searchProduct_n(p, index);
            printf("총 %d개의 주문이 있습니다.\n", num);
        }
        else if( menu == 7){
            int num = searchProduct_p(p, index);
            printf("총 %d개의 주문이 있습니다.\n", num);
        }
        else if( menu == 8){
            int num = searchProduct_d(p, index);
            printf("총 %d개의 주문이 있습니다.\n", num);
        }
                                                                                  
    }
    printf("종료됨!\n");
    return 0;
}
