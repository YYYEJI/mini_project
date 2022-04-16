#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[30];        // 상품 이름
	char info[30];        // 상품 설명, information
	char gram[10];        // 상품의 중량
	int price;            // 판매 가격
	int deli;             // 배송방법 (1: 새벽배송, 2: 택배배송)
}Product;

int selectMenu();             
int addProduct(Product *p);      // 상품 추가
void infoProduct(Product *p);   // 한 상품 정보 출력
int updateProduct(Product *p);   // 상품 정보 변경
void saveData(Product *p);       // 상품의 정보를 file에 저장
void loadData(Product *p);       // 상품 정보 갯수
