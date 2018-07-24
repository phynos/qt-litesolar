
-- 引入lua模块
require("mylua")
-- 引入C模块
MyMath = require("MyMath")

avg = average(8,6)

print("The average is ", avg)  

mydata = {id = 1, name = "lupc"}



--初始化函数(接口函数)
function MyExInit()
	print "do lua init"
	
	mylua:test()

	kk = MyMath.average(10,90)
	print("kk ", kk)  
end

--主循环函数(接口函数)
function MyExLoop()
	print "do lua loop"
end