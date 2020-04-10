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
static int sample_array[1000] = {0};
static int sample_index = 0;


void append_buffer(int value);

int get_item_from_end(int index_from_end);


#endif /* __CIRCULAR_BUFFER_H__ */