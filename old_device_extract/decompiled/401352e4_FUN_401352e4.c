// Function : FUN_401352e4
// Address  : 0x401352e4
// Size     : 90 bytes


int FUN_401352e4(undefined4 param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  param_3 = param_3 + 0xc;
  uVar3 = 0;
  while( true ) {
    if (uVar3 == param_4) {
      memw();
      iVar2 = FUN_40134e84(param_1,param_2,param_5 >> 7);
      return iVar2;
    }
    bVar1 = uVar3 == (param_5 >> 1 & 0x3f);
    memw();
    iVar2 = FUN_4013365c(param_2,param_3 + -0xc,bVar1);
    if (iVar2 != 0) break;
    iVar2 = FUN_4013365c(param_2 + 0xc,param_3,bVar1);
    param_3 = param_3 + 0x24;
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar3 = uVar3 + 1 & 0xff;
  }
  return iVar2;
}

