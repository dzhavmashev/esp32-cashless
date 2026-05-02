// Function : FUN_40100700
// Address  : 0x40100700
// Size     : 96 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40100700(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = FUN_40100598();
  puVar4 = _DAT_3ffc5858;
  if (iVar1 == 0) {
    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)puVar4[1]) {
      uVar2 = *puVar4;
      uVar3 = FUN_40184ef4(uVar2);
      iVar1 = (*(code *)&SUB_4008bdec)(param_1,uVar3);
      if (iVar1 == 0) {
        FUN_401005b0();
        return uVar2;
      }
    }
    FUN_401005b0();
  }
  else {
    uVar2 = (*(code *)&SUB_40094b80)();
    FUN_4012113c(1,"jects.c","objects",uVar2,"jects.c",iVar1);
  }
  return 0;
}

