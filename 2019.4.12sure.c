#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	int id;
	char name[100];
	int age;
	float score;
	char level[10]; 
}stu;
stu a[100];
int i, j, n;
void Input(stu a[n]) 
{
	printf("请输入人数:\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("学号：", a[i].id);
		scanf("%d", &a[i].id);
		for (j = 0; j < i; j++)
		{
			if (a[j].id == a[i].id)
			{
				printf("学号重复，请重新输入");
				printf("学号:");
				scanf("%d", &a[i].id);
				j = -1;
			}
		}
		printf_s("姓名:");
		scanf_s("%s", a[i].name);
		printf_s("年龄:");
		scanf_s("%d", &a[i].age);
		printf_s("测评分:");
		scanf_s("%f", &a[i].score);
		printf_s("\n-------------------\n");
	}	
}

void output(stu a[n])
{
	int i;
	if(n==0)
		{
		  printf("没有学生信息!");
		  return;
		}
	printf("学号\t姓名\t年龄\t测评分\t等级\t\n");
    for(i=0;i<n;i++) 
	    printf("\n%d\t%s\t%d\t%.2f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);		
}

void Setlevel(stu a[n])
{
	 int i;	
	 for(i=0;i<n;i++)
	 {
	 	if(a[i].score>100||a[i].score<0)
	 	printf("成绩错误");
		else 
			if(a[i].score>=90&&a[i].score<=100)
			strcpy(a[i].level,"优秀");
			else
				if(a[i].score>=80&&a[i].score<=90)
				strcpy(a[i].level,"良好");
				else
					if(a[i].score>=70&&a[i].score<80)
					strcpy(a[i].level,"中等");
					else
						if(a[i].score>=60&&a[i].score<70)
						strcpy(a[i].level,"及格");
						else
							if(a[i].score<60)
			        		strcpy(a[i].level,"不及格");
	}
}

void Count(stu a[n])//
{
	int e=0,f=0,g=0,h=0,k=0;
	int i;	
	if(n==0)
		{
		  printf("没有学生信息!");
		  return;//如果没有员工信息则提示并退出 
		}else
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i].level,"优秀")==0)
		e++;
		else
			if(strcmp(a[i].level,"良好")==0)
			f++;
			else
				if(strcmp(a[i].level,"中等")==0)
				g++;
				else
					if(strcmp(a[i].level,"及格")==0)
					h++;
					else
						if(strcmp(a[i].level,"不及格")==0)
			        	k++;
	}
	printf("等级为优秀的有%d个人\n等级为良好的有%d个人\n等级为中等的有%d个人\n等级为及格的有%d个人\n等级为不及格的有%d个人\n",e,f,g,h,k); 
} 
void max_min(stu a[n])
		 {
		 	float max=a[0].score,min=a[0].score;
			 int i,j;
		 	int p=0,q=0,flag;
		 if(n==0)
				{
				  printf("没有学生信息!");
				  return;
			}
				for(i=0;i<n;i++)
				{
				if(a[i].score>max)
				{
				max=a[i].score;
				p=i;
			}
			}
				for(j=0;j<n;j++)
				{
				if(a[j].score<min)
				{
				min=a[j].score;
				q=j;
				}
			}
			printf("成绩最高学生信息为\n学号\t姓名\t年龄\t测评分\t\t等级\t\n\n%d\t%s\t%d\t%f\t%s\t\n",a[p].id,a[p].name,a[p].age,a[p].score,a[p].level);
			printf("成绩最低学生信息为\n学号\t姓名\t年龄\t测评分\t\t等级\t\n\n%d\t%s\t%d\t%f\t%s\t\n",a[q].id,a[q].name,a[q].age,a[q].score,a[q].level);
		 }
void search(stu a[n])
 {
 	int flag=0;
	int i,id;
	char answer;
	char m[10];
	int score;
	printf("请输入要查找的学号：");
	scanf("%d",&id);
    for(i=0;i<n;i++)
		{
			if(id==a[i].id)
			{
				printf("该学生信息为\n学号\t姓名\t年龄\t测评分\t等级\t\n");
				printf("该学生信息为\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
				printf("请选择：\nQ.退出 A.修改姓名 B.修改测评分\n");
				scanf("%*c%c",&answer);
				switch(answer)
				{
					case 'A':
					case 'a':
						flag=1;
						printf("请输入修改后的名称：");
						scanf("%s",m);
						strcpy(a[i].name,m);
						printf("该学生信息为\n学号\t姓名\t年龄\t测评分\t等级\t\n");
						printf("该学生信息为\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
						break;
					case 'Q':
					case 'q':
						flag=1;
						return;
						break;
					case 'B':
					case 'b':
						flag=1;
						printf("请输入修改后的测评分：");
						scanf("%d",&score);
						a[i].score=score;
						Setlevel(a);	
						printf("该学生信息为\n学号\t姓名\t年龄\t测评分\t等级\t\n");
						printf("该学生信息为\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
						break;
					default:
						printf("输入错误！");
						return;
						break;
					}
			}
				
					}
					if(flag==0)
					{
					printf("没有该学生信息！");
					return;
					}
				}
void add(stu a[n])
{
	int id; 
	printf("请输入要添学生的学号：");
	scanf("%d",&a[i].id);
	for (j = 0; j < i; j++)
		{
			if (a[j].id == a[i].id)
			{
				printf("%d已存在!",a[i].id);
				return; 
			}
		}
	n++;
	printf_s("姓名:");
	scanf_s("%s", a[n-1].name);
	printf_s("年龄:");
	scanf_s("%d", &a[n-1].age);
	printf_s("测评分:");
	scanf_s("%f", &a[n-1].score);
	Setlevel(a);
}
void del(stu a[n])
{
	char sure;
	int k,id;
	if(n==0)
	{
		printf("请先录入学生信息！");
		return;
	}
	printf("请输入要删除学生的的学号：");
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==a[i].id)
		{
			printf("该学生信息为\n学号\t姓名\t年龄\t测评分\t等级\t\n");
			printf("\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
			printf("确定要删除该学生吗(Y/N)!");
			scanf("%*c%c",&sure);
			switch(sure)
			{
				case 'y':
				case 'Y':
						for(k=i+1;k<n;k++)
						{
							a[i].id=a[k].id;
							strcpy(a[i].name,a[k].name);
							a[i].age=a[k].age;
							a[i].score=a[k].score;
							strcpy(a[i].level,a[k].level);
						}
						printf("\n学生已删除！");
						n--;
						return;
				case 'n':
				case 'N':
					return;
					break;
				default:
					printf("输入错误！"); 
					break;
			} 
		}
	}

		if(id!=a[i].id)
		printf("没有找到学生信息"); 
}
void edit(stu a[n])
{
	char answer;
	printf("请输入：Q.退出\tA.添加学生信息\tB.删除学生");
	scanf("%*c%c",&answer);
	switch(answer)
	{
		case 'a':
		case 'A':
			add(a);
			break;
		case 'b':
		case 'B':
			del(a);
			break;
		case 'q':
		case 'Q':
			return;
	} 
}
void file_write(stu a[n])
{
	FILE *fp;
	char filename[50];
	int i;
	if(n==0)
	{
		printf("无学生信息可保存\n");
		return;
	}
	printf("请输入要保存到的路径和文件名（例如：c:\\ifno.txt）:");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	fprintf(fp,"学号\t姓名\t年龄\t测评分\t等级\t");
	for(i=0;i<n;i++)
		fprintf(fp,"\n%d\t%s\t%d\t%.2f\t%s\t",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
	fclose(fp);
	
}
void file_open(stu a[n])
{
	int i,l=0;
	FILE *fp;
	char filename[50],ch;
	printf("请输入要读取的文件名（例如c:\\info.txt):");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("文件不存在\n");
		return;
	}
	n=0;
	while(!feof(fp))
	{
		ch=fgetc(fp);
		if(ch=='\n')
			n++;
	}
	fclose(fp);
	fopen(filename,"r");
	fscanf(fp,"学号\t姓名\t年龄\t测评分\t等级\t\n");
	for(i=0;i<n;i++) 
	fscanf(fp,"%d %s %d %f %s",&a[i].id,&a[i].name,&a[i].age,&a[i].score,&a[i].level);
	fclose(fp);  
	output(a);                       //与fopen成对使用 
}
void id_higher(stu a[n])
{
	int i,j;
	stu b;
	if(n==0)
	{
		printf("无学生信息！");
		return; 
	}
	for(j=1;j<n;j++)
		for(i=0;i<n-j;i++)
		{
			if(a[i].id>a[i+1].id)
			{
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			} 
		}
	output(a);
}
void score_higher(stu a[n])
{
	int i;
	stu b;
	if(n==0)
	{
		printf("无学生信息！");
		return; 
	}
	for(j=1;j<n;j++)
		for(i=0;i<n-j;i++)
		{
			if(a[i].score>a[i+1].score)
			{
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			} 
		}
	output(a);
}
void sort(stu a[n])
{
	int choice;
	printf("1.按学号分行排序\t2.按测评分分行排序");
	scanf("%d",&choice);
	 switch(choice)
	 {
	 	case 1:
	 		id_higher(a);
	 		break;
	 	case 2:
	 		score_higher(a);
	 		break;
	 	default:
	 		printf("输入错误请重新输入");
	 		break;
	 }
}
int main()
{
	
	int choice;
	int endflag=1;
	while(endflag)
	{
		printf("学生信息管理系统\n");
		printf("==========================\n");
		printf("请输入：\n");
		printf("1.请输入学生信息:\n");
		printf("2.显示学生信息\n"); 
		printf("3.统计每一等级的学生人数\n");
		printf("4.查询得分最高和最低的学生成绩\n");
		printf("5.查询并修改学生信息\n");
		printf("6.增加/删除学生信息\n");
		printf("7.保存学生信息到文件\n");
		printf("8.从文件读取学生信息\n");
		printf("9.分行排序\n");
		printf("10.退出\n"); 
		printf("=========================\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1://调用Input函数同时调用Sn
				Input(a);
				Setlevel(a);
				
				break;
			case 2://显示 
				output(a);
				break;
			case 3://调用Count函数 
				Count(a);
				break;
			case 4:
				max_min(a);
				break;
			case 5:
				search(a);
				break;
			case 6:
				edit(a);
			 	break;
			case 7:
				 file_write(a);
				 break;
			case 8:
				file_open(a);
				break;
			case 9:
				sort(a);
				break; 
			case 10://退出
				endflag=0;		
				break; 
			default:
				printf("输入错误，请重新输入！！");
		}
		system("pause");
		system("cls");
	 } 
	 return 0;
}

