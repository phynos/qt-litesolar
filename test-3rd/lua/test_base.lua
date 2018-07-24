--[[
	自定义模块
--]]

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

function mylua.f1(self,a)
	self.x = a
end

function mylua:f2(a)
	self.x = a
end

-- 创建新对象
function mylua:new()
	local new_mylua = {}
	self.__index = self -- 模拟继承关系
	setmetatable(new_mylua,self) -- 绑定元表
	return new_mylua
end

function mylua:test()
	print "loop test:"
	looptest()

	print "        "
	print "yu fa tang test:"
	self.f1(self,10)
	print(self.x)
	self:f2(20)
	print(self.x)

	print "        "
	print "create new object test:"
	local obj1 = self:new()
	obj1:f2(100)
	print(obj1.x)

	local obj2 = self:new()
	obj2:f2(200)
	print(obj2.x)

	print "        "
end

return mylua