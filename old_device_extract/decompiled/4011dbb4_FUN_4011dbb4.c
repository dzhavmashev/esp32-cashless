// Function : FUN_4011dbb4
// Address  : 0x4011dbb4
// Size     : 56 bytes


undefined4
FUN_4011dbb4(undefined4 param_1,undefined1 param_2,undefined2 param_3,uint *param_4,uint *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (*param_4 >> 0x10) + (*param_5 & 0xffff) + (*param_5 >> 0x10) + (*param_4 & 0xffff);
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  uVar1 = FUN_4011db40(param_1,param_2,param_3,(uVar2 >> 0x10) + (uVar2 & 0xffff));
  return uVar1;
}

