struct node {
    int val;
    node *next;
};

class list
{
    public:
        list();
        void add_b(int);
        void add_e(int);
        void add_sort(int);
        void remove(int);
        int count();
        void display_all();
    private:
        node *head;
};
