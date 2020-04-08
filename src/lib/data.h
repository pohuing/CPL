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
 * @param size count of integers for the data set
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
// @Returns if the operation was successful
//   1 for success -1 for out of bounds
/**
 * @brief Bounds checked getter
 * 
 * @param data struct to operate on
 * @param index index of data to get
 * @param out value of index
 * @return int -1 if bounds check failed, 1 if set successful
 */
int data_get(Data *data, size_t index, int *out);
/**
 * @brief Bounds checked setter
 * 
 * @param data struct to operate on
 * @param index of index to set
 * @param value to set index to
 * @return int -1 if bounds check failed, 1 if set successful
 */
int data_set(Data *data, size_t index, int value);
/**
 * @brief Bounds checked swap of indices
 * 
 * @param data struct to operate on
 * @param index1 index1 to swap
 * @param index2 index2 to swap
 * @return int -1 if bounds check failed, 1 if set successful
 */
int data_swap(Data *data, size_t index2, size_t index1);
/**
 * @brief Prints data contents to stdout
 * 
 * @param data struct to print
 */
void data_print(Data* data);


#endif // data
