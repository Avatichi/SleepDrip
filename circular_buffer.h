/* 
 * circular buffer 
 * I know.. I know.. writing cyclic buffer? again? why?
 * Well.. Since you asked, I look for one that let you accses the item I - X
 * 
 * Sorry .. I did not plan to write this.. again.. sorry
 */

#ifndef __CIRCULAR_BUFFER_H__
#define __CIRCULAR_BUFFER_H__

#include "error_values.h"


/* Should change this .. */
static int sample_array[1000];
static int sample_index;


void append_buffer(int value);

status_t get_item_from_end(int index_from_end, int *value);
void get_sample_amount(int *len);


#endif /* __CIRCULAR_BUFFER_H__ */