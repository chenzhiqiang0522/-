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
	printf("����������:\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("ѧ�ţ�", a[i].id);
		scanf("%d", &a[i].id);
		for (j = 0; j < i; j++)
		{
			if (a[j].id == a[i].id)
			{
				printf("ѧ���ظ�������������");
				printf("ѧ��:");
				scanf("%d", &a[i].id);
				j = -1;
			}
		}
		printf_s("����:");
		scanf_s("%s", a[i].name);
		printf_s("����:");
		scanf_s("%d", &a[i].age);
		printf_s("������:");
		scanf_s("%f", &a[i].score);
		printf_s("\n-------------------\n");
	}	
}

void output(stu a[n])
{
	int i;
	if(n==0)
		{
		  printf("û��ѧ����Ϣ!");
		  return;
		}
	printf("ѧ��\t����\t����\t������\t�ȼ�\t\n");
    for(i=0;i<n;i++) 
	    printf("\n%d\t%s\t%d\t%.2f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);		
}

void Setlevel(stu a[n])
{
	 int i;	
	 for(i=0;i<n;i++)
	 {
	 	if(a[i].score>100||a[i].score<0)
	 	printf("�ɼ�����");
		else 
			if(a[i].score>=90&&a[i].score<=100)
			strcpy(a[i].level,"����");
			else
				if(a[i].score>=80&&a[i].score<=90)
				strcpy(a[i].level,"����");
				else
					if(a[i].score>=70&&a[i].score<80)
					strcpy(a[i].level,"�е�");
					else
						if(a[i].score>=60&&a[i].score<70)
						strcpy(a[i].level,"����");
						else
							if(a[i].score<60)
			        		strcpy(a[i].level,"������");
	}
}

void Count(stu a[n])//
{
	int e=0,f=0,g=0,h=0,k=0;
	int i;	
	if(n==0)
		{
		  printf("û��ѧ����Ϣ!");
		  return;//���û��Ա����Ϣ����ʾ���˳� 
		}else
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i].level,"����")==0)
		e++;
		else
			if(strcmp(a[i].level,"����")==0)
			f++;
			else
				if(strcmp(a[i].level,"�е�")==0)
				g++;
				else
					if(strcmp(a[i].level,"����")==0)
					h++;
					else
						if(strcmp(a[i].level,"������")==0)
			        	k++;
	}
	printf("�ȼ�Ϊ�������%d����\n�ȼ�Ϊ���õ���%d����\n�ȼ�Ϊ�еȵ���%d����\n�ȼ�Ϊ�������%d����\n�ȼ�Ϊ���������%d����\n",e,f,g,h,k); 
} 
void max_min(stu a[n])
		 {
		 	float max=a[0].score,min=a[0].score;
			 int i,j;
		 	int p=0,q=0,flag;
		 if(n==0)
				{
				  printf("û��ѧ����Ϣ!");
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
			printf("�ɼ����ѧ����ϢΪ\nѧ��\t����\t����\t������\t\t�ȼ�\t\n\n%d\t%s\t%d\t%f\t%s\t\n",a[p].id,a[p].name,a[p].age,a[p].score,a[p].level);
			printf("�ɼ����ѧ����ϢΪ\nѧ��\t����\t����\t������\t\t�ȼ�\t\n\n%d\t%s\t%d\t%f\t%s\t\n",a[q].id,a[q].name,a[q].age,a[q].score,a[q].level);
		 }
void search(stu a[n])
 {
 	int flag=0;
	int i,id;
	char answer;
	char m[10];
	int score;
	printf("������Ҫ���ҵ�ѧ�ţ�");
	scanf("%d",&id);
    for(i=0;i<n;i++)
		{
			if(id==a[i].id)
			{
				printf("��ѧ����ϢΪ\nѧ��\t����\t����\t������\t�ȼ�\t\n");
				printf("��ѧ����ϢΪ\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
				printf("��ѡ��\nQ.�˳� A.�޸����� B.�޸Ĳ�����\n");
				scanf("%*c%c",&answer);
				switch(answer)
				{
					case 'A':
					case 'a':
						flag=1;
						printf("�������޸ĺ�����ƣ�");
						scanf("%s",m);
						strcpy(a[i].name,m);
						printf("��ѧ����ϢΪ\nѧ��\t����\t����\t������\t�ȼ�\t\n");
						printf("��ѧ����ϢΪ\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
						break;
					case 'Q':
					case 'q':
						flag=1;
						return;
						break;
					case 'B':
					case 'b':
						flag=1;
						printf("�������޸ĺ�Ĳ����֣�");
						scanf("%d",&score);
						a[i].score=score;
						Setlevel(a);	
						printf("��ѧ����ϢΪ\nѧ��\t����\t����\t������\t�ȼ�\t\n");
						printf("��ѧ����ϢΪ\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
						break;
					default:
						printf("�������");
						return;
						break;
					}
			}
				
					}
					if(flag==0)
					{
					printf("û�и�ѧ����Ϣ��");
					return;
					}
				}
void add(stu a[n])
{
	int id; 
	printf("������Ҫ��ѧ����ѧ�ţ�");
	scanf("%d",&a[i].id);
	for (j = 0; j < i; j++)
		{
			if (a[j].id == a[i].id)
			{
				printf("%d�Ѵ���!",a[i].id);
				return; 
			}
		}
	n++;
	printf_s("����:");
	scanf_s("%s", a[n-1].name);
	printf_s("����:");
	scanf_s("%d", &a[n-1].age);
	printf_s("������:");
	scanf_s("%f", &a[n-1].score);
	Setlevel(a);
}
void del(stu a[n])
{
	char sure;
	int k,id;
	if(n==0)
	{
		printf("����¼��ѧ����Ϣ��");
		return;
	}
	printf("������Ҫɾ��ѧ���ĵ�ѧ�ţ�");
	scanf("%d",&id);
	for(i=0;i<n;i++)
	{
		if(id==a[i].id)
		{
			printf("��ѧ����ϢΪ\nѧ��\t����\t����\t������\t�ȼ�\t\n");
			printf("\n%d\t%s\t%d\t%f\t%s\t\n",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
			printf("ȷ��Ҫɾ����ѧ����(Y/N)!");
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
						printf("\nѧ����ɾ����");
						n--;
						return;
				case 'n':
				case 'N':
					return;
					break;
				default:
					printf("�������"); 
					break;
			} 
		}
	}

		if(id!=a[i].id)
		printf("û���ҵ�ѧ����Ϣ"); 
}
void edit(stu a[n])
{
	char answer;
	printf("�����룺Q.�˳�\tA.���ѧ����Ϣ\tB.ɾ��ѧ��");
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
		printf("��ѧ����Ϣ�ɱ���\n");
		return;
	}
	printf("������Ҫ���浽��·�����ļ��������磺c:\\ifno.txt��:");
	scanf("%s",filename);
	fp=fopen(filename,"w");
	fprintf(fp,"ѧ��\t����\t����\t������\t�ȼ�\t");
	for(i=0;i<n;i++)
		fprintf(fp,"\n%d\t%s\t%d\t%.2f\t%s\t",a[i].id,a[i].name,a[i].age,a[i].score,a[i].level);
	fclose(fp);
	
}
void file_open(stu a[n])
{
	int i,l=0;
	FILE *fp;
	char filename[50],ch;
	printf("������Ҫ��ȡ���ļ���������c:\\info.txt):");
	scanf("%s",filename);
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("�ļ�������\n");
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
	fscanf(fp,"ѧ��\t����\t����\t������\t�ȼ�\t\n");
	for(i=0;i<n;i++) 
	fscanf(fp,"%d %s %d %f %s",&a[i].id,&a[i].name,&a[i].age,&a[i].score,&a[i].level);
	fclose(fp);  
	output(a);                       //��fopen�ɶ�ʹ�� 
}
void id_higher(stu a[n])
{
	int i,j;
	stu b;
	if(n==0)
	{
		printf("��ѧ����Ϣ��");
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
		printf("��ѧ����Ϣ��");
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
	printf("1.��ѧ�ŷ�������\t2.�������ַ�������");
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
	 		printf("�����������������");
	 		break;
	 }
}
int main()
{
	
	int choice;
	int endflag=1;
	while(endflag)
	{
		printf("ѧ����Ϣ����ϵͳ\n");
		printf("==========================\n");
		printf("�����룺\n");
		printf("1.������ѧ����Ϣ:\n");
		printf("2.��ʾѧ����Ϣ\n"); 
		printf("3.ͳ��ÿһ�ȼ���ѧ������\n");
		printf("4.��ѯ�÷���ߺ���͵�ѧ���ɼ�\n");
		printf("5.��ѯ���޸�ѧ����Ϣ\n");
		printf("6.����/ɾ��ѧ����Ϣ\n");
		printf("7.����ѧ����Ϣ���ļ�\n");
		printf("8.���ļ���ȡѧ����Ϣ\n");
		printf("9.��������\n");
		printf("10.�˳�\n"); 
		printf("=========================\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1://����Input����ͬʱ����Sn
				Input(a);
				Setlevel(a);
				
				break;
			case 2://��ʾ 
				output(a);
				break;
			case 3://����Count���� 
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
			case 10://�˳�
				endflag=0;		
				break; 
			default:
				printf("����������������룡��");
		}
		system("pause");
		system("cls");
	 } 
	 return 0;
}

