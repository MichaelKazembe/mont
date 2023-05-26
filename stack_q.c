
void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    
    bus.data_format = 0; // Set data_format to 0 for stack (LIFO)
}

void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    
    bus.data_format = 1; // Set data_format to 1 for queue (FIFO)
}
