class list {
    public:
      list();
      void append(int);
      int pop();
      void print();
      int get(int);
      bool store(int, int);
    private:
      int *arr;
      int last_index;
      int max_size;
      void reallocate();
};
