#include "circular_buffer.h"


void append_buffer(int value)
{
    sample_array[sample_index] = value;
    sample_index ++;
}

void get_sample_amount(int *len)
{
    *len = sample_index;
}

status_t get_item_from_end(int index_from_end, int *value)
{
    status_t ret = STATUS_OK;
    if (sample_index < index_from_end) {
        ret = BUFFER_ERROR;
    } else {
        *value = sample_array[sample_index - index_from_end];
    }
    return ret;
}

