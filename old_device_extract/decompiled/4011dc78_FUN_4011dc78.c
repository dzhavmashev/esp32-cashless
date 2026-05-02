// Function : FUN_4011dc78
// Address  : 0x4011dc78
// Size     : 79 bytes


uint FUN_4011dc78(int *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = false;
  uVar3 = 0;
  for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    iVar2 = FUN_40185550(param_1[1],*(undefined2 *)((int)param_1 + 10));
    uVar3 = (iVar2 + uVar3 >> 0x10) + (iVar2 + uVar3 & 0xffff);
    if ((*(ushort *)((int)param_1 + 10) & 1) != 0) {
      bVar1 = (bool)(bVar1 ^ 1);
      uVar3 = uVar3 * 0x100 & 0xffff | uVar3 >> 8 & 0xff;
    }
  }
  if (bVar1) {
    uVar3 = (uVar3 & 0xff) << 8 | uVar3 >> 8 & 0xff;
  }
  return (uVar3 ^ 0xffffffff) & 0xffff;
}

