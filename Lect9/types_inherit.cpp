#include <iostream>

using namespace std;

class BaseA
{
private:
    int private_a;
    void private_method() {
        cout<<"Use a";
    }

protected:
    int protected_b;
    void protected_method() {
        cout<<"Use b";
    }
public:
    int public_c;
    BaseA():private_a(1),protected_b(2), public_c(3) {}

    void public_method() {
        cout<<"Use c";
    }

};

class InheritPublic: public BaseA
{
public:
    void use() {
        //cout<<  private_a;
        cout<<  protected_b;
        cout<<  public_c;
        //private_method();
        protected_method();
        public_method();
    }
};

class InheritProtected: protected BaseA
{
public:
    void use() {
        //cout<<  private_a;
        cout<<  protected_b;
        cout<<  public_c;
        //private_method();
        protected_method();
        public_method();
    }
};


class InheritPrivate: private BaseA
{
public:
    void use() {
        //cout<<  private_a;
        cout<<  protected_b;
        cout<<  public_c;
        //private_method();
        protected_method();
        public_method();
    }
};

class InheritPublic2: public InheritPublic
{
public:
    void use() {
        //cout<<  private_a;
        cout<<  protected_b;
        cout<<  public_c;
        //private_method();
        protected_method();
        public_method();
    }
};

class InheritProtected2: protected InheritProtected
{
public:
    void use() {
        //cout<<  private_a;
        cout<<  protected_b;
        cout<<  public_c;
        //private_method();
        protected_method();
        public_method();
    }
};


class InheritPrivate2: private InheritPrivate
{
public:
    void use() {
        //cout<<  private_a;
        //cout<<  protected_b;
        //cout<<  public_c;
        //private_method();
        //protected_method();
        //public_method();
    }
};

int main()
{

    BaseA p1;
    p1.public_method();
    cout<<p1.public_c;

    InheritPublic p2;
    p2.public_method();
    cout<<p2.public_c;
    p2.use();

    InheritProtected p3;
    //p3.public_method();
    //cout<<p3.public_c;
    p3.use();

    InheritPrivate p4;
    p2.public_method();
    cout<<p2.public_c;
    p2.use();

    InheritPublic2 p5;
    p5.use();
    cout<<p5.public_c;

    InheritProtected2 p6;
    p6.use();
    //cout<<p6.public_c;

    InheritPrivate2 p7;
    p7.use();
    //cout<<p6.public_c;
}
/*
 * Use c3Use c323Use bUse cUse c323Use bUse cUse c323Use bUse c23Use bUse c323Use bUse c
 *
 * */
