// Function : FUN_400f0c1c
// Address  : 0x400f0c1c
// Size     : 230 bytes


void FUN_400f0c1c(undefined4 *param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  cVar1 = *(char *)((int)param_1 + 0xf);
  if (cVar1 < '\0') {
    uVar5 = 0xe;
    puVar4 = param_1;
  }
  else {
    puVar4 = (undefined4 *)*param_1;
    if (puVar4 == (undefined4 *)0x0) goto LAB_400f0c83;
    uVar5 = param_1[1];
  }
  uVar2 = FUN_40184778(param_2);
  if (uVar2 <= uVar5) {
    puVar6 = param_2;
    if (((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) &&
       (puVar6 = (undefined4 *)*param_2, puVar6 == (undefined4 *)0x0)) {
      uVar2 = 0;
    }
    func_0x4008b4d0(puVar4,puVar6,uVar2 + 1);
    uVar3 = FUN_40184778(param_2);
    FUN_40184790(param_1,uVar3);
    FUN_400f0a38(param_2);
    return;
  }
  if ((-1 < cVar1) && (func_0x40094d88(*param_1), (*(byte *)((int)param_1 + 0xf) & 0x80) == 0)) {
    *param_1 = 0;
  }
LAB_400f0c83:
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) & 0x7f;
    puVar4 = param_2;
    if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
      puVar4 = (undefined4 *)*param_2;
    }
    if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
      *param_1 = puVar4;
    }
  }
  else {
    *(byte *)((int)param_1 + 0xf) = *(byte *)((int)param_1 + 0xf) | 0x80;
    func_0x4008b4d0(param_1,param_2,0xf);
  }
  uVar3 = 0xe;
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    uVar3 = param_2[1];
  }
  if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
    param_1[1] = uVar3;
  }
  uVar3 = FUN_40184778(param_2);
  FUN_40184790(param_1,uVar3);
  *(byte *)((int)param_2 + 0xf) = *(byte *)((int)param_2 + 0xf) & 0x7f;
  param_2[1] = 0;
  *param_2 = 0;
  FUN_40184790(param_2,0);
  return;
}

