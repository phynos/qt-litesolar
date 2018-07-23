
avg = average(8,6)

print("The average is ", avg)  

mydata = {id = 1, name = "lupc"}

MyMath = require("MyMath")

--初始化函数(接口函数)
function MyExInit()
	kk = MyMath.average(10,90)
	print("kk ", kk)  
	print "do lua init"
end

--主循环函数(接口函数)
function MyExLoop()
	print "do lua loop"
end