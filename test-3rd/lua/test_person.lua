--[[
	模拟对象
--]]


Person = {}

-- 创建新对象
function Person:new()
	local new_person = {}
	self.__index = self -- 模拟继承关系
	setmetatable(new_person,self) -- 绑定元表
	return new_person;
end

-- 此形式相当于隐藏了第一个参数self
function Person:setName(name)
	self.name = name;
end

-- 此形式需要传入self
function Person.setAge(self,age)
	self.age = age
end

return Person



