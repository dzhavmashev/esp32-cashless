// Function : FUN_401463ac
// Address  : 0x401463ac
// Size     : 133 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401463ac(undefined *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  
  FUN_4014605c();
  iVar1 = _DAT_3ffc8804;
  if (*_DAT_3ffbfc54 < 2) {
    FUN_401460a4();
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    if (_DAT_3ffc8804 != 0) {
      puVar6 = &DAT_3f4239bb;
      if (param_1 != (undefined *)0x0) {
        puVar6 = param_1;
      }
      (*(code *)&SUB_4008b3d0)(_DAT_3ffc8804 + 0x9c,puVar6,6);
      FUN_40153ed0(*(undefined4 *)(iVar1 + 0xec),0xc0,2);
      for (uVar4 = 1; uVar4 <= _DAT_3ffbfc54[0x3f6]; uVar4 = uVar4 + 1 & 0xff) {
        iVar5 = *(int *)(uVar4 * 4 + iVar1 + 0xec);
        if ((iVar5 != 0) &&
           ((param_1 == (undefined *)0x0 ||
            (iVar2 = (*(code *)&SUB_4008b33c)(param_1,iVar5 + 4,6), iVar2 == 0)))) {
          FUN_4015e19c(iVar5);
        }
      }
      uVar3 = 1;
    }
    FUN_401460a4();
  }
  return uVar3;
}

