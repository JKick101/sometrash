
//МЕТОДЫ КОНТЕЙНЕРОВ (Стр 425 Стенли Б)




//Определение функций +=(-=) и т.д через указатель this

Sales_data &Sales_data::combine(const Sales_data &rsh) //Определяем функцию которая вернет нам ссылку на класс (передаваемая функция не изменяется так
{														//что объявляем ее как константу
	units_sold += rsh.units_sold  //выполняем сложение в котором к параметру объекта класса на который указывает this прибавляем параметр объекта rsh
	return *this 	//возвращаем указатель на текущий класс(в нашем случае total)
}
total.combine(some) //тут передаем функции объект some класса Sales-data  а указатель  this в этом методе будет ссылаться на total т к это его метод


//Получение нового объекта представляющего сумму двух других


Sales_data add(const Sales_data& one,const Sales_data& two)
{
	Sales_data sum=one; //копирование параметров класса one в sum
	sum.combine(two); // добавление значений two к sum
	return sum;
}

//что значит const в конце функции?
std::string Sales_data::func() const
{
	return String;
}
// здесь используется указатель this который указывает на текущий класс.По умолчанию он определен как каонстантный указатель
// Sales_data const* this,что значит что данный казатель нельзя изменить.если мы хотим чтобы указатель указывал на константный класс то мы пишем в
//конце const (наглядный пример:std::string Sales_data::func(const Sales_data const* this) но так как писать так нельзя то мы просто ставим конст в конце)



//методы с потоками ввода и вывода

istream &read(istream &in,Sales_data &item) //читает данные из потока в объект
{
	in>>item.some; //чтение.параметров может быть сколько угодно
	return in;

}
//пример использования: read(cin,classObject)

ostream &print(ostream &of, const Sales_data item)
{
	of<<item.some;
	return os;
}
//пример использования: print(cout,classObject)
//Обе функции получают ссылки на поток воода\вывода так как эти объекты не могут быть копированны.они единственные.
//они не константы так как измеяются в процессе


//Инициализатор конструктора
Constructor(std:string &s, unsigned int n, double d):
			Book(s),number(n),cost(d*n) {}
//инициализирует каждый параметр класса в соответствии с тем значение что в скобках поэтому тело фукции пустое.
Constructor(std:string &s):
			Book(s),number(0),cost(0) {} //возможен и такой вариант



//дружественная функция член
class Screen
{
	//класс Window должен быть объявлен перед screen
	friend void Window_mgr::clear(screenIndex);
			}



//делегирующий конструктор(использует для инициализации другой конструктор)

class Sale
{
  Sale(std:string &s, unsigned int n, double d):
				Book(s),number(n),cost(d*n) {}
	Sale():Sale(" ",0,0){} //использует предыдущий конструктор для инициализации
	Sale(std::string s):Sale(s,0,0){}
	Sale(std::istream &is):Sale(){ read(&is,*this) } //использует для инициализации конструктор без параметров который в свою очередь использует
	 //конструктор с 3 параметрами,как только произойдет вся эта инициализация выполнится функция read.
	}

//explicit используется чтобы объекты класса можно было объявлять  только явно

explicit Sale(double one):value(one){}
//до
Sale obj(10); // можно (явное объявление)
Sale obj=10; // можно(неявное)
//после
Sale obj(10); // можно
Sale obj=10; // теперь нельзя



//static

class Sale
{
	private:
		static double one;
		static double rate(){
			//some code
		}
	}
//static обозначение используется когда нужно что бы переменная использовалась одна для всех объектов (переменная one для любого объекта класса
// одна,а не у каждого свой экземпляр как обыно)
// функций-члены не связна с конкретным объектом и не имеют указателя this
//обращаться к статическим членам можно как к обыным переменным.



/////////////////////СВЯЗЫВАНИЕ ПОТОКОВ ВВОДА ВЫВОДА///////////////////////


//istringstream  связывает с читаемой строкой
//ostringstream  с записываемой строкой
//sstringstream  и считывает и записывает
istringstream record(line)
//теперь record является потоком вывод из файла для строки line
//пусть эта строка в файле выглядит как morgan 9099233 231321 232332
//обработка
while(getline(cin,line)) //считали строку из файда
	istringstream record(line); // привязали поток к данной строке
	Person info; // создали объект
	record>>info.name; // записали имя
	while(record>>word) //
		info.phones.push_back(word); //в цикле записали в вектор все номера
		 people.push_back(info);// занесли в вектор этого человека (стр 418 Стенли Б)

istream_iterator<T> in(is)// in читает значения типа Т из потока is
istream_iterator<T> end //итератор конца для  istream_iterator<T> in(is)

istream_iterator<int> in_iter(cin);// читает числа из потока
istream_iterator<int> eof;//итератор конца
while (in_iter != eof)// пока не достигнут конец
	vec.push_back(*in_iter++);// увеличивает итератор на 1,но в функцию возвращает предыдущий

ostream_iterator<int> out_iter(cout, " ");// связывает итератор с потоком вывода
for(auto e : vec)
	*out_iter++ = e;// выводит элементы вектора vec  через пробел
cout<<endl;



//РАБОТА С ФАЙЛАМИ

ios::app //дописать весь вывод в конец файла
ios::ate // открыть файл для вывод и переместиться в конец
ios::in // открыть файл для ввода
ios::out // открыть файл для вывода(все предыдущие данные сотруться)
ios::trunc // отбросить содержимое файла
ios::binary	 //	 открыть файл для двоичного ввода вывода
ofstream outFile("cliend.txt",ios::out)



//////////////////////////////////////////////КОНТЕЙНЕРЫ////////////////////////////////////////////

//определение
vector<int> mas;
vector<int > mas;
vector<vector<int>> mas;
list<string>::iterator it; //объявление итератора(не используется  с операцией денкремента)
value_type;//используется для обозначения типа элемента контейнера
reference==value_type&;
const_reference==const value_type&
list<string> a = {"dsfh","dsf"};
auto it1 = a.begin(); //list<string>::iterator
auto it2 = a.rbegin(); //list<string>::reverse_iterator
auto it3 = a.cbegin(); //list<string>::const_iterator
auto it4 = a.crbegin(); //list<string>::const_reverse_iterator
array<int,42> ia1;//массив из 42 int
array<int,42>::size_type j;
swap(c1,c2)
c1.swap(c2) //обменивает элементы объектов.быстрее копирования

//assign обеспечивает присвоение разных,но совместимых типов или
//присвоение контейнерам последовательностей
list<string> names;
vector<const char*> old;
names.assign(old.cbegin(),old.cend())

//пример работы реверсивного итератора
vector<int> vec = {0,1,2,3,4,5};
for (auto r_iter = vec.crbegin();
			r_iter != vec.crend();
				++r_iter)//емент итератора на 1 элемент (5,4,3,2,1,0)
		cout<<*r_iter<<endl;


//ПРЕДИКАТЫ служат в алгоритмах заменой < > == !=  и т.д.ОНи могут принимать один или 2 аргуметнта,(стр 497 Стенли)
//если нам нужно больше аргументов используются лямбда выражения
//лямбда-выражения
// объявление [список захвата] (список парамеров) -> тип возращаемого значения {тело функции}
auto f=[] {return 42;} //список параметров и типа возвращаемого значения могут отсутствовать
//лябда выражения могут быть определены в функции(в отличии от обычных функций)
[](const string& a,const string& b)//пустой список захватат означает что лябда не использует локальных перменных из окружающей функции
{return a.size()<b.size();}

stable_sort(words.begin(),word.end(),
			[](const string &a,const string &b)
							{return a.size()<b.size();})
//Пускай у нас в функции есть переменная sz которая содержит размер строки
//получить итератор на первый элемент,размер которого больше или равен 	sz
auto wc=find_if(words.begin(),words.end(),
					[sz](const string& a)
						{return a.size()>=sz};)

void fnc1()
{
	size_t v1 = 42;
	auto f = [v1]{return v1;};//лябда выражение захватывает переменную v1(создается специальный класс
	//в котором  КОПИЯ v1 является атрибутом )
	v1 = 0;
	auto j = f(); // j=42 т.к в лямбде уже есть копия v1 и мзменнения самой v1 на нее не влияют
}
//переменный также можно захватывать по ссылке(работает как обычная ссылка)
auto f = [&v1]{return v1;};


// у алгоритмов которые имеют входным параметром предикат имеется _if
//которые копируют результат _copy
reverse_copy(beg,end,des);// копирует перевернутый вектор в des

// ассоциативные контейнеры
// map создает словарь
map<string, size_t> word_count; //пустая карта строк и часел
string word;
while (cin >> word)
	++word_count[word]; //получить и прирастить счетчик слов
for (const auto &w: word_count)
	cout<< w.first << "occus" << w.second
		<< ((w.second > 1) ? "times" : "time") << end;

// списочная инициальзация
map<string, string> autors = { {"James","Jade"},
								{"Austen", "Jane"}};

//set это набор
map<string, size_t> word_count;
set<string> ex= {"The","But","And",
					"the","and","but"};

string word;
while (cin >> word)
	if (ex.find(word)==ex.end())//если алгоритм find не найдет слово он вернет конечный итератор поэтому тут такое сравнение
		++word_count[word];
//multimap multiset не имеют ограничений на значения присвоенные одному ключу



//ИНТЕЛЕКТУАЛЬНЫЕ УКАЗАТЕЛИ <memory>

shared_ptr<string> p1;//указывает на строку(позволяет нескольким указателям ссылаться на 1 объект)
unique_ptr<string> p2;
//если указатель не нулевой и не указывает на пустую строку
if (p1 && p1->empty())
        *p1="hi";

make_shared<T>(args)//возвращает указатель shared_ptr на
//динамически созданный объект типа Т.Аргументы args использу
//ются для инициализации создаваемого объекта

shared_ptr<int> p3 = make_shared<int>(42);//указатель на 42
shared_ptr<string> p4 = make_shared<string>(10,'9');//указатель на строку 99999999
shared_ptr<int> p5 = make_shared<int>();//указатель на 0
//основная причина использования динамической памяти-совместное использование одних и тех же данных разыми объектами

//выделение статического указателя new
int *pi = new int(1024);
string *ps = new string(10, '9');
vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7};
//const int
const int *pci = new const int(1024);
//const string
const string *pcs = new const string;
//при исчерпании памяти чтобы new не выкидывало исключения
int *p2 = new (nothrow) int;
//освобождение памяти
delete p2;
delete [] p2;//если указывает на массив
shared_ptr<int> p1(new int(1024))//используется только явное указание
p1.reset()//освобождает указатель
p1.reset(q)//р1 будет указаывать на q

unique_ptr<int> p2(new int(42));
p2.reset();
p2.reset(q);
unique_ptr<string> p3(new string("Trex"));
unique_ptr<string> p2.reset(p3.release());//передает собственность от р3  к р2

int *pia = new int[10];
int *pia2 = new int[10]();//default 0
int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};



/////////////////////////КЛАССЫ///////////////////////////////////////////////////

//Конструктор копий
//если первый параметр ссылка на тип класса а все остальные параметры по умолчанию то это конструктор копий
class Foo {
public:
    Foo(); //стандартный конструктор
    Foo(const foo&); //конструктор копий
};
пример
Foo::Foo(const Foo& orig):
    bookNo(orig.bookNo),
    units_sold(orih.units_sold),
    revenue(org.revenue) {}
string s(dots); //прямая инициализация
string s2=dots; //инициализация копией




/////////////////////КЛАССЫ УПРАВЛЯЮЩИЕ ДИНАМИЧЕСКОЙ ПАМЯТЬЮ//////////////////////////////////////////////////

ОПРЕДЕЛИМ КЛАСС StrVec ПОХОЖИЙ НА VECTOR(стенли стр 666)

class StrVec:
{
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);//конструктор копий
    StrVec&operator=(const StrVec&);//присвоение копии
    ~StrVec();//деструктор
    void push_back(const std::string&);//копирует элемент
    size_t size() const{return first_free-elements;}//проверка на количество элементов
    size_t capacity() const {return cap-elements;}//возвращает количесво элементов которые поместятся в классе
    std::string *begin() const { return elements;}//фактически это итератор на начало вектора
    std::string *end() const { return first_free};//итератор на конец вектора
private:
    std::allocator<std::string> alloc;//резервирует элементы,использутся функциямми которые добавляют элементы
    void chk_n_alloc() //проверяет память на свободное пространство и пересоздает вектор ели памяти недостаточно
        {if (size() == capacity()) reallocate();}
        std::pair<std::string*,std::string*> alloc_n_copy
                    (const std::string*, const std::string*);
    void free();//удаляет элементы и освобождает пространство
    void reallocate();//резервирует больше места и копирует предыдущие элементы
    std::string *elements;//указатель на первый элемент массива
    std::string *first_free;//указатель на первый свободны элемент массива
    std:;string *cap;//указатель на элемент после конца массива

};

void StrVec::push_back(const string& s)
{
    chk_n_alloc();//удостоверится о наличии места для элемента

    //создает объект s в месте на которое указывает указатель firs_free
    alloc.construct(first_free++, s);//
    //
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e)
{
    //сначала резервируем пространство для содержания элементов диапазона e-b(a.allocete(n))
    auto date = alloc.allocate(e-b);


    //функции могут возвращать список значений в скобках(С++11)
    //uninitialized_copy(b, e, data) копируте элменты из диапазона e-b в незаполеннную память data.
    return {data, uninitialized_copy(b, e, data)};//data будет указателем на начало зарезервированной памяти а второе значени на след элементн
}

void StrVec::free()
{
    if(elements)//не пустой ли вектор
    {
        for(auto p= first_free; p != elements;)// проходимся по всем элементам от последнего к первому
            alloc.destroy(--p);//удаляем их
        alloc.deallocate(elements, cap - elements);//освобождаем всю выделенную память
    }
}

StrVec::StrVce(const StrVec &s)
{

    //вызов функции alloc_n_copy для резервирования количества эментов
    //как в s
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
    //резервируем вдвоем больше размер(напрозапас) а если пуст резервируем 1 элемент
    auto newcapacity = size() ? 2* size() : 1;
    //резервирем новую память
    auto newdata = alloc.allocate(newcapacity);//a.allocate(n)
    //перемещаем данные из прежней памяти в новую
    auto dest = newdata;//указывает на след свободную позицию в новом массиве
    //
    auto  elem= elements;//указывает на следующий элемент в старом массиве
    //
    for(size_t i = 0; i != size(); ++i)//тут проходимся по всем элментам
        alloc.construct(dest++,std::move(*elem++));//и перемещаем их с помощью move
    free();//освобождаем память
    //
    elemebts = newdata;
    frist_free = dest;
    cap = elements + newcapacity;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////ССЫЛКА &&/////////////////////////////////////////
//в отличии от обычной ссылки указывает на r-знаечние

int &&r = 42;
int i = 10;
int &&rr = i*2;

//так же используется при перемещении

int &&tt1 = std::move(rr1);


////////////КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ/////////////////////////

StrVec::StrVec(StrVec &&s) noexcept //перемещение не будет передавать исключений
    :elements(s.elements), first_free(s.first_free), cap(s.cap)
    {
        s.elments = s.first_free = s.cap = nullptr;//остваить s в состоянии при котором запуск деструктора ббезопасен

    }


 ///////////ПРИСВОЕНИЕ ПРИ ПЕРЕМЕНЩЕНИИ///////////////////////////////////
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

//////////////ПЕРЕГРУЗКА ФУНКЦИЙ////////////////////////


/////////////Перегрузка потока вывода
ostream &operator<<(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " "<< item.units_sold <<  " "
        << item.revenue << " " <<item.avg_price();
        return os;
}

//////Перегрузка потока ввода
istream &operator>>(istream &is, Sales_data &item)
{

    double price;
    is>> item.bookNo >> item.units_sold >> price;
    if (is) //проверить успех ввода данных
        item.revenue = item.units_sold  * price;
    else
        item = Sales_data(); //ввод нейдачен:вернуть объект в стандартное состояние

    return is;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;//копрование переменных в sum
    sum += rhs;//добавить rhs к sum
    return rhs;

}

bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() ==  rhs.isbn();

}
//////////БИБЛИОТЕЧНЫЙ ТИП FUNCTION////////////////(Stenli 744)
////это шаблон в котором надо указывать сигнатуру функции
function<int(int,int)> f1 = add; //указатель на функцию
function<int(int,int)> f2 = div(); //объект класса объекта функции
 function<int(int,int)> f3 = [](int i,int j)// лямда выражение
                                    { return i*j};

cout<< f1(4,2) << endl; // выводит 6
cout<< f2(4,2) << endl;// 2
cout<< f2(4,2) << endl;// 9

///////ОПРЕДЕЛЕНИЕ БАЗОВОГО КЛАССА/////////

class Quote{

public:
    Quote() = default;//(page 345)
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    std::string isbn() const {return bookNo;}

    virtual double net_price(std::size_t n) const //virtual используется для переопределени этой функции
            { return n*price} //в дочернем классе
    virtual ~Quote() = default;

private:
    std::string bookNo;
protected:
    double price = 0.0;

} ;

///////ОПРЕДЕЛЕНИЕ ПРОИЗВОДНОГО КЛАССА//////
class Bulk_quote : public Quote {
    Bulk_quote() = default;
    Bulk_auote(const std::string&, double, std::size_t, double);
    double net_price(std::size_t) const override;//override пишется когда функция переопределяется
private:
    std::size_t min_qty = 0;
    double discont = 0.0;
};
//для определения переменных базорого класса используем базоывый конструктор в составе производного
Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) :
            Quote(book,p), min_qty(qty), discont(disc) {}

Qoute item;
Bulk_quote bulk;
Quote *p = &item;// p указывает на объект Quote
p = &bulk;// p указывает на часть bulk объекта Quote
Quote &r = bulk;//r связан с часть bulk объекта Quote


