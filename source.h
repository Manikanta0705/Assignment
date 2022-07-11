/Function declaration
double **createMat(int m,int n);
void readMat(double **p, int m,int n);
void print(double **p,int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_inv(double **mat, int m);
double **matmul(double **a, double **b, int m, int n, int p);
double **transpose(double **a,  int m, int n);
void uniform(char *str, int len);
int gaussian(char *str, int len,double, double, double sig2,unsigned short n,double);
double mean(char *str);
//End function declaration


//Defining the function for matrix creation
double **createMat(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation


//Defining the function for reading matrix 
void readMat(double **p, int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%lf",&p[i][j]);
  }
 }
}
//End function for reading matrix

//Read  matrix from file
double **loadtxt(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%lf",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}


//Defining the function for printing
void print(double **p, int m,int n)
{
 int i,j;

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  printf("%lf ",p[i][j]);
 printf("\n");
 }
}
//End function for printing

//Defining the function for norm

double linalg_norm(double **a, int m)
{
int i;
double norm=0.0;

 for(i=0;i<m;i++)
 {
norm = norm + a[i][0]*a[i][0];
}
return sqrt(norm);

}
//End function for norm

//Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for inverse of 2x2 matrix


double **linalg_inv(double **mat, int m)
{
double **c, det;
c = createMat(m,m);

det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];

c[0][0] = mat[1][1]/det;
c[0][1] = -mat[1][0]/det;
c[1][0] = -mat[0][1]/det;
c[1][1] = mat[0][0]/det;

return c;

}
// End  function for inverse of 2x2 matrix


//Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat(m,p);

 for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat(n,m);

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
c[i][j]= a[j][i];
//  printf("%lf ",c[i][j]);
  }
 }
return c;

}
//End function for transpose of matrix

void triangular_distribution(char * str){

  FILE *fw = fopen(str,"w");

  double temp,u1,u2;
  int n=1000000;
  for (int i=0;i<n;i++){
    temp=0;
    u1=rand()/RAND_MAX;
    u2=rand()/RAND_MAX;
    temp=u1+u2;
    fprintf(fw,"%lf\n",temp);
  }
  fclose(fw);
}
//Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}
//End function for generating uniform random numbers

//Defining the function for calculating the mean of random numbers
double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//End function for calculating the mean of random numbers

//Defining the function for generating Gaussian random numbers
int gaussian(char *str, int len,double invarU , double inmeanU, double sig2,unsigned short n,double div)
{
int i,j;
double temp;
FILE *fp;

srand(n);

fp = fopen(str,"w");
int num = sig2*invarU;
if (num==0){ return -1; }
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0.0;
for (j = 0; j < num; j++)
{
  //double a = (double) rand()/  RAND_MAX;
  temp += ((double) rand()/RAND_MAX)*div;
}
temp-=(double) num/inmeanU ;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);
return 1;

}
void AA_distribution(char * str, char * chi){
  FILE *fw=fopen(str,"w");
  FILE* fr=fopen(chi,"r");
  int n;
  double temp;
  n=1000000;
  for (int i=0; i<n;i++){
    fscanf(fr,"%lf",&temp);
    temp=sqrt(temp);
    fprintf(fw,"%lf\n",temp);
  }
  fclose(fw);
  fclose(fr);
}
//End function for generating Gaussian random numbers
void rayleigh(char * str,double y){
    FILE *fw=fopen(str,"w");
    int n=1000000;
    int check = gaussian("../data/gau1.dat",192,32,n,y/2.0,3,0.1);
    gaussian("../data/gau2.dat",n,192,32,y/2.0,2,0.1);
    if (check == -1)
      return;
    FILE *f1=fopen("../data/gau1.dat","r");
    FILE *f2=fopen("../data/gau1.dat","r");
    double num1,num2;
    double rl;
    while (n-- >0){
      fscanf(f1,"%lf",&num1);
      fscanf(f2,"%lf",&num2);
      rl=num1*num1+num2*num2;
      rl=sqrt(rl);
      fprintf(fw,"%lf\n",rl);
    }
    fclose(f1);
    fclose(f2);
    fclose(fw);
}

void Y_distribution(char *str,char *fileA,char* fileX, char* fileN){
  FILE *fw =fopen(str,"w");
  FILE *fA =fopen(fileA,"r");
  FILE *fX =fopen(fileX,"r");
  FILE *fN =fopen(fileN,"r");
  int n = 1000000;
  double temp,A,X,N;
  while (n-- > 0){
    fscanf(fA,"%lf",&A);
    fscanf(fX,"%lf",&X);
    fscanf(fN,"%lf",&N);
    temp=A*X+N;
    fprintf(fw,"%lf\n",temp);
  }
  fclose(fw);
  fclose(fA);
  fclose(fX);
  fclose(fN);
  
}

void X_cap_distribution(char *str,char *fileY){
  FILE *f = fopen(str,"w");
  FILE *fy= fopen(fileY,"r");

  double Y;
  int temp;
  int n = 1000000;
  while (n-- > 0){
    fscanf(fy,"%lf",&Y);
    temp = (Y>0)? 1 : -1;
    fprintf(f,"%d\n",temp);
  }
  fclose(f);
  fclose(fy);
}


void X_distribution(char * str){
  FILE *f;
  f=fopen(str,"w");
  int temp;
  int n=1000000;
  for (int i=0;i<n;i++){
    temp=rand()-RAND_MAX/2;
    temp=(temp>0)?1:-1;
    fprintf(f,"%d\n",temp);

  }
  fclose(f);
}

void A_distribution(char * str, double a){
  int n;
  n=1000000;
  FILE * fw= fopen(str,"w");

  for (int i=0;i<n;i++){
    fprintf(fw,"%f\n",a);
  }
  fclose(fw);
}
double chi_square(double a, double b){
  double temp = a*a+b*b;
  return temp;
}
void chi_square_distribution(char *str, char * gau1, char * gau2){
  FILE * fw= fopen(str,"w");
  FILE *f1= fopen(gau1,"r");
  FILE*f2 =fopen(gau2,"r");
  int n;
  double g1,g2,temp;
  n = 1000000;
  for (int i=0; i<n; i++){
    fscanf(f1,"%lf",&g1);
    fscanf(f2,"%lf",&g2);
    temp = chi_square(g1,g2);
    fprintf(fw,"%lf\n",temp);
  }
  fclose(fw);
  fclose(f1);
  fclose(f2);
}
