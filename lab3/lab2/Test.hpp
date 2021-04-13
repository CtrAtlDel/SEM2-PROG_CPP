////поимк в дереве рекурсивный алгоритм лекция
//NTreeNode<T>* Find(T item)
//{
//	return Find(item, this->root);
//}
//
//
//
//NTreeNode<T>* Find(T item, NTreeNode<T>* node)
//{
//	if (root->Getitem() == item)
//	{
//		return this->root;
//	}
//	for (size_t index = 0; index < node->GetChildCount; index++)
//	{
//		NTreeNode<T>* n = node->GetChild(index);
//		NTreeNode<T>* fNode = Find(item, n);
//	}
//	if (fNode != nullptr)
//	{
//		return fNode;
//	}
//
//}
////поиск в дереве нерекурсивный алгоритм
//
//Sequence<NTreeNode<T>*>* Find(bool (*predicate)(T))
//{
//	Queue<NTreeNode<T>*>* queue = new Queue();
//	Queue->Enqueue(this->root);
//	while (queue->Getcount() != 0)
//	{
//		NTreeNode<T>* node = queue->Dequeue();
//		if (node->Getitem() == item)
//		{
//			queue->~Queue();
//			return node;
//		}
//		queue->Enqueue(node->GetChilds());
//	}
//}












// its a trash
///////////////
//
//Stack<string>* stack;
//stack = new Stack<string>();
//Stack<string>* stack1;
//stack1 = new Stack<string>();
//
//stack->Set("asfalsgkjd");
//stack->Set("bbbbb");
//stack->Set("K");
//
////////
//Test Where
//stack->Set("asfalsgkjd");
//stack->Set("bbbbb");
//stack->Set("K");
//
//stack1 = stack->Where(K);
//cout << stack1->Get(0) << endl;
//////
//Test map
//cout << stack->Get(0) << endl;
//cout << stack->Get(1) << endl;
//stack->Map(A);
//cout << stack->Get(0) << endl;
//cout << stack->Get(1) << endl;
////////////////////////////////////
//Stack<int>* stack1;
//stack1 = new Stack<int>();
//
//for (int i = 0; i < 4; i++)
//{
//	stack1->Set(i);
//}
//	T reduce(T(*foo)(T, T), T start, std::string other) {
//Sequence<TreeNode<T>*>* Threadtree = this->Thread(other);
//T result;
//for (int i = 0; i < Threadtree->GetLength(); i++) {
//	if (i == 0) {
//		result = foo(Threadtree->Get(i)->data, start);
//	}
//	else {
//		result = foo(Threadtree->Get(i)->data, result);
//	}
//}
//
//return result;
//	}
//for (int i = 0; i < SIZE; i++)
//{
//	stack->Set(i);
//}
//Print(stack);
//Print(stack1);
//
//cout << "Index is -> " << stack->Search(stack1) << endl;
//system("pause");
//return 0;
//
////list->GetSubList(1, 3);
//Print(list);
//list->GetSubsequence(1, 3);
////cout << "Size" << (list->GetSubsequence(1, 3))->GetLength();
//for (size_t i = 0; i < (list->GetSubsequence(1, 3))->GetLength(); i++)
//{
//	cout << "sublist " << i << " " << (list->GetSubsequence(1, 3))->Get(i) << endl;
//}
//
//
//
//ListSequence<int>* list2;
//list2 = new ListSequence<int>();
//
//ListSequence<int>* list;
//list = new ListSequence<int>();
//
//ListSequence<int>* list1;
//list1 = new ListSequence<int>();
//
//for (size_t i = 0; i < SIZE; i++)
//{
//	list->Append(i);
//}
//
//
//for (size_t i = 0; i < list->GetLength(); i++)
//{
//	cout << "List  " << i << " = " << (list->GetSubsequence(3, 5))->Get(i) << endl;
//}
//
//
//cout << "list1 = " << list->GetLength() << endl;
//for (size_t i = 0; i < SIZE; i++)
//{
//	list1->Append(8);
//}
//
//list->Concat(list1);
//cout << (list->Concat(list1))->Get(3) << endl;
//for (size_t i = 0; i < SIZE * 2; i++)
//{
//	cout << (list->Concat(list1))->Get(i) << endl;
//}