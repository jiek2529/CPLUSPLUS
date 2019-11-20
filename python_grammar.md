python

2019.7.23

# 注释

#字符串

>>> "hello, " "world!"

##字符拼接
>>> "hello, "+"World!"
>>> x = 'hello, '
>>> y = 'world'
>>> x + y

##长字符串
>>> print '''长字符,
可多行''' """我也是长字符，可多行"""

>>> print 'hello, \
world.' "单双引擎可混合成对出现，" '行尾\\是续行'

##原字符串
>>> print r'https://github.com/jiek2529'

##unicode

>>> print u"中国".encode("GBK")