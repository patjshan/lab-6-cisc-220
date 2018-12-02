/*
 * Sorting.hpp
 *
 *  Created on: Dec 1, 2018
 *      Author: patrickshannon
 */

#ifndef SORTING_HPP_
#define SORTING_HPP_
#include "wordInfo.hpp"

class Sorting{

public:
	void insertionSort(wordInfo *w, int len);
	void selectionSort(wordInfo *w, int len);
	void mergeSort(wordInfo *w, int l1, int l2);
	void quickSort(wordInfo *w, int beg, int end);
	int partition(wordInfo *w, int beg, int end);
	void merge(wordInfo *w, int i, int m , int r);
};


#endif /* SORTING_HPP_ */
