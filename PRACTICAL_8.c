#include <stdio.h>
#include <string.h>
#define MAX 10
#define SIZE 10
int parent[MAX];
int rank[MAX];
void makeSet(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find(int x)
{
    if(parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}
void simpleUnion(int a,int b)
{
    int rootA = find(a);
    int rootB = find(b);

    parent[rootB] = rootA;
}
void smartUnion(int a,int b)
{
    int rootA = find(a);
    int rootB = find(b);
    if(rank[rootA] < rank[rootB])
        parent[rootA] = rootB;
    else if(rank[rootA] > rank[rootB])
        parent[rootB] = rootA;
    else
    {
        parent[rootB] = rootA;
        rank[rootA]++;
    }
}
struct Student
{
    int id;
    char name[20];
};
struct Student table[SIZE];
int hash(int id)
{
    return id % SIZE;
}
void insertStudent(int id, char name[])
{
    int index = hash(id);

    table[index].id = id;
    strcpy(table[index].name, name);
}
void searchStudent(int id)
{
    int index = hash(id);

    if(table[index].id == id)
        printf("Student Found: %d %s\n", table[index].id, table[index].name);
    else
        printf("Student not found\n");
}
void displayStudents()
{
    printf("\nStudent Records:\n");
    for(int i=0;i<SIZE;i++)
    {
        if(table[i].id != 0)
            printf("%d %s\n", table[i].id, table[i].name);
    }
}
int main()
{
    int n = 5;
    makeSet(n);
    printf("Simple Union:\n");
    simpleUnion(0,1);
    simpleUnion(2,3);
    printf("Find(1): %d\n", find(1));
    printf("Find(3): %d\n", find(3));
    printf("\nSmart Union:\n");
    smartUnion(1,3);
    printf("Find(3): %d\n", find(3));
    printf("\nPath Compression:\n");
    printf("Find(3): %d\n", find(3));
    insertStudent(101,"shreya");
    insertStudent(102,"aashta");
    insertStudent(103,"gauri");
    displayStudents();
    searchStudent(102);
    return 0;
}
