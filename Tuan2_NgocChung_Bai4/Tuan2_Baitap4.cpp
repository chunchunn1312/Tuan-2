#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#define out "out.txt"
int inx,iny,outx,outy;
int x[2500],y[2500],a[50][50],c[50][50],h,
dx[5]={0,0,1,0,-1},
dy[5]={0,-1,0,1,0};
char e[50][50], tenfile[50][50];
int m,n,i,j,d,s;
FILE *f,*f1;

void nhap() // Doc Du lieu tu file và hien thi du lieu tu file len man hinh
{
	printf ("\n ban hay nhap vao cac so de lua chon me cung dau vao: ");

         for (i=1;i<=10;i++)
             printf ("\n %d. inp%d.txt",i,i);

         printf ("\n");
         
   printf ("\n AN SO 0 DE NHAP VAO TEN FILE DO BAN TAO RA: ");

         scanf("%d",&h);
         switch (h)
         {
         	case  (0):
         	{
            printf("\n MOI BAN NHAP VAO TEN FILE : ");
            printf("\n TEN FILE CO DANG  *.txt \n\n \t");
    			fflush(stdin);
   		   gets(tenfile[0]);
            f=fopen(tenfile[0],"r");

            break;
            }
         	case  (1):
         	{
            f=fopen("inp1.txt","r");
            break;
            }
            case  (2):
         	{
            f=fopen("inp2.txt","r");
            break;
            }
         	case  (3):
         	{
            f=fopen("inp3.txt","r");
            break;
            }
         	case  (4):
         	{
            f=fopen("inp4.txt","r");
            break;
            }

         	case  (5):
         	{
            f=fopen("inp5.txt","r");
            break;
            }
         	case  (6):
         	{
            f=fopen("inp6.txt","r");
            break;
            }
         	case  (7):
         	{
            f=fopen("inp7.txt","r");
            break;
            }
         	case  (8):
         	{
            f=fopen("inp8.txt","r");
            break;
            }
         	case  (9):
         	{
            f=fopen("inp9.txt","r");
            break;
            }
         	case  (10):
         	{
            f=fopen("inp10.txt","r");
            break;
            }
        }

   if (h!=0)
	printf("\n\n\t\t\ THONG TIN ME CUNG DUOC DOC TU FILE inp%d.txt \n",h);
   else
   printf("\n\n\t\t\ THONG TIN ME CUNG DUOC DOC TU FILE %s \n",tenfile[0]);
	printf("\n\n");
	//f=fopen(inp,"r");
	printf("\t Mo file thanh cong: \n\n");
	fscanf(f,"%d %d",&m,&n);
	printf("\t\t So Hang        : %d \n",m);
	printf("\t\t So Cot         : %d \n",n);
	fscanf(f,"%d %d %d %d",&inx,&iny,&outx,&outy);
	printf("\t\t Toa do Bat Dau : A(%d,%d)  \n",inx,iny);
	printf("\t\t Toa do Ket Thuc: A(%d,%d)  \n\n",outx,outy);
	printf("\n\t An Enter de tiep tuc.......\n\n");
	getch();

	printf("\t HINH ANH CUA ME CUNG \n");
	for (i=0;i<m;++i)
		{
   	printf("\n");
   	printf("\t\t\t");
		for (j=0;j<n;++j)
   		{
    		fscanf(f,"%d",&a[i][j]);
    		printf(" %d",a[i][j]);
   		}
   	}
	printf("\n");
	printf("\n\t An Enter de tiep tuc.......\n\n");
	getch();
	fclose(f);
}

void inhinh()
	{
   	switch (c[i][j])
   		{
   		case 3:
   			{
      		e[i*2][j*2]='0';
      		e[i*2][j*2-1]='-';
      		break;
      		}
   		case 2:
      		{
      		e[i*2][j*2]='0';
      		e[i*2-1][j*2]='|';
     			break;
           	}
         case 1:
           	{e[i*2][j*2]='0';
            e[i*2][j*2+1]='-';
           	break;
           	}
         case 4:
           	{
           	e[i*2][j*2]='0';
            e[i*2+1][j*2]='|';
           	break;
            }
         }
     }

int ok(int i,int j)
	{
	if ((i<0)||(i>=m)||(j<0)||(j>=n)) return 0;
	if ((a[i][j]!=0)||(c[i][j]!=0)) return 0;
	return 1;
	}

void dfs(int i,int j)
	{
	if ((i==outx-1)&&(j==outy-1)) d=1;
	else
		{
		int k;
		for (k=1;k<=4;++k)
		if (ok(i+dx[k],j+dy[k]))
			{
			c[i+dx[k]][j+dy[k]]=k;
			dfs(i+dx[k],j+dy[k]);
			}
		}
		}

void chuanbi()
	{
	for (i=0;i<m;++i)
		for (j=0;j<n;++j) c[i][j]=0;
	for (i=0;i<=2*(m-1);++i)
		for (j=0;j<=2*(n-1);++j)
   		if (i%2==0 && j%2==0)
   			e[i][j]='.';
      	else
      		e[i][j]=' ';
	c[inx-1][iny-1]=-1;
	d=0;
	}

void tim()
	{
	s=0;
	x[0]=outx-1;
	y[0]=outy-1;
	i=outx-1;
	j=outy-1;
	int k;
	while (c[i][j]!=-1)
		{
		k=c[i][j];
		inhinh();
		i=i-dx[k];
		j=j-dy[k];
		s++;
		x[s]=i;
		y[s]=j;
		}
	}

void xuly()
	{
	chuanbi();
	dfs(inx-1,iny-1);
	if (d==1) tim();
	e[2*(inx-1)][2*(iny-1)]='>';
	e[2*(outx-1)][2*(outy-1)]='>';
	}

void xuat()
	{
	FILE *f;
	f=fopen(out,"w");
	if (d != 1)
      {
   	fprintf(f,"KET LUAN: KHONG CO DUONG DI");
      printf("KET LUAN:\t KHONG CO DUONG DI\n\n");
      }
	if (d==1)
		{
		//fprintf(f,"%d\n",s);
      fprintf(f,"Day CAC TOA DO CAC DIEM TREN DUONG DI THOAT KHOI ME CUNG \n\n");
     // fprintf(f,"\n (TUONG UNG CHI SO DONG VA COT CUA MA TRAN DAU VAO) \n");
		for (i=s;i>=0;i--)
      fprintf(f,"a[%d][%d]-->",x[i],y[i]);

      fprintf (f,"\n\n DUONG DI TRONG ME CUNG LA: \n\n\n");
		printf ("\n DUONG DI TRONG ME CUNG LA: \n\n\n");
      for (i=0;i<=2*(m-1);i++)
      	{
         for (j=0;j<=2*(n-1);j++)
         	{
            printf ("%c",e[i][j]);
            fprintf(f,"%c",e[i][j]);
            }
         printf ("\n");
         fprintf(f,"\n");
         }

      printf("DO DAI DUONG DI TRONG ME CUNG LA : %d\n",s);
      printf("Day cac toa do duong di da duoc luu ra file out.txt.....\n\n");

      fprintf(f,"\n\n DO DAI DUONG DI TRONG ME CUNG LA : %d\n",s);
		}
	fclose(f);
	}


void main()
	{
   int chay = 13;
	while (chay==13)
		{
		nhap();
		xuly();
      xuat();
		printf("Ban an EnTer de tiep tuc, an phim bat ky de ket thuc.....\n\n");
   	chay=getch();
		}
		getch();
	}

