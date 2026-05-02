// Function : FUN_40185550
// Address  : 0x40185550
// Size     : 113 bytes


uint FUN_40185550(ushort *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort uStack_22;
  
  uStack_22 = 0;
  memw();
  uVar4 = (uint)param_1 & 1;
  if (((param_2 >> 0x1f) - param_2 < 0) && (uVar4 != 0)) {
    uVar1 = *param_1;
    param_2 = param_2 + -1;
    param_1 = (ushort *)((int)param_1 + 1);
    uStack_22 = (ushort)(byte)uVar1 << 8;
    memw();
  }
  iVar3 = 0;
  for (; 1 < param_2; param_2 = param_2 + -2) {
    iVar3 = iVar3 + (uint)*param_1;
    param_1 = param_1 + 1;
  }
  if (param_2 == 1) {
    uStack_22 = CONCAT11(uStack_22._1_1_,(byte)*param_1);
    memw();
  }
  uVar2 = ((uint)uStack_22 + iVar3 >> 0x10) + ((uint)uStack_22 + iVar3 & 0xffff);
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  if (uVar4 != 0) {
    uVar2 = uVar2 * 0x100 & 0xffff | uVar2 >> 8 & 0xff;
  }
  memw();
  return uVar2 & 0xffff;
}

