#include <stdio.h>
#include <stdio.h>
#include <stdlib.h> //这里包含system("cls")和system("pause") 
#include <string.h>
#define N 3
struct Xscj {
	char xh[14];
	char xm[10];
	char xb[4];
	float gs, cyy, sd, zf;
};
void Createfile() { //这个函数是需要创建文件时才调用
	FILE *fp;
	char filename[20];
	printf("请输入新文件的文件名和扩展名:");
	gets(filename);
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("文件创建失败!!\n");//一般不会失败
		exit(0);  //强行终止程序的运行
	}
	fclose(fp);
}
void Savedata(Xscj *p) { //保存数据函数
	Xscj *q;
	FILE *fp;
	q = p;
	char filename[20];
	printf("请输入保存数据的文件名和扩展名:");
	gets(filename);
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("文件创建失败!!\n");//一般不会失败
		exit(0);  //强行终止程序的运行
	}
	for (; p < q + N; p++) {
		fwrite(p, sizeof(Xscj), 1, fp);
	}
	fclose(fp);
}
void Opendata(Xscj *p) { //打开数据函数
	Xscj *q;
	FILE *fp;
	q = p;
	char filename[20];
	printf("请输入打开数据的文件名和扩展名:");
	gets(filename);
	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("文件创建失败!!\n");//一般不会失败
		exit(0);  //强行终止程序的运行
	}
	for (; p < q + N; p++) {
		fread(p, sizeof(Xscj), 1, fp);
	}
	fclose(fp);
}
void Inputdata(Xscj *p) { //输入数据函数
	Xscj *q = p;
	int i = 1;
	while (p < q + N) {
		printf("请输入第 %d 个学生的学号: ", i);
		gets(p->xh);
		printf("请输入第 %d 个学生的姓名: ", i);
		gets(p->xm);
		printf("请输入第 %d 个学生的性别: ", i);
		gets(p->xb);
		printf("请输入第 %d 个学生的高数成绩", i);
		scanf("%f", &p->gs);
		printf("请输入第 %d 个学生的C语言成绩", i);
		scanf("%f", &p->cyy);
		printf("请输入第 %d 个学生的数电成绩", i);
		scanf("%f", &p->sd);
		p->zf = p->gs + p->cyy + p->sd;
		getchar();
		i++;
		p++;
		printf("\n");
	}
}
void Outputdata(Xscj *p) {//输出数据
	Xscj *q = p;
	int i = 1;
	printf("\n序号    学号     姓名     性别  高数  C语言  数电  总分\n");
	for (; p < q + N; p++) {
		printf(" %-3d", i++);
		printf("%s", p->xh);
		printf("%7s", p->xm);
		printf("%7s", p->xb);
		printf("%6g", p->gs);
		printf("%6g", p->cyy);
		printf("%7g", p->sd);
		printf("%6g\n", p->zf);
	}
	printf("\n\n");
}
void Modifydata(Xscj *p) { //修改第i个数据
	printf("不需要修改就直接回车，需要修改请输入修改的内容\n\n");
	char ch;
	int i;
	Xscj *q = p;
	Outputdata(q);
	printf("请输入修改数据的序号:");
	scanf("%d", &i);
	if (i < 1 || i > N) return;
	p = p + (i - 1);
	getchar(); //接收输入i后的回车符
	printf("学号 %s:\n", p->xh);
	printf("你需要修改吗？Yy/:");
	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		getchar();
		gets(p->xh);
	}
	printf("姓名 %s:\n", p->xm);
	printf("你需要修改吗？Y/y:");
	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		getchar();
		gets(p->xm);
	}
	printf("性别 %s:\n", p->xb);
	printf("你需要修改吗？Y/y:");
	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		getchar();
		gets(p->xb);
	}
	printf("高数 %g:\n", p->gs);
	printf("你需要修改吗？Y/y:");
	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		scanf("%f", &p->gs);
		getchar();
	}
	printf("C语言 %g:\n", p->cyy);
	printf("你需要修改吗？Y/y:");
	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		scanf("%f", &p->cyy);
		getchar();
	}
	printf("数电 %g:\n", p->sd);
	printf("你需要修改吗？Y/y:");
	ch = getchar();
	if (ch == 'Y' || ch == 'y') {
		scanf("%f", &p->sd);
		getchar();
	}
	p->zf = p->gs + p->cyy + p->sd;
	Savedata(q);
}
void Seekdata(Xscj *p) { //查找数据
	printf("\n\t\t请输入下列查找项目的编号进行相应的应用查找\n\n") ;
	printf("\t\t  1.按学号查找        2.按姓名查找\n\n");
	printf("\t\t  3.按性别查找        4.查找高数分数段\n\n");
	printf("\t\t  5.查找C语言分数段   6.查找数据分数段\n\n");
	printf("\t\t  7.查找总分分数段\n\n");
	int i;
	Xscj *q = p;
	char st[14];
	bool flag = 1;
	float start, end, temp;
	scanf("%d", &i);
	switch (i) {
		case 1:
			getchar();//接收输入i后的回车符
			printf("请输入要查找的学号: ");
			gets(st);
			for (; p < q + N; p++) {
				if (!strcmp(p->xh, st)) {
					flag = 0;//表示找到了
					break;
				}
			}
			if (!flag) {
				p = q;
				printf("\n    学号     姓名     性别  高数  C语言  数电  总分\n");
				for (; p < q + N; p++) {
					if (!strcmp(p->xh, st)) {
						printf("%s", p->xh);
						printf("%7s", p->xm);
						printf("%7s", p->xb);
						printf("%6g", p->gs);
						printf("%6g", p->cyy);
						printf("%7g", p->sd);
						printf("%6g\n", p->zf);
					}
				}
			} else printf("没有查找到学号为 %s 的记录\n", st);
			break;
		case 2:
			getchar();//接收输入i后的回车符
			printf("请输入要查找的姓名: ");
			gets(st);
			for (; p < q + N; p++) {
				if (!strcmp(p->xm, st)) {
					flag = 0;//表示找到了
					break;
				}
			}
			if (!flag) {
				p = q;
				printf("\n    学号     姓名     性别  高数  C语言  数电  总分\n");
				for (; p < q + N; p++) {
					if (!strcmp(p->xm, st)) {
						printf("%s", p->xh);
						printf("%7s", p->xm);
						printf("%7s", p->xb);
						printf("%6g", p->gs);
						printf("%6g", p->cyy);
						printf("%7g", p->sd);
						printf("%6g\n", p->zf);
					}
				}
			} else printf("没有查找到姓名为 %s 的记录\n", st);
			break;
		case 3:
			getchar();//接收输入i后的回车符
			printf("请输入要查找的性别: ");
			gets(st);
			for (; p < q + N; p++) {
				if (!strcmp(p->xb, st)) {
					flag = 0;//表示找到了
					break;
				}
			}
			if (!flag) {
				p = q;
				printf("\n    学号     姓名     性别  高数  C语言  数电  总分\n");
				for (; p < q + N; p++) {
					if (!strcmp(p->xb, st)) {
						printf("%s", p->xh);
						printf("%7s", p->xm);
						printf("%7s", p->xb);
						printf("%6g", p->gs);
						printf("%6g", p->cyy);
						printf("%7g", p->sd);
						printf("%6g\n", p->zf);
					}
				}
			} else printf("没有查找到性别为 %s 的记录\n", st);
			break;
		case 4:
			printf("请输入查找高数的分数段,查找某个分数输入相同的值:");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > 100 || end > 100) return;
			if (start > end) { //始终保持start<=end
				temp = start;
				start = end;
				end = temp;
			}
			for (; p < q + N; p++) {
				if (p->gs >= start && p->gs <= end) {
					flag = 0;//表示找到了
					break;
				}
			}
			if (!flag) {
				p = q;
				printf("\n    学号     姓名     性别  高数  C语言  数电  总分\n");
				for (; p < q + N; p++) {
					if (p->gs >= start && p->gs <= end) {
						printf("%s", p->xh);
						printf("%7s", p->xm);
						printf("%7s", p->xb);
						printf("%6g", p->gs);
						printf("%6g", p->cyy);
						printf("%7g", p->sd);
						printf("%6g\n", p->zf);
					}
				}
			} else printf("区间在[%g,%g]的分数段不存在\n", start, end);
			break;
		case 5:
			printf("请输入查找C语言的分数段,查找某个分数输入相同的值:");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > 100 || end > 100) return;
			if (start > end) { //始终保持start<=end
				temp = start;
				start = end;
				end = temp;
			}
			for (; p < q + N; p++) {
				if (p->cyy >= start && p->cyy <= end) {
					flag = 0;//表示找到了
					break;
				}
			}
			if (!flag) {
				p = q;
				printf("\n    学号     姓名     性别  高数  C语言  数电  总分\n");
				for (; p < q + N; p++) {
					if (p->cyy >= start && p->cyy <= end) {
						printf("%s", p->xh);
						printf("%7s", p->xm);
						printf("%7s", p->xb);
						printf("%6g", p->gs);
						printf("%6g", p->cyy);
						printf("%7g", p->sd);
						printf("%6g\n", p->zf);
					}
				}
			} else printf("区间在[%g,%g]的分数段不存在\n", start, end);
			break;
		case 6:
			printf("请输入查找数电的分数段,查找某个分数输入相同的值:");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > 100 || end > 100) return;
			if (start > end) { //始终保持start<=end
				temp = start;
				start = end;
				end = temp;
			}
			for (; p < q + N; p++) {
				if (p->sd >= start && p->sd <= end) {
					flag = 0;//表示找到了
					break;
				}
			}
			if (!flag) {
				p = q;
				printf("\n    学号     姓名     性别  高数  C语言  数电  总分\n");
				for (; p < q + N; p++) {
					if (p->sd >= start && p->sd <= end) {
						printf("%s", p->xh);
						printf("%7s", p->xm);
						printf("%7s", p->xb);
						printf("%6g", p->gs);
						printf("%6g", p->cyy);
						printf("%7g", p->sd);
						printf("%6g\n", p->zf);
					}
				}
			} else printf("区间在[%g,%g]的分数段不存在\n", start, end);
			break;
		case 7:
			printf("请输入查找高数的总分段,查找某个分数输入相同的值:");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > N * 100 || end > N * 100) return;
			if (start > end) { //始终保持start<=end
				temp = start;
				start = end;
				end = temp;
			}
			for (; p < q + N; p++) {
				if (p->zf >= start && p->zf <= end) {
					flag = 0; //表示找到了
					break;
				}
			}
			if (!flag) {
				p = q;
				printf("\n    学号     姓名     性别  高数  C语言  数电  总分\n");
				for (; p < q + N; p++) {
					if (p->zf >= start && p->zf <= end) {
						printf("%s", p->xh);
						printf("%7s", p->xm);
						printf("%7s", p->xb);
						printf("%6g", p->gs);
						printf("%6g", p->cyy);
						printf("%7g", p->sd);
						printf("%6g\n", p->zf);
					}
				}
			} else printf("区间在[%g,%g]的分数段不存在\n", start, end);
			break;
		default:
			printf("你输入的编号不正确，不能进行查找操作\n");
			break;
	}
	printf("\n");
}
void DataSort(Xscj a[]) {//数据排序
	printf("\n\t\t请输入下列查找项目的编号进行相应的排序\n\n") ;
	printf("\t\t  1.按学号排序        2.按姓名排序\n\n");
	printf("\t\t  3.按性别排序        4.查找高数排序\n\n");
	printf("\t\t  5.查找C语言排序     6.查找数据排序\n\n");
	printf("\t\t  7.查找总分排序\n\n");
	int i, j, q, choise;
	Xscj temp;
	scanf("%d", &choise);
	switch (choise) {
		case 1:
			for (i = 0; i < N - 1; i++) {
				q = i;
				for (j = i + 1; j < N; j++)
					if (strcmp(a[q].xh, a[j].xh) > 0) q = j;
				if (i != q) {
					temp = a[i];
					a[i] = a[q];
					a[q] = temp;
				}
			}
			break;
		case 2:
			for (i = 0; i < N - 1; i++) {
				q = i;
				for (j = i + 1; j < N; j++)
					if (strcmp(a[q].xm, a[j].xm) > 0) q = j;
				if (i != q) {
					temp = a[i];
					a[i] = a[q];
					a[q] = temp;
				}
			}
			break;
		case 3:
			for (i = 0; i < N - 1; i++) {
				q = i;
				for (j = i + 1; j < N; j++)
					if (strcmp(a[q].xb, a[j].xb) > 0) q = j;
				if (i != q) {
					temp = a[i];
					a[i] = a[q];
					a[q] = temp;
				}
			}
			break;
		case 4:
			for (i = 0; i < N - 1; i++) {
				q = i;
				for (j = i + 1; j < N; j++)
					if (a[q].gs > a[j].gs) q = j;
				if (i != q) {
					temp = a[i];
					a[i] = a[q];
					a[q] = temp;
				}
			}
			break;
		case 5:
			for (i = 0; i < N - 1; i++) {
				q = i;
				for (j = i + 1; j < N; j++)
					if (a[q].cyy > a[j].cyy) q = j;
				if (i != q) {
					temp = a[i];
					a[i] = a[q];
					a[q] = temp;
				}
			}
			break;
		case 6:
			for (i = 0; i < N - 1; i++) {
				q = i;
				for (j = i + 1; j < N; j++)
					if (a[q].sd > a[j].sd) q = j;
				if (i != q) {
					temp = a[i];
					a[i] = a[q];
					a[q] = temp;
				}
			}
			break;
		case 7:
			for (i = 0; i < N - 1; i++) {
				q = i;
				for (j = i + 1; j < N; j++)
					if (a[q].zf > a[j].zf) q = j;
				if (i != q) {
					temp = a[i];
					a[i] = a[q];
					a[q] = temp;
				}
			}
			break;
		default:
			printf("对不起，你输入的编号有误，不能进行操作\n");
			break;
	}
}
int Countdata(Xscj *p) { //统计数据
	printf("\n\t\t请输入下列查找项目的编号进行相应的排序\n\n") ;
	printf("\t\t  1.统计女生人数                2.统计男生人数\n\n");
	printf("\t\t  3.统计高数分数段的人数        4.统计C语言分数段的人数\n\n");
	printf("\t\t  5.统计数电分数段的人数        6.统计总分分数段的人数\n\n");
	int choise, k = 0;
	float start, end;
	Xscj *q = p;
	scanf("%d", &choise);
	switch (choise) {
		case 1:
			for (; p < q + N; p++) {
				if (!strcmp(p->xb, "女")) k++;
			}
			return k;
		case 2:
			for (; p < q + N; p++) {
				if (!strcmp(p->xb, "男")) k++;
			}
			break;
		case 3:
			printf("请输入统计高数的分数段，统计某个分数输入相同的值: ");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > 100 || end > 100) {
				printf("对不起，你输入的分数段有误。");
				return -1;//满足函数类型的要求
			}
			if (start > end) {//让start<end始终成立
				float t;
				t = start;
				start = end;
				end = t;
			}
			for (; p < q + N; p++) {
				if (p->gs >= start && p->gs <= end) k++;
			}
			break;
		case 4:
			printf("请输入统计C语言的分数段，统计某个分数输入相同的值: ");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > 100 || end > 100) {
				printf("对不起，你输入的分数段有误。");
				return -1;//满足函数类型的要求
			}
			if (start > end) {//让start<end始终成立
				float t;
				t = start;
				start = end;
				end = t;
			}
			for (; p < q + N; p++) {
				if (p->cyy >= start && p->cyy <= end) k++;
			}
			break;
		case 5:
			printf("请输入统计数电的分数段，统计某个分数输入相同的值: ");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > 100 || end > 100) {
				printf("对不起，你输入的分数段有误。");
				return -1;//满足函数类型的要求
			}
			if (start > end) {//让start<end始终成立
				float t;
				t = start;
				start = end;
				end = t;
			}
			for (; p < q + N; p++) {
				if (p->sd >= start && p->sd <= end) k++;
			}
			break;
		case 6:
			printf("请输入统计总分的分数段，统计某个分数输入相同的值: ");
			scanf("%f%f", &start, &end);
			if (start < 0 || end < 0 || start > N * 100 || end > N * 100) {
				printf("对不起，你输入的分数段有误。");
				return -1;//满足函数类型的要求
			}
			if (start > end) {//让start<end始终成立
				float t;
				t = start;
				start = end;
				end = t;
			}
			for (; p < q + N; p++) {
				if (p->zf >= start && p->zf <= end) k++;
			}
			break;
		default:
			printf("对不起，你输入的编号有误，不能操作\n");
			k = -1;
			break;
	}
	return k;
}
void Meau(Xscj * p) { //主菜单
	int i;
	while (true) {
		system("cls"); //清屏命令
		printf("\n\n\t\t\t************ 欢迎使用成绩管理系统 ****************\n\n");
		printf("\t\t\t************ 请输入一下列功能的编号执行相应有功能*\n\n");
		printf("\t\t\t************ 1、打开数据 *************************\n\n");
		printf("\t\t\t************ 2、输入数据 *************************\n\n");
		printf("\t\t\t************ 3、输出数据 *************************\n\n");
		printf("\t\t\t************ 4、修改数据 *************************\n\n");
		printf("\t\t\t************ 5、查找数据 *************************\n\n");
		printf("\t\t\t************ 6、添加数据 *************************\n\n");
		printf("\t\t\t************ 7、删除数据 *************************\n\n");
		printf("\t\t\t************ 8、统计数据 *************************\n\n");
		printf("\t\t\t************ 9、数据排序 *************************\n\n");
		printf("\t\t\t************ 10、保存数据 *************************\n\n");
		printf("\t\t\t************ 11、退出系统 ************************\n\n");
		printf("\t\t请输入相应功能的编号：");
		scanf("%d", &i);
		switch (i) {
			case 1:
				//调用创建文件函数
				getchar(); //接收输入i后的回车符
				Opendata(p);
				break;
			case 2:
				//调用输入数据函数
				getchar();
				Inputdata(p);
				break;
			case 3:
				//调用输出数据函数
				Outputdata(p);
				break;
			case 4:
				//调用修改数据函数
				Modifydata(p);
				break;
			case 5:
				//调用查找数据函数
				Seekdata(p);
				break;
			case 6:
				//调用添加数据函数
				break;
			case 7:
				//调用删除数据函数
				break;
			case 8:
				//调用统计数据函数
				int k;
				k = Countdata(p);
				printf("你需要的数据是：%d\n", k);
				break;
			case 9:
				//调用数据排序函数
				DataSort(p);
				break;
			case 10:
				//调用保存数据函数
				getchar(); //接收输入i后的回车符
				Savedata(p);
				break;
			case 11:
				goto Lable;
				break;
			default:
				printf("你输入的编号有误，请重新输入:");
				break;
		}//end swithc
		system("pause");//屏幕暂停命令
	}//end while
Lable:
	printf("\t\t\t欢迎下次光临，请提出宝贵意见！！\n");
}

int main() {
	Xscj cj[N] ;
	Meau(cj);
	return 0;
}