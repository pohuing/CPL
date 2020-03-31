#if !defined(DATA_H)
#define DATA_H
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Represents a sized array of integers to be used with the data_* 
 * functions
 * 
 */
typedef struct Data{
    size_t size;
    int* data;
} Data;

/**
 * @brief Allocates and Generates a random set of data
 * 
 * @param size count of integers for the dataset
 * @param outData struct to operate on
 */
void data_generate(size_t size, Data* outData);
/**
 * @brief Allocates a set of data, does not zero values
 * 
 * @param size 
 * @param outData 
 */
void data_instantiate(size_t size, Data* outData);
/**
 * @brief Frees data contents
 * Frees data contents and sets the data pointer to NULL
 * Also sets size to 0
 * 
 * @param data struct to free
 */
void data_delete(Data* data);
// Bounds checked access into data of index index
// @Returns if the opearation was successfull
//   1 for success -1 for out of bounds
/**
 * @brief Bounds checked getter
 * 
 * @param index index of data to get
 * @param data struct to operate on
 * @param out value of index
 * @return int -1 if bounds check failed, 1 if set successfull
 */
int data_get(size_t index, Data* data, int* out);
/**
 * @brief Bounds checked setter
 * 
 * @param index of index to set
 * @param data struct to operate on
 * @param value to set index to
 * @return int -1 if bounds check failed, 1 if set successfull
 */
int data_set(size_t index, Data* data, int value);
/**
 * @brief Bounds checked swap of indices
 * 
 * @param index1 index1 to swap
 * @param index2 index2 to swap
 * @param data struct to operate on
 * @return int -1 if bounds check failed, 1 if set successfull
 */
int data_swap(size_t index1, size_t index2, Data* data);
/**
 * @brief Prints data contents to stdout
 * 
 * @param data struct to print
 */
void data_print(Data* data);


#endif // data
