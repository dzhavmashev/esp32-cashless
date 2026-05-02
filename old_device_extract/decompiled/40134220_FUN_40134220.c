// Function : FUN_40134220
// Address  : 0x40134220
// Size     : 53 bytes


int FUN_40134220(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4013167c(param_1 + 1,param_2);
  if ((iVar1 == 0) && (iVar1 = FUN_4013167c(param_1 + 4,param_3), iVar1 == 0)) {
    uVar2 = FUN_401317d8(param_1 + 1);
    *param_1 = uVar2;
    memw();
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + -0x3580;
  }
  return iVar1;
}

