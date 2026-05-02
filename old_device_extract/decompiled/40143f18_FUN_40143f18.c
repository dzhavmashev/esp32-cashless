// Function : FUN_40143f18
// Address  : 0x40143f18
// Size     : 72 bytes


int FUN_40143f18(uint *param_1,byte *param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  if ((byte *)*param_1 != param_2) {
    *param_3 = (uint)*(byte *)*param_1;
    memw();
    iVar1 = FUN_40141738(param_1,param_2,param_3 + 1,param_4 | 0xa0);
    if (iVar1 == 0) {
      uVar2 = *param_1;
      param_3[2] = uVar2;
      *param_1 = uVar2 + param_3[1];
      memw();
      return 0;
    }
    if (iVar1 != -0x62) {
      return iVar1 + -0x2180;
    }
  }
  return 0;
}

