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
struct CustomerProduct
{
	ProductPart product;
	int originPrice;
};
int main() {
	int catagories;
	scanf("%d", &catagories);
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
	vector<CustomerProduct> cusRequirement;
	for (int x = 0; x < productKinds; x++){
		CustomerProduct cp;
		int no, quantity, total;
		scanf("%d %d %d", &no, &quantity, &total);
		cp.product.no = no;
		cp.product.quantity = quantity;
		cp.originPrice = total;
		cusRequirement.push_back(cp);
	}
	//	while (1);
	int originTotalPrice = 0;
	for (int x = 0; x < productKinds; x++){
		originTotalPrice += cusRequirement[x].product.quantity * cusRequirement[x].originPrice;
	}

	return 0;
}