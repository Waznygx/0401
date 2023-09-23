#include"stdio.h"
#include"stdlib.h"
#include"string.h"
int shoudsave = 0;
struct student {
	char num[10]; //学号
	char name[20];
	char sex[4];
	int cgrade;
	int mgrade;
	int egrade;
	int total;
	int ave;
	char neartime[10]; //最近更新时间
};

typedef struct node {
	struct student data;
	struct node* next;
}Node, * Link;

void menu() {
	printf("*****************************************\n");
	printf("\t1登记学生资料\t\t\t\t\t2删除学生资料\n");
	printf("\t3查询学生资料\t\t\t\t\t4修改学生资料\n");
	printf("\t5保存学生资料\t\t\t\t\t6排序学生资料\n");
	printf("\t7统计学生资料\t\t\t\t\t8输出学生资料\n");
	printf("\t9帮助信息\t\t\t\t\t0退出系统\n");
	printf("*****************************************\n");
}

void printstart() {
	printf("------------------------------\n");
}

void Wrong() {
	printf("\n=====>提示:输入错误!\n");
}

void Nofind() {
	printf("\n=====>提示:没有找到该学生!\n");
}

void printc() {
	printf("学号 姓名 性别 英语成绩 数学成绩 C语言成绩 总分 平均分\n");
}

void printe(Node* p) {
	printf("%s %-10s%s %7d%11d%11d\t%6d%8d\n", p->data.num, p->data.name, p->data.sex, p->data.egrade, p->data.mgrade,
		p->data.cgrade, p->data.total, p->data.ave);
}

Node* Locate(Link l, char findmess[], char nameornum[]) {
	Node* r;
	if (strcmp(nameornum, "num") == 0) {//按学号查询
		r = l->next;
		while (r != NULL) {
			if (strcmp(r->data.num, findmess) == 0)
				return r;
			r = r->next;
		}
	}
	else if (strcmp(nameornum, "name") == 0) {//按姓名查询
		r = l->next;
		while (r != NULL) {
			if (strcmp(r->data.name, findmess) == 0)
				return r;
			r = r->next;
		}
	}
	return 0;
}
void Add(Link l) {//增加学生
	Node* p, * r, * s;
	char num[10];
	r = l;
	s = l->next;
	while (r->next != NULL)
		r = r->next;//将指针置于最末尾
	while (1) {
		printf("请你输入学号(以'0'返回上一级菜单:)");
		scanf("%s", num);
		if (strcmp(num, "0") == 0)
			break;
		while (s) {
			if (strcmp(s->data.num, num) == 0) {
				printf("\n=====>提示:学号为'%s'的学生已经存在，若要修改请你选择'4修改'!\n", num);
				printstart();
				printc();
				printe(s);
				printstart();
				printf("\n");
				return;
			}
			s = s->next;
		}
		p = (Node*)malloc(sizeof(Node));
		strcpy(p->data.num, num);
		printf("请你输入姓名:");
		scanf("%s", p->data.name);
		getchar();
		printf("请你输入性别:");
		scanf("%s", p->data.sex);
		getchar();
		printf("请你输入c语言成绩:");
		scanf("%d", &p->data.cgrade);
		getchar();
		printf("请你输入数学成绩:");
		scanf("%d", &p->data.mgrade);
		getchar();
		printf("请你输入英语成绩:");
		scanf("%d", &p->data.egrade);
		getchar();
		p->data.total = p->data.egrade + p->data.cgrade + p->data.mgrade;
		p->data.ave = p->data.total / 3;
		//信息输入已经完成
		p->next = NULL;
		r->next = p;
		r = p;
		shoudsave = 1;
	}
}
void Qur(Link l) {//查询学生
	int sel;
	char findmess[20];
	Node* p;
	if (!l->next) {
		printf("\n=====>提示:没有资料可以查询!\n");
		return;
	}
	printf("\n=====>1按学号查找\n=====>2按姓名查找\n");
	scanf("%d", &sel);
	if (sel == 1) {
		printf("请你输入要查找的学号:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if (p) {
			printf("\t\t\t\t查找结果\n");
			printstart();
			printc();
			printe(p);
			printstart();
		}
		else
			Nofind();
	}
	else if (sel == 2) {
		printf("请你输入要查找的姓名:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if (p) {
			printf("\t\t\t\t查找结果\n");
			printstart();
			printc();
			printe(p);
			printstart();
		}
		else
			Nofind();
	}
	else
		Wrong();
}
void Del(Link l) {//删除
	int sel;
	char findmess[20];
	Node* p, * r;
	if (!l->next) {
		printf("\n=====>提示:没有资料可以删除!\n");
		return;
	}
	printf("\n=====>1按学号删除\n=====>2按姓名删除\n");
	scanf("%d", &sel);
	if (sel == 1) {
		printf("请你输入要删除的学号:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if (p) {
			r = l;
			while (r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n=====>提示:该学生已经成功删除!\n");
			shoudsave = 1;
		}
		else
			Nofind();
	}
	else if (sel == 2) {
		printf("请你输入要删除的姓名:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if (p) {
			r = l;
			while (r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n=====>提示:该学生已经成功删除!\n");
			shoudsave = 1;
		}
		else
			Nofind();
	}
	else
		Wrong();
}

void Modify(Link l) {//本函数用于修改资料
	Node* p;
	char findmess[20];
	if (!l->next) {
		printf("\n=====>提示:没有资料可以修改!\n");
		return;
	}
	printf("请输入要修改的学生学号:");
	scanf("%s", findmess);
	p = Locate(l, findmess, "num");
	if (p) {
		printf("请输入新学号(原来是%s):", p->data.num);
		scanf("%s", p->data.num);
		getchar();
		printf("请输入新姓名(原来是%s):", p->data.name);
		scanf("%s", p->data.name);
		getchar();
		printf("请输入新性别(原来是%s):", p->data.sex);
		scanf("%s", p->data.sex);
		getchar();
		printf("请输入新的C语言成绩(原来是%d分):", p->data.cgrade);
		scanf("%d", &p->data.cgrade);
		getchar();
		printf("请输入新的数学成绩(原来是%d分):", p->data.mgrade);
		scanf("%d", &p->data.mgrade);
		getchar();
		printf("请输入新的英语成绩(原来是%d分):", p->data.egrade);
		scanf("%d", &p->data.egrade);
		p->data.total = p->data.egrade + p->data.cgrade + p->data.mgrade;
		p->data.ave = p->data.total / 3;
		printf("\n=====>提示:资料修改成功!\n");
		shoudsave = 1;
	}
	else
		Nofind();
}
void Disp(Link l) {//本函数用于显示资料
	int count = 0;
	Node* p;
	p = l->next;
	if (!p) {
		printf("\n=====>提示:没有资料可以显示!\n");
		return;
	}
	printf("\t\t\t\t查找结果\n");
	printstart();
	printc();
	printf("\n");
	while (p) {
		printe(p);
		p = p->next;
	}
	printstart();
	printf("\n");
}

void Count(Link l) {//本函数用于统计分数
	Node* pm, * pe, * pc, * pt, * pa;//用于指向分数最高的接点
	Node* r = l->next;
	if (!r) {
		printf("\n=====>提示:没有资料可以统计!\n");
		return;
	}
	pm = pe = pc = pt = pa = r;
	while (r != NULL) {
		if (r->data.cgrade >= pc->data.cgrade)
			pc = r;
		if (r->data.mgrade >= pm->data.mgrade)
			pm = r;
		if (r->data.egrade >= pe->data.egrade)
			pe = r;
		if (r->data.total >= pt->data.total)
			pt = r;
		if (r->data.ave >= pa->data.ave)
			pa = r;
		r = r->next;
	}
	printf("---------------------统计结果---------------------\n");
	printf("总分最高者:\t%s %d分\n", pt->data.name, pt->data.total);
	printf("平均分最高者:\t%s %d分\n", pa->data.name, pa->data.ave);
	printf("英语最高者:\t%s %d分\n", pe->data.name, pe->data.egrade);
	printf("数学最高者:\t%s %d分\n", pm->data.name, pm->data.mgrade);
	printf("c语言最高者:\t%s %d分\n", pc->data.name, pc->data.cgrade);
	printstart();
}
void Sort(Link l) {
	Link ll;
	Node* p, * rr, * s;
	ll = (Link)malloc(sizeof(Node));//用于做新的连表
	ll->next = NULL;
	if (l->next == NULL) {
		printf("\n=====>提示:没有资料可以排序");
		return;
	}
	p = l->next;
	while (p) {
		s = (Node*)malloc(sizeof(Node));//新建接点用于保存信息
		s->data = p->data;
		s->next = NULL;
		rr = ll;
		while (rr->next != NULL && rr->next->data.total >= p->data.total)
			rr = rr->next;
		if (rr->next == NULL)
			rr->next = s;
		else {
			s->next = rr->next;
			rr->next = s;
		}
		p = p->next;
	}
	free(l);
	l->next = ll->next;
	printf("\n=====>提示:排序已经完成!\n");
}

void Save(Link l) {
	FILE* fp;
	Node* p;
	int flag = 1, count = 0;
	fp = fopen("student", "wb");
	if (fp == NULL) {
		printf("\n=====>提示:重新打开文件时发生错误!\n");
		exit(1);
	}
	p = l->next;
	while (p) {
		if (fwrite(p, sizeof(Node), 1, fp) == 1) {
			p = p->next;
			count++;
		}
		else {
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("\n=====>提示:文件保存成功.(有%d条记录已经保存.)\n", count);
		shoudsave = 0;
	}
	fclose(fp);
}

void main() {
	Link l;//连表
	FILE* fp;//文件指针
	int sel;
	char ch;
	int count = 0;
	Node* p, * r;
	printf("\t\t\t\t学生成绩管理系统\n");
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;
	//password();
	fp = fopen("student", "rb");
	if (fp == NULL)
		fp = fopen("student", "wb");
	printf("\n=====>提示:文件已经打开，正在导入记录......\n");
	while (!feof(fp)) {
		p = (Node*)malloc(sizeof(Node));
		if (fread(p, sizeof(Node), 1, fp)) {//将文件的内容放入接点中
			p->next = NULL;
			r->next = p;
			r = p;//将该接点挂入连中
			count++;
		}
		if (count == 0)break;
	}
	fclose(fp);//关闭文件
	printf("\n=====>提示:记录导入完毕，共导入%d条记录.\n", count);
	while (1) {
		menu();
		printf("请你选择操作:");
		scanf("%d", &sel);
		if (sel == 0) {
			if (shoudsave == 1) {
				getchar();
				printf("\n=====>提示:资料已经改动，是否将改动保存到文件中(y/n)?\n");
				scanf("%c", &ch);
				if (ch == 'y' || ch == 'Y')
					Save(l);
			}
			printf("\n=====>提示:你已经退出系统，再见!\n");
			break;
		}
		switch (sel) {
		case 1:Add(l); break;//增加学生
		case 2:Del(l); break;//删除学生
		case 3:Qur(l); break;//查询学生
		case 4:Modify(l); break;//修改学生
		case 5:Save(l); break;//保存学生
		case 6:Sort(l); break;//排序学生
		case 7:Count(l); break;//统计学生
		case 8:Disp(l); break;//显示学生
		case 9:printf("\t\t\t==========请联系工作人员!==========\n"); break;
		default:Wrong(); getchar(); break;
		}
	}
}


