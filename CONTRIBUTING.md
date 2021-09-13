# Netiquette

I don't want to bore you with useless descriptions on how to be nice. We all know how to be nice. So, just be nice, ok?

> TL;DR; You're not required to poop rainbows all day, but at least try to be nice to each other.

# What you can do

This project will never be done as there is always something to improve. You can be a part of this project.

You can do as little as describe bugs in an [issue](https://gitlab.com/florian0/sro_devkit/-/issues) or write down small
guides for the [documentation page](https://florian0.gitlab.io). You can also go ahead and improve the documentation
with better screenshots, better descriptions or fix spelling and grammar errors.

If you feel like it, you can also go ahead and add more information to existing bugs and help fixing them this way.

Maybe you managed to fix a bug yourself, so why not contribute the fix back?

# Commit Guidelines

This section applies to contributing code to DevKit.

## Create a merge-request

Please don't try to contribute code through issues, mail or Discord. These are not suitable for contributing code.
Create a merge-request through GitLab. This is the only way to get your code into DevKit.

## Writing Code

We dream of having clean code. We know, everyone has their own style. Make use of patterns, if it's convenient, feel
free to introduce new types and classes.

When declaring a function (usually in a header file), please make a comment that describes where you found it. This
allows everyone to quickly navigate between code and binary. This also applies to functions where the address is part
of the name.

Example:

```cpp
class CGFontTexture {
    // ...
    
    /// \address 008B4400
	void sub_8B4400(int a1, int a2);
	
	
	// ...
}
```

Every function should be completely implemented. Partial implementations are only allowed on individual occasions. The
minimal implementation should either be an assertion (signaling *not yet implemented*) or a redirection to the original
function in the code.

Example:

```cpp
void CIFTileWnd::SetGWndSize(int width, int height) {
    // Not yet implemented
	BS_ASSERT_MSG(FALSE, "Not yet implemented"); 
}
```

```cpp
void CIFTileWnd::sub_81AE00() {
	// Redirection to original client code
	reinterpret_cast<void(__thiscall*)(CIFTileWnd*)>(0x0081AE00)(this);
}
```

If your new function appears to be empty, place a comment stating this. Empty functions might be confusing as they look
if someone either forgot to put a redirection or assert.

```cpp
void CGWnd::OnUpdate() {
	// empty
}
```

### Big changes!

Contact us, **before** you start writing code! We might already have code, ideas, tips, plans or requirements for
solving a specific task or problem. This will avoid lots of discussion and maybe changes afterwards.

### Coding Guidelines

While guidelines are really necessary for a community project, complex guidelines will discourage people from helping.
So we will keep it as simple as possible:

* Language is english. Code is english, Comments are english. No other languages permitted.
    * Only exception: Original korean messages from the game.
* Don't put multiple classes/structures in one file (except simple nested types that stay completely internal)
* Don't split classes across multiple files.
* Adapt the current formatting. (Currently working on a written definition)
* Write comments. Quality > Quantity. Keep them informative.
* No dirty code. No hacks. Keep it clean. Avoid memory leaks. 
* Avoid assembly code whenever possible.

## Commit Rules

> These rules were *taken* from the [MonoDevelop Project](http://www.monodevelop.com/developers/)
> But they fit so nicely!

1. Enter a meaningful explanation in the commit log message.
2. The first line of the commit message should be a short (ideally <50 columns) message, followed by a blank line. The
   rest of the commit message could contain a more detailed explanation of the change, wrapped to 80 columns.
3. When entering a message describing a change, take into account that the goal is to explain why the change was done,
   rather than what was changed. For example, the message “Added property X” is in general useless since it is obvious
   looking at the patch.
4. All changes included in a commit should be related and as atomic as possible. Here are some examples:
    * You do an API change that affects several projects across the source tree. All changes can go in a single commit.
    * You implement a new feature A. Then you implement another new feature B that uses A. Although those changes are
      related (B needs A), they should be committed separately, since they belong to two different features.
5. Don’t do reformatting commits, unless you’re the original author of the code. This includes changing line endings.
6. Never remove copyright notices from the code.
7. Never remove licensing info from code.
8. Never commit code you didn’t write yourself or code that doesn’t have a suitable license.
9. Never commit code that doesn't work.

