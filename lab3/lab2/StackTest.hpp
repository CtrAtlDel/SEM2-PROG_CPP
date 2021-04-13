//string A(string s)
//{
//	s = "A ";
//	return s;
//}
//
//bool K(string s)
//{
//	if (s == "K")
//	{
//		return 1;
//	}
//	else return 0;
//}
//
//int Twice(int x)
//{
//	return 2 * x;
//}
//
//int Square(int x)
//{
//	return x * x;
//}
//
//auto Swap(int (*foo)(int))
//{
//	if (foo == Twice)
//	{
//		return Square;
//	}
//	else
//	{
//		return Twice;
//	}
//}
//
//bool W2(int (*foo)(int))
//{
//	if (foo == Twice)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
////void TestString()
//{
//	Stack<string>* stack;
//	stack = new Stack<string>();
//	Stack<string>* stack1;
//	stack1 = new Stack<string>();
//
//	stack->Set("Info");
//	stack->Set("Psdteyt");
//	stack->Set("K");
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "Test Where" << endl;
//	stack1 = stack->Where(K);
//	cout << stack1->Get(0) << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "Test Search" << endl;
//	cout << "Index : " << stack->Search(stack1) << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "Test Concatination" << endl;
//	cout << "This is concatination, begin length " << stack->GetLength() << endl;
//	stack1 = stack->Concatination(stack1);
//	cout << "This is concatination, end length " << stack1->GetLength() << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "It is getsubseq inedx 0 to index 1  : " << endl;
//	stack1 = stack->GetSubsequence(0, 1);
//	cout << stack1->Get(0) << endl;
//	cout << stack1->Get(1) << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "Test Map" << endl;
//	cout << stack->Get(0) << endl;
//	cout << stack->Get(1) << endl;
//	stack->Map(A);
//	cout << "Use Map " << endl;
//	cout << stack->Get(0) << endl;
//	cout << stack->Get(1) << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "///////////////////////////////////////////" << endl;
//}
//
//void TestFunctions() 
//{
//
//	int (*Ftwice)(int) = Twice;
//	int (*Fsquare)(int) = Square;
//
//	Stack<int(*)(int)>* stack;
//	stack = new Stack<int(*)(int)>();
//	Stack<int(*)(int)>* stacks;
//	stacks = new Stack<int(*)(int)>();
//	Stack<int(*)(int)>* stackc;
//	stackc = new Stack<int(*)(int)>();
//
//	stack->Set(Ftwice);
//	stack->Set(Fsquare);
//	//stacks->Set(Ftwice);
//	//stacks->Set(Ftwice);
//	//cout << "This is concatination, end length " << stacks->GetLength() << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "Adress of our functions" << endl;
//	cout << stack->Get(0)<< endl;
//	cout << stack->Get(1)<< endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "Map swipe" << endl;
//	stack->Map(Swap);
//	cout << stack->Get(0) << endl;
//	cout << stack->Get(1) << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "Twice filter(function where)"<< endl;
//	stacks = stack->Where(W2);
//	cout <<"Length of new filters stack"<<stacks->GetLength() << endl;
//	cout << "Adress of first element where" << endl;
//	cout << stack->Get(0)<< endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout <<"Search : " << endl;
//	cout << "Index : " << stack->Search(stacks)<< endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "It is getsubseq inedx 0 to index 1  : " << endl;
//	stackc = stack->GetSubsequence(0, 1);
//	cout << stackc->Get(0) << endl; 
//	cout << stackc->Get(1) << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "This is concatination, begin length " << stack->GetLength()<< endl;
//	stacks = stack->Concatination(stacks);
//	cout << "This is concatination, end length " << stacks->GetLength() << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	cout << "///////////////////////////////////////////" << endl;
//	
////}
//
//void Test()
//{
//	TestString();
//	TestFunctions();
//}
