struct node
{
  char *word;
  node *next;
};

class queue
{
  public:
    queue();
    void push(char*);
    char* pop();
    bool is_empty();
  private:
    node *head;
    node *tail;
};
