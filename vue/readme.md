# vue2

diff算法

数据->virtual dom->real dom



## 监视的原理

 首先是更新的问题，如果数据里面一个数组的东西用一个对象直接替代，但是vue检测不大

```
data:{
	persons:[
	{},
	{}
	]
}

this.persons[0]={} 这样vue检测不到变化
```



setter方法 在改变时 重新解析模板。

```js
data:{}
Object.defineProperty(data,'name'{
	get(){
    return data.name
},
    set(val){
       data.name.val 
}
})//这个代码巨大的问题就是，你修改和获取的时候会调用get和set但是，这又会引起修改和改变这个动作，因此又调用get和set 最后call stack溢出
```



```js
data:{}

const obs = new Observer(data);//检测data的变化

let vm = {}
vm._data = data = obs

//vm会递归所有属性，并且为之设置set和get
function Observer(obj){
    const keys = Obeject.keys(obj)
    keys.forEach((k)=>{
        Object.defineProperty(this,k,{
            get()
            {
                return obj[k]
            },
            set(val)
            {
                解析模板，生成虚拟dom
				obj[k] = val
            }
        })
    })
}
```



```js
//vm上追加属性
Vue.set(targetObj,key,val)
//不用给data和vm加属性
//必须是里面的
```



不能检测到数组 是因为没有对索引值的set和get 

```
this.persons[0]={} 这样vue检测不到变化
//vue检测push splice 等等7个
//不过vm管理的数组 里面的push包装过 除了使用array.prototype.push 还有解析
this.persons[0].splice(0,1,{})这个才能被检测到
```

