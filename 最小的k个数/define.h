class Min_k {
    public:
        Min_k(int A[], int l, int kval):pnum(A), len(l), k(kval){};
        void quick_k(int, int);
        void heap_k();
    private:
        void create_heap(); 
        void make_heapify(int);
        int quick_sort_partion(int*, int*);
        int *pnum;
        int len;
        int k;
};
