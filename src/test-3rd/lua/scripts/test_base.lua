--[[
	自定义模块
--]]

local Person = require("test_person")

mylua = {}

mylua.data = {"Jack-Ma","Pony-Ma","Robin"}

-- 本地函数 被调用必须写在前面
local function f3()
	print "mylua local f3"
end

-- 基本语法测试
local function basetest()

end

-- 循环测试
local function looptest()
	for i=1,3 do
		print(mylua.data[i])
	end
end

-- 流程控制测试
local function statetest()

end

-- 字符串测试
local function stringtest()

end


function mylua:test()
	print "loop test:"
	looptest()

	print "        "
	print "新对象创建测试:"
	local p1 = Person:new()
	p1:setName("tink")
	p1.setAge(p1,111)
	local p2 = Person:new()
	p2:setName("icefrog")
	p2.setAge(p2,222)

	print(p1.name)
	print(p2.name)
	print(p1.age)
	print(p2.age)

	print "        "
end

return mylua