# Creating Tests

SRO_DevKit includes a static testing library to ensure reverse engineered 
classes have the correct size and member variables are at the correct offset.

The following class declaration is used as an example to illustrate a class you
could have created. The class also contains an empty test fixture.

A class may only have one test fixture.

!!! example
    ```cpp
    class CMyClass {
        
    private:
        int m_OtherVariable1;
        int m_OtherVariable2;
        int m_MyMemberVariable;
        int m_OtherVariable3;
        
        
        BEGIN_FIXTURE()
        
        END_FIXTURE()
        
        RUN_FIXTURE(CMyClass)
    };
    ```

## Basic fixtures

### Size testing

Use the macro `ENSURE_SIZE` in a basic test fixture to make sure the class 
`CMyClass` is always `16` bytes large.


!!! example
    ```cpp
    BEGIN_FIXTURE()
        ENSURE_SIZE(16);
    END_FIXTURE()

    RUN_FIXTURE(CMyClass)
    ```

If the size of `CMyClass` is not 16 bytes, the code will not compile and throw
an error instead.

### Offset testing

Use the macro `ENSURE_OFFSET` in a basic text fixture to make sure the variable
`m_MyMemberVariable` is always at offset 0x8 of class `CMyClass`.

!!! example

    ```cpp
    BEGIN_FIXTURE()
        ENSURE_OFFSET(m_MyMemberVariable, 0x8);
    END_FIXTURE()

    RUN_FIXTURE(CMyClass)
    ```

If `m_MyMemberVariable` of `CMyClass` is not at offset `0x8`, the code will not
compile and throw an error instead.


### Grouping multiple tests

If you run multiple tests, which is very likely, just group them together into
the same fixture.


!!! example

    ```cpp
    BEGIN_FIXTURE()
        ENSURE_SIZE(16);
        ENSURE_OFFSET(m_MyMemberVariable, 0x8);
    END_FIXTURE()

    RUN_FIXTURE(CMyClass)
    ```

## Under the hood

You don't need to know how the system works under the hood. But if you're 
interested, this is the place to look.

### Basics

The implementation of the testing is pretty primitive. Both tests rely on the 
same mechanism.

```cpp
int testcase[expression ? 1 : -1];
```

When the given expression is `true`, the array `testcase` will be created with 
a size of `1`. If the expression is `false`, the array size will be `-1`. This
is not a valid size. Therefore compiler will throw an error in this case.

For size-testing, the expression is basically:

```cpp
sizeof(CMyClass) == 16
```

If `sizeof` returns anything other than 16, the expression will return false.

For offset-testing, we make use of the `offsetof` macro.

```cpp
offsetof(CMyClass, m_MyMemberVariable) == 0x08
```

`offsetof` will make a (null-)pointer of type `CMyClass`. Then it will get the 
address of `m_MyMemberVariable`. The value of the pointer will automatically 
be the same as the offset because the value of the base pointer was zero.

```cpp
// This code is very simplified. Do not use it. Use offsetof instead.
(&((CMyClass*)0)->m_MyMemberVariable)
```

### Behind the macro magic

For calling offsetof, we need to be *inside* the class we are testing. 
Otherwise we can not access `private` and `protected` easily.

Every fixture is it's own class named `TestFixture`, hidden inside the class 
you are testing. It's a template class to avoid repeating the classname over 
and over again.

The macros `ENSURE_SIZE` and `ENSURE_OFFSET` just create member variables 
inside the `TestFixture`-class. 

The `RUN_FIXTURE`-macro creates a static instance of the class. We need to 
instanciate the class because `TestFixture` is a template that otherwise would 
not be evaluated.


!!! example "Our example from above with evaluated macros"

    ```cpp
    class CMyClass {
        
    private:
        int m_OtherVariable1;
        int m_OtherVariable2;
        int m_MyMemberVariable;
        int m_OtherVariable3;
        
        
    private
        // BEGIN_FIXTURE()
        template<typename T>
        class TestFixture {
        
            // ENSURE_SIZE(16)
            int __sizeof [ sizeof (T) == 16 ? 1 : -1 ];
            
            // ENSURE_OFFSET(m_MyMemberVariable, 0x8);
            int  __offsetm_MyMemberVariable [ offsetof(T, m_MyMemberVariable) == 0x8 ? 1 : -1 ];
        
        // END_FIXTURE()
        };
        
        // RUN_FIXTURE(CMyClass)
        static void _RunFixture() {
            static CMyClass::TestFixture<CMyClass> testFixture;
        }
    };
    ```

As you can see, this results in quite a lot of unreadble code. That's why we 
choose to hide the implementation-details behind some macros.
