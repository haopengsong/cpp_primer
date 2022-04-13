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

    // display overloaded on whether the object is const or not
    // when one member calls another, the 'this' pointer is passed implicitly;
    // Thus, when display calls do_display, its own 'this' pointer is implicitly passed to do_display;
    // When the non-const version of display calls do_display, its 'this' pointer is implicitly converted from a pointer to non-const to a pointer to const
    // When we call display on an object, wheter that object is const determines which version of display is called
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

    // Window_mgr members can access the private parts of class Screen
    friend class Window_mgr;

    /*

    Or, Screen can specify that only the clear member is allowed access

    Window_mgr::clear must have been declared before class Screen
    
    ///////////////////////////////////////////
    friend void Window_mgr::clear(ScreenIndex);
    ///////////////////////////////////////////

    */
    // ostream version of storeOn may access the private parts of Screen objects
    friend std::ostream& storeOn(std::ostream &, Screen &);

private:
    mutable size_t access_ctr; // may change even in a const object
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    // function do the work of displaying a screen
    void do_display(std::ostream &os) const
    {
        os << contents;
    }
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

// Overloaded storeOn functions
extern std::ostream& storeOn(std::ostream &, Screen &);
extern BitMap& storeOn(BitMap &, Screen &);
      

