#include <stdio.h>

int main()
{
        float n1, n2, n3, n4, m,n5;
        scanf("%f%f%f%f",&n1,&n2,&n3,&n4);
        m=(2*n1+3*n2+4*n3+n4)/10;
        printf("Media: %.1f\n",m);
        if(m>=7.0) printf("Aluno aprovado.\n",m);
        else if(m<5.0) printf("Aluno reprovado.\n",m);
        else if(m>=5.0&&m<=6.9){
                printf("Aluno em exame.\n",m);
                scanf("%f",&n5);

printf("Nota do exame: %0.1f\n",n5);
                m=(m+n5)/2;
                if(m>=5.0) printf("Aluno aprovado.\n");
                if(m<=4.9) printf("Aluno reprovado.\n");
                printf("Media final: %.1f\n",m);
        }
        return 0;
}
