// Function : FUN_401312c0
// Address  : 0x401312c0
// Size     : 126 bytes


int FUN_401312c0(uint *param_1,uint param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  
  uVar1 = FUN_401317d8(param_3);
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  uVar5 = *param_1;
  if ((uVar5 < param_2) || (uVar5 - param_2 < uVar1)) {
LAB_401312d3:
    iVar2 = -0x6c;
  }
  else {
    *param_1 = uVar5 - uVar1;
    memw();
    iVar2 = FUN_40131900(param_3,uVar5 - uVar1,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((*param_3 == 1) && (pbVar4 = (byte *)*param_1, (*pbVar4 & 0x80) != 0)) {
      if ((int)((int)pbVar4 - param_2) < 1) goto LAB_401312d3;
      *param_1 = (uint)(pbVar4 + -1);
      uVar1 = uVar1 + 1;
      pbVar4[-1] = 0;
      memw();
    }
    memw();
    iVar2 = FUN_40131188(param_1,param_2,uVar1);
    if (-1 < iVar2) {
      iVar3 = FUN_40185bfc(param_1,param_2,2);
      iVar2 = iVar3 + iVar2 + uVar1;
      if (iVar3 < 0) {
        iVar2 = iVar3;
      }
    }
  }
  return iVar2;
}

