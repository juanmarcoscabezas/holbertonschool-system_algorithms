#include "huffman.h"

/**
* symbol_create - creates a symbol_t data structure
* @data: data to be stored in the structure
* @freq: its associated frequency
* Return: pointer to the created structure, or NULL otherwise
*/
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *symbol;

	symbol = NULL;

	symbol = malloc(sizeof(symbol_t));
	if (!symbol)
		return (NULL);

	symbol->data = data;
	symbol->freq = freq;

	return (symbol);
}
