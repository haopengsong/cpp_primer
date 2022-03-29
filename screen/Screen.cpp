class Screen {
public:
    typedef std::string::size_type pos;
    // alternative way to declare a type member using a type alias
    using pos = std::string::size_type;
    // other members as before
    Screen() = default; // need because Scrren has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const // get the character at the cursor
    { return contents[cursor]; } // implicitly inline

    inline char get(pos ht, pos wd) const; // explicity inline
    Screen &move(pos r, pos c); // can be made inline later

    void some_member() const;

    // set character at the cursor or at a given location
    Screen &set(char);
    Screen &set(pos, pos, char);

private:
    mutable size_t access_ctr; // may change even in a const object
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};


inline
Screen &Screen::move(pos r, pos c)
{
    pos = row = r * width; // compute the row location
    cursor = row + c; // move cursor to the column within that row
    return *this; // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared as inline in the class
{
    pos row = r * width; //compute row location
    return contents[row + c]; // return character at the given column
}

void Screen::some_member() const
{
    // despite the fact that some_member is a const member function, it can change the value of access_ctr
    ++access_ctr; // keep a count of the calls to any member function
    // whatever other work this member needs to do
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c; // set the new value at the current cursor location
    return *this; // return this object as an lvalue;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; // set specified location to given value
    return *this;
}


