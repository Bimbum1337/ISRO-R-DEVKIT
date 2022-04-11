# Code Style

We dream of having clean code. We know and understand that everyone got their own preferences. However, keeping the code
understandable is important for having a project people want to work with.

We distinguish between code style and code formatting. This document mainly defines code style.

## "One" more word about formatting

Current formatting is based on the ruleset of LLVM. A `.clang-format` file with these rules is shipped in the 
repository. Your (modern) IDE can perform auto-formatting using this file.

In general, we don't strictly enforce formatting rules. However, if your formatting is completely terrible, we may ask 
you to fix it.

These simple points will resolve most of the trouble you may run into:

* Indentation uses 4 spaces. Tabs will no longer be accepted.
* If in doubt: Try to adapt the current formatting of the file.
* Correct indentation, please.

## Language

Language is english. Code is english, Comments are english. No other languages permitted.

!!! warning "Only exception"
    Original korean messages from the game. In this case add a comment with the english meaning.


## Static

!!! important
    The use of `static`-variables, especially pointers, is strictly prohibited!

Just kidding. `static` has its use-case, and you are allowed to use it. The way it is commonly used by the community is
incorrect most of the time. If you consider creating a `static` variable, think closely if there is really no other way 
to achieve what you are trying.

> The common use for global variables in the community is to achieve something like this:
> 
```cpp
CIFMainWindow::RankingWindow->Update();
```
> This is an awful solution for accessing the RankingWindow, because there is absolutely no guarantee that 
> `RankingWindow` will be a valid pointer at any given time. This is a global reference to a dynamic runtime object.
> 
> If you need a pointer to a window, or a control, always use `GetResObj`.
> 


## Classes

Classes usually have two files. A header file and a source file. All function declarations go into the header 
file. All function definitions go into the source file. If there are no definitions (yet), the source file
shall be omitted (no one needs empty files).

Please refrain from putting multiple classes into one file. Every class should have its own file. You may put simple 
nested or helper-structures into the same file. 

The filenames must be the same as the class name, excluding the `C` prefix.

The public interface of a class shall go first in the class declaration, the member variables go last.

!!! example
    ```cpp
    class CMyClass {
    public:
        void MyPublicFunction();
    private:
        void MyPrivateFunction();
    private: /* member variables */
        int m_number;
    }
    ```

When you reconstruct a class from the game, consider [creating tests for it](advanced/creating-tests.md) 
right away. Tests increase the reliability of the code.

!!! info
    You don't need to create tests for classes that don't appear in the game. Tests assure binary compatibility. We can
    not have that for non-game-classes. 


### Functions

Please make a comment on the declaration of every function you create that describes where you found it. 
This allows anyone to quickly navigate between code and binary.


!!! example
    ```cpp
    class CGFontTexture {
        /// \address 008B37A0
        void CGFontTexture::FUN_008B37A0();
    };
    ```

Every function should be completely implemented. Partial implementations are only allowed on 
individual occasions. The minimal implementation should either be an 
assertion (signaling *not yet implemented*) or a redirection to the original function in the code.

Do not use `assert`. We are compiling a *Release* build. *Release* builds will not have asserts. Always use `BS_ASSERT`.

!!! example "Example: Not yet implemented"
    ```cpp
    void CIFTileWnd::SetGWndSize(int width, int height) {
        // Not yet implemented
	    BS_ASSERT(FALSE); 
    }
    ```

!!! example "Example: Redirection"
    ```cpp
    void CIFTileWnd::FUN_0081AE00() {
        // Redirection to original client code
        reinterpret_cast<void(__thiscall*)(CIFTileWnd*)>(0x0081AE00)(this);
    }
    ```

If your new function appears to be empty, place a comment stating that it is empty.

!!! example "Example: Empty function"
    ```cpp
    void CGWnd::OnUpdate() {
        // empty
    }
    ```

## Naming

* Class Member variables shall be prefixed with `m_`. e. g. `m_numberOfElements`.
* Class names should be prefixed with a capital `C`, corresponding file names shall not include the `C`. e. g. `CMyClass`.
* Pointer-types shall be prefixed with `p`. e. g. `pMyCoolWindow`.
* Global variables shall be prefixed with `g_`. `g_cameraPath`.
* Variable names (including parameters) are in *camelCase*.
* Function names are in *CamelCase* (like variables, but with the first letter being capital).
  * Function names of unknown functions shall be named `FUN_` and the address of the function. e. g. `FUN_0081AE00`.


### Hungarian notation

Many variables have a marking of their type included in the name. e.g. `fLength` (a float), `hFile` (a handle), 
`iNumberOfItems` (an integer), `lnBytesWritten` (a long), `bIsOpen` (a boolean), etc.

We don't really recommend doing this extensively. It makes the code kinda messy, reduces readability while not adding
much valuable information. Your IDE can show the datatype anyway!

> These mostly come from my workflow during reversing. Most reversing tools are not good at showing type info, so encoding
> basic info into the name makes it easier to navigate and understand. I tend to keep these names so DevKits code and my
> reverse engineered tools are *in sync*. Removing the notation when after reconstructing would be possible, but also 
> makes it harder to map types back to the tools when working on something further.   

## Assembly, __asm and naked-functions

Not allowed.


## Commit Rules

!!! info
    These rules were *stolen* from the [MonoDevelop Project](http://www.monodevelop.com/developers/)
    But they fit so nicely!

Use commits wisely. Make multiple smaller commits instead of a few large. Don't commit code that does not work. Don't 
use commits as quick-save. Commit, when the state of development deserves a snapshot.

1. Enter a meaningful explanation in the commit log message.
1. The first line of the commit message should be a short (ideally <50 columns) message, followed by a blank line. The rest of the commit message could contain a more detailed explanation of the change, wrapped to 80 columns.
1. When entering a message describing a change, take into account that the goal is to explain why the change was done, rather than what was changed. For example, the message “Added property X” is in general useless since it is obvious looking at the patch.
1. All changes included in a commit should be related and as atomic as possible. Here are some examples:
    * You do an API change that affects several projects across the source tree. All changes can go in a single commit.
    * You implement a new feature A. Then you implement another new feature B that uses A. Although those changes are related (B needs A), they should be committed separately, since they belong to two different features.
1. Don’t do reformatting commits, unless you’re the original author of the code. This includes changing line endings.
1. Never remove copyright notices from the code.
1. Never remove licensing info from code.
1. Never commit code you didn’t write yourself or code that doesn’t have a suitable license.
