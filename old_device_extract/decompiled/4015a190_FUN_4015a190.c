// Function : FUN_4015a190
// Address  : 0x4015a190
// Size     : 60 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4015a190(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_2 == 0) || (0x18 < (param_1 & 0xff))) {
    uVar1 = 0;
  }
  else {
    iVar2 = (param_1 & 0xff) + 0x50;
    uVar1 = 1;
    if (param_2 != *(int *)(&DAT_3ffc87f0 + iVar2 * 4)) {
      if (*(int *)(&DAT_3ffc87f0 + iVar2 * 4) != 0) {
        (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      }
      *(int *)(&DAT_3ffc87f0 + iVar2 * 4) = param_2;
      memw();
      return 1;
    }
  }
  return uVar1;
}

