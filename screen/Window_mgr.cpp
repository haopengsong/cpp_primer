class Window_mgr {
public:
    // Location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);
    // add a Screen to the window and returns its index
    ScreenIndex addScreen(const Screen&);
    
private:
    std::vector<Screen> screens{Screen(24, 80, '')};
};

void Window_mgr::clear(ScreenIndex i)
{
    /*

    If clear (Window_mgr) were not a friend of Screen, this code would not compile.

    The clear function would not be allowed to use the height, width or contents members of Screen.
    
    Screen grants friendship to Window_mgr, all the members of Screen are accessible to the functions in Window_mgr.

    */
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = string(s.height * s.width, '');
}

// return type is seen before we're in the scope of Window_mgr
// So we must specify the class in which that type is defined
Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}
