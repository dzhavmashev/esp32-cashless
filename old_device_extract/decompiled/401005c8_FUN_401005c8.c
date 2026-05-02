// Function : FUN_401005c8
// Address  : 0x401005c8
// Size     : 77 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401005c8(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(*(code *)&SUB_40094dd8)(1,8);
  iVar2 = 0x101;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    memw();
    iVar2 = FUN_40100598();
    if (iVar2 == 0) {
      puVar1[1] = _DAT_3ffc5858;
      _DAT_3ffc5858 = puVar1;
      _DAT_3ffc5854 = _DAT_3ffc5854 + 1;
      memw();
      FUN_401005b0();
    }
    else {
      (*(code *)&SUB_40094d80)(puVar1);
    }
  }
  return iVar2;
}

