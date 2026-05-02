// Function : FUN_401344dc
// Address  : 0x401344dc
// Size     : 68 bytes


int FUN_401344dc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_44 [68];
  
  FUN_4013562c(auStack_44);
  memw();
  iVar1 = FUN_4013633c(param_1,auStack_44,param_4,param_3,param_5,param_6,0);
  if (iVar1 == 0) {
    iVar2 = FUN_40135e44(auStack_44);
    iVar1 = -0x4f80;
    if (iVar2 == 0) {
      iVar1 = FUN_4013167c(param_2,auStack_44);
    }
  }
  FUN_401356a8(auStack_44);
  return iVar1;
}

