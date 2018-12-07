/*
 * Sorting.cpp
 *
 *  Created on: Dec 1, 2018
 *      Author: patrickshannon
 */

#include "Sorting.hpp"

void Sorting::insertionSort(wordInfo ** w, int len){
	for(int i = 1; i < len - 1; i++){
		int j = i;
		while( j > 0 && w[j -1]->ct > w[j]->ct){
			wordInfo *tmp = w[j - 1];
			w[j-1] = w[j];
			w[j] = tmp;
			j --;
		}
	}

}

void Sorting::selectionSort(wordInfo ** w, int len){
	wordInfo *min;
	for(int i = 0; i < len - 1; i++){
		min = w[i];
		for(int j = i + 1; j <len; j++){
			if(w[j]->ct < min->ct){
				min = w[j];
			}
			wordInfo *tmp = min;
			min = w[i];
			w[i] = tmp;
		}
	}
}

void Sorting::quickSort(wordInfo ** w, int beg, int end){
	if(end - beg > 1){
		int pivot = partition(w, beg, end);

		quickSort(w, beg, pivot - 1);
		quickSort(w, pivot + 1, end);
	}

}

int partition(wordInfo ** w, int beg, int end){

	wordInfo * pivot = w[beg];

	int trav1 = beg + 1;
	int trav2 = end;

	while (trav1 < trav2){
		if(w[trav1]->ct < pivot->ct && w[trav2]->ct > pivot->ct){
			trav1 ++;
			trav2 --;
		}
		else if(w[trav1]->ct > pivot->ct && w[trav2]->ct > pivot->ct){
			trav2 --;
		}
		else if (w[trav1]->ct < pivot->ct && w[trav2]->ct > pivot->ct){
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

void Sorting::mergeSort(wordInfo ** w, int l1, int l2){
	int len1 = l1 - (l2/2);
	int len2 = l2/2 + 12 - 1;
	wordInfo ** left = new wordInfo *[len1];
	wordInfo ** right = new wordInfo *[len2];
	int k = 0;

	for(int j = l1; j < l2 / 2; j++){
		left[k] = w[j];
		k++;
	}
	k = 0;

	for(int n = l2/2 + 1; n < l2; n++){
		right[k] = w[n];
		k++;
	}

	if(l1  - l2 != 1){
		int i = (l1 - l2) / 2;
		mergeSort(left, l1, i);
		mergeSort(right, i + 1, l2);
	}
	merge(w, left, right, len1, len2);
	delete [] left;
	delete [] right;


}

void merge(wordInfo ** w, wordInfo ** w1,wordInfo ** w2, int len1, int len2){
	int j = 0;
	int k = 0;
	int n = 0;
	while(j < len1 && k < len2){
		if(w1[j]->ct < w2[k]->ct){
			w[n] = w1[j];
		}
		else{
			w[n] = w2[k];
		}
		n++ ;
	}
	while(j < len1){
		w[n] = w1[j];
		n++;
		j++;
	}
	while(k < len2){
		w[n] = w2[k];
		n++;
		k++;
	}
}

