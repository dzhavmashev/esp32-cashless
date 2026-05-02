// Function : FUN_4018e66c
// Address  : 0x4018e66c
// Size     : 46 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4018e66c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  
  memw();
  iVar1 = (*(code *)&SUB_40094b30)();
  if ((iVar1 != 0) && (uVar2 = FUN_4018e470(param_2), param_1 <= uVar2)) {
    (*_DAT_3ffbe0e4)(param_3,param_4,param_5,param_6);
  }
  return;
}

