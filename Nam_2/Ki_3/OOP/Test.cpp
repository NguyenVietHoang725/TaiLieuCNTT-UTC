#include  <iostream>
using namespace std;

class Format {
public:
    void display_form();
    virtual void header() {
        cout << "This is a header\n";
    }
    virtual void body() = 0;
    virtual void footer() {
        cout << "This is a footer\n\n";
    }
};

void Format :: display_form() {
    header();
    for(int index = 0; index < 3; index++) {
        body();
    }
    footer();
}

class MyForm : public Format {
public:
    void body() {
        cout << "This is a the new body of text\n";
    }
    void footer() {
        cout << "This is a new footer\n";
    }
};

int main() {
    Format* form = new MyForm();
    form->display_form();
}