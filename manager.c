#include "manager.h"

int selectMenu(){
    int menu;
    printf("\n*** Info product ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 가격 검색\n");
    printf("8. 배송방법 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();
    return menu;
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
void listProduct(Product *p, int cnt){
    int i = 0;
    printf("No  Name   information  gram  price  delivery\n");
    printf("=============================================\n");
    for(i=0; i<cnt; i++){
        if(p[i].price == -1) continue;
        printf("%2d", i+1);
        infoProduct(p[i]);
    }
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
int searchProduct_n(Product *p, int count){
    int scnt = 0;          // 현재 일치하는 데이터 갯수
    char search[20];

    printf("검색할 이름? ");
    scanf("%s", search);

    printf("No  Name   information  gram  price  delivery\n");
    printf("=============================================\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, search)){
            printf(" %s  %s  %s  %3d  %3d\n", p[i].name, p[i].info, p[i].gram, p[i].price, p[i].deli);
            scnt++;
        }

    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!\n");

    return scnt;
}
int searchProduct_p(Product *p, int cnt){
    int scnt = 0;
    int price;

    printf("검색할 가격? ");
    scanf("%d", &price);

    for(int i = 0; i<cnt; i++){
        if(p[i].price == -1) continue;
        if(price >= p[i].price) {
            printf(" %s  %s  %s  %3d  %3d\n", p[i].name, p[i].info, p[i].gram, p[i].price, p[i].deli);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!\n");
    return scnt;  
}
int searchProduct_d(Product *p, int cnt){
    int scnt = 0;
    int d;

    printf("검색할 배송 방법(1: 새벽배송, 2: 택배배송)? ");
    scanf("%d", &d);

    for(int i = 0; i<cnt; i++){
        if(p[i].price == -1) continue;
        if(p[i].deli == d) {
            printf(" %s  %s  %s  %3d  %3d\n", p[i].name, p[i].info, p[i].gram, p[i].price, p[i].deli);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!\n");
    return scnt;  
}
void saveData(Product *p, int cnt){        // 상품의 정보를 file에 저장
    FILE* file;
    file = fopen("product.txt", "wt");

    for(int i = 0; i<cnt; i++){
        if(p[i].price == -1) continue;
        fprintf(file,  "%s  %s  %s  %3d  %3d\n", p[i].name, p[i].info, p[i].gram, p[i].price, p[i].deli);
    }
    fclose(file);
    printf("=> 저장됨\n");
}

int selectDataNo(Product* p, int cnt){
    int no;
    listProduct(p, cnt);
    printf("\n번호는 (취소 :0)? ");
    scanf("%d", &no);

    return no;
}
int loadData(Product *p){
    int i = 0; 
    FILE* file;
    file = fopen("product.txt","rt");
    if(file == NULL) printf("=> 파일 없음\n");
    else{
        fscanf(file, "%s", p->name);
        fscanf(file, "%s", p->info);
        fscanf(file, "%s", p->gram);
        fscanf(file, "%d", &p->price);
        fscanf(file, "%d", &p->deli);           
        printf("=> 로딩 성공\n");
    }
    fclose(file);
    return i;
}

