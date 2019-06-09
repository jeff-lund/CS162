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
        // new functions from practice
        void display_last();
        int remove_middle();
    private:
        node *head;
};
