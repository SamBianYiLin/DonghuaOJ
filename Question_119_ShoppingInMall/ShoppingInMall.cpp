#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct ProductPart
{
	int no;
	int quantity;
};
struct Products
{
	vector<ProductPart> eachProduct;
	int totalPrice;
};
int main() {
	int catagories;
	vector<Products> discounts;
	//	读取优惠类别与优惠内容
		for (int x = 0; x < catagories; x++){
		int n;
		scanf("%d", &n);
		Products products;
		//	一个优惠分类中有几组商品
		for (int y = 0; y < n; y++){
			int no, quantity;
			scanf("%d %d", &no, &quantity);
			products.eachProduct.push_back({ no,quantity });
		}
		//	读入总价
		int total; 
		scanf("%d", &total);
		products.totalPrice = total;
		discounts.push_back(products);
	}
	int productKinds;
	scanf("%d", &productKinds);
	for (int x = 0; x < productKinds; x++){

	}
	return 0;
}