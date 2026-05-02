// Function : FUN_40143ce4
// Address  : 0x40143ce4
// Size     : 62 bytes


int FUN_40143ce4(uint *param_1,int param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint auStack_24 [9];
  
  iVar3 = -0x24e0;
  if (0 < param_2 - (int)*param_1) {
    bVar1 = *(byte *)*param_1;
    iVar3 = FUN_4014195c(param_1,param_2,auStack_24);
    if (iVar3 == 0) {
      param_3[2] = *param_1;
      uVar2 = *param_1;
      *param_3 = (uint)bVar1;
      param_3[1] = auStack_24[0];
      *param_1 = uVar2 + auStack_24[0];
      memw();
      iVar3 = 0;
    }
    else {
      iVar3 = iVar3 + -0x2480;
    }
  }
  return iVar3;
}

