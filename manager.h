#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];       // 상품 이름
    char info[30];       // 설명, information
    char gram[10];       // 중량
    int price;           // 판매 가격
    int deli;            // 배송방법 (1: 새벽배송, 2: 택배배송), delivery
}Product;

int selectMenu();
int addProduct(Product *p);                  // 상품 추가
void infoProduct(Product p);                 // 한 상품 정보 출력
void listProduct(Product *p, int cnt);       // 전체 상품 정보 출력
int updateProduct(Product *p);               // 제품 정보 변경
int deleteProduct(Product *p);               // 제품 정보 삭제
void saveData(Product *p, int cnt);          // 상품의 정보를 file에 저장
int loadData(Product *p);                    // 상품 정보 갯수 
int searchProduct_n(Product *p, int cnt);    // 제품 이름 검색
int searchProduct_p(Product *p, int cnt);    // 제품 가격 검색, 입력된 가격보다 낮은 가격의 상품 출력
int searchProduct_d(Product *p, int cnt);    // 제품 배송방법 검색
int selectDataNo(Product *p, int cnt);       // 리스트에 담긴 제품 중 한 제품 선택   
