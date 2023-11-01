//#include <iostream>
//#include <fstream>
//using namespace std;
//class Helper
//{
//public:
//	static int StringLength(char* Str);
//	static void StringCopy(char* src, char*& dest);
//	static void GetStringFromBuffer(char* Temp, char*&);
//	static char* concatenate(int num, char* str) {
//		int len = StringLength(str);
//
//		int num_copy = num;
//		int digits = 0;
//		while (num_copy > 0) {
//			digits++;
//			num_copy /= 10;
//		}
//		char* result = new char[len + digits + 1];
//		int i = 0;
//		for (int j = 0; j < len; j++) {
//			result[j] = str[j];
//		}
//		while (num > 0) {
//			result[len + digits - i - 1] = '0' + num % 10;
//			num /= 10;
//			i++;
//		}
//		result[len + digits] = '\0';
//		return result;
//	}
//	static bool Compare(const char* str1, char* str2)
//	{
//		int len1 = Helper::StringLength((char*)str1);
//		int len2 = Helper::StringLength((char*)str2);
//		if (len1 != len2)
//		{
//			return 0;
//		}
//		for (int i = 0; str1[i] != '\0'; i++)
//		{
//			if (str1[i] != str2[i])
//				return 0;
//		}
//		return 1;
//	}
//};
//class Date
//{
//	int date, month, year;
//public:
//	Date(int date = 0, int month = 0, int year = 0);
//	void Print();
//	void ReadDateFromFile(ifstream&);
//	bool Compare(Date temp1)
//	{
//		if (temp1.date == date && temp1.month == month && temp1.year == year)
//			return 1;
//		return 0;
//	}
//	static Date currentDate;
//	static void CurrentDate(int Date, int Month, int Year)
//	{
//		currentDate.date = Date;
//		currentDate.month = Month;
//		currentDate.year = Year;
//	}
//	static void PrintDate()
//	{
//		cout << currentDate.date << "/" << currentDate.month << "/" << currentDate.year << endl;
//	}
//	int DateDifferences( Date rhcc)
//	{
//		return rhcc.year - year;
//	}
//	~Date()
//	{
//		date = 0;
//		month = 0;
//		year = 0;
//	}
//	
//};
//class activity
//{
//	int Type;
//	char* Value;
//public:
//	void ReadDataFromFile(ifstream& fin)
//	{
//		fin >> Type;
//		char Temp[200];
//		fin.getline(Temp, 200, '/');
//		Helper::GetStringFromBuffer(Temp, Value);
//		Helper::StringCopy(Temp, Value);
//	}
//	~activity()
//	{
//		if (Value != 0)
//			delete[] Value;
//	}
//	void Print()
//	{
//		if (Type == 1)
//		{
//			cout << " is feeling   ";
//		}
//		if (Type == 2)
//		{
//			cout << "is thinking about  ";
//		}
//		if (Type == 3)
//		{
//			cout << " is making ";
//		}
//		if (Type == 4)
//		{
//			cout << " is celebrating  ";
//		}
//		cout << Value;
//	}
//};
//class Facebook;
//class Post;
//class object
//{
//	char* ID;
//	static int postcounter;
//public:
//	virtual void Register(Post* ptr)
//	{
//	}
//	object()
//	{
//		ID = 0;
//	}
//	virtual void setID(char* id)
//	{
//		Helper::GetStringFromBuffer(id, ID);
//		Helper::StringCopy(id, ID);
//	}
//	virtual	char* getID() = 0;
//
//	void setobjId(char* id)
//	{
//
//		Helper::GetStringFromBuffer(id, ID);
//		Helper::StringCopy(id, ID);
//	}
//	virtual void printname() = 0;
//	~object()
//	{
//		if (ID)
//		{
//			delete[] ID;
//		}
//	}
//};
//class Comment
//{
//	char* ID;
//	object* CommentBy;
//	char* Text;
//	static int TotalComments;
//public:
//	Comment()
//	{
//		CommentBy = 0;
//		Text = 0;
//		ID = 0;
//	}
//	void SetAllValues(char* id, char* text, object* comment)
//	{
//		TotalComments++;
//		Helper::GetStringFromBuffer(id, ID);
//		Helper::StringCopy(id, ID);
//		Helper::GetStringFromBuffer(text, Text);
//		Helper::StringCopy(text, Text);
//		CommentBy = comment;
//	}
//	Comment(object* CommentBy, char*);
//	void ViewComment()
//	{
//		cout << "\t\t";
//		//  cout << ID<<" ";
//		CommentBy->printname();
//		cout << "   wrote : ";
//		cout << Text << endl;
//	}
//	~Comment()
//	{
//		if (ID)
//			delete[] ID;
//		if (CommentBy)
//			delete[] CommentBy;
//		if (Text)
//			delete[] Text;
//	}
//};
//class Post
//{
//protected:
//	char* PostId;
//	char* Text;
//	Date SharedDate;
//	activity* Activity;
//	object* SharedBy;
//	object** LikedBy;
//	int countLikedby;
//	Comment** Comments;
//	int totalcomments;
//	static int Postcount;
//public:
//	Post();
//	void ReadPost(ifstream& fin);
//	void SetSharedBy(object* share)
//	{
//		SharedBy = share;
//	}
//	void SetLikedBy(object* ptr)
//	{
//		if (!LikedBy)
//			LikedBy = new object * [10];
//		if (countLikedby < 10)
//		{
//			LikedBy[countLikedby] = ptr;
//			countLikedby++;
//		}
//	}
//	char* getId()
//	{
//		return PostId;
//	}
//	void Addcomments(Comment*& ptr)
//	{
//		if (!Comments)
//			Comments = new Comment * [10];
//		if (totalcomments < 10)
//		{
//			Comments[totalcomments] = ptr;
//			totalcomments++;
//		}
//	}
//	void  viewLikedBy()
//	{
//		for (int i = 0; i < countLikedby; i++)
//		{
//			cout << LikedBy[i]->getID() << "   ";
//			LikedBy[i]->printname();
//			cout << endl;
//		}
//	}
//	void AddComment(object* ptr, char* text)
//	{
//		Comment* c1 = new Comment(ptr, text);
//		Comments[totalcomments] = c1;
//		totalcomments++;
//	}
//	void ViewComments()
//	{
//		for (int i = 0; i < totalcomments; i++)
//		{
//			Comments[i]->ViewComment();
//		}
//	}
//	 void PrintPost()
//	{
//		cout << "-----------------------------------------------------------------" << endl;
//		cout << endl;
//		SharedBy->printname();
//		if (Activity)
//		{
//			Activity->Print();
//		}
//		//	cout << endl;
//		if (!Activity)
//		{
//			cout << "has shared  ";
//		}
//		cout << endl;
//		cout << "\"" << Text << "\"" << endl;
//		cout << endl;
//		cout << "----------Comments---------------" << endl;
//
//		ViewComments();
//	}
//	virtual void Print()
//	{
//		cout << "-----------------------------------------------------------------" << endl;
//		cout << endl;
//		SharedBy->printname();
//		if (Activity)
//		{
//			Activity->Print();
//		}
//		//	cout << endl;
//		if (!Activity)
//		{
//			cout << "has shared  ";
//		}
//		cout << endl;
//		cout << "\"" << Text << "\"";
//		cout << "....";
//		SharedDate.Print();
//		cout << endl;
//		cout << "----------Comments---------------" << endl;
//
//		ViewComments();
//	}
//	Date GetDate()
//	{
//		return SharedDate;
//	}
//	Post(const char* text, object* ptr)
//	{
//		Helper::GetStringFromBuffer((char*)text, Text);
//		Helper::StringCopy((char*)text, Text);
//		SharedBy = ptr;
//		SharedDate = Date::currentDate;
//		char Str[5] = "post";
//		int count = Postcount+1;
//		Postcount++;
//		PostId = Helper::concatenate(count, (char*)Str);
//
//	}
//	void setPostCount(int num)
//	{
//		Postcount = num;
//	}
//
//	~Post()
//	{
//		PostId = 0;
//		Text = 0;
//		SharedDate = 0;
//		Activity = 0;
//		SharedBy = 0;
//		LikedBy = 0;
//		countLikedby = 0;
//		Comments = 0;
//		totalcomments = 0;
//	}
//};
//class pages :public object
//{
//	char* ID;
//	char* Title;
//	Post** PostTimeLine;
//	int postcount;
//public:
//	void ReadDataFromFile(ifstream& fin);
//	//void Print();
//	pages();
//	~pages();
//	void setID(char* id)
//	{
//		Helper::GetStringFromBuffer(id, ID);
//		Helper::StringCopy(id, ID);
//	}
//	char* getID()
//	{
//		return ID;
//	}
//	void printname()
//	{
//		cout << Title << "   ";
//	}
//	void Register(Post* ptr)
//	{
//		if (!PostTimeLine)
//		{
//			PostTimeLine = new Post * [10];
//		}
//
//		PostTimeLine[postcount] = ptr;
//
//		if (ptr != 0)
//		{
//			postcount++;
//		}
//	}
//	void PrintPagesLatest()
//	{
//		for (int i = 0; i < postcount; i++)
//		{
//			Date PostDate = PostTimeLine[i]->GetDate();
//			if (PostDate.Compare(Date::currentDate))
//			{
//				PostTimeLine[i]->PrintPost();
//			}
//		}
//	}
//	void DisplayUserTimeLine()
//	{
//		for (int i = 0; i < postcount; i++)
//		{
//			PostTimeLine[i]->Print();
//			cout << "  ";
//		}
//	}
//};
//class Memory :public Post
//{
//	Post* orignalPost;
//public:
//	Memory(const char* text, object* UserPtr, Post* ptr) :Post(text, UserPtr)
//	{
//		orignalPost = ptr;
//	}
//	void Print()
//	{
//		cout << endl;
//		SharedBy->printname();
//		cout << "         shared a memory ";
//		cout << endl;
//		Date temp = orignalPost->GetDate();
//		cout<<temp.DateDifferences(SharedDate);
//		//cout << SharedDate.DateDifferences(temp);
//	    //orignalPost->SharedDateDateDifferences(SharedDate);
//		cout << "years ago ";
//		/*cout << "-----------------------------------------------------------------" << endl;
//		cout << "<<<<<<<<<<<<<<<<" << getId() << ">>>>>>>>>>>>>>>>>>>>>>>>" << endl;*/
//		SharedDate.Print();
//		//cout << endl;
//		//cout << "<<<<<<<<<<<<<<<<" << SharedBy->getID() << ">>>>>>>>>>>>>>>>>>>>>>>>" << endl;
//		//SharedBy->printname();
//		if (Activity)
//		{
//			Activity->Print();
//		}
//		cout << Text << endl;
//		cout << endl;
//		orignalPost->Print();
//	}
//};
//class User :public object
//{
//	char* ID;
//	char* Fname;
//	char* Lname;
//	int Likedpagescount;
//	pages** LikedPages;
//	int friendscount;
//	User** FriendList;
//	Post** PostTimeLine;
//	int postcount;
//public:
//	void ReadDataForUser(ifstream&);
//	void Likedpage(pages* anypage)
//	{
//		if (!LikedPages)
//			LikedPages = new pages * [10];
//		if (Likedpagescount < 10)
//		{
//			LikedPages[Likedpagescount] = anypage;
//			Likedpagescount++;
//		}
//		else
//			cout << "exceeding Limit pf Liked pages" << endl;
//	}
//	void AddFriends(User* USER)
//	{
//		if (!FriendList)
//		{
//			FriendList = new User * [10];
//		}
//		if (friendscount < 10)
//		{
//			FriendList[friendscount] = USER;
//			friendscount++;
//		}
//	}
//	void ViewFrindList()
//	{
//		for (int i = 0; i < friendscount; i++)
//		{
//			cout << FriendList[i]->ID << "  ";
//			cout << FriendList[i]->Fname << "   " << FriendList[i]->Lname << endl;
//		}
//	}
//	void	ViewLikedBy()
//	{
//		for (int i = 0; i < Likedpagescount; i++)
//		{
//			cout << LikedPages[i]->getID();
//			LikedPages[i]->printname();
//			cout << endl;
//		}
//	}
//	void PrintUser();
//	void setPostCount(int num)
//	{
//		postcount = num;
//	}
//	User();
//	~User();
//	void setID(char* id)
//	{
//		Helper::GetStringFromBuffer(id, ID);
//		Helper::StringCopy(id, ID);
//	}
//	char* getID()
//	{
//		return ID;
//	}
//	void printname()
//	{
//		cout << Fname << "  " << Lname;
//	}
//	void Register(Post* ptr)
//	{
//		if (!PostTimeLine)
//		{
//			PostTimeLine = new Post * [10];
//		}
//		PostTimeLine[postcount] = ptr;
//		if (ptr != 0)
//		{
//			postcount++;
//		}
//	}
//	void DisplayUserTimeLine()
//	{
//		for (int i = 0; i < postcount; i++)
//		{
//			PostTimeLine[i]->Print();
//			cout << "  ";
//		}
//	}
//	void ViewHomePage()
//	{
//		for (int i = 0; i < friendscount; i++)
//		{
//			FriendList[i]->PrintFriendLatest();
//		}
//		for (int i = 0; i < Likedpagescount; i++)
//		{
//			LikedPages[i]->PrintPagesLatest();
//		}
//	}
//	void PrintFriendLatest()
//	{
//		for (int i = 0; i < postcount; i++)
//		{
//			Date PostDate = PostTimeLine[i]->GetDate();
//			if (PostDate.Compare(Date::currentDate))
//			{
//				PostTimeLine[i]->PrintPost();
//			}
//		}
//	}
//	void SharedMemory(const char* text, Post* ptr)
//	{
//		if (postcount < 10)
//		{
//			PostTimeLine[postcount] = new Memory(text, this, ptr);
//			postcount++;
//		}
//	}
//	void SeeMemory()
//	{
//		printname();
//		cout << "has shared a memory : " << endl;
//
//	}
//};
//class Facebook
//{
//	pages** Page;
//	User** user;
//	Post** post;
//	static int totalusers;
//	static int totalPages;
//	static int totalPost;
//	static int totalcomments;
//public:
//	void Load();
//	void LoadUserFromFile();
//	void LoadPagesFromFile();
//	void LoadPostsFromFile();
//	void LoadCommentsFromFile();
//	void Run();
//	static int getTotapost()
//	{
//		return totalPost;
//	}
//	pages* SearchPageById(const char* temp)
//	{
//		for (int i = 0; i < totalPages; i++)
//		{
//
//			if (Helper::Compare(temp, Page[i][0].getID()))
//			{
//				return Page[i];
//			}
//		}
//		return 0;
//	}
//	User* SearchUserById(const char* temp)
//	{
//		char* TempId;
//		for (int i = 0; i < totalusers; i++)
//		{
//			TempId = user[i][0].getID();
//			if (Helper::Compare(temp, TempId))
//			{
//				return user[i];
//			}
//		}
//		return 0;
//	}
//	object* SearchObjectByID(const char* temp)
//	{
//		if (temp[0] == 'u')
//		{
//			return SearchUserById(temp);
//		}
//		if (temp[0] == 'p')
//		{
//			return SearchPageById(temp);
//		}
//		return 0;
//	}
//	Post* SearchPostById(const char* temp)
//	{
//		for (int i = 0; i < totalPages; i++)
//		{
//
//			if (Helper::Compare(temp, post[i][0].getId()))
//			{
//				return post[i];
//			}
//		}
//		return 0;
//	}
//	void ViewPost(const char* str)
//	{
//		Post* ptr = SearchPostById(str);
//		if (ptr != nullptr)
//			ptr->Print();
//	}
//	void ViewLikedList(const char* str)
//	{
//
//		Post* ptr = SearchPostById(str);
//		ptr->viewLikedBy();
//	}
//
//	~Facebook()
//	{
//		if (Page != 0)
//		{
//
//			//cout << "pages destructor called\n";
//			for (int i = 0; i < totalPages; i++)
//			{
//				if (Page[i] != 0)
//				{
//					delete Page[i];
//				}
//			}
//			delete[] Page;
//		}
//		Page = 0;
//
//		if (user != 0)
//		{
//			//cout << "users destructor called\n";
//			for (int i = 0; i < totalusers; i++)
//			{
//				delete user[i];
//			}
//			delete user;
//		}
//		user = 0;
//
//		if (post != 0)
//		{
//			//cout << "posts destructor called\n";
//			for (int i = 0; i < totalPages; i++)
//			{
//				delete post[i];
//			}
//			delete post;
//		}
//		post = 0;
//	}
//};
//int main()
//{
//	Facebook rafay;
//	rafay.Load();
//	rafay.Run();
//}
//int Helper::StringLength(char* Str)
//{
//	int length = 0;
//	for (int i = 0; Str[i] != '\0'; i++)
//	{
//		length++;
//	}
//	return length;
//}
//void  Helper::StringCopy(char* src, char*& dest)
//{
//	if (src != 0)
//	{
//		int len = StringLength(src);
//
//		for (int i = 0; src[i] != '\0'; i++)
//		{
//			dest[i] = src[i];
//		}
//		dest[len] = '\0';
//	}
//}
//void Helper::GetStringFromBuffer(char* Temp, char*& obj)
//{
//	int len = StringLength(Temp);
//	obj = new char[len + 1];
//}
//pages::pages()
//{
//	ID = 0;
//	Title = 0;
//	postcount = 0;
//	PostTimeLine = 0;
//}
//void pages::ReadDataFromFile(ifstream& fin)
//{
//	char Temp[150];
//	fin >> Temp;
//	Helper::GetStringFromBuffer(Temp, ID);
//	Helper::StringCopy(Temp, ID);
//	fin.getline(Temp, 150);
//	Helper::GetStringFromBuffer(Temp, Title);
//	Helper::StringCopy(Temp, Title);
//}
//pages::~pages()
//{
//	if (ID)
//		delete ID;
//	if (Title)
//		delete Title;
//	if (PostTimeLine)
//	{
//		delete[] PostTimeLine;
//	}
//	postcount = 0;
//}
//User::User()
//{
//	ID = 0;
//	Fname = 0;
//	Lname = 0;
//	LikedPages = 0;
//	FriendList = 0;
//	Likedpagescount = 0;
//	friendscount = 0;
//	postcount = 0;
//	PostTimeLine = 0;
//}
//void User::ReadDataForUser(ifstream& fin)
//{
//	char Temp[150];
//	fin >> Temp;
//	Helper::GetStringFromBuffer(Temp, ID);
//	Helper::StringCopy(Temp, ID);
//	fin >> Temp;
//	Helper::GetStringFromBuffer(Temp, Fname);
//	Helper::StringCopy(Temp, Fname);
//	fin >> Temp;
//	Helper::GetStringFromBuffer(Temp, Lname);
//	Helper::StringCopy(Temp, Lname);
//}
//void User::PrintUser()
//{
//	cout << "  " << ID;
//}
//User::~User()
//{
//	if (ID != 0)
//		delete[] ID;
//	if (Fname != 0)
//		delete[] Fname;
//	if (Lname != 0)
//		delete[] Lname;
//	if (LikedPages != 0)
//	{
//		
//		delete[] LikedPages;
//	}
//	if (FriendList != 0)
//	{
//		delete[] FriendList;
//	}
//	if (PostTimeLine)
//	{
//		
//		delete[] PostTimeLine;
//	}
//	postcount = 0;
//}
//void Facebook::Run()
//{
//	Date::CurrentDate(15, 11, 2017);
//	cout << "Command:\tSet current System Date 15 11 2017 \n";
//	cout << "System Date:\t";
//	Date::PrintDate();
//	cout << "Command:\t Set Curerent User \"u7\"" << endl;
//
//	User* currentUser = SearchUserById("u7");
//	currentUser->printname();
//	cout << " successfully set as Current User\n";
//	cout << endl << endl;
//	cout << "Command:\tView Friends List \n";
//	cout << "-----------------------------------------------------------------------------------------\n";
//	currentUser->printname();
//	cout << "-Friend List\n";
//	currentUser->ViewFrindList();
//	cout << endl << endl;
//	cout << "Command:\tView Liked Pages\n";
//	cout << "-----------------------------------------------------------------------------------------\n";
//	currentUser->printname();
//	cout << "-Liked Pages\n\n";
//	currentUser->ViewLikedBy();
//	cout << "-----------------------------------------------------------------------------------------\n";
//	cout << endl << endl;
//	cout << "Command:\tView Home \n";
//	cout << "-----------------------------------------------------------------------------------------\n";
//	currentUser->printname();
//	cout << "-HomePage\n\n";
//
//	currentUser->ViewHomePage();
//	cout << endl << endl;
//	cout << "Command:\tView Timeline \n";
//	cout << "-----------------------------------------------------------------------------------------\n";
//	currentUser->printname();
//	cout << "-TimeLine\n\n";
//	currentUser->DisplayUserTimeLine();
//	cout << "-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView LikedList (post5) \n";
//	ViewLikedList("post5");
//
//	cout << "-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\t Like(post5) \n";
//
//	char PostId[10] = "post5";
//	Post* post = SearchPostById(PostId);
//	post->SetLikedBy(currentUser);
//	cout << "-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView LikedList (post5) \n";
//	ViewLikedList("post5");
//	cout << "-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tPost Comment(post4,Good Luck For your Result)  \n";
//	/*char commentText[100] = "Good Luck For your Result";
//	post = SearchPostById("post4");
//	post->AddComment(currentUser, commentText);*/
//	ViewPost("post4");
//	cout << "\n-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tPost Comment(post8,Thanks For The wishes)  \n";
//	//AddComment("post8", "Thanks For The wishes");
//	char commentText[100] = "Thanks For The wishes";
//	post = SearchPostById("post8");
//	post->AddComment(currentUser, commentText);
//	ViewPost("post8");
//	cout << "\n-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tSee Your Memories()\n";
//	post = SearchPostById("post10");
//	currentUser->SharedMemory("Never thought I will be specialist in this field...",post);
//	cout << "\n-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tShare Memory(post10,Never thought I will be specialist in this field...) \n";
////	Memory("post10", "Never thought I will be specialist in this field...", currentUser);
//	cout << "Command:\tView Timeline \n";
//	currentUser->printname();
//	/**/cout << "-TimeLine\n\n";
//	currentUser->DisplayUserTimeLine();
//	cout << "\n-----------------------------------------------------------------------------------------\n";
//	cout << "Command:\tView Page(\"p1\" ) \n";
//	pages* currentpage = SearchPageById("p1");
//	currentpage->DisplayUserTimeLine();
//	cout << "\n----------------------------------------------------------------------------------------\n";
//	cout << "Command:\t Set Curerent User \"u11\"" << endl;
//
//	 currentUser = SearchUserById("u11");
//	currentUser->printname();
//	cout << " successfully set as Current User\n";
//	cout << endl << endl;
//	currentUser->ViewHomePage();
//	currentUser->DisplayUserTimeLine();
//}
//void  Facebook::LoadPagesFromFile()
//{
//	ifstream fin;
//	fin.open("PagesFile.txt");
//	int TotalPages;
//	fin >> TotalPages;
//	totalPages = TotalPages;
//	Page = new pages * [TotalPages];
//	for (int i = 0; i < TotalPages; i++)
//	{
//		Page[i] = new pages;
//		Page[i]->ReadDataFromFile(fin);
//	}
//	fin.close();
//}
//void  Facebook::LoadUserFromFile()
//{
//	ifstream fin;
//	fin.open("UserFiles.txt");
//	int TotalUser;
//	fin >> TotalUser;
//	totalusers = TotalUser;
//	user = new  User * [TotalUser];
//	char*** RestDataofUser = new char** [TotalUser];
//	for (int i = 0; i < TotalUser; i++)
//	{
//		user[i] = new User;
//		user[i][0].ReadDataForUser(fin);
//		RestDataofUser[i] = new char* [10];
//		char Data[50];
//		for (int j = 0; j < 10; j++)
//		{
//			fin >> Data;
//			if (Data[0] == '-' && Data[1] == '1')
//			{
//				int len = Helper::StringLength(Data);
//				RestDataofUser[i][j] = new char[len + 1];
//				Helper::StringCopy(Data, RestDataofUser[i][j]);
//				break;
//			}
//
//			int len = Helper::StringLength(Data);
//			RestDataofUser[i][j] = new char[len + 1];
//			Helper::StringCopy(Data, RestDataofUser[i][j]);
//		}
//		for (int j = 0; j < 10; j++)
//		{
//			fin >> Data;
//			if (Data[0] == '-' && Data[1] == '1')
//			{
//				break;
//			}
//			user[i][0].Likedpage(SearchPageById(Data));
//		}
//	}
//	for (int i = 0; i < TotalUser; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (RestDataofUser[i][j][0] == '-' && RestDataofUser[i][j][1] == '1')
//			{
//				break;
//			}
//			user[i][0].AddFriends(SearchUserById(RestDataofUser[i][j]));
//		}
//	}
//	for (int i = 0; i < TotalUser; i++)
//	{
//		for (int j = 0; j < 10; j++)
//		{
//			if (RestDataofUser[i][j][0] == '-' && RestDataofUser[i][j][1] == '1')
//			{
//				delete[] RestDataofUser[i][j];
//				break;
//			}
//			delete[] RestDataofUser[i][j];
//		}
//		delete[] RestDataofUser[i];
//	}
//	delete[] RestDataofUser;
//}
//void Facebook::LoadPostsFromFile()
//{
//	ifstream fin;
//	char temp[200];
//	fin.open("Posts.txt");
//	fin >> totalPost;
//
//	post = new Post * [totalPost];
//	
//	for (int i = 0; i < totalPost; i++)
//	{
//		if (i == 0)
//		{
//			post[i]->setPostCount(totalPost);
//		}
//		post[i] = new Post;
//		
//		post[i]->ReadPost(fin);
//		fin >> temp;
//		object* ptr = SearchObjectByID(temp);
//		post[i]->SetSharedBy(ptr);
//		ptr->setobjId(temp);
//		ptr->Register(post[i]);
//		do
//		{
//			fin >> temp;
//			if (temp[0] == '-' && temp[1] == '1')
//				break;
//			ptr = SearchObjectByID(temp);
//			post[i]->SetLikedBy(ptr);
//		} while (1);
//	}
//	fin.close();
//}
//void Facebook::LoadCommentsFromFile()
//{
//	ifstream fin;
//	fin.open("Comments.txt");
//	fin >> totalcomments;
//	char Temp[200];
//	for (int i = 0; i < totalcomments; i++)
//	{
//		char ID[5];
//		Comment* ptr = new Comment;
//		fin >> ID;
//		fin >> Temp;
//		Post* post = SearchPostById(Temp);
//		fin >> Temp;
//		object* TempPtr;
//		TempPtr = SearchObjectByID(Temp);
//		TempPtr->setobjId(Temp);
//		char temp[200];
//		fin.getline(temp, 200, '/');
//		ptr->SetAllValues(ID, temp, TempPtr);
//		post->Addcomments(ptr);
//	}
//	fin.close();
//}
//void Facebook::Load()
//{
//	LoadPagesFromFile();
//	LoadUserFromFile();
//	LoadPostsFromFile();
//	LoadCommentsFromFile();
//}
//Date::Date(int Date, int Month, int Year)
//{
//	date = Date;
//	month = Month;
//	year = Year;
//}
//void Date::Print()
//{
//	cout << date << "/" << month << "/" << year << endl;
//}
//void Date::ReadDateFromFile(ifstream& fin)
//{
//	fin >> date;
//	fin >> month;
//	fin >> year;
//}
//Post::Post()
//{
//	PostId = 0;
//	Text = 0;
//	Activity = 0;
//	SharedBy = 0;
//	LikedBy = 0;
//	countLikedby = 0;
//	totalcomments = 0;
//	Comments = 0;
//}
//void Post::ReadPost(ifstream& fin)
//{
//	int Type;
//	fin >> Type;
//	char Temp[200];
//	fin >> Temp;
//	
//	Helper::GetStringFromBuffer(Temp, PostId);
//	Helper::StringCopy(Temp, PostId);
//	SharedDate.ReadDateFromFile(fin);
//	fin.getline(Temp, 200, '/');
//	Helper::GetStringFromBuffer(Temp, Text);
//	Helper::StringCopy(Temp, Text);
//	if (Type == 2)
//	{
//		Activity = new activity;
//		Activity->ReadDataFromFile(fin);
//	}
//}
//int Facebook::totalusers = 0;
//int Facebook::totalPages = 0;
//int Facebook::totalPost = 0;
//int Facebook::totalcomments = 0;
//int object::postcounter = 0;
//Comment::Comment(object* commentBy, char* text)
//{
//	Helper::GetStringFromBuffer(text, Text);
//	Helper::StringCopy(text, Text);
//	CommentBy = commentBy;
//	char* str1 = new char[2];
//	str1[0] = 'c';
//	str1[1] = '\0';
//	ID = Helper::concatenate(TotalComments + 1, (char*)str1);
//	TotalComments++;
//
//}
//int Comment::TotalComments = 0;
//Date Date::currentDate = Date();
//int Post::Postcount = 0;