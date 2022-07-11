#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
// Function declaration
// double **createMat(int m, int n);
// void readMat(double **p, int m, int n);
// void print(double **p, int m, int n);
// double **loadtxt(char *str, int m, int n);
// double linalg_norm(double **a, int m);
// double **linalg_sub(double **a, double **b, int m, int n);
// double **linalg_inv(double **mat, int m);
// double **matmul(double **a, double **b, int m, int n, int p);
// double **transpose(double **a, int m, int n);
double gen_mean(char *str);
double gen_var(char *str, double mean);
void uni_gen(char *str, int len);
void gau_gen(char *str, int len);
void tri_gen(char *str, int len);
void ber_gen(char *str, int len);
void max_lik_gen(char *str, int len);
// End function declaration

double gen_mean(char *str)
{
    FILE *fp = fopen(str, "r");
    double sum = 0, num = 0;
    int total_num = 0;
    while (fscanf(fp, "%lf", &num) != -1)
    {
        sum += num;
        total_num++;
        if (feof(fp))
        {
            break;
        };
    }
    fclose(fp);
    double mean = sum / total_num;
    return mean;
}

double gen_var(char *str, double mean)
{
    FILE *fp = fopen("./uni.dat", "r");
    double sum = 0, num = 0;
    int total_num = 0;
    while (fscanf(fp, "%lf", &num) != -1)
    {
        sum += pow((num - mean), 2.0);
        total_num++;
        if (feof(fp))
        {
            break;
        };
    }
    fclose(fp);
    double var = sum / total_num;
    return var;
}

void uni_gen(char *str, int len)
{
    FILE *fp = fopen(str, "w");
    for (int i = 0; i < len; i++)
    {
        double var = ((double)rand()) / RAND_MAX;
        fprintf(fp, "%lf\n", var);
    }
    fclose(fp);
}

void gau_gen(char *str, int len)
{
    FILE *fp = fopen(str, "w");
    for (int i = 0; i < len; i++)
    {
        srand(i);
        double x = 0;
        for (int j = 0; j < 12; j++)
        {
            double U = ((double)rand()) / RAND_MAX;
            x += U;
        }
        fprintf(fp, "%lf\n", x - 6.0);
    }
    fclose(fp);
}

void tri_gen(char *str, int len)
{
    FILE *fp = fopen(str, "w");
    for (int i = 0; i < len; i++)
    {
        srand(i);
        double x = 0;
        for (int j = 0; j < 2; j++)
        {
            double U = ((double)rand()) / RAND_MAX;
            x += U;
        }
        fprintf(fp, "%lf\n", x);
    }
    fclose(fp);
}

void ber_gen(char *str, int len)
{
    FILE *fp = fopen(str, "w");
    for (int i = 0; i < len; i++)
    {
        double temp = 0;
        double random = (double)rand() / (double)RAND_MAX;
        if (random < 0.5)
            temp = -1;
        else
            temp = 1;
        fprintf(fp, "%lf\n", temp);
    }
    fclose(fp);
}

void max_lik_gen(char *str, int len)
{
    FILE *fpN = fopen("gau.dat", "r");
    FILE *fpB = fopen("ber.dat", "r");
    FILE *fp = fopen(str, "w");
    double a = 0.5;
    for (int i = 0; i < len; i++)
    {
        double N = 0, B = 0;
        fscanf(fpN, "%lf", &N);
        fscanf(fpB, "%lf", &B);
        double x = a * B + N;
        fprintf(fp, "%lf\n", x);
    }
    fclose(fp);
}

double est_err(int len, int X)
{
    FILE *fpB = fopen("./ber.dat", "r");
    FILE *fp = fopen("./max_lik.dat", "r");
    int cases = 0, total = 0;
    for (int i = 0; i < len; i++)
    {
        double B = 0, Y = 0;
        fscanf(fp, "%lf", &Y);
        fscanf(fpB, "%lf", &B);
        if (X == -1 && B == -1.0)
        {
            total++;
            if (Y > 0.0)
                cases++;
        }
        else if (X == 1 && B == 1.0)
        {
            total++;
            if (Y < 0.0)
                cases++;
        }
    }
    double ans = (double)cases / (double)total;
    fclose(fp);
    fclose(fpB);
    return ans;
}
