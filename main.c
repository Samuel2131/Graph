#include "list.h"

int main() {

    adjList* l = newList();
    printList(l);
    printf("%d\n", add(l, "New item"));
    printf("%d\n", add(l, "Second item"));
    printf("%d\n", add(l, "Third item"));
    printf("%d\n", add(l, "Last item"));
    printList(l);
    printf("\nList len = %d", lenght(l));

    listNode* ln = getNode(l, "LasT iTeM");
    if(ln != NULL) printf("\nNode by value = %s", ln->value);
    else printf("\nNode by value not found...");

    listNode* ln2 = getNodeByIndex(l, 10);
    if(ln2 != NULL) printf("\nNode by index = %s", ln2->value);
    else printf("\nNode by index not found...");

    printf("\nRemove : %d", deleteNode(l, "last item"));
    printf("\nLength : %u", lenght(l));
    printList(l);

    printf("\nUpdate : %d", updateNode(l, "third item", "last item"));
    printList(l);

    printf("\nLength a : %u", lenght(l));
    printf("\n%d\n", add(l, "second item"));
    printf("\nLength a : %u", lenght(l));

    return 0;
}
