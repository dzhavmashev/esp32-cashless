// Function : FUN_40103040
// Address  : 0x40103040
// Size     : 114 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40103040(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_40105ca0(_DAT_3ffc80e4);
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x24) != 0)) {
    iVar1 = (*(code *)&LAB_40185113_1)(_DAT_3ffc80e4);
    if (*(int *)(param_1 + 0x28) != iVar1 + 8) {
      return 0xffffffff;
    }
    iVar3 = *(int *)(param_1 + 0x24);
    iVar1 = (*(code *)&LAB_40185113_1)(_DAT_3ffc80e4);
    if ((iVar1 != _DAT_3ffc80a8) ||
       (iVar2 = (*(code *)&SUB_4008b33c)(0x3ffc8088,iVar3 + 8,iVar1), iVar2 != 0)) {
      iVar2 = FUN_4015aa08(0,iVar3);
      if (iVar2 < 0) {
        return 0xffffffff;
      }
      memw();
      _DAT_3ffc80a8 = iVar1;
      (*(code *)&SUB_4008b3d0)(0x3ffc8088,iVar3 + 8,iVar1);
    }
  }
  return 0;
}

