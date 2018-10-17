#include <iostream>
using namespace std;

struct Rule
{
	int quota;
	int percentage;
};

void inputRules(struct Rule rules[], int n){
	for(int i = 0; i < n; i++){
		cout << "请输入第" << i + 1 << "条规则:";
		cin >> rules[i].quota >> rules[i].percentage;
	}

	cout <<"纳税规则如下：" << endl;
	cout <<"纳税线      税率"<< endl;
	for(int i = 0; i < n; i++){
		cout << rules[i].quota << "          " << rules[i].percentage << endl;
	}
}


double computeTax(struct Rule rules[], int n, int income){
	double sum = 0;
	for(int i = 0; i < n - 1; i++){
		if(income <=rules[i].quota){
			return sum;
		}
		if(income > rules[i].quota && income <= rules[i+1].quota){
			sum = sum + (income - rules[i].quota) * rules[i].percentage / 100.0;
			return sum;
		}
		if(income > rules[i + 1].quota){
			sum = sum + (rules[i + 1].quota - rules[i].quota) * rules[i].percentage / 100.0;
		}
		if(i==n-2 && income > rules[n - 1].quota){
			sum = sum + (income - rules[n-1].quota) * rules[n-1].percentage / 100.0;
			return sum;
		}
	}
}

int main(){
	cout << "请输入规则的条数：";
	int n;
	cin >> n;
	struct Rule rules[10];
	inputRules(rules, n);
	int income = 0;

	while(income != -1){
		cout  << "请输入您的收入：";
		cin >> income;
		if (income == -1) {
			cout << "再见" << endl;
			break;
		}
		cout << "您的收入是：" << income << ",应交所得税：" << computeTax(rules,n,income) << "元。" << endl;
	}
	return 0;
}

