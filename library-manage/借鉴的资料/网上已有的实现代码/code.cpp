  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  #include<conio.h>
  #define M 2
  #define PAGE 3
  /*ͼ��ṹ������*/
  typedef struct
  {int num;        /*ͼ���*/
   char name[20];      /*����*/
   char zuozhe[20];    /*��������*/
   char chubanshe[20]; /*������*/
   int price;      /*�۸�*/
  }BOOKS;
  

  int read_file(BOOKS books[])
     {  FILE *fp;
        int i=0;
        if((fp=fopen("project choose.txt","rt"))==NULL)
        { printf("\n\n*****����ļ�������!�봴��");
          return 0;
        }
        while(feof(fp)!=1)
        {  fread(&books[i],sizeof(BOOKS),1,fp);
           if(books[i].num==0)
              break;
           else
              i++;
        }
        fclose(fp);
        return i;
     }

  void save_file(BOOKS books[],int sum)
  {     FILE *fp;
      int i;
      if((fp=fopen("project choose.txt","wb"))==NULL)
      {   printf("���ļ�����\n");
          return;
      }
      for(i=0;i<sum;i++)
          if(fwrite(&books[i],sizeof(BOOKS),1,fp)!=1)
             printf("д�ļ�����\n");
      fclose(fp);
}
  

 /*����ģ��*/
   int input(BOOKS books[])
   {   int i=0;
       system("cls");
       printf("\n\n                   ¼��ͼ����Ϣ   (���%d��)\n",M);
       printf("----------------------------------------------------\n");
       do
       {   printf("\n                       ��%d��ͼ��",i+1);
       printf("\n                ͼ���ţ�");
           scanf("%d",&books[i].num);                                                                                  if(books[i].num==0)  break;
       printf("\n                ͼ�����ƣ�");
           scanf("%s",books[i].name);
           printf("\n                ���ߣ�");
           scanf("%s",books[i].zuozhe);
           printf("\n                �����磺");
           scanf("%s",&books[i].chubanshe);
           printf("\n                ͼ��۸�");
       scanf("%d",&books[i].price);
            i++;
       }while(i<M);
       fflush(stdin);
       getch(); 
       printf("\n                  --%d��ͼ����Ϣ�������!--\n",i);
       printf("\n                     ��������������˵�!");
       getchar();
       return i;
   }
   



    /*���ģ��*/
    void output(BOOKS books[])
    {int i=0,j=0,page=1;
     system("cls");
     printf("\n\n            --ͼ����Ϣ��--                 ��%dҳ\n\n",page);
     printf("ͼ����----ͼ������-----����----- ������-----ͼ��۸�\n");
     printf("-------------------------------------------------------\n");
     do
      {   if(books[i].num!=0)
      {   j++;
          if(j%PAGE!=0)
          { printf("%4d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price);
            printf("------------------------------------------------------\n");
          }
       else
          { printf("�����������!");
            getchar();
            system("cls");
            printf("\n\n     --ͼ����Ϣ��--                 ��%dҳ\n\n",++page);
            printf("ͼ����--ͼ������--����-- ������--ͼ��۸�\n");
            printf("------------------------------------------\n");
            printf("%4d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price);
            printf("---------------------------------------------\n");
           }
      }
        i++;
    }while(books[i].num!=0);
    printf("��������������˵�!");
    getchar( );
    }
    

  /*������ţ����ߣ������������Ϣģ��*/
     void find_by_num(BOOKS books[],int sum)     
    { int i,find_num;
      
      system("cls");
      printf("\n               ������Ҫ���ҵ�ͼ����:");
      fflush(stdin);
      scanf("%d",&find_num);
      
      for(i=0;i<sum;i++)
        if(books[i].num==find_num)       
        {
            printf("�����������ҵ���ͼ��:\n");
            printf("ͼ����----ͼ������----����---- ������---ͼ��۸�\n");
            printf("------------------------------------------\n");
            printf("%4d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                         books[i].zuozhe,  books[i].chubanshe,books[i].price);  
            printf("---------------------------------------------\n");
            break;
        }
          else
          {
            printf("\n       δ�ҵ�Ҫ���ҵ�ͼ����Ϣ�������������!");
            getchar();
            system("cls");    
          }
        
        fflush(stdin);
        getchar();
    }

    


    void find_by_zuozhe(BOOKS books[],int sum)
     { 
      int i;
       char find_zuozhe[20];
      
       system("cls");
       printf("\n               ������Ҫ���ҵ���������:");
       scanf("%s",find_zuozhe);
       for(i=0;i<sum-1;i++)
       fflush(stdin);
       getch();
       if(strcmp(books[i].zuozhe,find_zuozhe)==0)
       {printf("�����������ҵ����ڸ����ߵ�ͼ��:");
        printf("ͼ����--ͼ������--����-- ������--ͼ��۸�\n");
        printf("------------------------------------------\n");
        printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
        printf("---------------------------------------------\n");
       }
       else
       {printf("\n       δ�ҵ�Ҫ���ҵ�ͼ����Ϣ�������������!");
        getchar();
        system("cls");    
       }
     }

 
    
    
      void find_by_chubanshe(BOOKS books[],int sum)
     { 
      int i;
       char find_chubanshe[20];
      
       system("cls");
       printf("\n               ������Ҫ���ҵĳ���������:");
       scanf("%s",find_chubanshe);
       for(i=0;i<sum;i++)
       fflush(stdin);
       getch();
      if(strcmp(books[i].chubanshe,find_chubanshe)==0)
        {printf("�����������ҵ����ڸó������ͼ��:");
         printf("ͼ����--ͼ������--����-- ������--ͼ��۸�\n");
         printf("------------------------------------------\n");
         printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
         printf("---------------------------------------------\n");
        }
      else
       {printf("\n       δ�ҵ�Ҫ���ҵ�ͼ����Ϣ�������������!");
        getchar();
        system("cls");    
       }
     }

      void find(BOOKS books[],int sum)

    { int choice;
      system("cls");
      printf("\n     ��Ҫ�������ַ�ʽ����?  \n");
      printf("\n      1.��ͼ���Ų���  \n");
      printf("\n      2.��ͼ�����߲���  \n");
      printf("\n      3.�����������  \n");
      printf("\n      0. �˳�\n");
      printf("\n       ��ѡ��(0-3):  \n");
      scanf("%d",&choice);
      switch(choice)  
      { case 1:     find_by_num(books,sum); break;
        case 2:     find_by_zuozhe(books,sum); break;
        case 3:     find_by_chubanshe(books,sum); break;
        case 0:                               break;
      }
     }  


       /*ɾ����Ϣģ��*/
       void del(BOOKS books[])
     { int i,g,sum;
       int del_num;
       
        { system("cls");
             printf("\n               ������Ҫɾ����ͼ����:");
             scanf("%d",&del_num);
             fflush(stdin);
             getch();
              
             for(i=0;i<sum;i++)
             if(books[i].num==del_num)
     g=i;
    for(g=i;g<sum;g++)
     books[g+1]=books[g];
    
             fflush(stdin);
             getch();
    {
             printf("��������Ҫɾ��ͼ����Ϣ:\n");
             printf("ͼ����----ͼ������----����---- ������----ͼ��۸�\n");
             printf("----------------------------------------------------\n");
             printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
             printf("-----------------------------------------------------\n");
             fflush(stdin);
             getch();
                                                      
             printf("��ȷ��Ҫɾ����?");
             printf("�����������!");
             getchar();
    
             fflush(stdin);
             getch();
             printf("�ѳɹ�ɾ��ͼ����Ϣ!");
          }
          books[i].num=0;
        }
     }


      /*��Ϣ�޸�ģ��*/
     void modify(BOOKS books[],int sum)
     {int i=0,choice,modify_num,flag;
      do
      {system("cls");
       printf("������Ҫ�޸ĵ�ͼ���ţ�");
       scanf("%d",&modify_num);
       for(i=0;i<sum;i++)
       if(books[i].num==modify_num)
       { printf("\n\n            --ͼ����Ϣ--                 \n\n");
         printf("ͼ����----ͼ������----����---- ������----ͼ��۸�\n");
        printf("------------------------------------------\n");
        printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
        printf("---------------------------------------------\n");
         printf("\n                ��Ҫ�޸���һ��?\n");
         printf("\n                  1.ͼ������\n");
         printf("\n                  2.����\n");
         printf("\n                  3.������\n");
         printf("\n                  4.ͼ��۸�\n");
         printf("\n                 ��ѡ��(1-4):\n");
         scanf("%d",&choice);
         switch(choice)
         { case 1: printf("\n          �������޸ĺ��ͼ������:");
                
                scanf("%s",books[i].name); break;   
           case 2: printf("\n          �������޸ĺ����������:");
                scanf("%s",books[i].zuozhe); break;   
           case 3: printf("\n          �������޸ĺ�ĳ���������:");
                scanf("%s",books[i].chubanshe); break;   
           case 4: printf("\n          �������޸ĺ��ͼ��۸�:");
                scanf("%d",&books[i].price); break;   
         }
        fflush(stdin);
        getch();

        printf("\n\n            --ͼ����Ϣ--                 \n\n");
         printf("ͼ����----ͼ������----����---- ������----ͼ��۸�\n");
        printf("--------------------------------------------\n");
        printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
        printf("---------------------------------------------\n");
        break;
       }
       else
       {printf("\n          ���鲻����!");
        getchar();
       }
       printf("\n    �޸ĳɹ�!\n");
       printf("��Ҫ�����޸���?(Y/N)");
       if (choice=='Y'||choice=='y')
       { flag=1;
         printf("\n                     ����!\n");
        }
       else flag=0;
      }while( flag==1);
       fflush(stdin);
       getch();
       
       printf("\n     ��������������˵�!");
       getchar();
      }
   


       /*ͼ����Ϣͳ��ģ��*/

     
    
     
      void count(BOOKS books[],int sum)   /*ͳ��ĳ���������ͼ����*/
      { int i;
       char count_chubanshe[20];
       int n=0;
       system("cls");     
       printf("������һ������������:\n");
       fflush(stdin);
       scanf("%s",count_chubanshe);     
       for(i=0;i<sum;i++)
       {          
         if( strcmp(books[i].chubanshe,count_chubanshe)==0)
             n++;
         break;
       }
       fflush(stdin);
       
       printf("ͳ�Ƴ����ڸó�����һ����%d����\n",n);
       getch();
     }


      





     /*����ģ��*/
     void sort(BOOKS books[],int sum)   /*��ͼ��������ģ��*/
     {BOOKS t;
      int i,j,k;
      system("cls");  
      printf("\n            --ͼ����Ϣ--      \n");
      printf("\n ���� ͼ����     ͼ������        ����         ������  ͼ��۸�\n");
      
      for(i=0;i<sum-1;i++)
      { k=i;
        for(j=i+1;j<sum;j++)
           if(books[k].num>books[j].num)
    
           {t=books[j];
            books[j]=books[k];  
            books[k]=t;
           }
      }
      for(i=0;i<sum;i++)
      { printf("%2d  %8d %12s %12s %12s %6d \n",i+1,books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
      }
      fflush(stdin);
      getch();
    }



       int main()
       { BOOKS books[M];
         int choice,sum;
         sum=read_file(books);
         if (sum==0)
         {printf("��¼�����ͼ����Ϣ!*******\n");
          getch();
          sum=input(books);
         }
        do
       { system("cls"); 
         printf("\n\n\n      *******ͼ�����ϵͳ*******    \n\n");
         printf("                 1.�޸�ͼ����Ϣ \n\n");
         printf("                 2.ɾ��ͼ����Ϣ\n\n");
         printf("                 3.����ͼ����Ϣ\n\n");
         printf("                 4.ͳ��ͼ����Ϣ\n\n");
         printf("                 5.ͼ��������Ϣ\n\n");
         printf("                 0.�˳�ϵͳ\n\n");
         printf("                  ��ѡ��\n\n");
         scanf("%d",&choice);
         switch(choice)
         {  case 1 :     modify(books,sum);    break;
            case 2 :     del(books);           break;
            case 3 :     find(books,sum);      break;
            case 4 :     count(books,sum);     break;
            case 5 :     sort(books,sum);      break;
            case 0 :                           break;
         }
       }while(choice!=0);
       save_file(books,sum);
       
       system("pause");
       return 0;

      }
