#ifndef FORMAT_H_
#define FORMAT_H_

void integer_to_string(unsigned int ip_addr, char* ip_addr_as_str);

unsigned int string_to_integer(char ip_addr[]);

unsigned int get_subnet_mask_len(char ip_addr[]);

void get_broadcast_addr(char addr[], char *broadcast_addr);


#endif // FORMAT_H_
