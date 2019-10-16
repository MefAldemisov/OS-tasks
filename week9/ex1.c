/**
* Date: 16.10.19
* Author: Alina Bogdanova
* Write a program that simulates a paging
* system using the ageing algorithm. The
* number of page frames is a parameter.
* The sequence of page references should
* be read from a file. For a given input file,
* your program should print Hit/Miss ratio
* Test your program with 10, 50 and 100
* page frames using test data from Moodle
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N_PAGE_FRAMES	100
#define MAX_DEG			32

FILE* input;

int active_pages[N_PAGE_FRAMES];
unsigned int page_counters[N_PAGE_FRAMES];

float hit;
float miss;

void fill_arrays(){
	for (int i=0; i<N_PAGE_FRAMES; i++){
		active_pages[i] = 0;
		page_counters[i] = 0;
	}
}

int get_next_page(){
	int page;
	int out = fscanf(input, "%d", &page);
	if (!feof(input)){
		return page;
	}
	return -1;
}

int shift_counters(){
	for (int i=0; i<N_PAGE_FRAMES; i++){
		page_counters[i] >>= 1;
	}
}

int search_page(int page){
	for (int i=0; i<N_PAGE_FRAMES; i++){
		if(active_pages[i]==page){
			hit++;
			return i;
		}
	}
	miss++;
	return -1;
}

int min_counter(){
	int min_index = 0;
	for (int i=1; i<N_PAGE_FRAMES; i++){
		if(page_counters[min_index] > page_counters[i]){
			min_index = i;
		}
	}
	return min_index;
}

void add_page(int page){
	shift_counters();
	int index = search_page(page);
	if (index < 0){
		index = min_counter();
		page_counters[index] = 0;
		active_pages[index] = page;
	}
	page_counters[index] += (unsigned int)pow(2, MAX_DEG);
}

int main() {
	fill_arrays();
	input = fopen("Lab 09 input.txt", "r");
	hit = 0;
	miss = 0;
	int page;
	while((page=get_next_page()) > 0){
		add_page(page);
	}
	fclose(input);
	printf("Hit_ratio: %f\n", hit/(hit+miss));
	printf("Miss_ratio: %f\n", miss/(hit+miss));
	return 0;
}
/*
Output:
10
Hit_ratio: 0.010000
Miss_ratio: 0.990000
50
Hit_ratio: 0.036000
Miss_ratio: 0.964000
100
Hit_ratio: 0.036000
Miss_ratio: 0.964000
*/