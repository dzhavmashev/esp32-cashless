// Function : FUN_40134030
// Address  : 0x40134030
// Size     : 111 bytes


int FUN_40134030(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1 + 4;
  iVar1 = FUN_40131ad8(iVar3,0);
  if (((int)param_2 < 0) || (iVar1 == 0)) {
    iVar1 = -0x3080;
  }
  else {
    uVar2 = FUN_401317d8(iVar3);
    iVar4 = param_1 + 0x1c;
    if (param_2 < uVar2) {
      iVar1 = FUN_401323a8(iVar4,param_2);
    }
    else {
      iVar1 = FUN_4013400c(iVar4,iVar3,param_3,param_4);
      if (iVar1 == -0xe) {
        return -0x3180;
      }
    }
    if (iVar1 == 0) {
      iVar1 = FUN_4013d3d8(param_1 + 0x28,param_1 + 0x10,iVar4,iVar3,param_1 + 0x4c);
      if (iVar1 == 0) {
        iVar1 = FUN_40133fd4(param_1 + 0x28,iVar3);
      }
    }
  }
  return iVar1;
}

