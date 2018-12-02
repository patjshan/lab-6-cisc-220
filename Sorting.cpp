/*
 * Sorting.cpp
 *
 *  Created on: Dec 1, 2018
 *      Author: patrickshannon
 */

#include "Sorting.hpp"

void Sorting::insertionSort(wordInfo *w, int len){
	for(int i = 1; i < len - 1; i++){
		int j = i;
		while( j > 0 && w[j -1].ct > w[j].ct){
			wordInfo *tmp = w[j - 1];
			w[j-1] = w[j];
			w[j] = tmp;
			j --;
		}
	}

}

void Sorting::selectionSort(wordInfo *w, int len){
	wordInfo min;
	for(int i = 0; i < len - 1; i++){
		min = w[i];
		for(int j = i + 1; j <len; j++){
			if(w[j].ct < min.ct){
				min = w[j];
			}
			wordInfo *tmp = min;
			min = w[i];
			w[i] = tmp;
		}
	}
}

void Sorting::quickSort(wordInfo *w, int beg, int end){
	if(end - beg > 1){
		int pivot = partition(w, beg, end);

		quickSort(w, beg, pivot - 1);
		quickSort(w, pivot + 1, end);
	}

}

int partition(wordInfo *w, int beg, int end){

	int pivot = w[beg].ct;

	int trav1 = beg + 1;
	int trav2 = end;

	while (trav1 < trav2){
		if(w[trav1].ct < pivot && w[trav2].ct > pivot){
			trav1 ++;
			trav2 --;
		}
		else if(w[trav1].ct > pivot && w[trav2].ct > pivot){
			trav2 --;
		}
		else if (w[trav1].ct < pivot && w[trav2].ct > pivot){
			trav1 ++;
		}
		else{
			wordInfo *tmp = w[trav2];
			w[trav2] = w[trav1];
			w[trav1] = tmp;
		}
	}
	wordInfo *swap = w[trav2];
	w[trav2] = pivot;
	w[beg] = swap;
	return trav2;
}

void Sorting::mergeSort(wordInfo *w, int l1, int l2){


}

void merge(wordInfo *w, int l, int m, int r){

}

