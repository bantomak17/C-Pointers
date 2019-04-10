//link.h

typedef void *Data;
typedef struct _linkedList LinkedList;

LinkedList* getLinkedListInstance();
void removeLinkedListInstance(LinkedList* List);
void addNode(LinkedList*, Data);
Data removeNode(LinkedList*);

