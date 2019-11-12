//
//  main.c
//  HelloC
//
//  Created by apple on 2019/10/26.
//  Copyright © 2019 apple. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define __PI 3.14159265358979323846
//const float PI = 3.1415926f;//不可重赋值，否则编译时报错

#define SUM(a,b,c) a+b+c;

typedef struct AAA {
    char text[32];
    int age;
}
;

int encode (int i)
{
    return i+4;
}

void ln() {
    printf("\n-------\n");
}

void fahrenheit2celsius(int F) {
    float c =  5 * (F - 32) / 9;//，取位2小数
    printf("fahrenhait=%d ==> celsius=%08.2f\n\n", F, c);
    ln();
}

float countCircleArea (float radius)
{
    const float PI = 3.1415926;
    return PI * radius * radius;
}

void dosomething ( int input) {
    while (input) {
        printf("%d " , input%10);
        input /= 10;
    }
    ln();
}

void a() {
    int value = 2;
    
    switch(value)
    {
        case 1:printf("one");break;
        case 2:printf("two");break;
        case 3:printf("three");break;
        default:printf("other");break;
    }
    ln();
}

void d() {
    int radius = 3;
    printf("radius=%d; CircleArea=%3.2f\n", radius, countCircleArea(radius));
}

void whileStatement(int i) {
    while(i++<20)
    {
        printf("count %d \n",i);
    }
    ln();
    printf("while after i = %d\n", i);
    do {
        printf("i = %d\n", i);
    } while (i-- > 0);
    ln();
    
    for(int j=0;j<100;j++)
    {
        printf("j count is %d\n",j);
    }
    ln();
}

void testBool() {
    bool a = 0;
    printf("bool a = %d \n", a);
    a = 1;
    printf("bool a = %d \n", a);
    a = 3;
    printf("bool a = %d \n", a);
    a = -1;
    printf("bool a = %d \n", a);
}

void test1() {
    int a;
    float b,c;
    scanf("%2d%3f%4f", &a,&b,&c);
    printf("a=%d, b=%f, c=%f", a,b,c);
    ln();
}

void testCharScanf() {
    char a,b,c;
    printf("please input num a:\n");
    scanf("%c",&a);
    printf("please input num b:\n");
    scanf("%c",&b);
    printf("please input num c:\n");
    scanf("%c",&c);
    printf("%c,%c,%c",a,b,c);
    ln();
    
    //    char a,b,c;
    printf("please input num a:\n");
    scanf("%c",&a);
    getchar();
    printf("please input num b:\n");
    scanf("%c",&b);
    getchar();
    printf("please input num c:\n");
    scanf("%c",&c);
    printf("%c,%c,%c",a,b,c);
    ln();
}

void testChar () {
    char a,b,c;
    a = getchar();
    b = getchar();
    c = getchar();
    a= toupper(a);
    b= toupper(b);
    c= toupper(c);
    printf("a=%c \n", a);
    printf("b=%c \n", b);
    printf("c=%c \n", c);
    ln();
    putchar(getchar());
    putchar(getchar());
    putchar(getchar());
    ln();
    
}

void testChar1 (char argc[])
{
    int c = 4, i;
    for(i=0;i<c;i++) {
        printf("%c_", argc[i]);
    }
    ln();
    
    char a[6]={'c', ' h ', 'i', 'n', 'a' , '\0' };
    char b[]={"china"};
}
void testArr() {
    int a[100]={1,2,3,4,5}; //定义一个整型数组a，前5个元素即赋值为1，2，3，4，5,后95个元素值值全部为0
    float b[10]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,0.0};  //定义float数组b并对全部float类型的元素都分别赋值
    char c[256]={'C','l','a','n','g','u','a','g','e'};  //定义一个数组名为c的字符型数组 并对前9个元素进行赋值，其余元素全部为'\0'
    
    int d[3][4]={{1,2,3,4},{10,20,30,40},{100,200,300,400}};//定义一个三行四列的二维数组,按行赋值
    int e[3][4]={1,2,3,4,10,20,30,40,100,200,300,400};//定义一个三行四列的二维数组并对其中的12（3*4）个元素进行赋值
    
    ln();
};

void converseAddress(int *b) {
    while (*b > 0) {
        printf("%d ", *b%10);
        *b = *b/10;
    }
    ln();
}
void converseInt(int b) {
    while (b > 0) {
        printf("%d ", b%10);
        b = b/10;
    }
    ln();
}
static void testAddress_value() {
    int t = 1234567890;
    //    converseInt(t);
    //        converseAddress(&t);
    printf("0x%016x ", &t);
    ln();
    printf("%d", *&t);
    ln();
    
    int i;
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    char b[10]={'c','l','a','n','g','u','a','g','e'};
    for(i=0;i<10;i++)
    {
        printf("int Address:0x%x, Value:%d\n",&a[i],a[i]);
    }
    ln();
    for(i=0;i<10;i++)
    {
        printf("char Address:0x%x,Value :%c\n",&b[i],b[i]);
    }
    ln();
    
    char d[5] = "abcd";
    char e[] = "i love luka & yang";
    printf("%s \n",d);
    printf("%s ",e);
    //    gets(d);
    ln();
    
}

static void testPointer() {
    int num=2014;
    int *pp=&num;
    printf("num Address = 0x%012x,num=%d\n",&num,num);
    printf("p = 0x%012x,*p=%d\n",pp,*pp);
    printf("%d\n",*&num);
    ln();
    
    int f[1<<20] = {};
    printf("0x%010x %s\n", &f, f);
    
    struct INFO
    {
        int a;
        char b;
        double c;
    };
    int *p;
    char *p1;
    float *p2;
    double *p3;
    struct INFO *p4;   //struct INFO类型为结构体类型 我们将会在后面的章节中讲解
    void *p5;
    printf("int point size is :%d\n",sizeof(p));
    printf("char point size is :%d\n",sizeof(p1));
    printf("float point size is :%d\n",sizeof(p2));
    printf("double point size is :%d\n",sizeof(p3));
    printf("struct point size is :%d\n",sizeof(p4));
    printf("void point size is :%d\n",sizeof(p5));
    
    ln();
    int a[10] = {'a','b'}; /*定义 a 为包含 10 个整型数据的数组*/
    int *p6; /*定义 p 为指向整型变量的指针*/
    p6=&a[0]; /*把 a[0]元素的地址赋给指针变量 p*/
    printf("%x", p6);
    ln();
    p6 = a;
    printf("%x", p6);
    ln();
    printf("%s", *p6);
    ln();
}

static void testPointer2() {
    int i;
    int a[10]={1,2,3,4,5,6,7,8,9,0};
    int *p=a;
    for(i=0;i<10;i++)
    {
        printf("P Value:%d   a Value :%d\n",*(p++),*(a+i));
    }
    ln();
}

static void testString() {
    char *str = "www.dotcpp.com";
    char string[]="Welcome to dotcpp.com";
    str[0]='C';
    printf("%s ",str);
    ln();
    printf("%s ",string);
    ln();
}
static void testStruct() {
    
    struct AAA jiek = {"jiek", 22}
    ,luka = {"luka", 23}
    ,obj = {"obj",25};
    
    obj.age = 2019;
    
    strcpy(obj.text,"Welcome to dotcpp.com");
    
    printf("This year is %d, %s\n",obj.age,obj.text);
    //    char *p = "my name is jiek.";
    char p[] = "my name is jiek.";
    char *q;
    printf("%s  %x\n", p, *obj.text);
    //    obj.text = p;
    printf("This year is %d, %s\n",obj.age,obj.text);
    
    q = &p;
    //    strcpy(*q, p);//此句怎样都是错的。
    printf("q = %s", q);
    ln();
    
}

static void testStruck1() {
    struct address
    {
        char name[30];
        /*姓名,字符数组作为结构体中的成员 */
        char street[40]; /*街道*/
        unsigned long tel; /*电话,无符号长整型作为结构体中的成员 */
        unsigned long zip; /*邮政编码*/
    }
    student[3]={
        {"Zhang","Road NO.1",111111,4444},
        {"Wang"," Road NO.2",222222,5555},
        {"Li"," Road NO.3",333333,6666}
    };
    
    //todo 待解决使用结构体数据
}

enum weekday {monday = 1, tuesday, wednesday, thursday, friday, saturday, sunday};
static void printday(enum weekday day) {
    switch (day) {
        case monday:
            printf("monday");
            break;
        case tuesday:
            printf("tuesday");
            break;
        case wednesday:
            printf("wednesday");
            break;
        case thursday:
            printf("thursday");
            break;
        case friday:
            printf("friday");
            break;
        case saturday:
            printf("saturday");
            break;
        case sunday:
            printf("sunday");
            break;
            
        default:
            printf("the day ,%d ,is error day!", day);
            break;
    }
    ln();
}

static void testEnum() {
    enum color_name {a=13, b, c=8};
    printf("%d %d %d", b,a,c);
    ln();
    enum color_name cc;
    cc = c;
    printf("%d ", cc);
    
    ln();
    
    printday(1);
    printday(2);
    printday(5);
    printday(4);
    printday(3);
    printday(7);
    printday(6);
    printday(0);
    printday(8);
}

static void testDefine() {
    const int pp = 123;
    printf("%d", pp);
    int yes = 251;
    printf("%c", yes);
    ln();
    float area = __PI * pow(3.0, 2.0);
    printf("area = %f", area);
    ln();
    int sum =SUM(1, 2, 4);
    printf("sum = %d", sum);
    
    ln();
}
union INFO
{
    int a;
    int b;
    int c;
};
static void textUnion() {
    union INFO A;
    A.a=1;
    A.b=2;
    A.c=3;
    printf("a:%d\n",A.a);
    printf("b:%d\n",A.b);
    printf("c:%d\n",A.c);
    
    ln();
}

static void randomNum() {
    //    srand(1);//srand(time(NULL));//需导入 time.h,需在 VS 中调试
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d, ", rand()%1100);
    }
    ln();
}

void _main ()
{
    printf("-------\n");
    
    //    fahrenheit2celsius(57);
    //
    //    d();
    //
    //    dosomething(123456789);
    //
    //    a();
    //
    //    whileStatement(12);
    
    //    testBool();
    
    //    test1();
    //    testCharScanf();
    
    //    testChar();
    //    testChar1("abcd efg 123");
    //    testArr();
    
    //    int a = 12;
    //    printf("%03d \n", a);
    //    printf("%03o \n", a);
    //    printf("%03x \n", a);
    
    //    testAddress_value();
    
    //        testPointer();
    //    testPointer2();
    //    testString();
    
    //    testStruct();
    //    testStruck1();
    
    //    testEnum();
    //    testDefine();
    
    
//    textUnion();
    
//    randomNum();
}

