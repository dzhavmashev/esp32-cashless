// Function : FUN_4011db40
// Address  : 0x4011db40
// Size     : 112 bytes


uint FUN_4011db40(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = false;
  for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    iVar2 = FUN_40185550(param_1[1],*(undefined2 *)((int)param_1 + 10));
    param_4 = (iVar2 + param_4 >> 0x10) + (iVar2 + param_4 & 0xffff);
    if ((*(ushort *)((int)param_1 + 10) & 1) != 0) {
      bVar1 = (bool)(bVar1 ^ 1);
      param_4 = param_4 * 0x100 & 0xffff | param_4 >> 8 & 0xff;
    }
  }
  if (bVar1) {
    param_4 = (param_4 & 0xff) << 8 | param_4 >> 8 & 0xff;
  }
  iVar2 = FUN_40185290(param_2);
  iVar3 = FUN_40185290(param_3);
  param_4 = iVar2 + iVar3 + param_4;
  uVar4 = (param_4 >> 0x10) + (param_4 & 0xffff);
  return ((uVar4 >> 0x10) + (uVar4 & 0xffff) ^ 0xffffffff) & 0xffff;
}

