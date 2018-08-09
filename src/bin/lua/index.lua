
--搜索lua模块
package.path = 'lua/?.lua;'   
--搜索so模块
package.cpath = "./?.so" --so搜寻路劲     

-- 引入lua模块
test_base = require("test_base")
-- 引入C模块
MyMath = require("MyMath")

require("test_sqlite3")

avg = average(8,6)

print("The average is ", avg)  

-- 中文测试
print "中文测试:"

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