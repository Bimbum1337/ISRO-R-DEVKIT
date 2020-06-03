# Code Style

We dream of having clean code. We know, everyone has their own style. Make use of patterns, if it's convenient, 
feel free to introduce new types and classes.

Keeping the code understandable is key for having a project people want to work with.

## General rules

Let's talk about some general considerations first. Following a certain set of guidelines can improve the code 
quality. These general rules also act like a checklist you can work through before submitting a pull request.

Contact us, **before** you start writing code! We might already have code, ideas, tips, plans or requirements for 
solving a specific task or problem. This will avoid lots of discussion and maybe changes afterwards.

### Language

Language is english. Code is english, Comments are english. No other languages permitted.

!!! warning "Only exception"
    Original korean messages from the game.

### Classes

Classes usually have two files. A header file and a source file. All function declarations go into the header 
file. All function definitions go into the source file. If there are no definitions (yet), the source file
may be omitted.

Please refrain from putting multiple classes into one file. Every class should have it's own file. You may put simple 
nested or helper-structures into the same file. 

When you reconstruct a class from the game, consider [creating tests for it](advanced/creating-tests.md) 
right away. Tests increase the reliability of the code.

!!! info
    You don't need to create tests for classes that don't appear in the game. Tests only asure binary 
    compatibility. We don't need that for non-game-classes. 

### Functions

Please make a comment on the declaration of every function you create that describes where you found it. 
This allows everyone to quickly navigate between code and binary.

Example:

!!! example
    ```cpp
    class CGFontTexture {
        /// \address 008B37A0
        void CGFontTexture::sub_8B37A0();
    };
    ```

Every function should be completely implemented. Partial implementations are only allowed on 
individual occasions. The minimal implementation should either be an 
assertion (signaling *not yet implemented*) or a redirection to the original function in the code.


!!! example "Example: Not yet implemented"
    ```cpp
    void CIFTileWnd::SetGWndSize(int width, int height) {
        // Not yet implemented
	    assert(FALSE); 
    }
    ```

!!! example "Example: Redirection"
    ```cpp
    void CIFTileWnd::sub_81AE00() {
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

## Formatting

* Use 4 spaces. Tabs will no longer be accepted.
* All curly braces go into the same line
* Type declaration modifiers such as pointer (`*`) and reference (`&`) always go to the variable, not the type.
* The public interface of a class shall go first in the class declaration, the member variables go last.


* Write comments. Quality > Quantity. Keep them informative.
* No dirty code. No hacks. Keep it clean. Avoid memory leaks.

## Naming

* Class Member variables shall be prefixed with `m_`
* Class names should be prefixed with a capital `C`, corresponding file names shall not include the `C`.
* Variable names (including parameters) are in *camelCase*
* Function names are in *CamelCase* (like variables, but with the first letter being capital).


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
