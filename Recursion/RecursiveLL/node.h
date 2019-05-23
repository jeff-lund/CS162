struct node
{
  int val;
  node *next;
};

class list
{
  public:
    list();
    void display();
    void add(int);
    void remove(int);
    void count();
  private:
    node *head;
    void display_r(node * head);
    void add_r(node * & head, int);
    void remove_r(node * * head, int);
    void count_r(node * head);
};
