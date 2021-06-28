Markdown
========
Contents
--------
- [Basic Syntax](#basic-syntax)
    - [Headings](#headings)
    - [Styling](#styling)
    - [Quotes](#quotes)
    - [Links](#links)
    - [Images](#images)
    - [Lists](#lists)
- [Extended Syntax](#extended-syntax)
    - [Task Lists](#task-lists)
    - [Tables](#tables)
    - [Fenced Code Blocks](#fenced-code-blocks)
- [Useful Links](#useful-links)
    - [Basic Syntax Links](#basic-syntax-links)
    - [Extended Syntax Links](#extended-syntax-links)
    - [General Information Links](#general-information-links)

Basic Syntax
------------
### Headings
---
```markdown
# H1
## H2
### H3
#### H4
##### H5
###### H6
H1
==
H2
--
```

Output:

# H1
## H2
### H3
#### H4
##### H5
###### H6
H1
==
H2
--

### Styling
---
```markdown
**bold**
*italic*
~~strike-through~~
```
Output:

**bold**

*italic*

~~strike-through~~

### Quotes
---
```markdown
> Text
>> Nested Quote
`Code`
```
Output:

> Text

>> Nested Quote

`Code`

### Links
---
```markdown
[Link Text](URL or Path)
[Heading Link Text](#heading-text)
```
Output:

[Link Text](#)

[Heading Link Text](#contents)

### Images
---
```markdown
![Alt Text](Image Path "Image Title")
[![Alt Text](Image Path "Image Title")](Image Link URL)
```
### Lists
---
```markdown
1. Item 1
2. Item 2
3. Item 3

- Item 1
- Item 2
- Item 3

1. Item 1
2. Item 2
    - Sub Item 1
        - Sub Sub Item 1
        - Sub Sub Item 2
    - Sub Item 2
3. Item 3
```
Output:

1. Item 1
2. Item 2
3. Item 3

- Item 1
- Item 2
- Item 3

1. Item 1
2. Item 2
    - Sub Item 1
        - Sub Sub Item 1
        - Sub Sub Item 2
    - Sub Item 2
3. Item 3

Extended Syntax
---------------
### Task Lists
```markdown
- [x] Task 1 is complete
- [ ] Task 2 is incomplete
- [ ] Task 3 is incomplete
```
Output:

- [x] Task 1 is complete
- [ ] Task 2 is incomplete
- [ ] Task 3 is incomplete

### Tables
---
```markdown
| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |

| Left-aligned | Center-aligned | Right-aligned |
| :---         |     :---:      |          ---: |
| Content Cell | Content Cell   | Content Cell  |
| Content Cell | Content Cell   | Content Cell  |
```
Output:

| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |

| Left-aligned | Center-aligned | Right-aligned |
| :---         |     :---:      |          ---: |
| Content Cell | Content Cell   | Content Cell  |
| Content Cell | Content Cell   | Content Cell  |

### Fenced Code Blocks
---
````markdown
```javascript
function test() {
    console.log("fenced code block");
}
```
````
Output:

```javascript
function test() {
    console.log("fenced code block");
}
```
Useful Links
------------
- #### Basic Syntax Links:
    - <https://www.markdownguide.org/basic-syntax/>
    - <https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github>
- #### Extended Syntax Links:
    - <https://www.markdownguide.org/extended-syntax>
    - <https://docs.github.com/en/github/writing-on-github/working-with-advanced-formatting>
- #### General Information Links
    - <https://daringfireball.net/projects/markdown/>
    - <https://guides.github.com/features/mastering-markdown/>
    - <https://github.github.com/gfm/>
