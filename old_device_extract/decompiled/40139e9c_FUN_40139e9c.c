// Function : FUN_40139e9c
// Address  : 0x40139e9c
// Size     : 60 bytes


int FUN_40139e9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,uint param_6)

{
  uint uVar1;
  int iVar2;
  
  memw();
  uVar1 = FUN_4018658c(param_1);
  iVar2 = -0x4380;
  if (uVar1 <= param_6) {
    memw();
    iVar2 = FUN_4013c4d0(param_1,0,0,0,param_2,param_4,param_3,param_5);
    if ((iVar2 == 0) && (uVar1 < param_6)) {
      iVar2 = -0x3900;
    }
  }
  return iVar2;
}

