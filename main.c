#include <stdio.h>http://www.1234jk.com

#include <stdlib.h>

#define FILENAME "student.dat"

typedef enum{MAN, WOMAN} SEX;

typedef struct tagStudent

{

         int num;           //ѧ���ı��

         char name[20];       //ѧ��������

         SEX  sex;           //ѧ�����Ա�

         int age;             //ѧ��������

         char major[20];       //ѧ����רҵ

         struct tagStudent *next;//��һ���ڵ��ָ��

}STUDENT, *PSTUDENT;



STUDENT g_head;  //ͷ�ڵ�



//1.��ʾ�˵�

void ShowMenu();

//2.��ȡ�û�ѡ��Ĳ˵��ı��

int GetMenuChoose();

//3.����һ���ڵ�,���᷵��һ���´�����ѧ����Ϣ�ڵ��ָ��

PSTUDENT CreateStudent();

//4.��ѧ����Ϣ�ڵ���뵽������

int AddStudent(PSTUDENT pstu);

//5.����ָ�����ѧ���ڵ����һ���ڵ��ָ��

PSTUDENT GetPrevAddr(int num);

//6.��ʾ����ѧ����Ϣ

void ShowAll();

//7.��ʾ��Ϣ����

int ShowStudentCount();



int Question(const char *pstr);

//10.��ȡ�û������ѧ���ı��

int GetInputNum();

//11.ɾ�����Ϊnum��ѧ����Ϣ

void DelStudent(int num);

//12.ɾ�����е�ѧ����Ϣ

void DelAll();







int main()

{

         int running = 1;

         while(running)

         {

                   switch(GetMenuChoose())

                   {

                            case 0:

                            running = 0;

                            break;

                            case 1:

//                        printf("��ѡ���˲˵�1\n");

                            AddStudent(CreateStudent());

                            break;

                            case 2:

//                        printf("��ѡ���˲˵�2\n");

                            DelStudent(GetInputNum());

                            break;

                            case 3:

                            printf("��ѡ���˲˵�3\n");

                            break;

                            case 4:

//                        printf("��ѡ���˲˵�4\n");

                            ModityStudent(GetInputNum());

                            break;

                            case 5:

//                        printf("��ѡ���˲˵�5\n");

                            DelAll();

                            break;

                            case 6:

//                        printf("��ѡ���˲˵�6\n");

                            ShowAll();

                            break;

                            case 7:

//                        printf("��ѡ���˲˵�7\n");

                            ShowStudentCount();

                            break;



//                        printf("��ѡ���˲˵�8\n");




//                        printf("��ѡ���˲˵�9\n");



                   }

                   system("pause");

         }



         return 0;

}

//1.��ʾ�˵�

void ShowMenu()

{

         system("cls");

         printf("-----------------------------ѧ������ϵͳ--------------------------------\n");

         printf("\n\t1.���ѧ����Ϣ    2.ɾ��ĳ��ѧ����Ϣ    3.��ʾĳ��ѧ����Ϣ\n");

         printf("\t4.�޸�ѧ����Ϣ    5.ɾ������ѧ����Ϣ    6.��ʾ����ѧ����Ϣ\n");



         printf("\t0.�˳�ϵͳ\n");

         printf("\n-------------------------------------------------------------------------\n");

}

//2.��ȡ�û�ѡ��Ĳ˵��ı��

int GetMenuChoose()

{

         int num;//�����û�ѡ��Ĳ˵����

         ShowMenu();

         printf("��ѡ��˵�(0 ~ 6):");

         while(1 != scanf("%d", &num) || num < 0 || num > 9)

         {

                   ShowMenu();

                   printf("ѡ��˵�����������ѡ��(0 ~ 9):");

                   fflush(stdin);//������뻺����

         }

         return num;

}

//3.����һ���ڵ�,���᷵��һ���´�����ѧ����Ϣ�ڵ��ָ��

PSTUDENT CreateStudent()

{

         int sex;

         PSTUDENT pstu = (PSTUDENT)malloc(sizeof(STUDENT));//�ڶ��ڴ�����ռ䣬�洢ѧ����Ϣ

         if(!pstu)

         {

                   printf("�����ڴ�ռ�ʧ��!\n");

                   return NULL;

         }

         printf("������ѧ���ı��(����)��");

         while(1 != scanf("%d", &pstu->num) || GetPrevAddr(pstu->num))

         {

                   printf("ѧ��������������Ѿ����ڣ�����������ѧ���ı��(����)��");

                   fflush(stdin);

         }

         printf("������ѧ��������(С��20�ַ�)��");

         scanf("%20s", pstu->name);//(*pstu).name

         printf("��ѡ��ѧ�����Ա�(1.��  2.Ů)��");

         while(1 != scanf("%d", &sex) || sex < 1 || sex > 2)

         {

                   printf("�Ա�ѡ�����������ѡ��ѧ�����Ա�(1.��  2.Ů)��");

                   fflush(stdin);

         }

         if(1 == sex)

                   pstu->sex = MAN;

         else

                   pstu->sex = WOMAN;

         printf("������ѧ��������(10 ~ 40)��");

         while(1 != scanf("%d", &pstu->age) || pstu->age < 10 || pstu->age > 40)

         {

                   printf("���������������������ѧ��������(10 ~ 40)��");

                   fflush(stdin);

         }

         printf("������ѧ����רҵ(С��20�ַ�)��");

         scanf("%20s", pstu->major);

         pstu->next = NULL;

         return pstu;

}

//4.��ѧ����Ϣ�ڵ���뵽������

int AddStudent(PSTUDENT pstu)

{

         PSTUDENT ps = &g_head;

         if(!pstu)

         {

                   return 0;

         }

         //�ж�һ�¸�ѧ����Ϣ�ǲ����Ѿ�����

         if(GetPrevAddr(pstu->num))

         {

                   printf("���Ϊ%d��ѧ����Ϣ�Ѿ����ڣ�\n", pstu->num);

                   free(pstu);//�ͷŸýڵ��ڴ�ռ�

                   return 0;

         }

         //whileѭ�����������ҵ���ǰ��������һ���ڵ�

         while(ps->next)

                   ps = ps->next;

         //���½ڵ���뵽����Ǹ��ڵ�ĺ���

         ps->next = pstu;

         pstu->next = NULL;

         return 1;

}

//5.����ָ�����ѧ���ڵ����һ���ڵ��ָ��

PSTUDENT GetPrevAddr(int num)

{

         PSTUDENT pstu = &g_head;

         while(pstu->next)

         {

                   if(pstu->next->num == num)

                            return pstu;

                   pstu = pstu->next;

         }

         return NULL;

}

//6.��ʾ����ѧ����Ϣ

void ShowAll()

{

         PSTUDENT pstu = &g_head;

         printf("--------------------------------------------------------------------\n");

         printf("  ���        ����            �Ա�     ����               רҵ\n");

         printf("--------------------------------------------------------------------\n");

         while(pstu->next)

         {

                   printf("  %-8d  ", pstu->next->num);

                   printf("%-20s", pstu->next->name);

                   printf("%-6s", pstu->next->sex == MAN ? "��" : "Ů");

                   printf("%4d", pstu->next->age);

                   printf("%20s\n", pstu->next->major);

                   pstu = pstu->next;//��ָ��ָ����һ���ڵ�

         }

         printf("--------------------------------------------------------------------\n");

}

//7.��ʾ��Ϣ����

int ShowStudentCount()

{

         int count = 0;

         PSTUDENT pstu = &g_head;

         while(pstu->next)

         {

                   ++count;

                   pstu = pstu->next;

         }

         printf("\n��ǰ����%dλѧ����Ϣ��\n", count);

         return count;

}

//8.�޸�ѧ����Ϣ������ΪҪ�޸ĵ�ѧ���ı��

void ModityStudent(int num)

{

         PSTUDENT pstu = GetPrevAddr(num);//��ȡҪ�޸ĵ�ѧ���ڵ����һ���ڵ�

         int choose;

         if(!pstu)

         {

                   printf("û�б��Ϊ%d��ѧ����Ϣ��\n", num);

                   return;

         }

         pstu = pstu->next;//��Ҫ�޸ĵ�ѧԱ�ڵ��ָ���Ϊָ���Լ���

         printf("��ǰѧ��������Ϊ%s,", pstu->name);

         if(Question("ȷ��Ҫ�޸���"))

         {

                   printf("������ѧ��������(С��20�ַ�)��");

                   scanf("%20s", pstu->name);

         }

         printf("��ǰѧ�����Ա�Ϊ%s,", pstu->sex == MAN ? "��" : "Ů");

         if(Question("ȷ��Ҫ�޸���"))

         {

                   printf("������ѧ�����Ա�(1.�� 2.Ů)��");

                   while(1 != scanf("%d", &choose) || choose < 1 || choose > 2)

                   {

                            printf("�����������������ѧ�����Ա�(1.�� 2.Ů)��");

                            fflush(stdin);

                   }

                   if(1 == choose)

                            pstu->sex = MAN;

                   else

                            pstu->sex = WOMAN;

         }

         printf("��ǰѧ��������Ϊ%d,", pstu->age);

         if(Question("ȷ��Ҫ�޸���"))

         {

                   printf("������ѧ��������(10 ~ 40)��");

                   while(1 != scanf("%d", &pstu->age) || pstu->age < 10 || pstu->age > 40)

                   {

                            printf("���������������������ѧ��������(10 ~ 40)��");

                            fflush(stdin);

                   }

         }

         printf("��ǰѧ����רҵΪ%s,", pstu->major);

         if(Question("ȷ��Ҫ�޸���"))

         {

                   printf("������ѧ����רҵ(С��20�ַ�):");

                   scanf("%20s", pstu->major);

         }

         printf("�޸���ϣ�\n");

}

//9.��ȡ�û���ѡ��

int Question(const char *pstr)

{

         char answer;

         printf("%s��ѡ��y or n����", pstr);

         while(1 != scanf(" %c", &answer) || (answer != 'y' && answer != 'n'))

         {

                   printf("�������%s������ѡ��y or n����", pstr);

                   fflush(stdin);//������뻺����,C�⺯��

         }

         if('y' == answer)

                   return 1;

         else

                   return 0;

}

//10.��ȡ�û������ѧ���ı��

int GetInputNum()

{

         int num;

         printf("������ѧ���ı��(����)��");

         while(1 != scanf("%d", &num))

         {

                   printf("��������������������ѧ���ı��(����)��");

                   fflush(stdin);

         }

         return num;

}

//11.ɾ�����Ϊnum��ѧ����Ϣ

void DelStudent(int num)

{

         PSTUDENT pstu, ptmp;

         if(pstu = GetPrevAddr(num))

         {

                   if(!Question("ȷ��Ҫɾ����ѧ����Ϣ��"))

                   {

                            return;

                   }

                   ptmp = pstu->next;

                   pstu->next = ptmp->next;

                   free(ptmp);

                   printf("ɾ���˱��Ϊ%d��ѧ����Ϣ��\n", num);

         }

         else

         {

                   printf("û���ҵ����Ϊ%d��ѧ����Ϣ��\n", num);

         }

}

//12.ɾ�����е�ѧ����Ϣ

void DelAll()

{

         PSTUDENT pstu = g_head.next, ptmp;

         int count = 0;

         if(!Question("ȷ��Ҫɾ����ǰ���е�ѧ����Ϣ��"))

         {

                   return;

         }

         while(pstu)

         {

                   ptmp = pstu;

                   pstu = pstu->next;

                   free(ptmp);

                   ++count;

         }

         printf("��ɾ����%dλѧ����Ϣ��\n", count);

         g_head.next = NULL;

}


