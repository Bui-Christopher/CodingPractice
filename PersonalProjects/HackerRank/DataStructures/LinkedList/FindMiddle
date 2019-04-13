template <typename Data_t>
void SLinkedList<Data_t>::findMiddleMethodOne() {
	int count = 0;
	Node *current = head;
	while (current != nullptr) {
		++count;
		current = current->next;
	}
	std::cout << "Amount of Nodes: " << count << std::endl;

	current = head;

	for (int x = 0; x < count / 2; x++) {
		current = current->next;
	}
	std::cout << "The middle is: " << current->data;
}
