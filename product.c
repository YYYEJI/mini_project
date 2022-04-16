#include "product.h"

int selectMenu(){
	int menu;
	printf("\n*** Info product ***\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 파일저장\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	getchar();
	return menu;
}
int main(){
	Product p;
	int cnt = 0, menu;

	while(1){
		menu = selectMenu();
		if(menu == 0) break;
		if(menu == 1) {
			if(cnt>0) infoProduct(p);
		}
		else if(menu == 2) cnt+=addProduct(&p);
		else if(menu == 3) updateProduct(&p);
		else if(menu == 4) saveData(&p);
	}
	printf("종료됨!\n");
	return 0;
}
int addProduct(Product *p){
    printf("상품의 이름은? ");
    scanf("%[^\n]s", p->name);
    getchar();
    printf("상품 정보 입력 > ");
    scanf("%[^\n]s", p->info);
    getchar();
    printf("상품의 중량 입력 > ");
    scanf("%[^\n]s", p->gram);
    getchar();
    printf("상품의 가격 입력 >  ");
    scanf("%d", &p->price);
    printf("배송 방법 입력(1: 새벽배송, 2: 택배배송) > ");
    scanf("%d", &p->deli);

    return 1;
}
void infoProduct(Product p){                  // 한 상품 정보 출력
    printf(" %s  %s  %s  %3d  %3d\n", p.name, p.info, p.gram, p.price, p.deli);
}


int updateProduct(Product *p){
    printf("상품의 이름은? ");
    scanf("%[^\n]s", p->name);
    getchar();
    printf("상품 정보 입력 > ");
    scanf("%[^\n]s", p->info);
    getchar();
    printf("상품의 중량 입력 > ");
    scanf("%[^\n]s", p->gram);
    getchar();
    printf("상품의 가격 입력 >  ");
    scanf("%d", &p->price);
    printf("배송 방법 입력(1: 새벽배송, 2: 택배배송) > ");
    scanf("%d", &p->deli);


    return 1;
}
int deleteProduct(Product *p){               // 제품 정보 삭제
    p->price = -1;
    return 1;
}
void saveData(Product *p){        // 상품의 정보를 file에 저장
    FILE* file;
    file = fopen("product.txt", "wt");


    if(p->price != -1) {
        fprintf(file,  "%s  %s  %s  %3d  %3d\n", p->name, p->info, p->gram, p->price, p->deli);
    }
    fclose(file);
    printf("=> 저장됨\n");
}

