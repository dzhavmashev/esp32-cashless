// Function : FUN_4011dbec
// Address  : 0x4011dbec
// Size     : 76 bytes


undefined4
FUN_4011dbec(undefined4 param_1,undefined1 param_2,undefined2 param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = *param_5 >> 0x10;
  uVar3 = (*param_4 & 0xffff) + (*param_4 >> 0x10) + (*param_5 & 0xffff) + uVar1;
  uVar3 = (uVar3 >> 0x10) + (uVar3 & 0xffff);
  uVar2 = FUN_4011db40(param_1,param_2,param_3,(uVar3 >> 0x10) + (uVar3 & 0xffff),uVar1,4);
  return uVar2;
}

