
void make_cycle(int pos)
{
    struct node *temp = first;
    struct node *ptr;
    int count = 1;
    while(temp->link != NULL)
    {
        if(pos == count)
        {
            ptr = temp;
        }
        temp = temp->link;
        count++;
    }
    temp->link = ptr;
}