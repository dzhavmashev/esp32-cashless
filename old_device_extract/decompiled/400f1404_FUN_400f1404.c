// Function : FUN_400f1404
// Address  : 0x400f1404
// Size     : 55 bytes


int FUN_400f1404(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = FUN_40184778(param_1);
  iVar3 = -1;
  if (param_3 < uVar1) {
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      param_1 = (int *)*param_1;
    }
    if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
      param_2 = (int *)*param_2;
    }
    iVar2 = func_0x4008ca64((int)param_1 + param_3,param_2);
    iVar3 = -1;
    if (iVar2 != 0) {
      iVar3 = iVar2 - (int)param_1;
    }
  }
  return iVar3;
}

