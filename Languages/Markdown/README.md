Markdown
========
Markdown language reference.

Headings
--------
# \#H1
## \#\#H2
### \#\#\#H3
#### \#\#\#\#H4
##### \#\#\#\#\#H5
###### \#\#\#\#\#\#H6

Emphasis
--------
*\*Italic\**

**\*\*Bold\*\***

***\*\*\*Bold and Italic\*\*\****

Blockquotes
-----------
>\>Blockquote

>\>Mulitple line
>
>\>Blockquote (line above contains \>)

>\>Blockquote
>>\>\>Nested Blockquote

Lists
------------
Ordered lists can be nested in unordered lists and unordered lists can be nested in ordered lists.

#### Ordered List
1. Item 1
2. Item 2
    1. Sub Item 1
    2. Sub Item 2
3. Item 3

#### Unordered List
- \- Item 1
- \- Item 2
    - \- Sub Item 1
    - \- Sub Item 2
- \- Item 3

* \* Item 1
* \* Item 2
    * \* Sub Item 1
    * \* Sub Item 2
* \* Item 3

+ \+ Item 1
+ \+ Item 2
    + \+ Sub Item 1
    + \+ Sub Item 2
+ \+ Item 3

Code
----
For word or phrase use \`:
``Code``

For block of code use triple \`'s and also supply language next to top row of \`'s:
```python
string = "python markdown code block"
print(string)
```

Horizontal Separator
--------------------
Use at least three \*'s, \-'s or \_'s in a row on own line.

Links and Images
----------------
#### Link
\[Link Text\]\(Link URL\)

#### Image
\!\[Alt Text\]\(Image Path "Image Title"\)

#### Image Link
\[\!\[Alt Text\]\(Image Path "Image Title"\)\]\(Image Link URL\)

________
Sources:
- [Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)
- [Basic Syntax](https://www.markdownguide.org/basic-syntax/)
- [Extended Syntax](https://www.markdownguide.org/extended-syntax/)



