


## 生成目录

```markdown
[toc]
```

[TOC]



---

##标题

```markdown
# h1

## h2

### h3

#### h4

##### h5

###### h6
```
#h1

##h2

### h3

#### h4

##### h5

###### h6

---
##块引用

###单层

```markdown
> hello world!
```
> hello world!

###多层嵌套

```markdown
> aaa

>> bbb 

>>> ccc

```
> aaa

>> bbb 

>>> ccc



---

##列表

###无序列表
```markdown
* Red
* Green
* Blue
```
* Red
* Grean
* Blue

### 有序列表

```markdown
1. Red
2. Green
3. Blue
```
1. Red 
2. Green 
3. Blue

###任务列表

```markdown
- [ ] a task list 
- [ ] list syntax required
- [x] completed
```

- [ ] a task list 
- [ ] list syntax required 
- [x] completed



---

## 代码块

```markdown
​```
function test() {
  console.log("notice the blank line before this function?");
}
​```

​```python
def test():
	return 0
​```
```

```
function test() {
  console.log("notice the blank line before this function?");
}
```

```python
def test():
    return 0
```



---

##表格

```markdown
|      a       |            b           |         c         |
|:-------:|:------------- | ----------:|
|     居中   | 左对齐                |          右对齐 |
|========|=============|============|
```

| a | b | c |
|:----:|:------|-----:|
|居中|左对齐|右对齐|
|====|====|====|

---


## 水平线

输出`***`或`---`然后回车会出现一条水平线

就像下面这条线：

---




## 行内元素

### 链接

```markdown
This is	[an example](https://www.google.com)
```

This is [an example](https://google.com)。



### URLs

```markdown
<https://www.google.com>
```

<https://www.google.com>



###图片

```
![](https://ktchen.cn/static/img/favicon.ico)
```
![](https://ktchen.cn/static/img/favicon.ico)



### 强调

```markdown
This is a **strong** tag
```

This is a **strong** tag



### 小代码块

```markdown
This is a small `code`
```

This is a small `code`



## 脚注

```markdown
[^footnote]: Here is the *text* of the **footnote**.
```
[^footnote]: Here is the *text* of the **footnote**.
