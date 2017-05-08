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

double distance_euclid(unsigned char * point1, unsigned char * point2)
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

double similarity_cosine(unsigned char * point1, unsigned char * point2)
{
	double sim = 0.0, tmp1 = 0.0, tmp2 = 0.0, tmp3 = 0.0;
	int a = 0;
	
	for(a=0; a<SIZE_ATTR; a++) {
		tmp1 += point1[a] * point1[a];
		tmp2 += point2[a] * point2[a];
		tmp3 += point1[a] * point2[a];
	}
	tmp1 = sqrt(tmp1);
	tmp2 = sqrt(tmp2);
	
	sim = tmp3 / (tmp1 * tmp2);
	
	return sim;
}

void calculate(int idx_test)
{
	int idx_train;
	for(idx_train=0; idx_train<SIZE_TRAIN; idx_train++) {
		// using euclidean distance
		test_to_train_dist[idx_test][idx_train] = distance_euclid(test_data[idx_test], train_data[idx_train]);
		
		// using consine similarity
		//test_to_train_dist[idx_test][idx_train] = similarity_cosine(test_data[idx_test], train_data[idx_train]);
	}
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


