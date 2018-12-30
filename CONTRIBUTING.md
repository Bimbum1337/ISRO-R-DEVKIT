# Reporting Bugs
Please report bugs through the GitLab Issue Tracker.

**Before reporting:** Check the list of already reported bugs and make sure your bug hasn't been submitted already.

Please write your report based on this template.

Template:
> **Description:**  
> What did you do?  
> Describe the actual behaviour  
> *If available:* Provide the entire error message (in a code block)  
>
> **Steps to reproduce:**
>
> 1. ...
> 2. ...
> 3. ...
> 
> *If available:* Provide a minimal code sample to reproduce the error.   
> Describe the expected behaviour.  
>
> **System Information:**
> * Operating System
> * Version / Git-Tag / Git-Commit



# Feature Request

Please request features through the GitLab Issue Tracker.

**Before requesting:** Check if a similar request has already been made.

Please write your request based on this template.

> **Request-Type:** 
> * Feature (something completely new)
> * Change (change the behaviour of something)
> 
> **Short brief:** 
> What are you thinking of? What is missing?
>
> **Description:**
> Any details? What exactly should be done?
>


# Commit Guidelines 

Thank you for considering contributing to this project. We really appreciate it. We made a few rules to keep 
everything in order.

## Create a merge-request

Please don't try to contribute code through issues, mail or Discord. These are not suitable for contributing code.
Create a merge-request through GitLab. This will get you noticed.

## Writing Code

We dream of having clean code. We know, everyone has their own style. Make use of patterns, if it's convenient, 
feel free to introduce new types and classes.

**Keep in mind**: The bigger your change is, the longer will it take us to review it, the longer it will take to 
get it accepted and the greater the risk that your changes will be rejected.

Use commits wisely. Make multiple smaller commits instead of a few large. Don't commit code that does not work. Don't 
use commits as quick-save. Commit, when the state of development deserves a snapshot.

### Big changes!

Contact us, **before** you start writing code! We might already have code, ideas, tips, plans or requirements for 
solving a specific task or problem. This will avoid lots of discussion and maybe changes afterwards.

### Coding Guidelines

While guidelines are really necessary for a community project, complex guidelines will discourage people from 
helping. So we will keep it as simple as possible:

* Language is english. Code is english, Comments are english. No other languages permitted.
* Don't put multiple classes/structures in one file (except simple nested types that stay completely internal)
* Don't split classes across multiple files.
* Adapt the current formatting. We are not very strict. If it's readable, it's good.
* Write comments. Quality > Quantity. Keep them informative.
* No dirty code. No hacks. Keep it clean. Avoid memory leaks.

## Commit Rules

> These rules were *stolen* from the [MonoDevelop Project](http://www.monodevelop.com/developers/)
> But they fit so nicely!

1. Enter a meaningful explanation in the commit log message.
2. The first line of the commit message should be prefixed by the component name in square brackets, if it affects a single component, e.g. `[SR_GameServer]`
3. The first line of the commit message should be a short (ideally <50 columns) message, followed by a blank line. The rest of the commit message could contain a more detailed explanation of the change, wrapped to 80 columns.
4. When entering a message describing a change, take into account that the goal is to explain why the change was done, rather than what was changed. For example, the message “Added property X” is in general useless since it is obvious looking at the patch.
5. All changes included in a commit should be related and as atomic as possible. Here are some examples:
    * You do an API change that affects several projects across the source tree. All changes can go in a single commit.
    * You implement a new feature A. Then you implement another new feature B that uses A. Although those changes are related (B needs A), they should be committed separately, since they belong to two different features.
6. Don’t do reformatting commits, unless you’re the original author of the code. This includes changing line endings.
7. Never remove copyright notices from the code.
8. Never remove licensing info from code.
9. Never commit code you didn’t write yourself or code that doesn’t have a suitable license.
