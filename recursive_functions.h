/* SYSC 2006 recursive_functions.h */

typedef struct node {
    int data;
    struct node *next;
} node_t;

double power(double x, int n);
int count(int a[], int n, int target);
int occurrences(node_t *head, int target);
int last(node_t *head);

/* Extra-practice exercises. */

int num_digits(int n);
double power2(double x, int n);
