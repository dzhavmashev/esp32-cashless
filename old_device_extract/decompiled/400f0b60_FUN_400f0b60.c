// Function : FUN_400f0b60
// Address  : 0x400f0b60
// Size     : 76 bytes


int FUN_400f0b60(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
    if (*param_1 == 0) goto LAB_400f0b7e;
    uVar3 = param_1[1];
  }
  else {
    uVar3 = 0xe;
  }
  if (param_2 <= uVar3) {
    return 1;
  }
LAB_400f0b7e:
  iVar1 = FUN_400f0a5c(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = FUN_40184778(param_1);
  if (iVar2 != 0) {
    return 1;
  }
  if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
    param_1 = (int *)*param_1;
  }
  *(undefined1 *)param_1 = 0;
  return iVar1;
}

