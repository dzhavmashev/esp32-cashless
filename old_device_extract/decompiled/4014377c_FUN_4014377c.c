// Function : FUN_4014377c
// Address  : 0x4014377c
// Size     : 77 bytes


int FUN_4014377c(uint *param_1,int param_2,uint *param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  
  pbVar1 = (byte *)*param_1;
  iVar3 = -0x22e0;
  if ((0 < param_2 - (int)pbVar1) && (iVar3 = -0x22e2, (*pbVar1 & 0x7f) == 2)) {
    *param_1 = (uint)(pbVar1 + 1);
    *param_3 = (uint)*pbVar1;
    memw();
    iVar3 = FUN_40186734(param_1,param_2,param_3 + 1);
    if (iVar3 == 0) {
      uVar2 = *param_1;
      param_3[2] = uVar2;
      *param_1 = uVar2 + param_3[1];
      memw();
      iVar3 = 0;
    }
    else {
      iVar3 = iVar3 + -0x2280;
    }
  }
  return iVar3;
}

