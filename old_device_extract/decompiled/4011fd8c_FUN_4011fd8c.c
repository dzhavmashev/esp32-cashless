// Function : FUN_4011fd8c
// Address  : 0x4011fd8c
// Size     : 107 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011fd8c(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  
  (*(code *)&SUB_40086460)(0x3ffc6cf8);
  if (_DAT_3ffc6d08 != 0 || _DAT_3ffc6d0c != 0) {
    FUN_4011fc74();
    _DAT_3ffc6d08 = 0;
    _DAT_3ffc6d0c = 0;
  }
  memw();
  (*(code *)&SUB_400864a0)(0x3ffc6cf8);
  iVar5 = *param_1;
  uVar3 = iVar5 * 1000000;
  iVar1 = param_1[1];
  uVar2 = uVar3 + iVar1;
  uVar6 = FUN_4011fe4c();
  uVar4 = uVar2 - (int)uVar6;
  FUN_4011fe6c(uVar4,(((uint)(uVar2 < uVar3) +
                      (int)((ulonglong)((longlong)iVar5 * 1000000) >> 0x20) + (iVar1 >> 0x1f)) -
                     (int)((ulonglong)uVar6 >> 0x20)) - (uint)(uVar2 < uVar4));
  return;
}

