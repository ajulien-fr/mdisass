#include "mdisass.h"

bool fetch_data(disass_data *data, uint32_t size)
{
    if (data->size < (data->read + size)) return false;
    
    data->code = (disass_code *)((uint8_t *)(data->code) + size);

    data->read += size;

    return true;
}

