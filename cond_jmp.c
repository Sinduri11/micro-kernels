#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NOINLINE __attribute__((noinline))
#define N 20000

static int *m_s1, *m_s2, *m_s3, *m_dst;
//char string1[1024], string2[1024], string3[1024];
int counter = 100;

void NOINLINE init(void) {
    m_s1 = malloc(sizeof(int)*N);
    m_s2 = malloc(sizeof(int)*N);
    m_s3 = malloc(sizeof(int)*N);
    m_dst = malloc(sizeof(int)*N);
    srand(42);
    int num;

    for (int i = 0; i < N; i++) {
        m_s1[i] = rand() % N;
        m_s2[i] = 0;
        m_s3[i] = 1;
    }

}

void NOINLINE sel_arr(int *dst, int *s1, int *s2, int *s3) {

for (int i = 0; i < N; i++) {
    if(s1[i] < 10035)
    {
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
	asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
	asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
        asm("   inc %rcx");
	asm("   inc %rcx");
        asm("   inc %rcx");
	asm("   inc %rcx");
        asm("   inc %rcx");
	asm("   inc %rcx");
        asm("   inc %rcx");
	//int *p = &s2[i];
    }
    else
    {
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
	asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
	asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
        asm("   dec %rcx");
	//int *p = &s3[i];
    }
    
    }

	
}

void NOINLINE run(int iter) {
  for(int i=0; i<iter; ++i)
    sel_arr(m_dst, m_s1, m_s2, m_s3);
}

int main(int argc, char *argv[])
{
  if (argc<2) {
      printf("%s: missing <num-iterations> arg!\n", argv[0]);
      exit(-1);
  }

  int iter = atol(argv[1]);

  init();
  run(iter);

  return 0;
}
