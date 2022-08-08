大致是这样的

单据列表, 字段不可查看权限
如果是 
单据定义字段, 列表显示 ***, 查询显示 无%s字段的查看权限，请更换查询条件进行过滤。
基础资料引用字段, 列表显示 ****, 但是过滤条件能查询
基础资料引用字段, 没有控权处理

相关代码
kd.bos.list.BillList#checkFilterPermission

String fieldName = this.getRealFieldKey(currentFieldName);
if (frule.getCanNotReadFields().contains(fieldName)) {
    throw new KDBizException(String.format(ResManager.loadKDString("无%s字段的查看权限，请更换查询条件进行过滤。", "BillList_8", "bos-form-core", new Object[0]), fieldName));
}

getCanNotReadFields() 
// 列表 [name,  base.name]
// this.getRealFieldKey();  传入 name , 返回 name,  能走到 异常提醒
// this.getRealFieldKey();  传入 base.name , 返回 base,  走不到 异常提醒
