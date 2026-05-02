// Function : FUN_400f948c
// Address  : 0x400f948c
// Size     : 136 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f948c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *apiStack_24 [9];
  
  FUN_400f9390();
  uVar1 = FUN_400faca0();
  iVar2 = FUN_400facfc(uVar1,param_1,param_2,param_3,apiStack_24);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)(*(code *)&SUB_40094d60)(0x14);
    if (puVar3 == (undefined4 *)0x0) {
      if (apiStack_24[0] != (int *)0x0) {
        (**(code **)(*apiStack_24[0] + 4))();
      }
      iVar2 = 0x101;
    }
    else {
      puVar3[2] = apiStack_24[0];
      iVar4 = _DAT_3ffc56dc + 1;
      _DAT_3ffc56dc = iVar4;
      puVar3[4] = param_1;
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[3] = iVar4;
      if (_DAT_3ffc56d0 != (undefined4 *)0x0) {
        _DAT_3ffc56d0[1] = puVar3;
      }
      *puVar3 = _DAT_3ffc56d0;
      puVar3[1] = 0;
      if (_DAT_3ffc56cc == (undefined4 *)0x0) {
        _DAT_3ffc56cc = puVar3;
      }
      _DAT_3ffc56d4 = _DAT_3ffc56d4 + 1;
      _DAT_3ffc56d0 = puVar3;
      *param_4 = iVar4;
    }
  }
  memw();
  FUN_400f9378();
  return iVar2;
}

