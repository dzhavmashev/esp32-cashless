// Function : FUN_40142af8
// Address  : 0x40142af8
// Size     : 35 bytes


void FUN_40142af8(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_4;
  if (param_3 != 0) {
    while (uVar1 != 0) {
      iVar2 = (param_4 < param_2) * param_4 + (param_4 >= param_2) * param_2;
      (*(code *)&SUB_4008b3d0)(param_1,param_3,iVar2);
      param_1 = param_1 + iVar2;
      param_2 = param_2 - iVar2;
      uVar1 = param_2;
    }
  }
  return;
}

