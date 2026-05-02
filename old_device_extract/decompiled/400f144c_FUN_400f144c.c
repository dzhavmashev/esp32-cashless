// Function : FUN_400f144c
// Address  : 0x400f144c
// Size     : 88 bytes


int FUN_400f144c(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  
  uVar2 = FUN_40184778(param_1);
  if (param_3 < uVar2) {
    puVar5 = param_1;
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      puVar5 = (undefined4 *)*param_1;
    }
    puVar4 = (undefined1 *)((int)puVar5 + param_3 + 1);
    uVar1 = *puVar4;
    *puVar4 = 0;
    puVar5 = param_1;
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      puVar5 = (undefined4 *)*param_1;
    }
    iVar3 = func_0x4008ca34(puVar5,param_2);
    *(undefined1 *)((int)puVar5 + param_3 + 1) = uVar1;
    if (iVar3 != 0) {
      if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
        param_1 = (undefined4 *)*param_1;
      }
      return iVar3 - (int)param_1;
    }
  }
  return -1;
}

