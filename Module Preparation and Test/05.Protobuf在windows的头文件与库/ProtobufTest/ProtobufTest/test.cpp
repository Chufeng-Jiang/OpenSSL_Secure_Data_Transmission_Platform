#include <iostream>
#include "Persion.pb.h"
using namespace std;
using namespace itcast;
/*
	message Persion
	{
	int32 id = 1;   // 编号从1开始
	string name = 2;
	string sex = 3;
	int32 age = 4;
	}
*/
int main()
{
	// 1. 创建persion对象, 并初始化
	Persion p;
	p.set_id(1001);
	// 申请一块内存, 存储名字
	p.add_name();
	p.set_name(0, "路飞");

	p.add_name();
	p.set_name(1, "艾斯");

	p.add_name();
	p.set_name(2, "萨博");
	p.set_sex("man");
	p.set_age(17);
	// 枚举
	p.set_color(Blue);
	itheima::Persion* info = p.mutable_info();
	info->set_address("北京昌平区tdb大厦");
	info->set_number(911);
	// 2. 将persion对象序列化 -> 字符串
	string output;
	p.SerializeToString(&output);
	cout << "序列化后的数据: " << output << endl;

	// 3. 数据传输
	// 4. 接收数据, 解析(output) -> 解码 -> 原始数据
	// 4.1 创建Persion对象
	Persion pp;
	pp.ParseFromString(output);
	// 将Info对象值取出
	itheima::Persion ii = pp.info();
	// 5. 处理原始数据 -> 打印数据信息
	cout << "id: " << pp.id() << ", name: "
		<< pp.name(0) << ", "
		<< pp.name(1) << ", "
		<< pp.name(2)
		<< ", sex: " << pp.sex() << ", age: " << pp.age()
		<< ", color: " << pp.color()
		<< ", address: " << ii.address()
		<< ", number: " << ii.number()
		<< endl;

	return 0;
}