
//������ ����������� (��� 425 ������ �)




//����������� ������� +=(-=) � �.� ����� ��������� this

Sales_data &Sales_data::combine(const Sales_data &rsh) //���������� ������� ������� ������ ��� ������ �� ����� (������������ ������� �� ���������� ���
{														//��� ��������� �� ��� ���������
	units_sold += rsh.units_sold  //��������� �������� � ������� � ��������� ������� ������ �� ������� ��������� this ���������� �������� ������� rsh
	return *this 	//���������� ��������� �� ������� �����(� ����� ������ total)
}
total.combine(some) //��� �������� ������� ������ some ������ Sales-data  � ���������  this � ���� ������ ����� ��������� �� total � � ��� ��� �����


//��������� ������ ������� ��������������� ����� ���� ������


Sales_data add(const Sales_data& one,const Sales_data& two)
{
	Sales_data sum=one; //����������� ���������� ������ one � sum
	sum.combine(two); // ���������� �������� two � sum
	return sum;
}

//��� ������ const � ����� �������?
std::string Sales_data::func() const
{
	return String;
}
// ����� ������������ ��������� this ������� ��������� �� ������� �����.�� ��������� �� ��������� ��� ������������ ���������
// Sales_data const* this,��� ������ ��� ������ �������� ������ ��������.���� �� ����� ����� ��������� �������� �� ����������� ����� �� �� ����� �
//����� const (��������� ������:std::string Sales_data::func(const Sales_data const* this) �� ��� ��� ������ ��� ������ �� �� ������ ������ ����� � �����)



//������ � �������� ����� � ������

istream &read(istream &in,Sales_data &item) //������ ������ �� ������ � ������
{
	in>>item.some; //������.���������� ����� ���� ������� ������
	return in;

}
//������ �������������: read(cin,classObject)

ostream &print(ostream &of, const Sales_data item)
{
	of<<item.some;
	return os;
}
//������ �������������: print(cout,classObject)
//��� ������� �������� ������ �� ����� �����\������ ��� ��� ��� ������� �� ����� ���� �����������.��� ������������.
//��� �� ��������� ��� ��� ��������� � ��������


//������������� ������������
Constructor(std:string &s, unsigned int n, double d):
			Book(s),number(n),cost(d*n) {}
//�������������� ������ �������� ������ � ������������ � ��� �������� ��� � ������� ������� ���� ������ ������.
Constructor(std:string &s):
			Book(s),number(0),cost(0) {} //�������� � ����� �������



//������������� ������� ����
class Screen
{
	//����� Window ������ ���� �������� ����� screen
	friend void Window_mgr::clear(screenIndex);
			}



//������������ �����������(���������� ��� ������������� ������ �����������)

class Sale
{
  Sale(std:string &s, unsigned int n, double d):
				Book(s),number(n),cost(d*n) {}
	Sale():Sale(" ",0,0){} //���������� ���������� ����������� ��� �������������
	Sale(std::string s):Sale(s,0,0){}
	Sale(std::istream &is):Sale(){ read(&is,*this) } //���������� ��� ������������� ����������� ��� ���������� ������� � ���� ������� ����������
	 //����������� � 3 �����������,��� ������ ���������� ��� ��� ������������� ���������� ������� read.
	}

//explicit ������������ ����� ������� ������ ����� ���� ���������  ������ ����

explicit Sale(double one):value(one){}
//��
Sale obj(10); // ����� (����� ����������)
Sale obj=10; // �����(�������)
//�����
Sale obj(10); // �����
Sale obj=10; // ������ ������



//static

class Sale
{
	private:
		static double one;
		static double rate(){
			//some code
		}
	}
//static ����������� ������������ ����� ����� ��� �� ���������� �������������� ���� ��� ���� �������� (���������� one ��� ������ ������� ������
// ����,� �� � ������� ���� ��������� ��� �����)
// �������-����� �� ������ � ���������� �������� � �� ����� ��������� this
//���������� � ����������� ������ ����� ��� � ������ ����������.



/////////////////////���������� ������� ����� ������///////////////////////


//istringstream  ��������� � �������� �������
//ostringstream  � ������������ �������
//sstringstream  � ��������� � ����������
istringstream record(line)
//������ record �������� ������� ����� �� ����� ��� ������ line
//����� ��� ������ � ����� �������� ��� morgan 9099233 231321 232332
//���������
while(getline(cin,line)) //������� ������ �� �����
	istringstream record(line); // ��������� ����� � ������ ������
	Person info; // ������� ������
	record>>info.name; // �������� ���
	while(record>>word) //
		info.phones.push_back(word); //� ����� �������� � ������ ��� ������
		 people.push_back(info);// ������� � ������ ����� �������� (��� 418 ������ �)

istream_iterator<T> in(is)// in ������ �������� ���� � �� ������ is
istream_iterator<T> end //�������� ����� ���  istream_iterator<T> in(is)

istream_iterator<int> in_iter(cin);// ������ ����� �� ������
istream_iterator<int> eof;//�������� �����
while (in_iter != eof)// ���� �� ��������� �����
	vec.push_back(*in_iter++);// ����������� �������� �� 1,�� � ������� ���������� ����������

ostream_iterator<int> out_iter(cout, " ");// ��������� �������� � ������� ������
for(auto e : vec)
	*out_iter++ = e;// ������� �������� ������� vec  ����� ������
cout<<endl;



//������ � �������

ios::app //�������� ���� ����� � ����� �����
ios::ate // ������� ���� ��� ����� � ������������� � �����
ios::in // ������� ���� ��� �����
ios::out // ������� ���� ��� ������(��� ���������� ������ ���������)
ios::trunc // ��������� ���������� �����
ios::binary	 //	 ������� ���� ��� ��������� ����� ������
ofstream outFile("cliend.txt",ios::out)



//////////////////////////////////////////////����������////////////////////////////////////////////

//�����������
vector<int> mas;
vector<int > mas;
vector<vector<int>> mas;
list<string>::iterator it; //���������� ���������(�� ������������  � ��������� �����������)
value_type;//������������ ��� ����������� ���� �������� ����������
reference==value_type&;
const_reference==const value_type&
list<string> a = {"dsfh","dsf"};
auto it1 = a.begin(); //list<string>::iterator
auto it2 = a.rbegin(); //list<string>::reverse_iterator
auto it3 = a.cbegin(); //list<string>::const_iterator
auto it4 = a.crbegin(); //list<string>::const_reverse_iterator
array<int,42> ia1;//������ �� 42 int
array<int,42>::size_type j;
swap(c1,c2)
c1.swap(c2) //���������� �������� ��������.������� �����������

//assign ������������ ���������� ������,�� ����������� ����� ���
//���������� ����������� �������������������
list<string> names;
vector<const char*> old;
names.assign(old.cbegin(),old.cend())

//������ ������ ������������ ���������
vector<int> vec = {0,1,2,3,4,5};
for (auto r_iter = vec.crbegin();
			r_iter != vec.crend();
				++r_iter)//����� ��������� �� 1 ������� (5,4,3,2,1,0)
		cout<<*r_iter<<endl;


//��������� ������ � ���������� ������� < > == !=  � �.�.��� ����� ��������� ���� ��� 2 ����������,(��� 497 ������)
//���� ��� ����� ������ ���������� ������������ ������ ���������
//������-���������
// ���������� [������ �������] (������ ���������) -> ��� ������������ �������� {���� �������}
auto f=[] {return 42;} //������ ���������� � ���� ������������� �������� ����� �������������
//����� ��������� ����� ���� ���������� � �������(� ������� �� ������� �������)
[](const string& a,const string& b)//������ ������ �������� �������� ��� ����� �� ���������� ��������� ��������� �� ���������� �������
{return a.size()<b.size();}

stable_sort(words.begin(),word.end(),
			[](const string &a,const string &b)
							{return a.size()<b.size();})
//������ � ��� � ������� ���� ���������� sz ������� �������� ������ ������
//�������� �������� �� ������ �������,������ �������� ������ ��� ����� 	sz
auto wc=find_if(words.begin(),words.end(),
					[sz](const string& a)
						{return a.size()>=sz};)

void fnc1()
{
	size_t v1 = 42;
	auto f = [v1]{return v1;};//����� ��������� ����������� ���������� v1(��������� ����������� �����
	//� �������  ����� v1 �������� ��������� )
	v1 = 0;
	auto j = f(); // j=42 �.� � ������ ��� ���� ����� v1 � ���������� ����� v1 �� ��� �� ������
}
//���������� ����� ����� ����������� �� ������(�������� ��� ������� ������)
auto f = [&v1]{return v1;};


// � ���������� ������� ����� ������� ���������� �������� ������� _if
//������� �������� ��������� _copy
reverse_copy(beg,end,des);// �������� ������������ ������ � des

// ������������� ����������
// map ������� �������
map<string, size_t> word_count; //������ ����� ����� � �����
string word;
while (cin >> word)
	++word_count[word]; //�������� � ���������� ������� ����
for (const auto &w: word_count)
	cout<< w.first << "occus" << w.second
		<< ((w.second > 1) ? "times" : "time") << end;

// ��������� �������������
map<string, string> autors = { {"James","Jade"},
								{"Austen", "Jane"}};

//set ��� �����
map<string, size_t> word_count;
set<string> ex= {"The","But","And",
					"the","and","but"};

string word;
while (cin >> word)
	if (ex.find(word)==ex.end())//���� �������� find �� ������ ����� �� ������ �������� �������� ������� ��� ����� ���������
		++word_count[word];
//multimap multiset �� ����� ����������� �� �������� ����������� ������ �����



//��������������� ��������� <memory>

shared_ptr<string> p1;//��������� �� ������(��������� ���������� ���������� ��������� �� 1 ������)
unique_ptr<string> p2;
//���� ��������� �� ������� � �� ��������� �� ������ ������
if (p1 && p1->empty())
        *p1="hi";

make_shared<T>(args)//���������� ��������� shared_ptr ��
//����������� ��������� ������ ���� �.��������� args ��������
//���� ��� ������������� ������������ �������

shared_ptr<int> p3 = make_shared<int>(42);//��������� �� 42
shared_ptr<string> p4 = make_shared<string>(10,'9');//��������� �� ������ 99999999
shared_ptr<int> p5 = make_shared<int>();//��������� �� 0
//�������� ������� ������������� ������������ ������-���������� ������������� ����� � ��� �� ������ ������ ���������

//��������� ������������ ��������� new
int *pi = new int(1024);
string *ps = new string(10, '9');
vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7};
//const int
const int *pci = new const int(1024);
//const string
const string *pcs = new const string;
//��� ���������� ������ ����� new �� ���������� ����������
int *p2 = new (nothrow) int;
//������������ ������
delete p2;
delete [] p2;//���� ��������� �� ������
shared_ptr<int> p1(new int(1024))//������������ ������ ����� ��������
p1.reset()//����������� ���������
p1.reset(q)//�1 ����� ���������� �� q

unique_ptr<int> p2(new int(42));
p2.reset();
p2.reset(q);
unique_ptr<string> p3(new string("Trex"));
unique_ptr<string> p2.reset(p3.release());//�������� ������������� �� �3  � �2

int *pia = new int[10];
int *pia2 = new int[10]();//default 0
int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};



/////////////////////////������///////////////////////////////////////////////////

//����������� �����
//���� ������ �������� ������ �� ��� ������ � ��� ��������� ��������� �� ��������� �� ��� ����������� �����
class Foo {
public:
    Foo(); //����������� �����������
    Foo(const foo&); //����������� �����
};
������
Foo::Foo(const Foo& orig):
    bookNo(orig.bookNo),
    units_sold(orih.units_sold),
    revenue(org.revenue) {}
string s(dots); //������ �������������
string s2=dots; //������������� ������




/////////////////////������ ����������� ������������ �������//////////////////////////////////////////////////

��������� ����� StrVec ������� �� VECTOR(������ ��� 666)

class StrVec:
{
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);//����������� �����
    StrVec&operator=(const StrVec&);//���������� �����
    ~StrVec();//����������
    void push_back(const std::string&);//�������� �������
    size_t size() const{return first_free-elements;}//�������� �� ���������� ���������
    size_t capacity() const {return cap-elements;}//���������� ��������� ��������� ������� ���������� � ������
    std::string *begin() const { return elements;}//���������� ��� �������� �� ������ �������
    std::string *end() const { return first_free};//�������� �� ����� �������
private:
    std::allocator<std::string> alloc;//����������� ��������,����������� ���������� ������� ��������� ��������
    void chk_n_alloc() //��������� ������ �� ��������� ������������ � ����������� ������ ��� ������ ������������
        {if (size() == capacity()) reallocate();}
        std::pair<std::string*,std::string*> alloc_n_copy
                    (const std::string*, const std::string*);
    void free();//������� �������� � ����������� ������������
    void reallocate();//����������� ������ ����� � �������� ���������� ��������
    std::string *elements;//��������� �� ������ ������� �������
    std::string *first_free;//��������� �� ������ �������� ������� �������
    std:;string *cap;//��������� �� ������� ����� ����� �������

};

void StrVec::push_back(const string& s)
{
    chk_n_alloc();//������������� � ������� ����� ��� ��������

    //������� ������ s � ����� �� ������� ��������� ��������� firs_free
    alloc.construct(first_free++, s);//
    //
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    //������� ����������� ������������ ��� ���������� ��������� ��������� e-b(a.allocete(n))
    auto date = alloc.allocate(e-b);


    //������� ����� ���������� ������ �������� � �������(�++11)
    //uninitialized_copy(b, e, data) �������� ������� �� ��������� e-b � ������������� ������ data.
    return {data, uninitialized_copy(b, e, data)};//data ����� ���������� �� ������ ����������������� ������ � ������ ������� �� ���� ��������
}

void StrVec::free()
{
    if(elements)//�� ������ �� ������
    {
        for(auto p= first_free; p != elements;)// ���������� �� ���� ��������� �� ���������� � �������
            alloc.destroy(--p);//������� ��
        alloc.deallocate(elements, cap - elements);//����������� ��� ���������� ������
    }
}

StrVec::StrVce(const StrVec &s)
{

    //����� ������� alloc_n_copy ��� �������������� ���������� �������
    //��� � s
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;//
    first_free = cap = newdata.second;//

}


StrVec &StrVec::operator=(const StrVce &rhs)
{
    auto data = alloc_n_cope(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;

}

StrVec::~StrVec()
{
    free();
}

void StrVec::reallocate()
{
    //����������� ������ ������ ������(����������) � ���� ���� ����������� 1 �������
    auto newcapacity = size() ? 2* size() : 1;
    //���������� ����� ������
    auto newdata = alloc.allocate(newcapacity);//a.allocate(n)
    //���������� ������ �� ������� ������ � �����
    auto dest = newdata;//��������� �� ���� ��������� ������� � ����� �������
    //
    auto  elem= elements;//��������� �� ��������� ������� � ������ �������
    //
    for(size_t i = 0; i != size(); ++i)//��� ���������� �� ���� ��������
        alloc.construct(dest++,std::move(*elem++));//� ���������� �� � ������� move
    free();//����������� ������
    //
    elemebts = newdata;
    frist_free = dest;
    cap = elements + newcapacity;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////������ &&/////////////////////////////////////////
//� ������� �� ������� ������ ��������� �� r-��������

int &&r = 42;
int i = 10;
int &&rr = i*2;

//��� �� ������������ ��� �����������

int &&tt1 = std::move(rr1);


////////////����������� �����������/////////////////////////

StrVec::StrVec(StrVec &&s) noexcept //����������� �� ����� ���������� ����������
    :elements(s.elements), first_free(s.first_free), cap(s.cap)
    {
        s.elments = s.first_free = s.cap = nullptr;//�������� s � ��������� ��� ������� ������ ����������� ����������

    }


 ///////////���������� ��� ������������///////////////////////////////////
StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free= rhs.first_free;
        cap = rhs.cap;
        rhs.elements=rhs.first_free=rhs.cap=nullptr;
    }
    return *this;
}

//////////////���������� �������////////////////////////


/////////////���������� ������ ������
ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " "<< item.units_sold <<  " "
        << item.revenue << " " <<item.avg_price();
        return os;
}

//////���������� ������ �����
istream &operator>>(istream &is, Sales_data &item)
{

    double price;
    is>> item.bookNo >> item.units_sold >> price;
    if (is) //��������� ����� ����� ������
        item.revenue = item.units_sold  * price;
    else
        item = Sales_data(); //���� ��������:������� ������ � ����������� ���������

    return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;//���������� ���������� � sum
    sum += rhs;//�������� rhs � sum
    return rhs;

}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() ==  rhs.isbn();

}
//////////������������ ��� FUNCTION////////////////(Stenli 744)
////��� ������ � ������� ���� ��������� ��������� �������
function<int(int,int)> f1 = add; //��������� �� �������
function<int(int,int)> f2 = div(); //������ ������ ������� �������
 function<int(int,int)> f3 = [](int i,int j)// ����� ���������
                                    { return i*j};

cout<< f1(4,2) << endl; // ������� 6
cout<< f2(4,2) << endl;// 2
cout<< f2(4,2) << endl;// 9

///////����������� �������� ������/////////

class Quote{

public:
    Quote() = default;//(page 345)
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const {return bookNo;}

    virtual double net_price(std::size_t n) const //virtual ������������ ��� �������������� ���� �������
            { return n*price} //� �������� ������
    virtual ~Quote() = default;

private:
    std::string bookNo;
protected:
    double price = 0.0;

} ;

///////����������� ������������ ������//////
class Bulk_quote : public Quote {
    Bulk_quote() = default;
    Bulk_auote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;//override ������� ����� ������� ����������������
private:
    std::size_t min_qty = 0;
    double discont = 0.0;
};
//��� ����������� ���������� �������� ������ ���������� �������� ����������� � ������� ������������
Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
            Quote(book,p), min_qty(qty), discont(disc) {}

Qoute item;
Bulk_quote bulk;
Quote *p = &item;// p ��������� �� ������ Quote
p = &bulk;// p ��������� �� ����� bulk ������� Quote
Quote &r = bulk;//r ������ � ����� bulk ������� Quote


