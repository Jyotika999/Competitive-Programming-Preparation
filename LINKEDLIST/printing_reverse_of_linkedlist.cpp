/* This is the ListNode class definition

class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
*/

void print_reversed_list(ListNode * head)
{
	if(head==NULL)
		return ;
	
	
	print_reversed_list(head->next);
	cout<<head->data<<" ";
}
void printLinkedListReverse (ListNode* head) {
    // add your logic here
	
	
	if(head==NULL)
		return;
	else
		print_reversed_list(head);
}