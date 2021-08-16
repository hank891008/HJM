### EOF
while True:
	try:
		pass
	except EOFError:
		break
###math
import math

math.ceil(x)#上高斯
math.floor(x)#下高斯
math.factorial(x)#接乘
math.fabs(x)#絕對值
math.fsum(arr)#跟sum一樣但更精確(小數點問題)
math.gcd(x, y)#bj4
math.exp(x)#e^x
math.log(x, base)
math.log2(x)#2為底
math.log10(x)#10為底
math.sqrt(x)
math.pow(x, y, mod)#精確些(float型態) MOD!!!
math.sin(x)# cos tan asin acos atan atan2(弧度) sinh cosh tanh acosh asinh atanh
math.hypot(x, y)#歐幾里德範數
math.degrees(x)#x從弧度轉角度
math.radians(x)#x從角度轉弧度
math.gamma(x)#x的gamma函數
math.pi#常數
math.e#常數
math.inf

### ascii
ord(x)#char to asc
chr(x)#asc to char

x.encode().hex()#string to hex
### reverse string
string = "abc"
string_reverse = string[::-1]