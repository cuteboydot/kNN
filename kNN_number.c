#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

#define K		3
#define SIZE_TRAIN	6
#define SIZE_TEST	3
#define SIZE_ATTR 	49

unsigned char train_data[SIZE_TRAIN][SIZE_ATTR];
unsigned int train_class[SIZE_TRAIN];
unsigned char test_data[SIZE_TEST][SIZE_ATTR];
double test_to_train_dist[SIZE_TEST][SIZE_TRAIN];

double distance(unsigned char * point1, unsigned char * point2)
{
	double dist = 0.0, tmp = 0.0;
	int a;
	for(a=0; a<SIZE_ATTR; a++) {
		tmp = point2[a] - point1[a];
		tmp = tmp * tmp;
		dist += tmp;
	}
	dist = sqrt(dist);
	
	return dist;
}

void calculate(int idx_test)
{
	int idx_train;
	for(idx_train=0; idx_train<SIZE_TRAIN; idx_train++)
		test_to_train_dist[idx_test][idx_train] = distance(test_data[idx_test], train_data[idx_train]);
}

void display()
{
	int a,b;
	for(a=0; a<SIZE_TEST; a++) {
		for(b=0; b<SIZE_TRAIN; b++) {
			printf("TEST#%d -> distance(TRAIN#%d) : %.2f \n", a, b, test_to_train_dist[a][b]);
		}
		printf("\n");
	}
}

void main ()
{
	int a;
	unsigned char train0[SIZE_ATTR] = {0,0,1,1,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0};
	unsigned char train1[SIZE_ATTR] = {0,0,1,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,1,0,1,1,0,0,0,1,1,1,0,0};
	unsigned char train2[SIZE_ATTR] = {0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,0};
	unsigned char train3[SIZE_ATTR] = {0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0};
	unsigned char train4[SIZE_ATTR] = {0,0,1,1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,0,0};
	unsigned char train5[SIZE_ATTR] = {0,1,1,1,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,0};
	
	unsigned char test0[SIZE_ATTR] = {0,0,1,1,1,0,0,1,1,1,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,1,1,0,0};
	unsigned char test1[SIZE_ATTR] = {0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0};
	unsigned char test2[SIZE_ATTR] = {0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,0};
	
	memcpy(train_data[0], train0, SIZE_ATTR);
	memcpy(train_data[1], train1, SIZE_ATTR);
	memcpy(train_data[2], train2, SIZE_ATTR);
	memcpy(train_data[3], train3, SIZE_ATTR);
	memcpy(train_data[4], train4, SIZE_ATTR);
	memcpy(train_data[5], train5, SIZE_ATTR);
	
	train_class[0] = 0;
	train_class[1] = 0;
	train_class[2] = 1;
	train_class[3] = 1;
	train_class[4] = 2;
	train_class[5] = 2;
	
	memcpy(test_data[0], test0, SIZE_ATTR);
	memcpy(test_data[1], test1, SIZE_ATTR);
	memcpy(test_data[2], test2, SIZE_ATTR);
	
	for(a=0; a<SIZE_TEST; a++)
		calculate(a);
	
	display();

	getchar();	
}


