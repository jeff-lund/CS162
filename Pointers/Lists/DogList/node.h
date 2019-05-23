struct dog
{
    char *name;
    char *breed;
    char *trick;
};

struct node {
    dog a_dog;
    node *next;
    ~node();
};


class list
{
    public:
        list();
        ~list();
        void add(dog);
        void append(dog);
        void remove(const char*);
        int count();
        void display_all();
    private:
        node *head;
};

dog build_dog(const char*, const char*, const char*);
dog interactive_build_dog();
