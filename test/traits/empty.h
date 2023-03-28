#ifndef __EMPTY__
#define __EMPTY__

class Empty {
    /*
        '= default' can only appear on Big Five, which includes
        0. ctor
        1. copy ctor
        2. move ctor
        3. copy operator=
        4. move operator=
        5. dtor
    
        '= delete' can be used for any functions
    */
};

// implementation of singleton
class NoCopy
{
public:
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;
    NoCopy& operator = (const NoCopy&) = delete;
    ~NoCopy() = default;
};

#endif  // __EMPTY__