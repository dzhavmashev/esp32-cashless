// Function : FUN_40141850
// Address  : 0x40141850
// Size     : 79 bytes


int FUN_40141850(int *param_1,int param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_40141738(param_1,param_2,param_3,3);
  if (iVar2 == 0) {
    iVar3 = *param_3;
    if (iVar3 == 0) {
      iVar2 = -0x60;
    }
    else {
      *param_3 = iVar3 + -1;
      bVar1 = *(byte *)*param_1;
      *(byte *)(param_3 + 1) = bVar1;
      memw();
      if (bVar1 < 8) {
        iVar3 = *param_1 + iVar3;
        param_3[2] = *param_1 + 1;
        *param_1 = iVar3;
        if (iVar3 != param_2) {
          iVar2 = -0x66;
        }
      }
      else {
        iVar2 = -100;
      }
    }
  }
  memw();
  return iVar2;
}

