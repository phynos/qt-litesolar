
-- 引入lua模块
test_base = require("test_base")
-- 引入C模块
MyMath = require("MyMath")

avg = average(8,6)

print("The average is ", avg)  

mydata = {id = 1, name = "lupc"}



--初始化函数(接口函数)
function MyExInit()
	print "do lua init"
	
	test_base:test()

	kk = MyMath.average(10,90)
	print("kk ", kk)  
end

--主循环函数(接口函数)
function MyExLoop()
	print "lua loop print"
end