#pragma once
#include <iostream>
#include <vector>

// ============================================================
// SORTING ALGORITHMS
// All operate on a std::vector<T> passed by reference
// ============================================================

// Helper: print a vector
template <typename T>
void printVector(const std::vector<T>& v) {
    std::cout << "[ ";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout << v[i] << (i < (int)v.size() - 1 ? ", " : " ");
    std::cout << "]\n";
}

// -------------------------------------------------------
// BUBBLE SORT
// Repeatedly compares adjacent elements and swaps them
// if they are in the wrong order. Largest values "bubble"
// to the end each pass.
// Time: O(n^2)  |  Space: O(1)
// -------------------------------------------------------
template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Early exit if no swaps occurred (already sorted)
        if (!swapped) break;
    }
}

// -------------------------------------------------------
// SELECTION SORT
// Finds the smallest element in the unsorted portion and
// swaps it into its correct position. Grows sorted portion
// from left to right.
// Time: O(n^2)  |  Space: O(1)
// -------------------------------------------------------
template <typename T>
void selectionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i)
            std::swap(arr[i], arr[minIdx]);
    }
}

// -------------------------------------------------------
// INSERTION SORT
// Builds a sorted portion one element at a time by taking
// each new element and inserting it into its correct
// position within the already-sorted portion.
// Time: O(n^2)  |  Space: O(1)  |  Best case O(n)
// -------------------------------------------------------
template <typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        // Shift elements greater than key one position right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
