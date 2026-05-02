// Function : FUN_4010e180
// Address  : 0x4010e180
// Size     : 155 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010e180(int param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    (*(code *)&SUB_40094c54)("id cseg",0x7a0,"process","cp_in.c");
  }
  uVar5 = (uint)_DAT_3ffc6356;
  if (uVar5 != 0) {
    _DAT_3ffc634c = 0;
    memw();
    while (_DAT_3ffc634c < uVar5) {
      iVar3 = FUN_4010e05c();
      if (iVar3 != 1) {
        if ((char)iVar3 == '\0') break;
        if (iVar3 == 2) {
          iVar3 = FUN_4010e05c();
          if ((iVar3 != 4) || (uVar5 <= _DAT_3ffc634c + 1)) break;
          sVar1 = FUN_4010e05c();
          uVar2 = FUN_4010e05c();
          uVar2 = sVar1 << 8 | uVar2;
          if (0x59b < (ushort)(uVar2 - 1)) {
            uVar2 = 0x59c;
          }
          *(ushort *)(param_1 + 0x5e) = uVar2;
          memw();
          memw();
        }
        else {
          uVar4 = FUN_4010e05c();
          if (uVar4 < 2) break;
          _DAT_3ffc634c = (_DAT_3ffc634c - 2) + (short)uVar4;
          memw();
          memw();
        }
      }
    }
  }
  memw();
  return;
}

